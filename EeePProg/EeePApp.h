/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/EeePApp.h $
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
 *I  File Name            : EeePApp.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: EeePApp.h 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __EEPAPP_H__
#define __EEPAPP_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <EApiApp.h>

#include <BinFuncs.h>
#include <ArgParse.h>
#include <CfgParse.h>
#include <EeeP.h>
#include <EeePDB.h>
#include <StrFuncs.h>
#include <Str2Value.h>
#include <StrPrint.h>
#include <EeePCfg.h>
#include <EeePArg.h>
  
#ifndef TRACE_BACK
#	define TRACE_BACK 1
#endif
#ifndef __FUNCTION__
#	define __FUNCTION__ ""
#endif

#if TRACE_BACK
#  define DO(x) \
  do{ \
    StatusCode=x;\
    if(!EAPI_TEST_SUCCESS(StatusCode)){ \
        siFormattedMessage_SC('E', __FILE__, "TB "  __FUNCTION__, __LINE__, \
        StatusCode, "%s\n", #x );\
      EAPI_APP_EXIT;\
    }\
  }while(0)
#else
#  define DO(x) \
  do{ \
    StatusCode=x;\
    if(!EAPI_TEST_SUCCESS(StatusCode)) \
      EAPI_APP_EXIT;\
  }while(0)
#endif



/*
 * CPU Independent Multi Byte 
 * Big Endian Memory Access
 */
void
EeeP_Set16BitValue_BE(
    uint8_t        *pBuffer,
    uint16_t        Value
     );
uint16_t
EeeP_Get16BitValue_BE(
    const uint8_t  *pBuffer
     );
void
EeeP_Set32BitValue_BE(
    uint8_t        *pBuffer,
    uint32_t        Value
     );
uint32_t
EeeP_Get32BitValue_BE(
    const uint8_t  *pBuffer
     );
void
EeeP_Set64BitValue_BE(
    uint8_t        *pBuffer,
    uint64_t        Value
     );
uint64_t
EeeP_Get64BitValue_BE(
    const uint8_t  *pBuffer
     );


/*
 * CPU Independent Multi Byte 
 * Little Endian Memory Access
 */
void
EeeP_Set16BitValue_LE(
    uint8_t        *pBuffer,
    uint16_t        Value
     );
uint16_t
EeeP_Get16BitValue_LE(
    const uint8_t  *pBuffer
     );
void
EeeP_Set32BitValue_LE(
    uint8_t        *pBuffer,
    uint32_t        Value
     );
uint32_t
EeeP_Get32BitValue_LE(
    const uint8_t  *pBuffer
     );
void
EeeP_Set64BitValue_LE(
    uint8_t        *pBuffer,
    uint64_t        Value
     );
uint64_t
EeeP_Get64BitValue_LE(
    const uint8_t  *pBuffer
     );



#ifdef __cplusplus
}
#endif
#endif /* __EEPAPP_H__ */
