/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/TokenFunc.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for TokenFunc.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : TokenFunc.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: TokenFunc.h 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __TOKENFUNC_H__
#define __TOKENFUNC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "RangeFunc.h"


typedef struct TokenDesc_s{
  char          *pszTokenList;
  unsigned long  ulTokenValue;
}TokenDesc_t;

typedef struct TokenListDesc_s{
  unsigned int uiTokenCount;
  TokenDesc_t *pTokenList;
}TokenListDesc_t;

#define PCFG_TOKEN_LIST_DESC(TLName, TokenList) \
TokenListDesc_t TLName={ \
  ARRAY_SIZE(TokenList), TokenList \
}

typedef struct TokenNumDesc_s{
  TokenListDesc_t   *pTokens;
  NumberRangeDesc_t *pRange ;
}TokenNumDesc_t;



EApiStatus_t
GetTokenFlags(
    __OUT   char               *szStrBuf   ,
    __INOUT signed int         *psiStrBufLen,
    __IN  const char           *cszFirstLine,
    __IN  const char           *cszOtherLines,
    __IN  const char           *cszName      ,
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  size_t                stValue
    ) ;

EApiStatus_t
GetTokenValue(
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  const char   *szValue  ,
    __OUT unsigned long*pulValue
  );

EApiStatus_t
GetValueToken(
    __OUT char                 *pszBuffer,
    __IN  size_t                stBufLen  ,
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  size_t                stValue
    );
EApiStatus_t
GetTokenValueStrip(
    __IN  const TokenListDesc_t*pcTokenDesc,
    __IN  char   *szValue  ,
    __OUT unsigned long*pulValue
    );


#ifdef __cplusplus
}
#endif
#endif /* __TOKENFUNC_H__ */

