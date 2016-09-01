/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/CfgParser.c $
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
 *I  File Name            : CfgParser.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 76 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-07-08 14:47:42 +0200 (Thu, 08 Jul 2010) $
 *I  ID                   : $Id: CfgParser.c 76 2010-07-08 12:47:42Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EeePApp.h>

/*  */
#define EAPI_STATUS_PARSE_ERROR EAPI_STATUS_ERROR

#define TEST_EEPCFG 0


static char ElementHeader[]=
"#################################################\n"
"  %s\n"
"#################################################\n"
;

static char BlockOpen[]=
"[%s]\n"
;
static char BlockClose[]=
"[/%s]\n"
;

#define STEP_SIZE 2
const char szComment[]="##";
const char szComment2[]="##  ";
EApiStatus_t
PrintCfgFile_Sub(
    __IN    CfgNodeGen_t  *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements ,
    __OUT   FILE *         OutStream          ,
    __IN    unsigned int   cuiRequired        ,
    __IN    unsigned int   Depth
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  unsigned int i2;
  char szBuffer[2048];
  int LclDepth;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      PrintCfgFile_Sub,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      PrintCfgFile_Sub,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  LclDepth=(Depth*STEP_SIZE)+STRLEN(szComment);
  while(stCfgBDescElements--){
    switch(pCfgBDesc->Gen.NodeType){
      case CfgBlockNode:
        if(pCfgBDesc->Block.Elements.stUsedCnt){
          EApiSprintfA(szBuffer, ARRAY_SIZE(szBuffer), BlockOpen, pCfgBDesc->Block.pszBlockName);
          DO(PrintStringBlockA(OutStream, szBuffer, 60, (cuiRequired&&pCfgBDesc->Block.cuiRequired?"":"# "), LclDepth, "\n"));
          DO(PrintCfgFile_Sub(pCfgBDesc->Block.Elements.pIndx, pCfgBDesc->Block.Elements.stUsedCnt, OutStream, cuiRequired&&pCfgBDesc->Block.cuiRequired, Depth+1));
          EApiSprintfA(szBuffer, ARRAY_SIZE(szBuffer), BlockClose, pCfgBDesc->Block.pszBlockName);
          DO(PrintStringBlockA(OutStream, szBuffer, 60, (cuiRequired&&pCfgBDesc->Block.cuiRequired?"":"# "), LclDepth, "\n"));
        }
        break;
      case CfgElementNode:
        EApiSprintfA(szBuffer, ARRAY_SIZE(szBuffer), ElementHeader, pCfgBDesc->Element.pcszElementName);
        DO(PrintStringBlockA(OutStream, szBuffer, 60, szComment, LclDepth, "\n"));
        fprintf(OutStream, 
            "%*s\t\t %s\n", LclDepth, szComment,
            (pCfgBDesc->Element.cuiRequired?"Required Element":"Optional Element")
          );
        fprintf(OutStream, 
            "%*s\t\t Allowed Maximum of %lu times in block\n", LclDepth, szComment,
            (unsigned long)pCfgBDesc->Element.Instances.stTotalCnt
          );
        DO(pCfgBDesc->Element.pHandlers->Help(
              &pCfgBDesc->Element, 
              szBuffer,
              ARRAY_SIZE(szBuffer)
            ));
        DO(PrintStringBlockA(OutStream, 
              szBuffer,
              60, szComment2, LclDepth+2, "\n"
            ));
        i2=0;
        do{
          fprintf(OutStream, "%*s%s=", LclDepth, 
                (cuiRequired&pCfgBDesc->Element.cuiRequired?"":"# "), 
                pCfgBDesc->Element.pcszElementName
              );
          DO(pCfgBDesc->Element.pHandlers->Default(
                &pCfgBDesc->Element, 
                OutStream  ,
                i2
              ));
          fprintf(OutStream, "\n");
        }while(++i2<pCfgBDesc->Element.cuiRequired);
        fprintf(OutStream, "\n");
        break;
      default:
        break;
    }
    pCfgBDesc++;
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
PrintCfgFile(
    __IN    CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements ,
    __OUT   FILE *         OutStream
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      PrintCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      PrintCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  DO(PrintCfgFile_Sub((CfgNodeGen_t*)pCfgBDesc, stCfgBDescElements, OutStream, 1, 0));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
CleanStruct_sub(
    __IN    CfgNodeGen_t  *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements ,
    __IN    size_t         stDepth
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      CleanStruct_sub,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      CleanStruct_sub,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  while(stCfgBDescElements --){
    switch(pCfgBDesc->Gen.NodeType){
      case CfgBlockNode:
        if(pCfgBDesc->Block.Elements.stUsedCnt){
          DO(CleanStruct_sub(pCfgBDesc->Block.Elements.pIndx, pCfgBDesc->Block.Elements.stUsedCnt, stDepth + 1));
        }
        pCfgBDesc->Block.stFound=0;
        break;
      case CfgElementNode:
        while(pCfgBDesc->Element.Instances.stUsedCnt --){
          DO(pCfgBDesc->Element.pHandlers->Clean(
                (CfgElementDesc_t*)pCfgBDesc,
                EAPI_CREATE_PTR(
                    pCfgBDesc->Element.Instances.pIndx, 
                    pCfgBDesc->Element.Instances.stElementSize*(pCfgBDesc->Element.Instances.stUsedCnt), 
                    void*
                  )
              ));
        }
        break;
      default:
        break;
    }
    pCfgBDesc++;
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
CleanStruct(
    __IN    CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EAPI_APP_ASSERT_PARAMATER_NULL(
      CleanStruct,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      CleanStruct,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  DO(CleanStruct_sub((CfgNodeGen_t*)pCfgBDesc, stCfgBDescElements, 0));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
GetElementDesc(
    __IN  CfgNodeGen_t   *pDesc         ,
    __OUT CfgNodeGen_t  **ppNodeDesc    ,
    __IN  const char     *cszElementName,
    __IN  NodeTypes_t     NodeType
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_NOT_FOUND;
  CfgNodeGen_t     *pNodeDesc;
  int   i;

  EAPI_APP_ASSERT_PARAMATER_NULL(
        GetElementDesc,
        EAPI_STATUS_INVALID_PARAMETER,
        pDesc
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        GetElementDesc,
        EAPI_STATUS_INVALID_PARAMETER,
        ppNodeDesc
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        GetElementDesc,
        EAPI_STATUS_INVALID_PARAMETER,
        cszElementName
      );
  *ppNodeDesc=NULL;
  for(
      i=(int)pDesc->Block.Elements.stUsedCnt,
      pNodeDesc=pDesc->Block.Elements.pIndx;
      i--;
      pNodeDesc++
      )
  {

    if(pNodeDesc->Element.NodeType==NodeType){
      if(!strcmp(cszElementName, pNodeDesc->Element.pcszElementName))
      {
        *ppNodeDesc=pNodeDesc;
        StatusCode=EAPI_STATUS_SUCCESS;
        break;
      }
    }
  }

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

#define MAX_LINE_LEN 2048
typedef struct ParseCfgContext_s{
  const char *pcszCfgFileName;
  FILE *pCfgFile;
  unsigned long ulLineNum;
  unsigned long ulDepth;
  char LineBuffer[MAX_LINE_LEN];
}ParseCfgContext_t;

EApiStatus_t
ParseCfgFile_sub(
    __IN    ParseCfgContext_t *pCtxt              ,
    __INOUT CfgNodeGen_t      *pCfgBDesc          ,
    __IN    size_t             stRequired
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  char *szName;
  char *szValue;
  size_t i;
  unsigned long ulBlockStartLine=pCtxt->ulLineNum;
  CfgNodeGen_t *pCurElement;

  EAPI_APP_ASSERT_PARAMATER_NULL(
        ParseCfgFile_sub,
        EAPI_STATUS_INVALID_PARAMETER,
        pCtxt
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        ParseCfgFile_sub,
        EAPI_STATUS_INVALID_PARAMETER,
        pCfgBDesc
      );

  ++ pCtxt->ulDepth;
/*   siFormattedMessage_M2('L', __FILE__, "ParseCfgFile_sub", __LINE__, pCfgBDesc->Block.pszBlockName,"Entering \n"); */


  while(!feof(pCtxt->pCfgFile)){
    szName=fgets(pCtxt->LineBuffer, ARRAY_SIZE(pCtxt->LineBuffer), pCtxt->pCfgFile);
    pCtxt->ulLineNum++;
#if TEST_EEPCFG
		siFormattedMessage_M2('L', __FILE__, "ParseCfgFile_sub", __LINE__, pCfgBDesc->Block.pszBlockName,
        "(%04lu)[%02lu]%s\n", pCtxt->ulLineNum, pCtxt->ulDepth, pCtxt->LineBuffer);
#endif
    /*
     * Remove Comments And New Lines etc..
     */
    szName=strpbrk(pCtxt->LineBuffer, ";#\n\r");
    if(szName!=NULL) *szName='\0';
    szName=skipWhiteSpaces(pCtxt->LineBuffer);
    if(!strlen(szName)){ /*Skip Empty Blank Lines */ continue; }

#if  TEST_EEPCFG
		siFormattedMessage_M2('L', __FILE__, "ParseCfgFile_sub", __LINE__, pCfgBDesc->Block.pszBlockName,
        "(%04lu)[%02lu]%s\n", pCtxt->ulLineNum, pCtxt->ulDepth, pCtxt->LineBuffer);
#endif
    if(szName[0]=='['){
      CfgNodeGen_t *pCurBlockDesc=NULL;
      size_t stTokenLen=strcspn(++szName, "]");
      if(!stTokenLen){
        siFormattedMessage_SC('L', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
          "(%04lu)%s\n", pCtxt->ulLineNum, pCtxt->LineBuffer);
      }
#if TEST_EEPCFG
      siFormattedMessage_M2('L', __FILE__, "ParseCfgFile_sub", __LINE__, "Block",
        "(%04lu)%s\n", pCtxt->ulLineNum, pCtxt->LineBuffer);
#endif
      if(szName[0]=='/'){
        szName[stTokenLen]='\0';
        ++szName;
        /*
         * End Of Block Marker
         *
         */
        if(strcmp(szName, pCfgBDesc->Block.pszBlockName))
        {
          StatusCode=EAPI_STATUS_PARSE_ERROR;
          siFormattedMessage_SC('W', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
                      "Expected '[/%s]' Got (%lu)'[/%s]'\n", 
                      pCfgBDesc->Block.pszBlockName, 
                      ulBlockStartLine,
                      szName
                    );
        }else{
          /*
           * Check Last Block Required
           */
            for(
                  i=pCfgBDesc->Block.Elements.stUsedCnt,
                  pCurElement=pCfgBDesc->Block.Elements.pIndx; 
                  i--; 
                  pCurElement++
                )
              {
                if(pCurElement->Block.Elements.stTotalCnt){
                  switch(pCurElement->Gen.NodeType){
                    case CfgBlockNode:
                      if(pCurElement->Block.cuiRequired>pCurElement->Block.stFound)
                      {
                        StatusCode=EAPI_STATUS_ERROR;
                        siFormattedMessage_SC('W', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
                            "Missing Required Block '%s' in Block (%lu)'%s'\n", 
                            pCurElement->Block.pszBlockName, 
                            ulBlockStartLine,
                            pCfgBDesc->Block.pszBlockName
                          );
                          EAPI_APP_EXIT;
                      }
                      break;
                    case CfgElementNode:
                      if(pCurElement->Element.cuiRequired>pCurElement->Element.Instances.stUsedCnt)
                      {
                        StatusCode=EAPI_STATUS_ERROR;
                        siFormattedMessage_SC('W', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
                            "Missing Required Element '%s' in Block (%lu)'%s'\n", 
                            pCurElement->Block.pszBlockName, 
                            ulBlockStartLine,
                            pCfgBDesc->Block.pszBlockName
                          );
                          EAPI_APP_EXIT;
                      }
                      break;
                    default:
                      break;
                  }
                }
              }

        }
        pCtxt->LineBuffer[0]='\0';
        EAPI_APP_EXIT;
      }else{
        szName[stTokenLen]='\0';
        StatusCode=GetElementDesc(pCfgBDesc, &pCurBlockDesc, szName, CfgBlockNode);
        szName[stTokenLen]=']';
        switch(StatusCode){
          case EAPI_STATUS_SUCCESS:
            pCurBlockDesc->Block.stFound=BLOCK_FOUND;
            DO(ParseCfgFile_sub(pCtxt, pCurBlockDesc, stRequired&&pCurBlockDesc->Block.cuiRequired));
            break;
          case EAPI_STATUS_NOT_FOUND:
            siFormattedMessage_SC(
                  'E', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
                  "Unknown Block on line %li, '%s'\n", pCtxt->ulLineNum, szName
            );
            break;
          default:
            EAPI_APP_EXIT;
            break;
        }
      }

    }else{
      unsigned int FoundElement=0;
      if(pCfgBDesc==NULL){
					siFormattedMessage_M2('W', __FILE__, "ParseCfgFile_sub", __LINE__, "Invalid Block",
            "(%04lu) : %s\n", 
            pCtxt->ulLineNum, 
            pCtxt->LineBuffer
							);
        continue;
      }
      szValue=strchr(szName, '=');
      if(szValue==NULL){
					siFormattedMessage_M2('W', __FILE__, "ParseCfgFile_sub", __LINE__, "Invalid Line",
            "(%04lu) : %s\n", 
            pCtxt->ulLineNum, 
            pCtxt->LineBuffer
							);
        continue;
      }
      *szValue++='\0';
      stripWhiteSpaces(szName);
      szValue=skipWhiteSpaces(szValue);
#if TEST_EEPCFG
		siFormattedMessage_M2('L', __FILE__, "ParseCfgFile_sub", __LINE__, pCfgBDesc->Block.pszBlockName,
        "(%04lu)%-20s = %s", pCtxt->ulLineNum, szName, szValue);
#endif
      StatusCode=GetElementDesc(pCfgBDesc, (CfgNodeGen_t**)&pCurElement, szName, CfgElementNode);

      switch(StatusCode){
        case EAPI_STATUS_SUCCESS:
          if(pCurElement->Element.Instances.stUsedCnt+1>pCurElement->Element.Instances.stTotalCnt){
            siFormattedMessage_SC(
                'E', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
                "ERROR Too Many Instances of %s at line %li\n", szValue, pCtxt->ulLineNum
            );
            EAPI_APP_EXIT;
          }
          StatusCode=pCurElement->Element.pHandlers->Handler(
                (CfgElementDesc_t*)pCurElement, 
                EAPI_CREATE_PTR(
                    pCurElement->Element.Instances.pIndx,
                    pCurElement->Element.Instances.stElementSize*pCurElement->Element.Instances.stUsedCnt, 
                    void*
                  ),
                szValue
              );
          if(!EAPI_TEST_SUCCESS(StatusCode)){
            siFormattedMessage_SC(
                'E', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
                "ERROR Parsing Line %li, %s\n", pCtxt->ulLineNum, szValue
            );
            EAPI_APP_EXIT;
          }
          pCurElement->Element.Instances.stUsedCnt++;
          FoundElement++;
          break;
        case EAPI_STATUS_NOT_FOUND:
          siFormattedMessage_SC(
                'E', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode,
                "Unknown Block Element on line %li, '%s'\n", pCtxt->ulLineNum, szName
          );
          break;
        default:
          EAPI_APP_EXIT;
          break;
      }
    }
  }

  

EAPI_APP_ASSERT_EXIT 
/*   siFormattedMessage_SC('L', __FILE__, "ParseCfgFile_sub", __LINE__, StatusCode, "Exiting %s\n", pCfgBDesc->Block.pszBlockName); */
  -- pCtxt->ulDepth;

  return StatusCode;
}

EApiStatus_t
ParseCfgFile(
    __IN    const char *pcszCfgFileName       ,
    __INOUT CfgBlockDesc_t *pCfgBDesc         ,
    __IN    size_t         stCfgBDescElements
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  CfgNodeGen_t DummyBDesc={{0, NULL, 0, {0, 0, 0, 0, NULL, NULL, NULL}, 0, 0, NULL, NULL}};
  ParseCfgContext_t  CCtxt={NULL, NULL, 0, 0, {0}};
  EAPI_APP_ASSERT_PARAMATER_NULL(
      _ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pcszCfgFileName
    );
  EAPI_APP_ASSERT_PARAMATER_NULL(
      _ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      pCfgBDesc
    );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
      _ParseCfgFile,
      EAPI_STATUS_INVALID_PARAMETER,
      stCfgBDescElements
    );
  CCtxt.pcszCfgFileName=pcszCfgFileName;
  CCtxt.pCfgFile=fopen(CCtxt.pcszCfgFileName, "r");
  
  EAPI_APP_RETURN_ERROR_IF_S(
      _ParseCfgFile,
      (CCtxt.pCfgFile==NULL),
      EAPI_STATUS_READ_ERROR
    );
  CCtxt.ulLineNum=0;
  CCtxt.ulDepth=0;
  DummyBDesc.Block.NodeType=CfgBlockNode;
  DummyBDesc.Block.pszBlockName="DummyMasterNode";
  DummyBDesc.Block.Elements.pIndx=pCfgBDesc;
  DummyBDesc.Block.Elements.stUsedCnt=stCfgBDescElements;
  DummyBDesc.Block.Elements.stTotalCnt=stCfgBDescElements;
  DummyBDesc.Block.Elements.stElementSize=sizeof(DummyBDesc);

  DO(ParseCfgFile_sub(&CCtxt, &DummyBDesc, BLOCK_REQUIRED));

EAPI_APP_ASSERT_EXIT 
  if(CCtxt.pCfgFile) fclose(CCtxt.pCfgFile);

  return StatusCode;
}



