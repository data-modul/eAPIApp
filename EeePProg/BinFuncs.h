/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/BinFuncs.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: All rights reserved. This program and the accompanying 
 *I              materials are licensed and made available under the 
 *I              terms and conditions of the BSD License which 
 *I              accompanies this distribution. The full text of the 
 *I              license may be found at 
 *I              http://opensource.org/licenses/bsd-license.php
 *I              
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN '
 *I              AS IS' BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: /KHeader>
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : BinFuncs.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: BinFuncs.h 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */

#ifndef __BINFUNCS_H__
#define __BINFUNCS_H__

#ifdef __cplusplus
extern "C" {
#endif

uint32_t 
u32ChecksumBlock(
    const void *pcvBuffer, 
    size_t      stLength
  );
uint16_t 
u16ChecksumBlock(
    const void *pcvBuffer, 
    size_t      stLength
  );
uint8_t  
u8ChecksumBlock (
    const void *pcvBuffer, 
    size_t      stLength
  );

typedef 
  EApiStatus_t 
  HashFuncinit_t(void**pContext);
typedef 
  EApiStatus_t 
  HashFuncbytes_t(
    __INOUT    void *pContext , /* CRC Context       */
    __IN const void *pcvBuffer, /* Pointer to Buffer */
    __IN size_t      stCount    /* Num bytes to CRC */
  );

typedef 
  EApiStatus_t 
  HashFuncfini_t(
    __IN      void **pContext,  /* CRC Context       */
    __OUT     void  *pvDigest   /* Pointer to Buffer */
  );

typedef 
  EApiStatus_t 
  HashFuncverify_t(
    __IN      void **pContext,  /* CRC Context       */
    __OUT     void  *pvDigest   /* Pointer to Buffer */
  );

typedef struct HashFunc_s{
  HashFuncinit_t  * init        ;
  HashFuncbytes_t * bytes       ;
  HashFuncfini_t  * fini        ;
  HashFuncverify_t* verify      ;
  size_t            stDigestLen ;
}HashFunc_t;

extern HashFunc_t CRC_CCITT;

HashFuncinit_t    u16CRC_CCITT_init   ;
HashFuncbytes_t   u16CRC_CCITT_bytes  ;
HashFuncfini_t    u16CRC_CCITT_fini   ;
HashFuncverify_t  u16CRC_CCITT_verify ;

EApiStatus_t
u16CRC_CCITT (
    __IN const void *pcvBuffer, /* Pointer to Buffer */
    __IN size_t      stCount  , /* Num bytes to CRC */
    __OUT      void *pvDigest   /* Pointer to Buffer */
  );


#define HEXTBL_8BIT_ELEMENT   0x0000
#define HEXTBL_16BIT_ELEMENT  0x1000
#define HEXTBL_32BIT_ELEMENT  0x2000
#define HEXTBL_64BIT_ELEMENT  0x3000
#define HEXTBL_128BIT_ELEMENT 0x4000
#define HEXTBL_WIDTH_MASK     0x7000

#define HEXTBL_COUNT_MASK     0x003F

#define HEXTBL_BIG_ENDIAN     0x0100

#define HEXTBL_7Bit_ASCII     0x0200
#define HEXTBL_8Bit_ASCII     0x0400
#define HEXTBL_ASCII_MASK     0x0600

#define HEXTBL_OFFSET_BAR     0x0800
#define HEXTBL_OFFSET_COUNT   0x0080
#define HEXTBL_OFFSET_TITLE   0x0040

#define HEXTBL_NORMAL_ATTRIB  (HEXTBL_OFFSET_BAR|HEXTBL_BIG_ENDIAN|HEXTBL_7Bit_ASCII|HEXTBL_OFFSET_COUNT|HEXTBL_OFFSET_TITLE)
#define HEXTBL_NORM8_ATTRIB   (HEXTBL_NORMAL_ATTRIB|HEXTBL_8BIT_ELEMENT|16)
#define HEXTBL_NORM16_ATTRIB  (HEXTBL_NORMAL_ATTRIB|HEXTBL_16BIT_ELEMENT|8)
#define HEXTBL_NORM32_ATTRIB  (HEXTBL_NORMAL_ATTRIB|HEXTBL_32BIT_ELEMENT|4)
#define HEXTBL_NORM64_ATTRIB  (HEXTBL_NORMAL_ATTRIB|HEXTBL_64BIT_ELEMENT|2)
TCHAR
cBin2Ascii_c(
    __IN  unsigned  uiValue
  );
int
siBin2Ascii_s(
    __OUT TCHAR           *szString   ,
    __IN  size_t          stBufLength ,
    __IN  const uint8_t  *pcu8Value ,
    __IN  size_t          stVarSize   ,
    __IN  const unsigned  cuiFlags
  );


EApiStatus_t
PrintHexAsciiTableEx(
	__IN    const void *   pcvBuffer	,
	__IN    const size_t   stBufSize	,
	__IN    const void *   pcvBase		,
	__IN    const TCHAR *   pcszDescription,
  __IN    const unsigned cuiFlags
	);

void 
PrintHexAsciiTable(
	__IN    const void *const pcvBuffer	    ,
	__IN    const size_t      cu16BufSize		,
	__IN    const void *const pcvBase		    ,
	__IN    const TCHAR *const pcszDescription
	);

EApiStatus_t 
WriteBinaryFile(
    __IN const char *cszFilename, 
    __IN const void *pcvBuffer   , 
    __IN size_t      stWriteBCnt
  );

EApiStatus_t
ReadBinaryFile(
    __IN  const char *cszFilename, 
    __OUT void      **pvBuffer, 
    __OUT size_t     *pstReadBCnt
  );

EApiStatus_t 
WriteTextFile(
    __IN const char *cszFilename, 
    __IN const void *pcvBuffer   , 
    __IN size_t      stWriteBCnt
  );

EApiStatus_t
ReadTextFile(
    __IN  const char *cszFilename, 
    __OUT void      **pvBuffer, 
    __OUT size_t     *pstReadBCnt
  );


#ifdef __cplusplus
}
#endif
#endif /* __BINFUNCS_H__ */
