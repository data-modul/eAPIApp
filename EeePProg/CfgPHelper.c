/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/CfgPHelper.c $
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
 *I              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "
 *I              AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF 
 *I              ANY KIND, EITHER EXPRESS OR IMPLIED.
 *I
 *I Description: Auto Created for EApiValidateAPI.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : CfgPHelper.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: CfgPHelper.c 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EeePApp.h>

/*  */

Handlers_t  String_Element_funcs  ={ String_Element  , Dealloc_Element  , String_Help       , No_Default_Txt       };
Handlers_t  Number_Element_funcs  ={ Number_Element  , GenClear_Element , Range_List_Help   , Range_Default_Txt    };
Handlers_t  Size_Element_funcs    ={ Size_Element    , GenClear_Element , Range_List_Help   , Range_Default_Txt    };
Handlers_t  TokenNum_Element_funcs={ TokenNum_Element, GenClear_Element , TokenNum_List_Help, TokenNum_List_Default};
Handlers_t  Token_Element_funcs   ={ Token_Element   , GenClear_Element , Token_List_Help   , Token_List_Default   };
Handlers_t  SpecRev_Element_funcs ={ SpecRev_Element , GenClear_Element , SpecRev_Help      , No_Default_Txt       };
Handlers_t  PNPID_Element_funcs   ={ PNPID_Element   , GenClear_Element , PNPID_Help        , No_Default_Txt       };
Handlers_t  I2C_EEPROM_Addr_funcs ={ I2C_EEPROM_Addr , GenClear_Element , I2C_EEPROM_Help   , No_Default_Txt       };
Handlers_t  GUID_Element_funcs    ={ GUID_Element    , GenClear_Element , GUID_Help         , GUID_Default         };

/*
 *
 *  Default Text Functions
 *
 *
 */
EApiStatus_t                                    
No_Default_Txt(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  pElementDesc=pElementDesc;
  stream=stream;
  uiCount=uiCount;
  return EAPI_STATUS_SUCCESS;
}


EApiStatus_t                                    
TokenNum_List_Default(
    __IN  struct  CfgElementDesc_s *pElementDesc,
    __IN  FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  struct  CfgElementDesc_s LclElementDesc=*pElementDesc;

  if(((TokenNumDesc_t*)pElementDesc->pExtraInfo)->pTokens){
    LclElementDesc.pExtraInfo=((TokenNumDesc_t*)pElementDesc->pExtraInfo)->pTokens;
    DO(Token_List_Default(&LclElementDesc, stream, uiCount));
  }else{
    LclElementDesc.pExtraInfo=((TokenNumDesc_t*)pElementDesc->pExtraInfo)->pRange;
    DO(Range_Default_Txt(&LclElementDesc, stream, uiCount));
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t                                    
Token_List_Default(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  TokenDesc_t *pTokens;
  uiCount=uiCount;
  pTokens=((TokenListDesc_t*)pElementDesc->pExtraInfo)->pTokenList; 
  fprintf(stream, "%s", pTokens->pszTokenList);
  return EAPI_STATUS_SUCCESS;
}


EApiStatus_t                                    
Range_Default_Txt(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  NumberRangeDesc_t *pRange=pElementDesc->pExtraInfo;
  uiCount=uiCount;
  fprintf(
      stream, 
      "0x%02X", 
      pRange->pNumberRange->uiLowerLimit
    );
  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t                                    
GUID_Default(
    struct  CfgElementDesc_s *pElementDesc,
    FILE * stream ,
    __IN  unsigned int uiCount
  )
{ 
  uiCount=uiCount;
  pElementDesc=pElementDesc;
  fprintf(stream, "FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF");
  return EAPI_STATUS_SUCCESS;
}

/*
 *
 *  HELP Functions
 *
 *
 */
const char *DeletePreserve[]={
  "Deleted",
  "Preserved"
};
EApiStatus_t                                    
String_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  StringDesc_t *pStringDesc=pElementDesc->pExtraInfo; 
  int len=0;
  len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
		  "%s\n", "Generic String");
  if(pStringDesc!=NULL){
    if(pStringDesc->uiMaxLength){
	len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
			"   Max Length %u\n", pStringDesc->uiMaxLength);
    }
    if(pStringDesc->uiMinLength){
	len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
		"   Min Length %u\n", pStringDesc->uiMinLength);
    }
    len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
		"   Trailing spaces %s\n", DeletePreserve[pStringDesc->uiPreserveTrailingSpaces]);
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
Range_List_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  NumberRange_t *pNumRange;
  size_t stRangeCnt;
  int len=0;
  len=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
	"%s\n", "Generic Number");
  if(pElementDesc->pExtraInfo==NULL) return EAPI_STATUS_SUCCESS;
  pNumRange=((NumberRangeDesc_t*)pElementDesc->pExtraInfo)->pNumberRange; 
  stRangeCnt=((NumberRangeDesc_t*)pElementDesc->pExtraInfo)->stRangeCount; 
  if(stRangeCnt>1)
    len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
	"%s\n", "Meeting one of the following conditions");
  else
    len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
	"%s\n", "Meeting the following condition");
  while(stRangeCnt--){
    switch(pNumRange->uiType){
      case RANGE_INCLUSIVE:
        if(pNumRange->uiLowerLimit==pNumRange->uiUpperLimit)
	  len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
              "\t Number == %8u(0x%04X)\n",
              pNumRange->uiLowerLimit, 
              pNumRange->uiLowerLimit 
            );
        else
	  len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
              "\t %8u(0x%04X) <= Number <= %8u(0x%04X)\n", 
              pNumRange->uiLowerLimit, 
              pNumRange->uiLowerLimit, 
              pNumRange->uiUpperLimit, 
              pNumRange->uiUpperLimit
            );
        break;
      case RANGE_EXCLUSIVE:
	len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, 
              "\t Number < %8u(0x%04X) || %8u(0x%04X) < Number\n",
              pNumRange->uiLowerLimit, 
              pNumRange->uiLowerLimit, 
              pNumRange->uiUpperLimit, 
              pNumRange->uiUpperLimit
            );
        break;
      default:
        break;
    }
    pNumRange++;
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t                                    
TokenNum_List_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  struct  CfgElementDesc_s LclElementDesc=*pElementDesc;
  int len;

  LclElementDesc.pExtraInfo=((TokenNumDesc_t*)pElementDesc->pExtraInfo)->pTokens;
  DO(Token_List_Help(&LclElementDesc, szHelpBuf, stHBufLen));
  len=(signed)strlen(szHelpBuf);
  len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len, "Or a \n");
  LclElementDesc.pExtraInfo=((TokenNumDesc_t*)pElementDesc->pExtraInfo)->pRange;
  DO(Range_List_Help(&LclElementDesc, szHelpBuf + len, stHBufLen - len));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
Token_List_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  TokenDesc_t *pTokens;
  size_t stTokenCount;
  int len;
  len=EApiSprintfA(szHelpBuf, stHBufLen, 
	"%s\n", "Supported Options");
  pTokens=((TokenListDesc_t*)pElementDesc->pExtraInfo)->pTokenList; 
  stTokenCount=((TokenListDesc_t*)pElementDesc->pExtraInfo)->uiTokenCount; 
  while(stTokenCount--){
	len+=EApiSprintfA(szHelpBuf + len, stHBufLen - len,
		"\t %s\n", pTokens->pszTokenList);
    pTokens++;
  }
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
GUID_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  pElementDesc=pElementDesc;
  EApiSprintfA(szHelpBuf , stHBufLen , 
		"GUID in the Format F9168C5E-CEB2-4faa-B6BF-329BF39FA1E4\n"
		"  Means Not Supported 00000000-0000-0000-0000-000000000000\n"
		"  Means Setable       FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF\n"
		  );
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
SpecRev_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  pElementDesc=pElementDesc;
  EApiSprintfA(szHelpBuf , stHBufLen , "2.0\n");
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
PNPID_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  pElementDesc=pElementDesc;
  EApiSprintfA(szHelpBuf , stHBufLen , "3 Letter PNPID e.g. PMG,KEM");
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
I2C_EEPROM_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  pElementDesc=pElementDesc;
  EApiSprintfA(szHelpBuf , stHBufLen , 
		  "Encodded I2C EEPROM Device Selector Address 0xA0,0xA2,0xA4,0xA6,0xA8,0xAA,0xAC,0xAE\n");
  return EAPI_STATUS_SUCCESS;
}

/*
 *
 *  Clean Functions
 *
 *
 */
EApiStatus_t
Dealloc_Element(
    __IN    struct  CfgElementDesc_s *pElementDesc, 
    __INOUT void   *pCurElement
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                Dealloc_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitOffset != 0
        );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                Dealloc_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitLength != 8*sizeof(char*)
        );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                Dealloc_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->Instances.stElementSize != sizeof(char*)
        );
  if(*(char**)pCurElement!=NULL){
    free(*(char**)pCurElement);
    *(char**)pCurElement=NULL;
  }
EAPI_APP_ASSERT_EXIT
  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t
GenClear_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    __OUT void    *pvCurElement                 
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  uint8_t *pu8CurElement=pvCurElement;
  size_t stByteOffset=pElementDesc->stBitOffset/8;
  size_t stBitOffset =pElementDesc->stBitOffset%8;
  size_t stByteLen   =((pElementDesc->stBitLength + stBitOffset)/8) ;
  size_t stBitLen    =(pElementDesc->stBitLength + stBitOffset - 8)%8;
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                Dealloc_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitLength+ pElementDesc->stBitOffset> pElementDesc->Instances.stElementSize*8
        );
  if(stBitOffset){
    *(pu8CurElement+stByteOffset)=(uint8_t)(*(pu8CurElement+stByteOffset)&((1<<stBitOffset)-1));
    ++stByteOffset;
  }
  if(stByteLen){
    memset(pu8CurElement+stByteOffset, 0x00, stByteLen);
    stByteOffset+=stByteLen;
    if(stBitLen){
      *(pu8CurElement+stByteOffset)=(uint8_t)(*(pu8CurElement+stByteOffset)&(UINT8_MAX<<stBitLen));
    }
  }
EAPI_APP_ASSERT_EXIT
  return EAPI_STATUS_SUCCESS;
}

/*
 *
 *  Parse Functions
 *
 *
 */
EApiStatus_t
String_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void  *pCurElement, 
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  StringDesc_t *pStringDesc=pElementDesc->pExtraInfo; 
  size_t stStrLength;
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                String_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitOffset != 0
        );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                String_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitLength != 8*sizeof(char*)
        );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                String_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->Instances.stElementSize != sizeof(char*)
        );
  if(pStringDesc!=NULL){
    if(!pStringDesc->uiPreserveTrailingSpaces){
      stripWhiteSpaces(szValue);
    }
    stStrLength=strlen(szValue);
    if(pStringDesc->uiMinLength){
      if(pStringDesc->uiMinLength>stStrLength){
        printf("\tString_Element = String Too Short, %s\n", szValue);
      }
    }
    if(pStringDesc->uiMaxLength){
      if(pStringDesc->uiMaxLength<stStrLength){
        printf("\tString_Element = String Too Long, %s\n", szValue);
      }
    }
  }
  *(char **)pCurElement=EAPI_strdup(szValue);
#if TEST_EEPCFG
/*   printf("\tString_Element = %s, %s\n", *(char**)pCurElement, szValue); */
#endif
EAPI_APP_ASSERT_EXIT
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
GUID_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void    *pCurElement, 
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned int i;
  char    *szEnd;
  char     Short[3];
  EeePGUID_t *pGUID=pCurElement;
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                GUID_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitOffset != 0
        );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                GUID_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->Instances.stElementSize != sizeof(*pGUID)
        );
  szValue=skipWhiteSpaces(szValue);
  stripWhiteSpaces(szValue);
  /*0000000000111111111122222222223333333333
   *0123456789012345678901234567890123456789
   *F9168C5E-CEB2-4faa-B6BF-329BF39FA1E4
   */
  if( szValue[ 8]!='-'||
      szValue[13]!='-'||
      szValue[18]!='-'||
      szValue[23]!='-'||
      szValue[36]!='\0'
    )
  {
    printf("\tString_Element = Invalid Format, %s\n", szValue);
    return EAPI_STATUS_ERROR;
  }
  EeeP_Set32BitValue_BE(pGUID->a.b, strtoul(szValue+0, &szEnd, 16));
  EeeP_Set16BitValue_BE(pGUID->b[0].b, (uint16_t)strtoul(szValue+ 9, &szEnd, 16));
  EeeP_Set16BitValue_BE(pGUID->b[1].b, (uint16_t)strtoul(szValue+14, &szEnd, 16));
  for(i=19;i<22;i+=2){
    memcpy(Short, szValue+i, 2);
    Short[2]='\0';
    pGUID->c[0 + ((i - 19)/2)]=(uint8_t)strtoul(Short, &szEnd, 16);
  }
  for(i=24;i<35;i+=2){
    memcpy(Short, szValue+i, 2);
    Short[2]='\0';
    pGUID->c[2 + ((i - 24)/2)]=(uint8_t)strtoul(Short, &szEnd, 16);
  }
#if TEST_EEPCFG
/*   printf("\tGUID_Element = "); */
/*   PrintHexAsciiTableEx( */
/*       pCurElement,  */
/*       16,  */
/*       pCurElement,  */
/*       NULL, */
/*       HEXTBL_8BIT_ELEMENT|16 */
/*     ); */
#endif
 
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
Number_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  signed long long sllValue;
  
  DO(ParseAsciiEqu(szValue, &sllValue));
  if(pElementDesc->pExtraInfo!=NULL){
    StatusCode=RangeCheckAny(
        ((NumberRangeDesc_t*)pElementDesc->pExtraInfo), 
        (unsigned long)sllValue
      );
  }
  if(!EAPI_TEST_SUCCESS(StatusCode)){
    printf("\tNumber_Element = Outside Range, %s\n", szValue);
  }else{
/*     printf("\tNumber_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
  	DO(AssignValue_VAB(
            sllValue, 
            pCurElement, 
            (signed int)pElementDesc->stBitOffset  ,
            (signed int)pElementDesc->stBitLength     , 
            (signed int)pElementDesc->Instances.stElementSize
          ));
  }

  
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
static MacroItem_t SizeMacros[]={
  {"BYTES", ""          },
  {"KB"   , "*(1024 BYTES)"},
  {"MB"   , "*(1024 KB)"},
  {"GB"   , "*(1024 MB)"},
};
static MacroList_t SizeMacroDesc={SizeMacros, ARRAY_SIZE(SizeMacros)};

EApiStatus_t
Size_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  signed long long sllValue;
  
  DO(ParseAsciiEquEx(szValue, &SizeMacroDesc, &sllValue));
  if(pElementDesc->pExtraInfo!=NULL){
    StatusCode=RangeCheckAny(
        ((NumberRangeDesc_t*)pElementDesc->pExtraInfo), 
        (unsigned long)sllValue
      );
  }

  if(!EAPI_TEST_SUCCESS(StatusCode)){
    printf("\tNumber_Element = Outside Range, %s\n", szValue);
  }else{
/*     printf("\tNumber_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
  	DO(AssignValue_VAB(
            sllValue, 
            pCurElement, 
            (signed int)pElementDesc->stBitOffset  ,
            (signed int)pElementDesc->stBitLength     , 
            (signed int)pElementDesc->Instances.stElementSize
          ));
  }

  
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
I2C_EEPROM_Addr(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned long ulDeviceAddress=ulConvertStr2NumEx(szValue, NULL);

  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                I2C_EEPROM_Addr,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->Instances.stElementSize < sizeof(uint16_t)
        );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                I2C_EEPROM_Addr,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitLength < 8*sizeof(uint16_t)
        );

  if((ulDeviceAddress<=0xAE)&&(ulDeviceAddress>=0xA0)&&!(ulDeviceAddress&1)){
/*     printf("\tI2C_EEPROM_Addr = 0x%02lX, %s\n", ulDeviceAddress, szValue); */
  	DO(AssignValue_VAB(
            ulDeviceAddress, 
            pCurElement, 
            (signed int)pElementDesc->stBitOffset  ,
            (signed int)pElementDesc->stBitLength     , 
            (signed int)pElementDesc->Instances.stElementSize
          ));
  }else{
  	printf("\tI2C_EEPROM_Addr = Invalid Address 0x%02lX, %s\n", ulDeviceAddress, szValue);
  	StatusCode=EAPI_STATUS_ERROR;
  }

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
Token_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned long    ulValue;


  szValue=skipWhiteSpaces(szValue);
  stripWhiteSpaces(szValue);
  StatusCode=GetTokenValue(
      ((TokenListDesc_t*)pElementDesc->pExtraInfo), 
      szValue, 
      &ulValue
    );

  if(!EAPI_TEST_SUCCESS(StatusCode)){
    printf("\tToken_Element = Unknown Token, %s\n", szValue);
  }else{
/*     printf("\tToken_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
  	DO(AssignValue_VAB(
            ulValue, 
            pCurElement, 
            (signed int)pElementDesc->stBitOffset  ,
            (signed int)pElementDesc->stBitLength     , 
            (signed int)pElementDesc->Instances.stElementSize
          ));
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
TokenNum_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void *pCurElement,
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned long ulValue;

  szValue=skipWhiteSpaces(szValue);
  stripWhiteSpaces(szValue);

  StatusCode=GetTokenValue(
      ((TokenNumDesc_t*)pElementDesc->pExtraInfo)->pTokens, 
      szValue, 
      &ulValue
    );
  if(EAPI_TEST_SUCCESS(StatusCode)){
    DO(AssignValue_VA(
        ulValue, 
        pCurElement, 
        (signed int)pElementDesc->Instances.stElementSize
    ));
  }else{
    struct  CfgElementDesc_s LclElementDesc=*pElementDesc;

    LclElementDesc.pExtraInfo=((TokenNumDesc_t*)pElementDesc->pExtraInfo)->pRange;
    DO(Number_Element(&LclElementDesc, pCurElement, szValue));
  }


EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
SpecRev_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void     *pCurElement,
    char   *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned int uiValue;
  char *szEnd;
  pElementDesc=pElementDesc;
  uiValue=(ulConvertStr2NumEx(szValue, &szEnd)&0xF)<<4;
  EAPI_APP_RETURN_ERROR_IF_S(
      SpecRev_Element,
      (*szEnd!='.'),
      EAPI_STATUS_ERROR
      );
  uiValue|=ulConvertStr2NumEx(szEnd+1, &szEnd)&0xF;
/*   printf("\tSpecRev_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
  DO(AssignValue_VAB(
            uiValue, 
            pCurElement, 
            (signed int)pElementDesc->stBitOffset  ,
            (signed int)pElementDesc->stBitLength     , 
            (signed int)pElementDesc->Instances.stElementSize
          ));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
PNPID_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void          *pCurElement,
    char          *szValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned int i;
  unsigned int uiCurChar;
  unsigned int uiPNPID=0;
  stripWhiteSpaces(szValue);

  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                PNPID_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->Instances.stElementSize < sizeof(uint16_t)
        );
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
                PNPID_Element,
                EAPI_STATUS_INVALID_PARAMETER,
                pElementDesc->stBitLength < 8*sizeof(uint16_t)
        );

  EAPI_APP_RETURN_ERROR_IF_S(
      PNPID_Element,
      (strlen(szValue)!=3),
      EAPI_STATUS_ERROR
      );

  for(i=3;i--;){
    uiCurChar=toupper(*szValue++);
    EAPI_APP_RETURN_ERROR_IF_S(
        PNPID_Element,
        (uiCurChar<'A'||uiCurChar>'Z'),
        EAPI_STATUS_ERROR
      );
    uiPNPID<<=5;
    uiPNPID|=uiCurChar - 'A'+1;
  }
  DO(AssignValue_VAB(
            uiPNPID, 
            pCurElement, 
            (signed int)pElementDesc->stBitOffset  ,
            (signed int)pElementDesc->stBitLength  , 
            (signed int)pElementDesc->Instances.stElementSize
          ));
/*   printf("\tPNPID_Element = 0x%04lX, %s\n", *(unsigned long*)pCurElement, szValue); */
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}



NumberRange_t UINT8Range[]={
  {0x00, UINT8_MAX, RANGE_INCLUSIVE},
};
NumberRangeDesc_t  UINT8RangeDesc={
  ARRAY_SIZE(UINT8Range), UINT8Range
};
NumberRange_t UINT16Range[]={
  {0x00, UINT16_MAX, RANGE_INCLUSIVE},
};
NumberRangeDesc_t  UINT16RangeDesc={
  ARRAY_SIZE(UINT16Range), UINT16Range
};
NumberRange_t UINT32Range[]={
  {0x00, UINT32_MAX, RANGE_INCLUSIVE},
};
NumberRangeDesc_t  UINT32RangeDesc={
  ARRAY_SIZE(UINT32Range), UINT32Range
};

TokenDesc_t  InsideCrcTokens[]={
  {"InsideCRC"	, EEEP_ADDBLK_IN_CRC  },
  {"OutsideCRC"	, 0  },
};
PCFG_TOKEN_LIST_DESC(InsideCrcTL, InsideCrcTokens);

StringDesc_t PreserveTrailingSpaces={0,0,1};
StringDesc_t DeleteTrailingSpaces={0,0,0};
