/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/Str2Value.c $
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
 *I  ID                   : $Id: Str2Value.c 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */

#include <EeePApp.h>
  #include <ctype.h>
  #include <limits.h>

#define EAPI_STATUS_PARSE_ERROR EAPI_STATUS_ERROR
char *
ReturnEnvVar(
    const char *const VarName
    )
{
    char* libvar=NULL;

#if 0
    size_t requiredSize;
    getenv_s( &requiredSize, NULL, 0, VarName);
    if(requiredSize==0)
      goto ErrorExit;

    libvar = (char*) malloc(requiredSize * sizeof(char));
    if (!libvar)
    {
        printf("Failed to allocate memory!\n");
        goto ErrorExit;
    }

    // Get the value of the LIB environment variable.
    getenv_s( &requiredSize, libvar, requiredSize, VarName );
#else
    libvar=getenv(VarName);
    if(libvar==NULL) goto ErrorExit;
    libvar=EAPI_strdup(libvar);
#endif
    // 
ErrorExit:
    return libvar;
}

#if 0
unsigned long 
ulConvertStr2NumCEx(
    const char *  cszString, 
    char **const  pszEnd, 
    const char  * Indent
    )
  {
    unsigned long ReturnVal;
    int siRadix=10;
    cszString=skipWhiteSpaces(cszString);
    if(*cszString=='0'){
      cszString++;
      switch(*cszString){
        case 'x':
          cszString++;
          siRadix=16;
          break;
        default:
          siRadix=8;
          break;
      }
    }
    ReturnVal = strtoul(cszString, pszEnd, siRadix);
/*     VERBOSEL(2) */
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, "ulConvertStr2NumCEx", __LINE__, "",
                  "0x%lX(%ld)  \n", ReturnVal, ReturnVal );
#endif
    return ReturnVal;
  }
unsigned long 
ulConvertStr2NumAsmEx(
    const char *  cszString, 
    char **const  pszEnd, 
    const char  * Indent
    )
  {
    unsigned long ReturnVal=0;
    char *pszEndH;
    char *pszEndB;
    cszString=skipWhiteSpaces(cszString);
    strtoul(cszString, &pszEndH, 16);
    strtoul(cszString, &pszEndB,  2);
    /* 
     *  0ffh
     */
    if(isdigit(*cszString) && (toupper(*pszEndH)=='H') ){
        ReturnVal = strtoul(cszString, pszEnd, 16);
        (*pszEnd)++;
    /* 
     *  011b
     */
    }else if((*cszString >= '0' && *cszString <= '1') && (toupper(*pszEndB)=='B') ){
        ReturnVal = strtoul(cszString, pszEnd, 2);
        (*pszEnd)++;
    /* 
     *  099t
     */
    }else {
        ReturnVal = strtoul(cszString, pszEnd, 10);
        if(toupper(**pszEnd)=='T')++(*pszEnd);
    }
/*     VERBOSEL(2) */
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, "ulConvertStr2NumAsmEx", __LINE__, "",
                  "0x%lX(%ld)  \n", ReturnVal, ReturnVal );
#endif
    return ReturnVal;
  }
#endif
unsigned long 
ulConvertStr2NumEx(
    __IN  const char *  cszString, 
    __OUT char **       pszEnd
    )
  {
    unsigned long ReturnVal=0;
    char *pszEndH;
    char *pszEndB;
    if(pszEnd==NULL)pszEnd=&pszEndB;
    cszString=skipWhiteSpaces(cszString);
    ReturnVal=strtoul(cszString, &pszEndH, 16);
    ReturnVal=strtoul(cszString, &pszEndB,  2);
    /* 
     *  0xff
     */
    if( !memcmp( "0x", cszString , 2) ){
        ReturnVal = strtoul(cszString+2, pszEnd, 16);
    /* 
     *  0ffh
     */
    }else if(isdigit(*cszString) && (toupper(*pszEndH)=='H') ){
        ReturnVal = strtoul(cszString, pszEnd, 16);
        ++(*pszEnd);
    /* 
     *  011b
     */
    }else if(isbinary(*cszString) && (toupper(*pszEndB)=='B') ){
        ReturnVal = strtoul(cszString, pszEnd, 2);
        ++(*pszEnd);
    /* 
     *  099
     */
    }else {
        ReturnVal = strtoul(cszString, pszEnd, 10);
        if(toupper(**pszEnd)=='T')++(*pszEnd);
    }
/*     VERBOSEL(2) */
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, "ulConvertStr2NumEx", __LINE__, "0x0, 00h, 00b, 000",
                  "0x%lX(%ld)  \n", ReturnVal, ReturnVal );
#endif
    return ReturnVal;
  }
enum OperationTypes_e{
  Op_NoOperation            ,
  Op_LogicalEqual           ,
  Op_LogicalNotEqual        ,
  Op_LogicalOr              ,
  Op_LogicalAnd             ,
  Op_LogicalGreaterThan     ,
  Op_LogicalGreaterThanEqual,
  Op_LogicalLessThan        ,
  Op_LogicalLessThanEqual   ,
  Op_LogicalNot             ,
  Op_BitwiseAnd             ,
  Op_BitwiseOr              ,
  Op_BitwiseXor             ,
  Op_BitwiseNot             ,
  Op_Multiply               ,
  Op_Modulus                ,
  Op_Divide                 ,
  Op_Add                    ,
  Op_Subtract               ,
  Op_Negate                 ,
  Op_LeftShift              ,
  Op_RightShift
};
EApiStatus_t
DoOperation(
    __IN  unsigned int     siOperation,
    __OUT signed long long *psllValue ,
    __IN  signed long long sllValue
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  switch(siOperation){
    case Op_NoOperation:
      break;
    case Op_LogicalOr:
      *psllValue=*psllValue||sllValue;
      break;
    case Op_LogicalAnd:
      *psllValue=*psllValue&&sllValue;
      break;
    case Op_LogicalNot:
      *psllValue=!sllValue;
      break;
    case Op_LogicalGreaterThan:
      *psllValue=*psllValue>sllValue;
      break;
    case Op_LogicalGreaterThanEqual:
      *psllValue=*psllValue>=sllValue;
      break;
    case Op_LogicalLessThan:
      *psllValue=*psllValue<sllValue;
      break;
    case Op_LogicalLessThanEqual:
      *psllValue=*psllValue<=sllValue;
      break;
    case Op_BitwiseAnd:
      *psllValue&=sllValue;
      break;
    case Op_BitwiseXor:
      *psllValue^=sllValue;
      break;
    case Op_BitwiseOr:
      *psllValue|=sllValue;
      break;
    case Op_Negate:
      *psllValue=-sllValue;
      break;
    case Op_BitwiseNot:
      *psllValue=~sllValue;
      break;
    case Op_Multiply:
      *psllValue*=sllValue;
      break;
    case Op_Modulus:
      *psllValue%=sllValue;
      break;
    case Op_Divide:
      *psllValue/=sllValue;
      break;
    case Op_Add:
      *psllValue+=sllValue;
      break;
    case Op_Subtract:
      *psllValue-=sllValue;
      break;
    case Op_LeftShift:
      *psllValue<<=sllValue;
      break;
    case Op_RightShift:
      *psllValue>>=sllValue;
      break;
    case Op_LogicalNotEqual:
      *psllValue=*psllValue!=sllValue;
      break;
    case Op_LogicalEqual:
      *psllValue=*psllValue==sllValue;
      break;
    default:
      EAPI_APP_RETURN_ERROR(
          DoOperation, 
          EAPI_STATUS_PARSE_ERROR, 
          "Invalid Operation"
        );
      break;
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
typedef struct BlockParser_s{
    const char       *szDesc;
    EApiStatus_t    (*pHandler)(struct BlockParser_s*, char* ,         signed long long*);
    EApiStatus_t    (*pParser )(void*, char**, char**, signed int      *);
    void             *pContext;
    const char       *szMsg2;
}BlockParser_t;

EApiStatus_t
ParserWrapper(
    __IN  BlockParser_t    *pContext,
    __IN  char             *szString,
    __IN  char             *szStringEnd,
    __OUT signed long long *psllValue

  )
{
  char SaveChar=0;
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  if(szStringEnd!=NULL){
    SaveChar=*szStringEnd;
    *szStringEnd='\0';
  }
  StatusCode=pContext->pHandler(pContext+1, szString, psllValue);
  if(szStringEnd!=NULL){
    *szStringEnd=SaveChar;
  }
  return StatusCode;
}
EApiStatus_t
ParseOpcodeTokensAscii(
    __IN  void       *pContext ,
    __IN  char      **pszString,
    __IN  char      **pszOpcode,
    __OUT signed int *psiOperationType
  )
{
  const StrDescElement_t*pElement ;
  char *szPos=*pszString;
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  szPos=szFindStr(szPos, pContext, &pElement);
  *pszOpcode=szPos;
  if(szPos==NULL){
    *pszString=NULL;
    *psiOperationType=Op_NoOperation;
    return StatusCode;
  }
  
  *psiOperationType=pElement->cuiValue;
  *pszString=szPos+strlen(pElement->pcszSymbol);
  return  StatusCode;
}

EApiStatus_t
ParseAsciiEqu_13(
    __IN  struct BlockParser_s *pContext,
    __IN  char             *szString,
    __OUT signed long long *psllValue

  )
{
    char *pszEnd;
    signed long long CurValue;
    EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
    szString=skipWhiteSpaces(szString);


    switch(*szString){
      case '!':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, &CurValue));
        DO(DoOperation(Op_LogicalNot, psllValue, CurValue));
        break;
      case '~':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, &CurValue));
        DO(DoOperation(Op_BitwiseNot, psllValue, CurValue));
        break;
      case '-':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, &CurValue));
        DO(DoOperation(Op_Negate, psllValue, CurValue));
        break;
      case '+':
#ifdef TEST_EQUPARSER
        siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_13", __LINE__, "!,~,-,+",
                "%s\n", szString );
#endif
        DO(ParseAsciiEqu_13(pContext, szString+1, psllValue));
        break;
      default:
        *psllValue=ulConvertStr2NumEx(szString, &pszEnd);
        pszEnd=skipWhiteSpaces(pszEnd);
        if(*pszEnd!='\0'){
          siFormattedMessage_SC('E', __FILE__, "ParseAsciiEqu_13", __LINE__, EAPI_STATUS_PARSE_ERROR,
              "%s\n",  szString
            );
          siFormattedMessage_SC('E', __FILE__, "ParseAsciiEqu_13", __LINE__, EAPI_STATUS_PARSE_ERROR,
              "%*s%s\n", ((signed int)(pszEnd - szString)), "", "^ Here"
            );
          return EAPI_STATUS_PARSE_ERROR;
        }
        break;
    }
EAPI_APP_ASSERT_EXIT
    return StatusCode;
}




EApiStatus_t
ParseAsciiEqu_cmn(
    __IN  BlockParser_t    *pContext,
    __IN  char             *szString,
    __OUT signed long long *psllValue
  )
{
  char *szOpt,*szPos3,*szPos1,*szPos2=szString;
  signed OperationType=Op_NoOperation, LOperationType;
  signed long long CurValue;
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;

  szOpt=NULL;

  if(pContext->pParser){
    DO(pContext->pParser(pContext->pContext, &szPos2, &szOpt, &OperationType));
  }
  if(szOpt!=NULL){
#ifdef TEST_EQUPARSER
      siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2,
              "%s\n", szString);
#endif
    DO(ParserWrapper(pContext, szString, szOpt, psllValue));

    do{
      LOperationType=OperationType;
      szPos1=skipWhiteSpaces(szPos2);
      do{
        szPos3=skipWhiteSpaces(szPos2);
        DO(pContext->pParser(pContext->pContext, &szPos2, &szOpt, &OperationType));
      }while(szPos3==szOpt);

      DO(ParserWrapper(pContext, szPos1, szOpt, &CurValue));

      DO(DoOperation(LOperationType, psllValue, CurValue));
    }while(szOpt!=NULL);
  }else{
    StatusCode=pContext->pHandler(pContext+1, szString, psllValue);
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

const StrDescElement_t cMultDiv[]={
  {"*",  Op_Multiply  },
  {"%",  Op_Modulus   },
  {"/",  Op_Divide    },
};
STR_DESC(cMultDiv_desc, cMultDiv);

const StrDescElement_t cAddSub []={
  {"+",  Op_Add       },
  {"-",  Op_Subtract  },
};
STR_DESC(cAddSub_desc, cAddSub);

const StrDescElement_t cBitShift[]={
  {"<<",  Op_LeftShift },
  {">>",  Op_RightShift},
};
STR_DESC(cBitShift_desc, cBitShift);

EApiStatus_t
ParseAscii_8(
    __IN  void       *pContext ,
    __IN  char      **pszString,
    __IN  char      **pszOpcode,
    __OUT signed int *psiOperationType
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  char *szGTLT=*pszString;
  char GTLT[]      = "<>";
  pContext=pContext;
  while((szGTLT=strpbrk(szGTLT, GTLT))!=NULL){
    if((szGTLT[1]=='<')||(szGTLT[1]=='>')){
      szGTLT+=2;
      continue;
    }
    break;
  }

  *pszOpcode=szGTLT;
  if(szGTLT==NULL){
    *pszString=NULL;
    *psiOperationType=Op_NoOperation;
    return StatusCode;
  }
  switch(*szGTLT++) {
    case '<':
      if(*szGTLT=='='){
        *psiOperationType=Op_LogicalLessThanEqual;
        szGTLT++;
      }else{
        *psiOperationType=Op_LogicalLessThan;
      }
      break;
    case '>':
      if(*szGTLT=='='){
        *psiOperationType=Op_LogicalGreaterThanEqual;
        szGTLT++;
      }else{
        *psiOperationType=Op_LogicalGreaterThan;
      }
      break;
  }

  *pszString=szGTLT;
  return StatusCode ;
}

const StrDescElement_t cCompare[]={
  {"==",  Op_LogicalEqual   },
  {"!=",  Op_LogicalNotEqual},
};
STR_DESC(cCompare_desc, cCompare);

const StrDescElement_t cBitwiseAnd[]={
  {"&",  Op_BitwiseAnd   },
};
STR_DESC(cBitwiseAnd_desc, cBitwiseAnd);

const StrDescElement_t cBitwiseXor[]={
  {"^",  Op_BitwiseXor   },
};
STR_DESC(cBitwiseXor_desc, cBitwiseXor);

const StrDescElement_t cBitwiseOr[]={
  {"|",  Op_BitwiseOr   },
};
STR_DESC(cBitwiseOr_desc, cBitwiseOr);

const StrDescElement_t cLogicalAnd[]={
  {"&&",  Op_LogicalAnd   },
};
STR_DESC(cLogicalAnd_desc, cLogicalAnd);

const StrDescElement_t cLogicalOr[]={
  {"||",  Op_LogicalOr    },
};
STR_DESC(cLogicalOr_desc, cLogicalOr);
/*
 * cond?vara:varb
 */
EApiStatus_t
ParseAsciiEqu_2(
    __IN  BlockParser_t    *pContext,
    __IN  char             *szString,
    __OUT signed long long *psllValue
  )
{
  char *szCondition;
  char *szSelBracket;
  signed long long Condition=0;
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  szCondition=strchr(szString, '?');
  if(szCondition!=NULL){
#ifdef TEST_EQUPARSER
    siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2,
              "%s\n", szString);
#endif
    DO(ParserWrapper(pContext, szString, szCondition , &Condition));
    szSelBracket=strchr(szCondition, ':');
    if(szSelBracket==NULL) {
      EAPI_APP_RETURN_ERROR( ParseAsciiEqu_2, EAPI_STATUS_PARSE_ERROR, "Missing Right ':'");
    }

/*     siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2, */
/*             "%s\n", szCondition+1); */
/*     siFormattedMessage_M2('D', __FILE__, pContext->szDesc, __LINE__, pContext->szMsg2, */
/*             "%s\n", szSelBracket+1); */
    if(Condition){
      DO(ParserWrapper(pContext, szCondition+1 , szSelBracket, psllValue));
    }else{
      DO(ParserWrapper(pContext - 1, szSelBracket+1, NULL, psllValue));
    }
  } else{
    StatusCode=pContext->pHandler(pContext+1, szString, psllValue);
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

BlockParser_t cAS[]={
{"ParseAsciiEqu_1" , ParseAsciiEqu_2  , NULL                  , NULL            , "()"        },
{"ParseAsciiEqu_2" , ParseAsciiEqu_cmn, NULL                  , NULL            , "cond?Vara:Varb"},
{"ParseAsciiEqu_3" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cLogicalOr_desc , "||"        },
{"ParseAsciiEqu_4" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cLogicalAnd_desc, "&&"        },
{"ParseAsciiEqu_5" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitwiseOr_desc , "|"         },
{"ParseAsciiEqu_6" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitwiseXor_desc, "^"         },
{"ParseAsciiEqu_7" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitwiseAnd_desc, "&"         },
{"ParseAsciiEqu_8" , ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cCompare_desc   , "==,!="     },
{"ParseAsciiEqu_9" , ParseAsciiEqu_cmn, ParseAscii_8          , NULL            , ">,>=,<,<=" },
{"ParseAsciiEqu_10", ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cBitShift_desc  , "<<,>>"     },
{"ParseAsciiEqu_11", ParseAsciiEqu_cmn, ParseOpcodeTokensAscii, cAddSub_desc    , "+,-"       },
{"ParseAsciiEqu_12", ParseAsciiEqu_13 , ParseOpcodeTokensAscii, cMultDiv_desc   , "*,/,%"     },
};
/*
 * ()
 */
EApiStatus_t
ParseAsciiEqu_1(
    __INOUT DStrDesc_t *pStrDesc   ,
    __OUT signed long long *psllValue
  )
{
  char *szStartBracket;
  char *szEndBracket;
  size_t stSubLen;
  signed long long CurValue;
  char szValue[sizeof(unsigned long long)*2];
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  *psllValue=0;
  while((szStartBracket=strrchr(pStrDesc->szStr, '('))!=NULL){
#ifdef TEST_EQUPARSER
  siFormattedMessage_M2('D', __FILE__, "ParseAsciiEqu_1", __LINE__, "()",
              "%s\n", szString );
#endif
    szEndBracket=strchr(szStartBracket, ')');
    if(szEndBracket!=NULL)
    {
      *szEndBracket='\0';
      DO(ParseAsciiEqu_cmn(cAS, szStartBracket+1, &CurValue));
      stSubLen=szEndBracket - szStartBracket;
      EApiSprintfA( szValue, ARRAY_SIZE(szValue), "%lld", CurValue);
      DO(ReplaceSubStr(pStrDesc, szStartBracket - pStrDesc->szStr, szEndBracket+1 - pStrDesc->szStr,  szValue));
    }
    else
    {
      EAPI_APP_RETURN_ERROR(
          ParseAsciiEqu_1, 
          EAPI_STATUS_PARSE_ERROR, 
          "Missing Right ')'"
        );
    }
  }
  if(EAPI_TEST_SUCCESS(StatusCode))
    StatusCode=ParseAsciiEqu_cmn(cAS, pStrDesc->szStr, psllValue);
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


const char cszEnvStartMarker[]="$(";
const char cszEnvEndMarker[]=")" ;
EApiStatus_t
ExpandEnviromentVariables(
    __INOUT  DStrDesc_t   *pStrDesc
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  char *szVarPosS,*szVarPosE, *szVarValue=NULL;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ExpandEnviromentVariables, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pStrDesc
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ExpandEnviromentVariables, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pStrDesc->szStr
    );
  while((szVarPosS=strrstr(pStrDesc->szStr, cszEnvStartMarker))!=NULL){
    /*
     * So we found the last occurance of our start marker.
     */
#ifdef TEST_EQUPARSER
    siFormattedMessage_M2('D', __FILE__, "ExpandEnviromentVariables", __LINE__, "",
              "%s\n", pStrDesc->szStr );
#endif
    szVarPosE=strstr(szVarPosS, cszEnvEndMarker);
    if(szVarPosE==NULL){
      siFormattedMessage_SC('E', __FILE__, "ExpandEnviromentVariables", __LINE__, EAPI_STATUS_PARSE_ERROR,
          "Missing Right Bracket '%s'",  cszEnvEndMarker
          );
      EAPI_APP_RETURN_ERROR(
          ExpandEnviromentVariables,
          EAPI_STATUS_PARSE_ERROR,
          ""
          );
    }
    *szVarPosE='\0';
    szVarValue=ReturnEnvVar(szVarPosS+strlen(cszEnvStartMarker));
    DO(ReplaceSubStr(pStrDesc, szVarPosS - pStrDesc->szStr, szVarPosE - pStrDesc->szStr,  szVarValue));
    if(szVarValue){
      free(szVarValue);
      szVarValue=NULL;
    }
#ifdef TEST_EQUPARSER
/*    siFormattedMessage_M2('D', __FILE__, "ExpandEnviromentVariables", __LINE__, "", */
/*               "[%i][%i][%i]%s, %s, %s\n", stStrLen, ValLen, stStrLen+ValLen - (szVarPosE - szVarPosS + 1), pStrDesc->szStr, szVarPosS, szVarPosS+strlen(cszEnvStartMarker) ); */
#endif
  }


#ifdef TEST_EQUPARSER
/*   siFormattedMessage_M2('D', __FILE__, "ExpandEnviromentVariables", __LINE__, "", */
/*               "[%i][%i][%i]%s, %s, %s\n", StrLen, ValLen, StrLen+ValLen - (szVarPosE - szVarPosS + 1), szLclBuf, szVarPosS, szVarPosS+strlen(cszEnvStartMarker) ); */
#endif
  EAPI_APP_EXIT;

EAPI_APP_ASSERT_EXIT
  if(szVarValue!=NULL)
    free(szVarValue);


  return StatusCode;
}



EApiStatus_t
ExpandMacros(
    __IN  DStrDesc_t   *pStrDesc,
    __IN  MacroList_t  *pMacros
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  char *szVarPosS;
  size_t stMacroLen;
  const MacroItem_t *pCurMacro;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ExpandMacros, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pStrDesc
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ExpandMacros, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pStrDesc->szStr
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ExpandMacros, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pMacros
    );
  while((szVarPosS=szFindWord(pStrDesc->szStr, pMacros, &pCurMacro))!=NULL){
    /*
    * So we found the first occurance of our MACRO.
    */
#ifdef TEST_EQUPARSER
    siFormattedMessage_M2('D', __FILE__, "ExpandMacros", __LINE__, "",
              "%s\n", pStrDesc->szStr );
#endif
    stMacroLen=strlen(pCurMacro->cszMacroName);

    DO(ReplaceSubStr(pStrDesc, szVarPosS - pStrDesc->szStr, szVarPosS - pStrDesc->szStr + stMacroLen,  pCurMacro->cszMacroValue));
  }


#ifdef TEST_EQUPARSER
/*   siFormattedMessage_M2('D', __FILE__, "ExpandEnviromentVariables", __LINE__, "", */
/*               "%s\n", szLclBuf ); */
#endif
  EAPI_APP_EXIT;

EAPI_APP_ASSERT_EXIT


  return StatusCode;
}









EApiStatus_t
ParseAsciiEquEx(
    __IN  const char       *cszString,
    __IN  MacroList_t      *pMacros  ,
    __OUT signed long long *psllValue
  )
{
  EApiStatus_t StatusCode;
  DStrDesc_t lclStrDesc={NULL, 0, 0};
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu, 
      EAPI_STATUS_INVALID_PARAMETER, 
      cszString
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu, 
      EAPI_STATUS_INVALID_PARAMETER, 
      psllValue
    );
  *psllValue=0;
  DO(InitStrDesc(&lclStrDesc, cszString));
#if 1
  DO(ExpandEnviromentVariables(&lclStrDesc));
  if(pMacros){
    DO(ExpandMacros(&lclStrDesc, pMacros));
  }
#endif
#ifdef TEST_EQUPARSER
  siFormattedMessage_M2('D', __FILE__, "ParseAsciiEquEx", __LINE__, "",
              "%s\n", lclStrDesc.szStr );
#endif
  DO(ParseAsciiEqu_1(&lclStrDesc, psllValue));
EAPI_APP_ASSERT_EXIT
  FreeStrDesc(&lclStrDesc);
  return StatusCode;
}
EApiStatus_t
ParseAsciiEqu(
    __IN  const char       *cszString,
    __OUT signed long long *psllValue
  )
{
  return ParseAsciiEquEx(cszString, NULL, psllValue);
}
EApiStatus_t
AssignValue_VA(
    __IN  const signed long long csllValue,
    __OUT void             *pvalue,
    __IN  signed int        siElementSize
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pvalue
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      siElementSize
    );
  memset(pvalue, 0x00, siElementSize);
  if(siElementSize==sizeof(unsigned long long)){
      *(unsigned long long*)pvalue=(unsigned long long)csllValue;

  }else if(siElementSize==sizeof(unsigned long)){
      if((csllValue>=0 && (((unsigned long long)  csllValue)>ULONG_MAX))||
         (csllValue< 0 && (((unsigned long long)- csllValue)>LONG_MAX ))
	)
      {
        EAPI_APP_RETURN_ERROR(
            ParseAsciiEqu_VA,
            EAPI_STATUS_MORE_DATA,
            "Value Too Large for unsigned long"
          );
      }
      *(unsigned long*)pvalue=(unsigned long)csllValue;
  }else if(siElementSize==sizeof(unsigned int)){
      if((csllValue>=0 && (((unsigned long long) csllValue)>UINT_MAX))||
         (csllValue< 0 && (((unsigned long long)-csllValue)>INT_MAX ))
         )
      {
        EAPI_APP_RETURN_ERROR(
            ParseAsciiEqu_VA,
            EAPI_STATUS_MORE_DATA,
            "Value Too Large for unsigned int"
          );
      }
       *(unsigned int*)pvalue=(unsigned int)csllValue;
   }else if(siElementSize==sizeof(unsigned short)){
      if((csllValue>=0 && (((unsigned long long) csllValue)>USHRT_MAX))||
         (csllValue< 0 && (((unsigned long long)-csllValue)>SHRT_MAX ))
         )
      {
        EAPI_APP_RETURN_ERROR(
            ParseAsciiEqu_VA,
            EAPI_STATUS_MORE_DATA,
            "Value Too Large for unsigned short"
          );
      }
      *(unsigned short*)pvalue=(unsigned short)csllValue;
  }else if(siElementSize==sizeof(unsigned char)){
      if((csllValue>=0 && (((unsigned long long) csllValue)>UCHAR_MAX))||
         (csllValue< 0 && (((unsigned long long)-csllValue)>CHAR_MAX ))
         )
      {
        EAPI_APP_RETURN_ERROR(
            ParseAsciiEqu_VA,
            EAPI_STATUS_MORE_DATA,
            "Value Too Large for unsigned char"
          );
      }
      *(unsigned char*)pvalue=(unsigned char)csllValue;
  }else{
      EAPI_APP_RETURN_ERROR(
          ParseAsciiEqu_VA,
          EAPI_STATUS_ERROR,
          "Unsupported Variable Lenght"
        );
  }

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
AssignValue_VAB(
    __IN  const signed long long csllValue,
    __OUT void             *pValue,
    __IN  signed int        siBitOffset ,
    __IN  signed int        siBitLen    ,
    __IN  signed int        siElementSize
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned long *pulValue=EAPI_CREATE_PTR(pValue, siBitOffset/8, unsigned long*);
  siBitOffset%=8;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      AssignValue_VAB, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pValue
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      AssignValue_VAB, 
      EAPI_STATUS_INVALID_PARAMETER, 
      siElementSize
    );
  if(siBitOffset||siBitLen!=siElementSize*8){
    unsigned long ulMask=(((unsigned long )1<<siBitLen)-1);
    EAPI_APP_RETURN_ERROR_IF_S(
        AssignValue_VAB, 
        sizeof(unsigned long)*8<(unsigned)(siBitOffset+siBitLen),
        EAPI_STATUS_INVALID_PARAMETER
      );
    EAPI_APP_RETURN_ERROR_IF_S(
        AssignValue_VAB, 
        (unsigned long long)csllValue>ulMask,
        EAPI_STATUS_MORE_DATA
      );
    *pulValue&=~(ulMask<<siBitOffset);
    *pulValue|=((csllValue&ulMask)<<siBitOffset) ;
  }else{
    DO(AssignValue_VA(csllValue, pulValue, siBitLen/8));
  }

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
RecoverValue_VA(
    __OUT signed long long *psllValue,
    __IN  void             *pvalue,
    __IN  signed int        siElementSize
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      psllValue
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pvalue
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      siElementSize
    );
  if(siElementSize==sizeof(unsigned long long)){
      *(unsigned long long*)psllValue=*(unsigned long long*)pvalue;
  }else if(siElementSize==sizeof(unsigned long)){
      *(unsigned long long*)psllValue=*(unsigned long *)pvalue;
  }else if(siElementSize==sizeof(unsigned int)){
      *(unsigned long long*)psllValue=*(unsigned int*)pvalue;
   }else if(siElementSize==sizeof(unsigned short)){
      *(unsigned long long*)psllValue=*(unsigned short*)pvalue;
  }else if(siElementSize==sizeof(unsigned char)){
      *(unsigned long long*)psllValue=*(unsigned char*)pvalue;
  }else{
      EAPI_APP_RETURN_ERROR(
          ParseAsciiEqu_VA,
          EAPI_STATUS_ERROR,
          "Unsupported Variable Lenght"
        );
  }

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
RecoverValue_VAB(
    __OUT signed long long *psllValue,
    __IN  void             *pValue,
    __IN  signed int        siBitOffset ,
    __IN  signed int        siBitLen    ,
    __IN  signed int        siElementSize
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned long *pulValue=EAPI_CREATE_PTR(pValue, siBitOffset/8, unsigned long*);
  siBitOffset%=8;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      RecoverValue_VAB, 
      EAPI_STATUS_INVALID_PARAMETER, 
      psllValue
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      RecoverValue_VAB, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pValue
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      RecoverValue_VAB, 
      EAPI_STATUS_INVALID_PARAMETER, 
      siElementSize
    );
  if(siBitOffset||siBitLen%8){
    unsigned long ulMask=(((unsigned long)1<<siBitLen)-1);
    EAPI_APP_RETURN_ERROR_IF_S(
        RecoverValue_VAB, 
        sizeof(unsigned long)*8<(unsigned)(siBitOffset+siBitLen),
        EAPI_STATUS_INVALID_PARAMETER
      );
    *(unsigned long long*)psllValue=(*pulValue>>siBitOffset)&ulMask;
  }else{
    DO(RecoverValue_VA(psllValue, pulValue, siBitLen/8));
  }

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


EApiStatus_t
ParseAsciiEqu_VA(
    __IN  const char       *cszString,
    __OUT void             *pvalue,
    __IN  signed int        siElementSize
  )
{
  signed long long sllValue;
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      cszString
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEqu_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pvalue
    );
  memset(pvalue, 0x00, siElementSize);
  DO(ParseAsciiEquEx(cszString, NULL, &sllValue));
  DO(AssignValue_VA(sllValue, pvalue, siElementSize));

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
ParseAsciiEquEx_VA(
    __IN  const char       *cszString     ,
    __IN  MacroList_t      *pMacros       ,
    __OUT void             *pvalue        ,
    __IN  signed int        siElementSize
  )
{
  signed long long sllValue;
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;

  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEquEx_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      cszString
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      ParseAsciiEquEx_VA, 
      EAPI_STATUS_INVALID_PARAMETER, 
      pvalue
    );
  memset(pvalue, 0x00, siElementSize);
  DO(ParseAsciiEquEx(cszString, pMacros, &sllValue));
  DO(AssignValue_VA(sllValue, pvalue, siElementSize));

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

#ifdef TEST_EQUPARSER
typedef struct TestCase_s{
  void *const      pValueStore ;
  signed int       pStoreSize  ;
  signed int       pElementSize;
  const char      *cszEquation ;
  signed long long sllValue    ;
}TestCase_t;
#if 0
#define __TEST_CASE(Store, Equ) {Store, sizeof(Store), sizeof(Store[0]), #Equ, (signed long long)Equ},
#define _TEST_CASE(Store, Equ) __TEST_CASE(Store, Equ)
#define TEST_CASE(Store, Equ) _TEST_CASE(Store, Equ)
#else
#define TEST_CASE(Store, Equ) {Store, sizeof(Store), sizeof(Store[0]), #Equ, (signed long long)Equ},
#endif
uint8_t  Val_u8[1];
uint16_t Val_u16[1];
uint32_t Val_u32[1];
uint64_t Val_u64[1];

TestCase_t TestCasesEquates[]={
  TEST_CASE(Val_u64, 1 + 1)
  TEST_CASE(Val_u64, 1 + 1 + 3 + 4 - 3)
  TEST_CASE(Val_u64, 0x00123)
  TEST_CASE(Val_u64, 123)
  TEST_CASE(Val_u64, 1 - 1)
  TEST_CASE(Val_u64, 2*2+1)
  TEST_CASE(Val_u64, 456%45+3*23/4+1)
  TEST_CASE(Val_u64, ((2*2)+1))
  TEST_CASE(Val_u64, (2*((2)+(1))))
  TEST_CASE(Val_u64, (2*((2)+(1)))==0)
  TEST_CASE(Val_u64, (2*((2)+(1)))!=0)
  TEST_CASE(Val_u64, (2*((2)+(1)))>=0)
  TEST_CASE(Val_u64, (2*((2)+(1)))<=0)
  TEST_CASE(Val_u64, (2*((2)+(1)))&&0)
  TEST_CASE(Val_u64, (2*((2)+(1)))||0)
  TEST_CASE(Val_u64, 0x505050|   0x0A0A0A0|0x0000000)
  TEST_CASE(Val_u64, 0x505050&   0x0A0A0A0|0x0000000)
  TEST_CASE(Val_u64, 0x505050&   0x0A0A0A0&0x0000000)
  TEST_CASE(Val_u64, 0x505050&  ~0x0A0A0A0|0x0000000)
  TEST_CASE(Val_u64, 0x505050&~~~0x0A0A0A0|0x0000000)
  TEST_CASE(Val_u64, 0x505050& ~~0x0A0A0A0|0x0000000)
  TEST_CASE(Val_u64, 0x505050^   0x0A0A0A0|0x0000000)
  TEST_CASE(Val_u64, 0x505050^   0x0A0A0A0^0x0000000)
  TEST_CASE(Val_u64, 1<<5)
  TEST_CASE(Val_u64, 5>>1)
  TEST_CASE(Val_u64, 5>>1>=0)
  TEST_CASE(Val_u64, 5>>1>=5>>2)
  TEST_CASE(Val_u64, 5>>1<=5>>2)
  TEST_CASE(Val_u64, -1)
  TEST_CASE(Val_u64, !0)
  TEST_CASE(Val_u64, ~0)
  TEST_CASE(Val_u64, 1?1:0)
  TEST_CASE(Val_u64, (1?1:0)?0:1)
  TEST_CASE(Val_u64, 1?0:1?2:3)
  TEST_CASE(Val_u64, 0?0:1?2:3)
  TEST_CASE(Val_u64, 0?1:0?2:3)
  TEST_CASE(Val_u64, 5- -1)
  TEST_CASE(Val_u64, 5- - -1)
  TEST_CASE(Val_u64, 5- - - -1)
  TEST_CASE(Val_u64, 5- + -1)
  TEST_CASE(Val_u64, 5- - + -1)
  TEST_CASE(Val_u64, 5-(-1))
  TEST_CASE(Val_u32, 0xFFFFFFFF  )
  TEST_CASE(Val_u16, 0xFFFF  )
  TEST_CASE(Val_u8 , 0xFF   )
};
TestCase_t TestCasesEnv[]={
  {Val_u8, sizeof(Val_u8), sizeof(Val_u8[0]), "$(NUMBER_OF_PROCESSORS)>=1", 1},
  {Val_u8, sizeof(Val_u8), sizeof(Val_u8[0]), "0x$(PROCESSOR_REVISION)", 0xd08},
  {Val_u8, sizeof(Val_u8), sizeof(Val_u8[0]), "$(PROCESSOR_REVISION)", 0},
};
static MacroItem_t SizeMacros[]={
  {"BYTES", ""          },
  {"KB"   , "*(1024 BYTES)"},
  {"MB"   , "*(1024 KB)"},
  {"GB"   , "*(1024 MB)"},
};
static MacroList_t SizeMacroDesc={SizeMacros, ARRAY_SIZE(SizeMacros)};
#define BYTES
#define KB *(1024 BYTES)
#define MB *(1024 KB)
#define GB *(1024 MB)
#define GB *(1024 MB)
TestCase_t TestCasesMACRO[]={
  TEST_CASE(Val_u64, 1 + 1 KB)
  TEST_CASE(Val_u64, 1 + 1 + 3 + 4 - 3 MB)
  TEST_CASE(Val_u64, 0x00123 MB)
  TEST_CASE(Val_u64, 1*8 GB)
  TEST_CASE(Val_u64, 1 - 1 GB)
  TEST_CASE(Val_u64, 2*2+1 BYTES)
};
const char *pszTestStatus[]={
  "FAIL",
  "PASS"
};
#include <crtdbg.h>
/* #include <signal.h> */
/* void (*prev_terminateFunc)(int); */
/* void terminateFunc(int Arg1) */
/* { */
/*   siFormattedMessage_M2('D', __FILE__, "terminateFunc", __LINE__, "", */
/*               "[%i]\n", Arg1 ); */
/*  */
/* } */

int __cdecl main(
/*     const char *const *const argv,  */
/*     const signed int argc,  */
/*     const char *const *const envp  */
    void
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  TestCase_t *pCurTestCase;
  int CasesLeft, TestCount=0, PassCount=0;
  signed long long sllLclValue;

/*   prev_terminateFunc = signal (SIGTERM ,terminateFunc); */
/*   if(prev_terminateFunc==SIG_ERR) */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%p\n", prev_terminateFunc ); */
/*  */
/*   prev_terminateFunc = signal (SIGBREAK,terminateFunc); */
/*   if(prev_terminateFunc==SIG_ERR) */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%p\n", prev_terminateFunc ); */
/*  */
/*   prev_terminateFunc = signal (SIGABRT ,terminateFunc); */
/*   if(prev_terminateFunc==SIG_ERR) */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%p\n", prev_terminateFunc ); */

/*   const char*const* pcszEnv;  */
/*   argv=argv; */
/*   argc=argc; */
/*   envp=envp; */

/*    _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG|_CRTDBG_LEAK_CHECK_DF|_CRTDBG_CHECK_EVERY_16_DF); */
/*   for (pcszEnv=envp;*pcszEnv!=NULL;pcszEnv++){ */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%s\n", *pcszEnv ); */
/*   } */
/*   for (pcszEnv=environ;*pcszEnv!=NULL;pcszEnv++){ */
/*     siFormattedMessage_M2('D', __FILE__, "main", __LINE__, "", */
/*               "%s\n", *pcszEnv ); */
/*   } */
  /*
  for(CasesLeft=ARRAY_SIZE(TestCasesEquates),
      pCurTestCase=TestCasesEquates;
      CasesLeft --;
      pCurTestCase ++
      )
  {
    TestCount++;
    StatusCode=ParseAsciiEqu(pCurTestCase->cszEquation, &sllLclValue);
    if(!EAPI_TEST_SUCCESS(StatusCode)){
      break;
    }
    printf(
        "[%04s]%30s | %8lli(0x%08llX), %8lli(0x%08llX)\n", 
        pszTestStatus[sllLclValue==pCurTestCase->sllValue], 
        pCurTestCase->cszEquation, 
        sllLclValue, sllLclValue, 
        pCurTestCase->sllValue, pCurTestCase->sllValue
      );
    if(sllLclValue==pCurTestCase->sllValue){
      PassCount++;
    }
  }
  */
  for(CasesLeft=ARRAY_SIZE(TestCasesEquates),
      pCurTestCase=TestCasesEquates;
      CasesLeft --;
      pCurTestCase ++
      )
  {
    TestCount++;
    DO(ParseAsciiEqu_VA(
            pCurTestCase->cszEquation, 
            pCurTestCase->pValueStore,
            pCurTestCase->pElementSize
        ));
    DO(RecoverValue_VA(
            &sllLclValue, 
            pCurTestCase->pValueStore,
            pCurTestCase->pElementSize
        ));
    printf(
        "[%04s](%i)%30s | %8lli(0x%08llX), %8lli(0x%08llX)\n", 
        pszTestStatus[sllLclValue==pCurTestCase->sllValue], 
        pCurTestCase->pElementSize, 
        pCurTestCase->cszEquation, 
        sllLclValue, sllLclValue, 
        pCurTestCase->sllValue, pCurTestCase->sllValue
      );
    if(sllLclValue==pCurTestCase->sllValue){
      PassCount++;
    }
  }
  for(CasesLeft=ARRAY_SIZE(TestCasesMACRO),
      pCurTestCase=TestCasesMACRO;
      CasesLeft --;
      pCurTestCase ++
      )
  {
    TestCount++;
    DO(ParseAsciiEquEx_VA(
            pCurTestCase->cszEquation , 
            &SizeMacroDesc            ,
            pCurTestCase->pValueStore ,
            pCurTestCase->pElementSize
        ));
    DO(RecoverValue_VA(
            &sllLclValue, 
            pCurTestCase->pValueStore,
            pCurTestCase->pElementSize
        ));
    printf(
        "[%04s](%i)%30s | %8lli(0x%08llX), %8lli(0x%08llX)\n", 
        pszTestStatus[sllLclValue==pCurTestCase->sllValue], 
        pCurTestCase->pElementSize, 
        pCurTestCase->cszEquation, 
        sllLclValue, sllLclValue, 
        pCurTestCase->sllValue, pCurTestCase->sllValue
      );
    if(sllLclValue==pCurTestCase->sllValue){
      PassCount++;
    }
  }
  for(CasesLeft=ARRAY_SIZE(TestCasesEnv),
      pCurTestCase=TestCasesEnv;
      CasesLeft --;
      pCurTestCase ++
      )
  {
    TestCount++;
    StatusCode=ParseAsciiEqu(pCurTestCase->cszEquation, &sllLclValue);
/*     if(!EAPI_TEST_SUCCESS(StatusCode)){ */
/*       break; */
/*     } */
    printf(
        "[%04s]%20s | %8lli(0x%08llX), %8lli(0x%08llX)\n", 
        pszTestStatus[sllLclValue==pCurTestCase->sllValue], 
        pCurTestCase->cszEquation, 
        sllLclValue, sllLclValue, 
        pCurTestCase->sllValue, pCurTestCase->sllValue
      );
/*     if(sllLclValue==pCurTestCase->sllValue){ */
    /*
     * Currently No Check
     */
      PassCount++;
/*     } */
  }
  printf(
      "Test Status\n"
      "  Total Tests : %i\n"
      "  Pass Count  : %i\n",
      TestCount,
      PassCount
    );
EAPI_APP_ASSERT_EXIT
  exit(StatusCode);
}
#endif

