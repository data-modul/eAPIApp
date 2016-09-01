/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/BinFuncs.c $
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
 *I  File Name            : BinFuncs.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: BinFuncs.c 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */

#include <EeePApp.h>

/*
 *
 *
 *
 *  Ckecksum
 *
 *
 *
 */
uint32_t 
u32ChecksumBlock(
	const void *pcvBuffer, 
	size_t  	  stLength
	)
{
  uint32_t ChkSum=0;
  while(stLength--){
    ChkSum+=(uint32_t)(*((uint8_t*)pcvBuffer));
    pcvBuffer=((uint8_t*)pcvBuffer)+1;
  }
  return ChkSum;
}
uint16_t 
u16ChecksumBlock(
	const void * pcvBuffer, 
	size_t   	   stLength
	)
{
  return EEEP_LO_UINT16(u32ChecksumBlock(pcvBuffer, stLength));
}
uint8_t  
u8ChecksumBlock (
	const void * pcvBuffer, 
	size_t   	   stLength
	)
{
  return EEEP_LO_UINT8(u32ChecksumBlock(pcvBuffer, stLength));
}

typedef struct CRC_State_s{
  unsigned   CRC;
  size_t     Cnt;
}CRC_State_t;

EApiStatus_t
u16CRC_CCITT_init (
    void**pContext
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  CRC_State_t * pCRC;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      u16CRC_CCITT_init,
      EAPI_STATUS_INVALID_PARAMETER,
      pContext
      );
  *pContext=pCRC=malloc(sizeof(CRC_State_t));
  EAPI_APP_ASSERT_PARAMATER_NULL(
      u16CRC_CCITT_init,
      EAPI_STATUS_ALLOC_ERROR,
      pCRC
      );
  pCRC->CRC=0;
  pCRC->Cnt=0;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

/*
 *
 *
 *
 *  CRC_CCITT
 *
 *
 *
 */
EApiStatus_t
u16CRC_CCITT_bytes (
    __IN       void *pContext , /* CRC Context       */
    __IN const void *pcvBuffer, /* Pointer to Buffer */
    __IN size_t      stCount    /* Num bytes to CRC */
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  const uint8_t *pcu8Buffer     =pcvBuffer; 
  CRC_State_t   *pCRC           =pContext ;
  unsigned       CRC            =pCRC->CRC;
  unsigned       i; 
  EAPI_APP_ASSERT_PARAMATER_NULL(
      u16CRC_CCITT_bytes,
      EAPI_STATUS_INVALID_PARAMETER,
      pcvBuffer
      );


/*   printf("L%04i 0x%04X 0x%04lX\n", __LINE__, CRC&0xFFFF, (unsigned long)pCRC->Cnt); */
/*   PrintHexAsciiTable(pcvBuffer, stCount, pcu8Buffer - pCRC->Cnt, NULL); */
  pCRC->Cnt+=stCount;
  while (stCount --) { 
    CRC^= *pcu8Buffer++ << 8; 
    for (i = 8; i ; i --){ 
      if (CRC & 0x8000){ 
        CRC+=CRC; 
        CRC^=0x1021; 
      }else{ 
        CRC+=CRC; 
      }
    }
  }
  pCRC->CRC=CRC;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
u16CRC_CCITT_fini  (
    __IN      void **pContext,  /* CRC Context       */
    __OUT     void  *pvDigest   /* Pointer to Buffer */
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  CRC_State_t * pCRC=*pContext;
  unsigned      CRC=pCRC->CRC;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      u16CRC_CCITT_fini,
      EAPI_STATUS_INVALID_PARAMETER,
      pvDigest
      );
/*   printf("L%04i 0x%04X 0x%04lX\n", __LINE__, pCRC->CRC&0xFFFF, (unsigned long)pCRC->Cnt); */
  free(*pContext);
  *pContext=NULL;

  EeeP_Set16BitValue_BE(pvDigest, EEEP_LO_UINT16(CRC));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
u16CRC_CCITT_verify  (
    __IN       void**pContext,  /* CRC Context       */
    __OUT      void *pvDigest   /* Pointer to Buffer */
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  uint8_t Digest[2];

  DO(u16CRC_CCITT_fini(pContext, Digest));

  EAPI_APP_RETURN_ERROR_IF(
      u16CRC_CCITT_verify,
      memcmp(Digest, pvDigest, sizeof(Digest)),
      EAPI_STATUS_ERROR,
      "Invalid CRC CCITT"
      );

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
u16CRC_CCITT (
    __IN const void    *pcvBuffer, /* Pointer to Buffer */
    __IN       size_t   stCount  , /* Num bytes to CRC  */
    __OUT      void    *pvDigest   /* Pointer to Buffer */
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  void * pContext;
  DO(u16CRC_CCITT_init(&pContext));
  DO(u16CRC_CCITT_bytes(pContext, pcvBuffer, stCount));
  DO(u16CRC_CCITT_fini(&pContext, pvDigest));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
HashFunc_t CRC_CCITT={
    u16CRC_CCITT_init   ,
    u16CRC_CCITT_bytes  ,
    u16CRC_CCITT_fini   ,
    u16CRC_CCITT_verify ,
    sizeof(uint16_t)
};

/*
 *
 *
 *
 *  PrintHexTable
 *
 *
 *
 */
TCHAR
cBin2Ascii(
    __IN  unsigned int uiValue
  )
{
  if(uiValue>=0x20&&uiValue<=0x7F){
    return (char)(uiValue);
  }else{
    return '.';
  }
}
signed int
siBin2Ascii(
    __OUT TCHAR          *pszString ,
    __IN  size_t          BufLength ,
    __IN  const uint8_t  *pcu8Value ,
    __IN  size_t          VarSize   ,
    __IN  const unsigned  cFlags
  )
{
    signed int StringPos=0;
    size_t Bufpos;
    for(Bufpos=0;Bufpos<VarSize;Bufpos++){
      if(cFlags&HEXTBL_BIG_ENDIAN){
        StringPos+=EApiSprintf(
            pszString+StringPos   ,
            BufLength - StringPos , 
            TEXT("%02X")                , 
            pcu8Value[VarSize - 1 - Bufpos]
          );
      }else{
        StringPos+=EApiSprintf(
            pszString+StringPos   , 
            BufLength - StringPos , 
            TEXT("%02X")                , 
            pcu8Value[Bufpos]
          );
      }
    }
    return StringPos;
}

EApiStatus_t
PrintHexAsciiTableEx(
	const void *   pcvBuffer	,
	const size_t   stBufSize	,
	const void *   pcvBase		,
	const TCHAR *  pcszDescription,
	const unsigned cuiFlags
	)
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
    size_t        stOffset;
    size_t        stOffsetBase;
    const uint8_t *pcu8Mem;
    const uint8_t *pcu8PageEnd;
    size_t        stElementSize;
    size_t        stElementCount;
    size_t        stRowSize;
    TCHAR  szAsciiBufer[100];


    EAPI_APP_ASSERT_PARAMATER_NULL(
        PrintHexAsciiTableEx,
        EAPI_STATUS_INVALID_PARAMETER,
         pcvBuffer
        );
    if(pcvBase==NULL)
      pcvBase=pcvBuffer;

    pcu8Mem=pcvBase;

    stElementSize=1<<((cuiFlags&HEXTBL_WIDTH_MASK)>>12);
    stElementCount=cuiFlags&HEXTBL_COUNT_MASK;
    stRowSize=stElementCount*stElementSize;
    pcu8PageEnd=((const uint8_t *)pcvBuffer)+stBufSize;

    if(pcszDescription!=NULL)
      EAPI_printf(TEXT("\n%s\n"), pcszDescription);
    stOffset=((uint8_t*)pcvBuffer)- pcu8Mem;

    if(cuiFlags&HEXTBL_OFFSET_TITLE)
      EAPI_printf(TEXT("\n\tOFFSET = 0x%08lX, LENGTH = 0x%08lX\n"), (unsigned long)stOffset, (unsigned long)stBufSize);

    if(stBufSize==0) EAPI_APP_EXIT;

    pcu8Mem=((uint8_t*)pcvBuffer) - (stOffset%stRowSize);

    stOffsetBase=pcu8Mem - (uint8_t*)pcvBase;
    while(pcu8Mem<pcu8PageEnd)
    {
      stOffset=pcu8Mem - (uint8_t*)pcvBase;
      if(!((stOffset - stOffsetBase)%(stRowSize*16))){
        /*
         * Print Block Header
         */
        EAPI_printf(TEXT("\n"));
        if(cuiFlags&HEXTBL_OFFSET_BAR)
          EAPI_printf(TEXT("         "));
        if(cuiFlags&HEXTBL_OFFSET_COUNT){
          for(stOffset=0;stOffset<stElementCount;stOffset++){
            EAPI_printf(TEXT("%0*lX "), (int)(2*stElementSize), (unsigned long)stOffset);
          }
          if(cuiFlags&HEXTBL_ASCII_MASK){
            for(stOffset=0;stOffset<(stRowSize);stOffset++){
              EAPI_printf(TEXT("%lX"), (((unsigned long)stOffset)&0xF));
            }
          }
          EAPI_printf(TEXT("\n"));
        }
        stOffset=pcu8Mem - (uint8_t*)pcvBase;
      }
      if(cuiFlags&HEXTBL_OFFSET_BAR)
        EAPI_printf(TEXT("%08lX ") , (unsigned long)stOffset);

        /*
         * Print Binary Hex Data
         */
      for(stOffset=0; stOffset<stRowSize; stOffset+=stElementSize)
      {
        if((pcu8PageEnd>(pcu8Mem+stOffset))&&((stOffset+pcu8Mem)>=((uint8_t *)pcvBuffer))){
          siBin2Ascii(
              szAsciiBufer            , 
              ARRAY_SIZE(szAsciiBufer), 
              pcu8Mem+stOffset        , 
              stElementSize           , 
              cuiFlags
            );
          EAPI_printf(TEXT("%s "), szAsciiBufer);
        }else{
          EAPI_printf(TEXT("%*s "), (int)(2*stElementSize), TEXT(""));
        }
      }
      if(cuiFlags&HEXTBL_ASCII_MASK){
        /*
         * Print ASCII Characters
         */
        for(stOffset=0;stOffset<stRowSize;stOffset++)
        {
          if((pcu8PageEnd>(pcu8Mem+stOffset))&&((stOffset+pcu8Mem)>=((uint8_t *)pcvBuffer))){
            EAPI_printf(TEXT("%c"), cBin2Ascii(pcu8Mem[stOffset]));
          }else{
            EAPI_printf(TEXT(" "));
          }
        }
      }
      pcu8Mem+=stRowSize;
      EAPI_printf(TEXT("\n"));
    }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

void 
PrintHexAsciiTable(
	__IN    const void *const pcvBuffer             ,
	__IN    const size_t      cstBufSize	        ,
	__IN    const void *const pcvBase		,
	__IN    const TCHAR *const pcszDescription
	)
{
  PrintHexAsciiTableEx(
      pcvBuffer           ,
      cstBufSize          ,
      pcvBase             ,
      pcszDescription     ,
      HEXTBL_NORM8_ATTRIB
    );
}



/*
 *
 *
 *
 *  File Access Routines
 *
 *
 *
 */
EApiStatus_t 
LclWriteFile(
    __IN const char *cszFilename, 
    __IN const void *pcvBuffer  , 
    __IN size_t      stWriteBCnt,
    __IN const char *cszWriteType
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  FILE *LclFilePtr;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      LclWriteFile,
      EAPI_STATUS_INVALID_PARAMETER,
      cszFilename
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      LclWriteFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pcvBuffer
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      LclWriteFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stWriteBCnt
    );

  LclFilePtr=fopen(cszFilename, cszWriteType);
  if(LclFilePtr==NULL){
    StatusCode=EAPI_STATUS_WRITE_ERROR;
    siFormattedMessage_SC('L', __FILE__, "LclWriteFile", __LINE__, StatusCode,
        "Opening File %s(%s)\n", cszFilename, cszWriteType);
    EAPI_APP_EXIT;
  }
  EAPI_APP_RETURN_ERROR_IF_S(
      LclWriteFile,
      (stWriteBCnt!=fwrite(pcvBuffer, sizeof(uint8_t), stWriteBCnt, LclFilePtr)),
      EAPI_STATUS_WRITE_ERROR
    );
  fclose(LclFilePtr);
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
LclReadFile(
    __IN  const char *cszFilename, 
    __OUT void      **pvBuffer, 
    __OUT size_t     *pstReadBCnt,
    __IN  const char *cszReadType 
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  FILE *LclFilePtr;
  size_t stFileLen;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      LclReadFile,
      EAPI_STATUS_INVALID_PARAMETER,
      cszFilename
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      LclReadFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pvBuffer
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      LclReadFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pstReadBCnt
    );
  *pstReadBCnt=0;
  LclFilePtr=fopen(cszFilename, cszReadType);
  if(LclFilePtr==NULL){
    StatusCode=EAPI_STATUS_READ_ERROR;
    siFormattedMessage_SC('L', __FILE__, "LclReadFile", __LINE__, StatusCode,
        "Opening File %s(%s)\n", cszFilename, cszReadType);
    EAPI_APP_EXIT;
  }

  fseek(LclFilePtr, 0, SEEK_END);
  stFileLen=ftell(LclFilePtr);
  *pvBuffer=malloc(stFileLen);
  EAPI_APP_ASSERT_PARAMATER_NULL(
      LclReadFile,
      EAPI_STATUS_ALLOC_ERROR,
      *pvBuffer
    );

  rewind(LclFilePtr);
  *pstReadBCnt=stFileLen;
#if 0
  if(stFileLen!=fread(*pvBuffer, sizeof(uint8_t), stFileLen, LclFilePtr)){
    free(*pvBuffer);
    *pvBuffer=NULL;
    EAPI_APP_RETURN_ERROR(
        LclReadFile,
        EAPI_STATUS_READ_ERROR,
        TEXT("(stFileLen!=fread(*pvBuffer, sizeof(uint8_t), stFileLen, LclFilePtr))")
      );
  }
#else
  stFileLen=fread(*pvBuffer, sizeof(uint8_t), stFileLen, LclFilePtr);
#endif
  *pstReadBCnt=stFileLen;
  fclose(LclFilePtr);

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t 
WriteBinaryFile(
    __IN const char *cszFilename, 
    __IN const void *pcvBuffer   , 
    __IN size_t      stWriteBCnt
  )
{
  return LclWriteFile(cszFilename, pcvBuffer, stWriteBCnt, "wb");
}

EApiStatus_t
ReadBinaryFile(
    __IN  const char *cszFilename, 
    __OUT void      **pvBuffer, 
    __OUT size_t     *pstReadBCnt
  )
{
  return LclReadFile(cszFilename, pvBuffer, pstReadBCnt, "rb");
}
EApiStatus_t 
WriteTextFile(
    __IN const char *cszFilename, 
    __IN const void *pcvBuffer   , 
    __IN size_t      stWriteBCnt
  )
{
  return LclWriteFile(cszFilename, pcvBuffer, stWriteBCnt, "w");
}

EApiStatus_t
ReadTextFile(
    __IN  const char *cszFilename, 
    __OUT void      **pvBuffer, 
    __OUT size_t     *pstReadBCnt
  )
{
  return LclReadFile(cszFilename, pvBuffer, pstReadBCnt, "r");
}

/*
 *
 *
 *
 *  Machine Independant Endian Access
 *
 *
 *
 */
/*
 * CPU Independent Multi Byte 
 * Big Endian Memory Access
 */
void
EeeP_Set16BitValue_BE(
    uint8_t *pBuffer,
    uint16_t Value
     )
{
  pBuffer[1]=EEEP_LO_UINT8(Value       );
  pBuffer[0]=EEEP_LO_UINT8(Value>>(8*1));
}
uint16_t
EeeP_Get16BitValue_BE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[1]       ) |
         (pBuffer[0]<<(8*1)) ;
}
void
EeeP_Set32BitValue_BE(
    uint8_t *pBuffer,
    uint32_t Value
     )
{
  pBuffer[3]=EEEP_LO_UINT8(Value       );
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[0]=EEEP_LO_UINT8(Value>>(8*3));
}
uint32_t
EeeP_Get32BitValue_BE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[3]       ) |
         (pBuffer[2]<<(8*1)) |
         (pBuffer[1]<<(8*2)) |
         (pBuffer[0]<<(8*3)) ;
}
void
EeeP_Set64BitValue_BE(
    uint8_t *pBuffer,
    uint64_t Value
     )
{
  pBuffer[7]=EEEP_LO_UINT8(Value       );
  pBuffer[6]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[5]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[4]=EEEP_LO_UINT8(Value>>(8*3));
  pBuffer[3]=EEEP_LO_UINT8(Value>>(8*4));
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*5));
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*6));
  pBuffer[0]=EEEP_LO_UINT8(Value>>(8*7));
}
uint64_t
EeeP_Get64BitValue_BE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[7]       ) |
         (pBuffer[6]<<(8*1)) |
         (pBuffer[5]<<(8*2)) |
         (pBuffer[4]<<(8*3)) |
         ((uint64_t)pBuffer[3]<<(8*4)) |
         ((uint64_t)pBuffer[2]<<(8*5)) |
         ((uint64_t)pBuffer[1]<<(8*6)) |
         ((uint64_t)pBuffer[0]<<(8*7)) ;
}
/*
 * CPU Independent Multi Byte 
 * Little Endian Memory Access
 */
void
EeeP_Set16BitValue_LE(
    uint8_t *pBuffer,
    uint16_t Value
     )
{
  pBuffer[0]=EEEP_LO_UINT8(Value       );
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*1));
}
uint16_t
EeeP_Get16BitValue_LE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[0]       ) |
         (pBuffer[1]<<(8*1)) ;
}
void
EeeP_Set32BitValue_LE(
    uint8_t *pBuffer,
    uint32_t Value
     )
{
  pBuffer[0]=EEEP_LO_UINT8(Value       );
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[3]=EEEP_LO_UINT8(Value>>(8*3));
}
uint32_t
EeeP_Get32BitValue_LE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[0]       ) |
         (pBuffer[1]<<(8*1)) |
         (pBuffer[2]<<(8*2)) |
         (pBuffer[3]<<(8*3)) ;
}
void
EeeP_Set64BitValue_LE(
    uint8_t *pBuffer,
    uint64_t Value
     )
{
  pBuffer[0]=EEEP_LO_UINT8(Value       );
  pBuffer[1]=EEEP_LO_UINT8(Value>>(8*1));
  pBuffer[2]=EEEP_LO_UINT8(Value>>(8*2));
  pBuffer[3]=EEEP_LO_UINT8(Value>>(8*3));
  pBuffer[4]=EEEP_LO_UINT8(Value>>(8*4));
  pBuffer[5]=EEEP_LO_UINT8(Value>>(8*5));
  pBuffer[6]=EEEP_LO_UINT8(Value>>(8*6));
  pBuffer[7]=EEEP_LO_UINT8(Value>>(8*7));
}
uint64_t
EeeP_Get64BitValue_LE(
    const uint8_t *pBuffer
     )
{
  return (pBuffer[0]       ) |
         (pBuffer[1]<<(8*1)) |
         (pBuffer[2]<<(8*2)) |
         (pBuffer[3]<<(8*3)) |
         ((uint64_t)pBuffer[4]<<(8*4)) |
         ((uint64_t)pBuffer[5]<<(8*5)) |
         ((uint64_t)pBuffer[6]<<(8*6)) |
         ((uint64_t)pBuffer[7]<<(8*7)) ;
}





#if TEST_BINFUNC



void
main(void)
{
  uint8_t buffer[0x100]=
    {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_8BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|15);
  PrintHexAsciiTableEx(buffer+3, 0x10, buffer, NULL, HEXTBL_NORM8_ATTRIB);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_8BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|17);

  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_16BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|7);
  PrintHexAsciiTableEx(buffer+3, 0x10, buffer, NULL, HEXTBL_NORM16_ATTRIB);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_16BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|9);

  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_32BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|3);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_NORM32_ATTRIB);
  PrintHexAsciiTableEx(buffer+5, 0x10, buffer, NULL, HEXTBL_32BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|5);

  PrintHexAsciiTableEx(buffer+2, 0x10, buffer, NULL, HEXTBL_64BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|1);
  PrintHexAsciiTableEx(buffer+4, 0x10, buffer, NULL, HEXTBL_NORM64_ATTRIB);
  PrintHexAsciiTableEx(buffer+6, 0x10, buffer, NULL, HEXTBL_64BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|3);

  EAPI_printf(TEXT("Checksum=%08")TEXT(PRIX32)TEXT("\n"), u32ChecksumBlock(buffer, ARRAY_SIZE(buffer)));

  PrintHexAsciiTable(buffer+3, 0x200, buffer, TEXT("Test 7"));
  
  PrintHexAsciiTableEx(buffer+2, 0x200, buffer, NULL, HEXTBL_8BIT_ELEMENT|HEXTBL_NORMAL_ATTRIB|24);
  
  exit(0);
}
#endif

