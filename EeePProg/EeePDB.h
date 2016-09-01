/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/EeePDB.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for sprintf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EeePDB.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: EeePDB.h 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __EEPDB_H__
#define __EEPDB_H__

#ifdef __cplusplus
extern "C" {
#endif


typedef void * EeePHandel_t;

#define EEEP_INIT_INCLUDE_CRC EAPI_UINT32_C(1<<0)

#define EEEP_DIVIDE_RU(Dividend, Divisor)  (((Dividend)+Divisor -1)/Divisor)
#define EEEP_DIVIDE_RD(Dividend, Divisor)  ((Dividend)/Divisor)
#define EEEP_ALIGN_VALUE(Value, Alignment) (EEEP_DIVIDE_RU(Value, Alignment)*Alignment)
#define EEEP_ALIGN_VALUE_B(Value, Alignment) ((Value+ Alignment-1)&(~(Alignment-1)))

#define EEEP_SIZE_UNITS        2
#define EEEP_ALIGN_LENGTH(x)  EEEP_ALIGN_VALUE_B(x, EEEP_SIZE_UNITS)
#define EEEP_MIN_BLOCK_LENGTH EEEP_ALIGN_LENGTH(sizeof(DBlockIdHdr_t))
#define EEEP_CRC_BLOCK_LENGTH EEEP_ALIGN_LENGTH(sizeof(EeePCRC16ChkBlock_t))


size_t 
EeePAdjLength(
    size_t Length
    );

size_t 
EeePAlignLength(
    size_t Length
    );

EApiStatus_t
SetBlockLength(
    EeePHandel_t BHandel,
    size_t       stBlockLength
    );

size_t 
GetBlockLength(
    const void * pcvBHandel
    );

DBlockIdHdr_t * 
GetNextBlock(
    DBlockIdHdr_t *pCurBlock
    );

EApiStatus_t
SetDynBlockHeader(
    void          *pCurBlock,
    uint8_t        u8BlockId,
    size_t         stBlockLength
    );

#define EEEP_RBL_REDUCE_TOP_DOWN  (1<<0)
EApiStatus_t
ReduceBlockLength(
    __IN     DBlockIdHdr_t**pvCurBlock,
    __IN     size_t         stReduceBy, 
    __OUTOPT DBlockIdHdr_t**pvNewBlock,
    __IN     unsigned int   uiFlags
    );

EApiStatus_t
EeePGetFirstDB(
    EeePHandel_t     BHandel,
    DBlockIdHdr_t ** pFirstDB, 
    size_t          *pstImageMaxSize
    );

EApiStatus_t
EeePCreateNewBuffer(
    EeePHandel_t *pBHandel,
    size_t   stBufferSize ,
    size_t   stHeaderSize ,
    uint32_t u32Flags
    );

EApiStatus_t
EeePFreeBuffer(
    EeePHandel_t *pBHandel
    );

typedef struct EeePBufferMap_s{
  EeePCmn_t       *pCmnHdr          ;
  DBlockIdHdr_t   *pEmptyBlock      ;
  EeePCRC16ChkBlock_t *pEeePCRCBlock    ;
}EeePBufferMap_t;


EApiStatus_t
EeePMapBuffer(
    EeePHandel_t     BHandel,
    EeePBufferMap_t *pBufMap
    );

#define EEEP_ADDBLK_IN_CRC (1<<0)
EApiStatus_t
EeePAddBlock(
    EeePHandel_t   BHandel ,
    const void    *pcvBlock , 
          void   **pvIBlock , 
    const unsigned cuiFlags    
    );

EApiStatus_t
EeePSetCRC(
    EeePHandel_t BHandel
    );

EApiStatus_t
EeePCheckCRC(
    EeePHandel_t BHandel
    );

EApiStatus_t
EeePFindBlock(
    __IN  EeePHandel_t   BHandel,
    __IN  uint8_t        BlockId,
    __IN  signed int     Instance,
    __OUT void         **pvFBlock
    );

EApiStatus_t
EeePFindVendorBlock(
    __IN  EeePHandel_t   BHandel,
    __IN  uint16_t       VendorId,
    __IN  uint8_t        VendorBlockId,
    __IN  signed int     Instance,
    __OUT void         **pvFBlock
    );

EApiStatus_t
EeePWriteBufferToFile(
    __IN  EeePHandel_t   BHandel,
    __IN  char          *pszFilename
    );

EApiStatus_t
EeePWriteBufferToEEP(
    __IN  EeePHandel_t   BHandel,
    __IN  unsigned       u16DeviceBus ,
    __IN  uint16_t       u16DeviceAddr 
    );

EApiStatus_t
EeePReadBufferFromFile(
    __OUT EeePHandel_t  *pBHandel,
    __IN  char          *pszFilename
    );

EApiStatus_t
EeePReadBufferFromEEP(
    __IN  EeePHandel_t  *pBHandel,
    __IN  unsigned       u16DeviceBus ,
    __IN  uint16_t       u16DeviceAddr 
    );

EApiStatus_t
EeePSetI2CDeviceDesc(
    __OUT I2CDeviceDesc_t *pDDesc,
    __IN  EeePHandel_t     BHandel,
    __IN  uint16_t         WRecTimems ,
    __IN  uint16_t         u16DeviceAddr
    );

EApiStatus_t
EeePListBlocks(
    EeePHandel_t BHandel,
    unsigned int uiFlags
  );
EApiStatus_t 
GetDBlckIdString(
    __OUT TCHAR *        pszString,
    __IN  size_t         stArrayLen,
    __IN  unsigned int   uiValue
    );
#ifdef __cplusplus
}
#endif
#endif /* __EEPDB_H__ */
