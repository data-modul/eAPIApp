/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/ArgParse.c $
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
 *I Description: Generic Command Line Argument Parsing Routines
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : ArgParse.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: ArgParse.c 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EeePApp.h>

EApiStatus_t 
StringArg(
    struct ArgDesc_s  *pArgs, 
    void * cszCurArg          ,  
    const char *cszArg 
    )
{
  pArgs=pArgs;
  *(void**)cszCurArg=EAPI_strdup(cszArg);
/*   printf("StringArg: %s\n", *(char**)cszCurArg); */
  return EAPI_STATUS_SUCCESS;
}
static MacroItem_t SizeMacros[]={
  {"BYTES", ""          },
  {"KB"   , "*(1024 BYTES)"},
  {"MB"   , "*(1024 KB)"},
  {"GB"   , "*(1024 MB)"},
};
static MacroList_t SizeMacroDesc={SizeMacros, ARRAY_SIZE(SizeMacros)};

EApiStatus_t 
SizeArg(
    struct ArgDesc_s  *pArgs, 
    void* pvalue   ,  
    const char *cszArg 
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;

  DO(ParseAsciiEquEx_VA(cszArg, &SizeMacroDesc, pvalue, (signed int)pArgs->stValueSize));

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t 
NumberArg(
    struct ArgDesc_s  *pArgs, 
    void* pvalue   ,  
    const char *cszArg 
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  
  DO(ParseAsciiEqu_VA(cszArg, pvalue, (signed int)pArgs->stValueSize));

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

const char cszHeader[]= 
  "+=============================================================================+\n"
  "| Usage                                                                       |\n"
  "+-----------------------------------------------------------------------------+\n"
;
const char cszFooter[]= 
  "+=============================================================================+\n"
  ;

EApiStatus_t
PrintUsage(
    FILE      *OutStream    , 
    CmdDesc_t *pCmdDesc     ,
    size_t    stArgDescCnt
    )
{
  ArgDesc_t *pArgDesc;
  size_t     stArgCount;
  int LineWidth=80;
  int LArgLen=25;
  int ArgOHead=STRLEN("| -c --") + LArgLen + STRLEN(" ");
  int HelpLen=LineWidth - ArgOHead - STRLEN(" |\n");
  fprintf(OutStream, cszHeader);
  while(stArgDescCnt --){
    /*
     *
     */
    if(pCmdDesc->cShort)
      fprintf(OutStream, "| -%c ", pCmdDesc->cShort );
    else
      fprintf(OutStream, "|  %c ", ' ' );
    /*
     *
     */
    if(pCmdDesc->cszLong!=NULL)
      fprintf(OutStream, "--%-*s ", LArgLen, pCmdDesc->cszLong );
    else
      fprintf(OutStream, "  %-*s ", LArgLen, "");
    /*
     *
     */
    PrintStringBlock(
        OutStream         ,
        pCmdDesc->cszHelp , 
        HelpLen, "|", -ArgOHead, " |\n"
      );

    
    pArgDesc=pCmdDesc->pArgs;
    for(stArgCount=0; stArgCount< pCmdDesc->stArgs; stArgCount++){
      fprintf( OutStream, 
							 "|%*s%s%lu ", ArgOHead, "", "Arg", 
							 (unsigned long)stArgCount
						);
      PrintStringBlock(
          OutStream         ,
          pArgDesc->cszHelp ,
          HelpLen   - (signed)STRLEN(" Arg0 "), "|", -(signed)(ArgOHead+(signed)STRLEN(" Arg0 ")), " |\n"
        );
      pArgDesc++;
    };
    if(pCmdDesc->pArgs){
      fprintf( OutStream, "|%*s|\n", (signed)(LineWidth - STRLEN("||\n")), "" );
    };

    pCmdDesc++;
  };
  fprintf(OutStream, cszFooter);
  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t
ParseArgsBuffer(
    const char *szCmdLine, 
    char      **pszArgv, 
    char       *szArgs, 
    signed int *psiArgc, 
    signed int *psiCharc 
  )
{
  signed int siInString;
  signed int siCopyChar;
  signed int siSlashesCnt;
  *psiArgc =0;
  *psiCharc=0;
  siInString=0;
  for(;;){
    while(*(szCmdLine)==' '||*(szCmdLine)=='\t'||*(szCmdLine)=='\n'){ ++(szCmdLine); }
    if(*szCmdLine=='\0')
      break;
    if(pszArgv!=NULL)
      *pszArgv++=szArgs;
    ++*psiArgc;
    for(;;){
      siCopyChar=1;

      siSlashesCnt=0;
      while(*szCmdLine=='\\'){
        szCmdLine++;
        siSlashesCnt++;
      }
      if(*szCmdLine=='\"'){
        if(!(siSlashesCnt%2)){
          if(siInString && szCmdLine[1]=='\"'){
            szCmdLine++;
          }else{
            siCopyChar=0;
            siInString=!siInString;
          }
        }
        siSlashesCnt/=2;
      }
      *psiCharc+=siSlashesCnt;
      if(szArgs!=NULL){
        while(siSlashesCnt --){
          *szArgs++='\\'; 
        }
      }
      if(*szCmdLine=='\0'||*szCmdLine=='\n'||(!siInString&&(*szCmdLine==' '||*szCmdLine=='\t')))
        break;
      if(siCopyChar){
        if(szArgs!=NULL)
          *szArgs++=*szCmdLine; 
        ++*psiCharc;
      }
      ++szCmdLine;
    }
    if(szArgs!=NULL)
      *szArgs++='\0'; 
    ++*psiCharc;
  }
  if(pszArgv!=NULL)
    *pszArgv++=NULL;
  ++*psiArgc;
  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t
CreateArgvArgcBuffer(
    const char *szCmdLine, 
    char      ***pszArgv, 
    signed int *psiArgc 
  )
{
  EApiStatus_t StatusCode;
  signed int siCharCnt;
  DO(ParseArgsBuffer(szCmdLine, NULL, NULL, psiArgc, &siCharCnt));
  *pszArgv=(char**)malloc(((*psiArgc)*sizeof(char*))+(siCharCnt*sizeof(char)));
  EAPI_APP_ASSERT_PARAMATER_NULL(
      CreateArgvArgcBuffer,
      EAPI_STATUS_ALLOC_ERROR,
      *pszArgv
    );
  (*psiArgc) --;
  StatusCode=ParseArgsBuffer(
          szCmdLine, 
          *pszArgv, 
          (char *)((*pszArgv)+(*psiArgc)), 
          psiArgc, 
          &siCharCnt
        );
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
ParseArgsFile(
    const char*szFilename,
    CmdDesc_t *pCmdDesc,
    size_t    stArgDescCnt
    )
{
  EApiStatus_t StatusCode;
  signed int siArgc;
  char**pszArgv=NULL;
  void *pvFileBuffer;
  char *szFileBuffer;
  size_t stFileSize;
  char ErrBuffer[200];
  StatusCode=ReadTextFile(szFilename, &pvFileBuffer, &stFileSize);
  szFileBuffer=pvFileBuffer;

  if(!EAPI_TEST_SUCCESS(StatusCode)){
    EApiSprintfA(
        ErrBuffer, ARRAY_SIZE(ErrBuffer),
        "Error Reading %s", szFilename
        );
    EAPI_APP_RETURN_ERROR(
        ParseArgs,
        StatusCode,
        ErrBuffer
      );
  }
  DO(CreateArgvArgcBuffer(szFileBuffer, &pszArgv, &siArgc));
  if(szFileBuffer!=NULL) free(szFileBuffer);
  szFileBuffer=NULL;

  DO(ParseArgs(siArgc - 1, (const char **)pszArgv, pCmdDesc, stArgDescCnt));

EAPI_APP_ASSERT_EXIT
  if(pszArgv  !=NULL) free(pszArgv  );
  pszArgv=NULL;
  return StatusCode;
}


EApiStatus_t
ParseSubArgs(
      signed int *psiArgc    ,
      const char***ppszArgv  ,
      size_t     stArgCount,
      ArgDesc_t *pArgDesc  
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  while(stArgCount -- ){
    if(!(*psiArgc)--){
      printf("ERROR: Missing Required Argument (%s)\n", pArgDesc->cszHelp);
      return EAPI_STATUS_ERROR;
    }
    ++(*ppszArgv);
    DO(pArgDesc->Handle(pArgDesc, pArgDesc->pValue, **ppszArgv));
    ++pArgDesc;
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


EApiStatus_t
ParseArgs(
    signed int siArgc,
    const char**pszArgv,
    CmdDesc_t *pCmdDesc,
    size_t    stArgDescCnt
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  const char **pszCurArg=pszArgv;
  CmdDesc_t *pCurArgDesc;
  size_t stI;
  unsigned int uiValid,uiSyntaxError;
  const char *szCurOption;
  uiSyntaxError=0;
  while(siArgc -- && *pszCurArg!=NULL){
/*     printf("DEBUG: Arg[%u] (%s)\n", siArgc, *pszCurArg); */
    uiValid=0;
    szCurOption=*pszCurArg;
    switch(*szCurOption++){
      case '@':
        DO(ParseArgsFile(szCurOption, pCmdDesc, stArgDescCnt));
        ++uiValid;
        break;
      case '-':
        if(*szCurOption=='-'){
          ++szCurOption;
          /*
          * Parse Long Commands
          */
          stI=stArgDescCnt;
          pCurArgDesc=pCmdDesc;
          while(stI --){
            if( pCurArgDesc->cszLong!=NULL&&
                !strcmp(szCurOption, pCurArgDesc->cszLong)
                )
            {
              if(pCurArgDesc->puiResult!=NULL){
                ++(*pCurArgDesc->puiResult);
              }
              DO(ParseSubArgs(&siArgc, &pszCurArg, pCurArgDesc->stArgs, pCurArgDesc->pArgs));
              ++uiValid;
              if(pCurArgDesc->handler!=NULL){
                DO(pCurArgDesc->handler(pCurArgDesc->pArgData));
              }
              break;
            }
            ++pCurArgDesc;
          }
        }else {
          /*
          * Parse Short Commands
          */
          while(*szCurOption){
            stI=stArgDescCnt;
            pCurArgDesc=pCmdDesc;
            uiValid=0;
            while(stI --){
              if(*szCurOption==pCurArgDesc->cShort){
                if(pCurArgDesc->puiResult!=NULL){
                  ++(*pCurArgDesc->puiResult);
                }
                DO(ParseSubArgs(&siArgc, &pszCurArg, pCurArgDesc->stArgs, pCurArgDesc->pArgs));
                ++uiValid;
                if(pCurArgDesc->handler!=NULL){
                  DO(pCurArgDesc->handler(pCurArgDesc->pArgData));
                }
                break;
              }
              ++pCurArgDesc;
            }
            if(!uiValid){
              ++uiSyntaxError;
              printf("ERROR: Unknown Arg [%c] in (%s)\n", *szCurOption, *pszCurArg);
              uiValid=0;
            }
            ++szCurOption;
          }
        }
        break;
      default:
        break;
    }
    if(!uiValid){
      uiSyntaxError++;
      printf("ERROR: Unknown Arg (%s)\n", *pszCurArg);
    }
    ++pszCurArg;
  }

  if(uiSyntaxError)
  StatusCode=EAPI_STATUS_INVALID_PARAMETER;
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
#if TEST_EEPARG

typedef struct OptionsTest_s{
  unsigned int uiHelp;
  unsigned int uiVerbose;
  unsigned int uiCreateCOM0R20M_CFG;
  char  *szCOM0R20M_Cfg_File;
}OptionsTest_t;
OptionsTest_t CurOptionsTest;
ArgDesc_t  COM0R20M_Cfg[]={
  {
  &CurOptionsTest.szCOM0R20M_Cfg_File        ,
  sizeof(CurOptionsTest.szCOM0R20M_Cfg_File) ,
  "<Filename>  Destination File"         ,
  StringArg
  },
};

CmdDesc_t ArgsDesc[]={
  {
    'h'                                             , 
    "help"                                          , 
    &CurOptionsTest.uiHelp                          , 
    "Print this usage message"                      , 
    NULL                                            ,
    0                          
  },
  {
    'v'                                             , 
    "verbose"                                       , 
    &CurOptionsTest.uiVerbose                       , 
    "Increases Verbosity Level\n"
    "      1\n"
    "    2\n"
    "  3\n"                                         , 
    NULL                                            ,
    0                          
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-CFG"                           , 
    &CurOptionsTest.uiCreateCOM0R20M_CFG            , 
    "Create COM0 Module Config File Template\n\tTest Me "       , 
    COM0R20M_Cfg                                    ,
    ARRAY_SIZE(COM0R20M_Cfg)
  },
};
char szCmdLine[]={
    "--CREATE-COM0R20CB-CFG\ttest -d -f -g\n"
    "--CREATE-COM0R20CB-CFG\ttest -dsdfgh -f -g\n"
    "--CREATE-COM0R20CB-CFG\\\"st -d -f -g\n"
    "--\\\\\\\\\"\\\\\\\"FG\ttest -d -f -g\n"
    "@Test.log\n"
};
char *DummyArgs1[]={
  "Program Name",
  "-a",
  "-s",
  "-v",
  "-q",
  "--Arg1",
  "--Arg2",
  "--CREATE-COM0R20M-CFG", "TestFile.cfg",
  "--Arg3",
};
#define DO_MAIN(x)  \
  EAPI_printf(        \
      TEXT("#####\n") \
      TEXT("#\t%s\n") \
      TEXT("#####\n"),\
      TEXT(#x)        \
    );                \
  StatusCode=x;   \
  if(!EAPI_TEST_SUCCESS(StatusCode)) \
    return StatusCode

/*
 * Create Block Content
 */
int 
__cdecl 
main(
    signed int siArgc, 
    const char *pszArgv[]
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  signed int  siArgcTest;
  char     **pszArgvTest;

#ifdef _DEBUG
  _CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag());
#endif

  PrintUsage(stderr, ArgsDesc, ARRAY_SIZE(ArgsDesc));
  ParseArgs(ARRAY_SIZE(DummyArgs1) - 1, DummyArgs1 + 1, ArgsDesc, ARRAY_SIZE(ArgsDesc));
/*   printf(szCmdLine); */

  ParseArgs(siArgc - 1, pszArgv + 1, ArgsDesc, ARRAY_SIZE(ArgsDesc));

  CreateArgvArgcBuffer(szCmdLine, &pszArgvTest, &siArgcTest);



  ParseArgs(siArgcTest , pszArgvTest, ArgsDesc, ARRAY_SIZE(ArgsDesc));

/*   for(siCharCnt=siArgcTest;-- siCharCnt ; ){ printf("ARG[%02i]=%s\n", siCharCnt, pszArgvTest[siCharCnt]); } */
  free(pszArgvTest);

  exit(StatusCode);
}

#endif
