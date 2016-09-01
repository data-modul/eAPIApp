/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/StrFuncs.c $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for sEAPI_printf.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : StrFuncs.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: StrFuncs.c 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */

#include <EeePApp.h>

char *
skipWhiteSpaces(
        const char *cszStr
        )
{
  if(cszStr==NULL) return (char*)cszStr;
  while((!iseol(*cszStr))&&iswhitespace(*cszStr))
    cszStr++;
  return (char*)cszStr;
}

void 
stripWhiteSpaces(
        char *const pszStr
        )
{
  char * pszEnd;
  if(pszStr==NULL) return ;
  pszEnd=pszStr+strlen(pszStr) - 1;
  while(iswhitespace(*pszEnd))
    pszEnd--;
  *(pszEnd+1)='\0';
}

char * 
szFindStr(
    __IN     const char             *szStr,
    __IN     const StrDesc_t        *pDesc,
    __OUTOPT const StrDescElement_t**pElement
    )
{
  char * szPos1=NULL, *szPos2;
  size_t stNumStrs=pDesc->cuiCount;
  const StrDescElement_t *pcCurElement=pDesc->pcDesc;
  while(stNumStrs --){
    szPos2=strstr(szStr, pcCurElement->pcszSymbol);
    if((szPos2!=NULL)&&((szPos1==NULL)||(szPos2<szPos1))){
      szPos1=szPos2;
      if(pElement) *pElement=pcCurElement;
    }

    pcCurElement++;
  }
  return szPos1;
}
const char szWordDelimns[]="()\\/!\"$%&=?`´*+~ \t<>;:,.'#^°-\0";

char * 
szFindCharMap(
    __IN     const char             *szStr,
    __IN     char                     CharMap[256/8]  
    )
{

  while(*szStr&&!((CharMap[(*szStr)/8]&(1<<((*szStr)%8))))){
    ++szStr;
  }
  while(*szStr&&((CharMap[(*szStr)/8]&(1<<((*szStr)%8))))){
    ++szStr;
  }
  return *szStr?(char*)szStr:NULL;
}
char * 
szStrCmp(
    __IN     const char             *szStr,
    __IN     const char             *szMatch
    )
{
  while(*szStr&&*szMatch&&*szStr==*szMatch){
    ++szStr;
    ++szMatch;
  }
  if(*szMatch){
    szStr =NULL;
  }
  return (char*)szStr;
}
char * 
szFindWord(
    __IN     const char             *szStr,
    __IN     const MacroList_t      *pDesc,
    __OUTOPT const MacroItem_t     **pElement
    )
{
  const char * szPos1=NULL, *szPos2;
  size_t stNumStrs;
  const MacroItem_t *pcCurElement;
  char CharMap[256/8]={0};
  szPos1=szWordDelimns;
  CharMap[0]=0x01;
  while(*szPos1){
    CharMap[(*szPos1)/8]|=(1<<((*szPos1)%8));
    ++szPos1;
  }

  szPos1=szStr;
  do{
    stNumStrs   =pDesc->stMacroCnt;
    pcCurElement=pDesc->pMacros   ;
    while(stNumStrs --){
      szPos2=szStrCmp(szPos1, pcCurElement->cszMacroName);
      if(szPos2!=NULL&&(CharMap[(*szPos2)/8]&(1<<((*szPos2)%8)))){
        *pElement=pcCurElement;
        return (char*)szPos1;
      }
      pcCurElement++;
    }
  } while((szPos1=szFindCharMap(szPos1+1, CharMap))!=NULL);
  return NULL;
}


char *
strrstr(
    __IN const char *cszString,
    __IN const char *cszSearchString
    )
{
  char *szLclPtr;
  unsigned uiMatchFound=0;
  if(cszString==NULL) return NULL;
  if(cszSearchString==NULL) return NULL;
  szLclPtr=strstr(cszString, cszSearchString);
  while(szLclPtr!=NULL){
    cszString=  szLclPtr+1;
    szLclPtr=strstr(cszString, cszSearchString);
    uiMatchFound++;
  };
  return uiMatchFound?(char *)cszString -1:NULL;
}


#define ALLOC_STEP_SIZE 20
EApiStatus_t
InitStrDesc(
    __INOUT DStrDesc_t *pStrDesc      ,
    __IN  const char   *cszInitStr
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReplaceSubStr,
      EAPI_STATUS_INVALID_PARAMETER,
      pStrDesc
    );

  pStrDesc->stStrLen=cszInitStr?strlen(cszInitStr)+1:1;

  pStrDesc->stAllocLen=(pStrDesc->stStrLen+ALLOC_STEP_SIZE - 1)/ALLOC_STEP_SIZE*ALLOC_STEP_SIZE;
  pStrDesc->szStr=malloc(pStrDesc->stAllocLen);
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReplaceSubStr,
      EAPI_STATUS_ALLOC_ERROR,
      pStrDesc->szStr
    );
  if(cszInitStr){
    memcpy(pStrDesc->szStr, cszInitStr, pStrDesc->stStrLen);
  }else{
    pStrDesc->szStr='\0';
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
FreeStrDesc(
    __INOUT DStrDesc_t *pStrDesc
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReplaceSubStr,
      EAPI_STATUS_INVALID_PARAMETER,
      pStrDesc
    );

  if(pStrDesc->szStr)
    free(pStrDesc->szStr);
  memset(pStrDesc, 0x00, sizeof(pStrDesc));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
ReplaceSubStr(
    __INOUT DStrDesc_t *pStrDesc      ,
    __IN    size_t      stStartPos    ,
    __IN    size_t      stEndPos      ,
    __IN  const char   *cszReplaceStr
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  size_t stRStrLen;
  intptr_t ipNewstrlen;
  intptr_t ipNewSize;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ReplaceSubStr,
      EAPI_STATUS_INVALID_PARAMETER,
      pStrDesc
    );
  stRStrLen=cszReplaceStr?strlen(cszReplaceStr):0;
  ipNewstrlen=pStrDesc->stStrLen+(stStartPos - stEndPos +stRStrLen);
  ipNewSize=(ipNewstrlen+ALLOC_STEP_SIZE - 1)/ALLOC_STEP_SIZE*ALLOC_STEP_SIZE;
  if(ipNewSize>(intptr_t)pStrDesc->stAllocLen){
    pStrDesc->stAllocLen=ipNewSize;
    pStrDesc->szStr=realloc(pStrDesc->szStr, ipNewSize);
    EAPI_APP_ASSERT_PARAMATER_NULL(
        ReplaceSubStr,
        EAPI_STATUS_ALLOC_ERROR,
        pStrDesc->szStr
      );
  }
  if(stStartPos+stRStrLen!=stEndPos){
    memmove(pStrDesc->szStr+stStartPos+stRStrLen, pStrDesc->szStr+stEndPos, pStrDesc->stStrLen - stEndPos);
  }
  memmove(pStrDesc->szStr+stStartPos, cszReplaceStr, stRStrLen);
  pStrDesc->stStrLen=ipNewstrlen;
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

/* char *_strdup( */
/*     __IN const char *pcszStr */
/*     ) */
/* { */
/*   char *pszDup; */
/*   if(pcszStr==NULL) return NULL; */
/*   pszDup=malloc(strlen(pcszStr)+1); */
/*   if(pszDup==NULL) return NULL; */
/*   strcpy(pszDup, pcszStr); */
/*   return pszDup; */
/* } */


#ifdef _MSC_VER 
#       if ( _MSC_VER < MSVC_2005 )

int cdecl 
sprintf_s (
  __IN    char *const             Buffer        , 
  __IN    const size_t            BufferLen     , 
  __IN    const char *const       fmt           , 
  ...
  )
{
  int ReturnValue;
  va_list arg;
  va_start(arg, fmt);
  ReturnValue=_vsnprintf(Buffer, BufferLen, fmt, arg);
  Buffer[BufferLen-1]='\0';
  va_end(arg);
  return ReturnValue;
}
int cdecl 
fopen_s (
  __OUT   FILE **                 instream      , 
  __IN    const char *const       fname         , 
  __IN    const char *const       ReadType
  )
{
  *instream=fopen(fname, ReadType);
  return (*instream==NULL?1:0);
}
char * 
strcpy_s(
  __OUT   char *const             StringDest    , 
  __IN    size_t                  StringBufLen  , 
  __IN    const char *const       StringSource
  )
{
  strncpy(StringDest, StringSource, StringBufLen);
  StringDest[StringBufLen-1]=TEXT('\0');
  return StringDest;
}

#       endif
#endif

#if TEST_BINFUNC



void
main(void)
{
  
  exit(0);
}
#endif

