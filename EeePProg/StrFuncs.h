/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/StrFuncs.h $
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
 *I  ID                   : $Id: StrFuncs.h 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define iswhitespace(x) ((x==' ')||(x=='\t'))
#define iseos(x)        ((x=='\0'))
#define iseol(x)        ((x=='\n')||(x=='\r'))
#define isdecimal(x)    ((x>='0')&&(x<='9'))
#define ishex(x)        (isdecimal(x)||(x>='A')&&(x<='F')||(x>='a')&&(x<='f'))
#define isoctal(x)      ((x>='0')&&(x<='7'))
#define isbinary(x)     ((x=='0')||(x=='1'))

char *
skipWhiteSpaces(
    const char *pcszStr
  );

void 
stripWhiteSpaces(
    char *const pszStr
  );

typedef struct StrDescElement_s{
  const char *pcszSymbol;
  const unsigned int cuiValue;
}StrDescElement_t;

typedef struct StrDesc_s{
  const unsigned int cuiCount;
  const StrDescElement_t *pcDesc;
}StrDesc_t;
#define STR_DESC(name, Elements) \
StrDesc_t name[]={ {ARRAY_SIZE(Elements), Elements}}
 
char * 
szFindStr(
    __IN     const char             *szStr,
    __IN     const StrDesc_t        *pDesc,
    __OUTOPT const StrDescElement_t**pElement
    );

char *
strrstr(
    __IN const char *cszString,
    __IN const char *cszSearchString
    );

typedef struct MacroItem_s{
  const char *cszMacroName;
  const char *cszMacroValue;
}MacroItem_t;

typedef struct MacroList_s{
  MacroItem_t *pMacros;
  size_t       stMacroCnt;
}MacroList_t;

char * 
szFindWord(
    __IN     const char             *szStr,
    __IN     const MacroList_t      *pDesc,
    __OUTOPT const MacroItem_t     **pElement
    );

typedef struct DStrDesc_s{
  char  *szStr;
  size_t stStrLen;
  size_t stAllocLen;
}DStrDesc_t;

EApiStatus_t
ReplaceSubStr(
    __INOUT DStrDesc_t *pStrDesc      ,
    __IN    size_t      stStartPos    ,
    __IN    size_t      stEndPos      ,
    __IN  const char   *cszReplaceStr
  );

EApiStatus_t
FreeStrDesc(
    __INOUT DStrDesc_t *pStrDesc
  );

EApiStatus_t
InitStrDesc(
    __INOUT DStrDesc_t *pStrDesc      ,
    __IN  const char   *cszInitStr
  );

#ifdef __cplusplus
}
#endif
#endif /* __STRFUNCS_H__ */
