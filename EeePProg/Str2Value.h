/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/Str2Value.h $
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
 *I  File Name            : StrFuncs.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: Str2Value.h 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __STR2VALUE_H__
#define __STR2VALUE_H__

#ifdef __cplusplus
extern "C" {
#endif

char *
ReturnEnvVar(
    const char *const VarName
    );


unsigned long 
ulConvertStr2NumEx(
    __IN  const char *  cszString, 
    __OUT char **       pszEnd
    );

EApiStatus_t
ExpandEnviromentVariables(
    __INOUT  DStrDesc_t   *pStrDesc
  );

EApiStatus_t
ParseAsciiEqu(
    __IN  const char       *cszString,
    __OUT signed long long *psllValue
  );
EApiStatus_t
ParseAsciiEquEx(
    __IN  const char       *cszString,
    __IN  MacroList_t      *pMacros  ,
    __OUT signed long long *psllValue
  );

EApiStatus_t
ParseAsciiEqu_VA(
    __IN  const char       *cszString,
    __OUT void             *pvalue,
    __IN  signed int        siElementSize
  );

EApiStatus_t
AssignValue_VA(
    __IN  const signed long long csllValue,
    __OUT void             *pvalue,
    __IN  signed int        siElementSize
  );

EApiStatus_t
AssignValue_VAB(
    __IN  const signed long long csllValue,
    __OUT void             *pvalue,
    __IN  signed int        siBitOffset ,
    __IN  signed int        siBitLen    ,
    __IN  signed int        siElementSize
  );

EApiStatus_t
RecoverValue_VA(
    __OUT signed long long *psllValue,
    __IN  void             *pvalue,
    __IN  signed int        siElementSize
  );
  
EApiStatus_t
RecoverValue_VAB(
    __OUT signed long long *psllValue,
    __IN  void             *pValue,
    __IN  signed int        siBitOffset ,
    __IN  signed int        siBitLen    ,
    __IN  signed int        siElementSize
  );
EApiStatus_t
ParseAsciiEquEx_VA(
    __IN  const char       *cszString     ,
    __IN  MacroList_t      *pMacros       ,
    __OUT void             *pvalue        ,
    __IN  signed int        siElementSize
  );


#ifdef __cplusplus
}
#endif
#endif /* __STR2VALUE_H__ */
