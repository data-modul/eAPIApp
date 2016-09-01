/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/common/EApiAHI2C.c $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: All rights reserved. This program and the accompanying 
 *I              materials are licensed and made available under the 
 *I              terms and conditions of the BSD License which 
 *I              accompanies this distribution. The full text of the 
 *I              license may be found at 
 *I              http://opensource.org/licenses/bsd-license.php
 *I              
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
 *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for EApiAHI2C.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EApiAHI2C.c
 *I  File Location        : apps\common
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: EApiAHI2C.c 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EApiApp.h>

EApiStatus_t 
EApiAHI2CCCreateAddrOffset(
    __IN  const I2CDeviceDesc_t *const pDDesc     , 
    __IN  size_t                       Offset     , 
    __OUT size_t                      *pEncAddr   , 
    __OUT size_t                      *pEncOffset
    )
{
    EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CCCreateAddrOffset, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pDDesc
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CCCreateAddrOffset, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pEncAddr
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CCCreateAddrOffset, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pEncOffset
        );
    if(pDDesc->ExtIndx==EApiAPI2CExtIndex)
    {
      *pEncOffset=EAPI_I2C_ENC_EXT_CMD(Offset);
      Offset>>=16;
      Offset&=3;
      if(EAPI_I2C_IS_10BIT_ADDR(pDDesc->DeviceAddr))
        *pEncAddr=EAPI_I2C_ENC_10BIT_ADDR(
            EAPI_I2C_DEC_10BIT_ADDR(pDDesc->DeviceAddr)+Offset);
      else
        *pEncAddr=EAPI_I2C_ENC_7BIT_ADDR(
            EAPI_I2C_DEC_7BIT_ADDR(pDDesc->DeviceAddr)+Offset);
    }
    else
    {
      *pEncOffset=EAPI_I2C_ENC_STD_CMD(Offset);
      Offset>>=8;
      Offset&=3;
      if(EAPI_I2C_IS_10BIT_ADDR(pDDesc->DeviceAddr))
        *pEncAddr=EAPI_I2C_ENC_10BIT_ADDR(
            EAPI_I2C_DEC_10BIT_ADDR(pDDesc->DeviceAddr)+Offset);
      else
        *pEncAddr=EAPI_I2C_ENC_7BIT_ADDR(
            EAPI_I2C_DEC_7BIT_ADDR(pDDesc->DeviceAddr)+Offset);

    }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
ValidEEPDevDesc(
    __IN const I2CDeviceDesc_t *const pDDesc
    )
{
    EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
    int AddrCnt;
    if(pDDesc->ExtIndx==EApiAPI2CExtIndex)
    {
      AddrCnt=pDDesc->DevSize>>16<<1;
      if(AddrCnt)
      {
        /* Not Sure */
      }
    }
    else
    {
      AddrCnt=pDDesc->DevSize>>8<<1;
      if(AddrCnt)
      {
        if((pDDesc->DeviceAddr+AddrCnt)>0xAF)
        {
          return EAPI_STATUS_INVALID_PARAMETER;
        }
      }
    }
    return StatusCode;
}
EApiStatus_t
EApiAHI2CWriteEeprom(
    __IN EApiId_t               Id          , 
    __IN const I2CDeviceDesc_t *const pDDesc, 
    __IN const size_t           ByteOffset  , 
    __IN void *                 pBuffer     , 
    __IN size_t                 ByteCnt 
    )
{
    EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
    uint32_t IntMaxBlckLen;
    size_t BlockEndAddress;
    size_t BlockLength;
    size_t BlockLengthStd;
    size_t CurOffset;
    size_t EncAddr;
    size_t EncOffset;
    
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pDDesc
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pBuffer
        );
    EAPI_APP_ASSERT_PARAMATER_ZERO(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteCnt
        );
    EAPI_APP_ASSERT_PARAMATER_CHECK(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ValidEEPDevDesc(pDDesc) , 
        "Invalid EEPROM Device Descriptor"
        );
    EAPI_APP_ASSERT_PARAMATER_CHECK(
        EApiAHI2CWriteEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteOffset+ByteCnt>pDDesc->DevSize, 
        "Prevented Write beyond Device Boundary"
        );
#if STRICT_VALIDATION
    if(ByteOffset+ByteCnt>pDDesc->DevSize)
    {
      ByteCnt=pDDesc->DevSize-ByteOffset;
    }
#endif
#if 0
    printf(
        "DeviceAddr = %04"PRIX16"\n"
        "PageSize   = %04"PRIX16"\n"
        "ExtIndx    = %04"PRIX16"\n"
        "WRecTimems = %04"PRIX16"\n"
        "DevSize    = %04"PRIX16"\n"
        "ByteCnt    = %04lX\n"
        "ByteOffset = %04lX\n",
        pDDesc->DeviceAddr,
        pDDesc->PageSize,
        pDDesc->ExtIndx,
        pDDesc->WRecTimems,
        pDDesc->DevSize ,
        (unsigned long)ByteCnt ,
        (unsigned long)ByteOffset
      );
#endif
    
    /* Get Storage Capabilities */
    StatusCode=EApiI2CGetBusCap(Id, &IntMaxBlckLen);
    if(!EAPI_TEST_SUCCESS(StatusCode))
      goto ErrorExit;

    BlockEndAddress=ByteOffset+ByteCnt;
    /* Just use BlockLength as write overhead calculator briefly 
     * Write Overhead is CMD + 10Bit Address
     * I.E. First Byte of address is not included
     * so CMD/INDX can be 1  or 2 Bytes and the Address can add an extra byte
     * so we can have between 1 and 3 bytes overhead on an write.
     */
    BlockLength=(EAPI_I2C_DEC_10BIT_ADDR(pDDesc->DeviceAddr)?1:0)+pDDesc->ExtIndx;
    /* Ok so now we need to check if Page Size+ Write overhead is greater than the 
     * Max Transfer length on this interface
     * Basically use whichever is shorter for our Block Length
     */
    BlockLength=(IntMaxBlckLen<(pDDesc->PageSize+BlockLength)?IntMaxBlckLen-BlockLength:pDDesc->PageSize);
    /* This check is more important for reads than writes */
    if(pDDesc->ExtIndx==EApiAPI2CExtIndex)
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(BlockLength<0x10000?BlockLength:0x10000);
    else
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(BlockLength<0x100?BlockLength:0x100);
    CurOffset=ByteOffset;
    BlockLengthStd=BlockLength;
    while(CurOffset<BlockEndAddress)
    {
      /* Adjust block length so we don't write more than we intended 
       */
      if(CurOffset+BlockLength>BlockEndAddress){
        BlockLength=BlockEndAddress - CurOffset;
      }
      /* Adjust block length so we don't overrun the end of the Page 
       * As we've already verified all the maximum block lengths above
       * This should only be because of 2 reasons
       * 1. Start offset isn't aligned. 
       * 2. Bus interfaces maximum block length is not a divisor of the 
       *    EEPROM page length. 
       * To adequately address both situations, or indeed a combination
       * of them we check here if we're going to overwrite the page boundary
       * and if so adjust the Block length. At the end of the transfer we 
       * restore the Max calculate block length, from above and do it all over 
       * again 
       * Example 1.
       * Max Bus length = 16 Bytes
       * Page Size      = 16 Bytes
       * Start Offset   =  1
       * Write Overhead =  2 Bytes     For the Ext Index
       * Total Transfer = 32 Bytes
       *
       * Results in a 
       * Max Block length of 14 Bytes
       * This results in 5 transfers
       * 14Bytes 1Byte 14Bytes 2Bytes 1Byte
       *
       * Example 2.
       * Max Bus length = 18 Bytes
       * Page Size      = 16 Bytes
       * Start Offset   =  3
       * Write Overhead =  3 Bytes     For the Ext Index & 10Bit Address
       * Total Transfer = 30 Bytes
       *
       * Results in a 
       * Max Block length of 15 Bytes
       * This results in 4 transfers
       * 13Bytes 15Bytes 1Bytes 1Bytes 
       *
       * Example 3.
       * Max Bus length =  32 Bytes
       * Page Size      = 256 Bytes
       * Start Offset   = 230 
       * Write Overhead =   2 Bytes     For the Extended Index
       * Total Transfer =  60 Bytes
       *
       * Results in a 
       * Max Block length of 30 Bytes
       * This results in 3 transfers
       * 26Bytes 30Bytes 4Bytes
       */
      if(((CurOffset%pDDesc->PageSize)+BlockLength)>pDDesc->PageSize){
        BlockLength-=(CurOffset+BlockLength)%pDDesc->PageSize;
      }
      /* Get Encoded Device and Offset */
      StatusCode=EApiAHI2CCCreateAddrOffset(pDDesc, CurOffset, &EncAddr, &EncOffset);
      if(!EAPI_TEST_SUCCESS(StatusCode))
        goto ErrorExit;
      /* Do the actual transfer */
      StatusCode=EApiI2CWriteTransfer(
          Id, 
          (uint32_t)EncAddr, 
          (uint32_t)EncOffset, 
          ((int8_t *)pBuffer)+(CurOffset-ByteOffset), 
          (uint32_t)BlockLength
          );
      if(!EAPI_TEST_SUCCESS(StatusCode))
        goto ErrorExit;
      CurOffset+=BlockLength;
      BlockLength=BlockLengthStd; /* Restore Standard Block Length */
      if(pDDesc->WRecTimems)
        EApiSleep((uint32_t)pDDesc->WRecTimems); /* Allow Device Time to Recover */
    }
ErrorExit:
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
EApiAHI2CReadEeprom(
    __IN EApiId_t              Id           , 
    __IN const I2CDeviceDesc_t *const pDDesc, 
    __IN const size_t          ByteOffset   , 
    __IN void *                pBuffer      , 
    __IN const size_t          BufLength    , 
    __IN size_t                ByteCnt 
    )
{
    EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
    uint32_t IntMaxBlckLen;
    size_t   BlockEndAddress;
    size_t   BlockLength;
    size_t   CurOffset;
    size_t   EncAddr;
    size_t   EncOffset;
    
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pDDesc
        );
    EAPI_APP_ASSERT_PARAMATER_NULL(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        pBuffer
        );
    EAPI_APP_ASSERT_PARAMATER_ZERO(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        BufLength
        );
    EAPI_APP_ASSERT_PARAMATER_ZERO(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteCnt
        );
    EAPI_APP_PREVENT_BUF_OVERFLOW(
        EApiAHI2CReadEeprom, 
        ByteCnt, 
        BufLength
        );
    EAPI_APP_ASSERT_PARAMATER_CHECK(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ValidEEPDevDesc(pDDesc) , 
        "Invalid EEPROM Device Descriptor"
        );
    EAPI_APP_ASSERT_PARAMATER_CHECK(
        EApiAHI2CReadEeprom, 
        EAPI_STATUS_INVALID_PARAMETER, 
        ByteOffset+ByteCnt>pDDesc->DevSize, 
        "Prevented Write beyond Device Boundary"
        );
#if STRICT_VALIDATION
    if(ByteOffset+ByteCnt>pDDesc->DevSize)
    {
      ByteCnt=pDDesc->DevSize-ByteOffset;
    }
#endif
    
    /* Get Storage Capabilities */
    StatusCode=EApiI2CGetBusCap(Id, &IntMaxBlckLen);
    if(!EAPI_TEST_SUCCESS(StatusCode))
      goto ErrorExit;

    BlockEndAddress=ByteOffset+ByteCnt;

    if(pDDesc->ExtIndx==EApiAPI2CExtIndex)
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(IntMaxBlckLen<0x10000?IntMaxBlckLen:0x10000);
    else
      /* After this length it is necessary to increment the Device Address */
      BlockLength=(IntMaxBlckLen<0x100?IntMaxBlckLen:0x100);
    CurOffset=ByteOffset;
    while(CurOffset<BlockEndAddress)
    {
      /* Adjust block length so we don't overrun the end of the device */
      if(CurOffset+BlockLength>BlockEndAddress){
        BlockLength=BlockEndAddress-CurOffset;
      }
      /* Get Encoded Device and Offset */
      StatusCode=EApiAHI2CCCreateAddrOffset(pDDesc, CurOffset, &EncAddr, &EncOffset);
      if(!EAPI_TEST_SUCCESS(StatusCode))
        goto ErrorExit;
      /* Do the actual transfer */
      StatusCode=EApiI2CReadTransfer(
          Id, 
          (uint32_t)EncAddr, 
          (uint32_t)EncOffset, 
          ((int8_t *)pBuffer)+(CurOffset-ByteOffset), 
          (uint32_t)BlockLength, 
          (uint32_t)BlockLength
          );
      if(!EAPI_TEST_SUCCESS(StatusCode))
        goto ErrorExit;
      CurOffset+=BlockLength;
    }


ErrorExit:
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

