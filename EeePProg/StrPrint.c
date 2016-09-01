/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: Kontron Secure Bios
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/StrPrint.c $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Generic Command Line Argument Parsing Routines
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : ArgParse.c
 *I  File Location        : Aristo\common
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: StrPrint.c 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EeePApp.h>


EApiStatus_t
StringBlock(
    const char *cszStr        ,
    size_t      stOffset      ,
    size_t      stMaxBlockLen ,
    size_t     *pstLastPos    ,
    signed int *psiLenAdj
    )
{
  const char *cszLastPos=cszStr;
  size_t stTabLen=8;
  size_t stCurOffset;
  size_t stTabStop;
  *pstLastPos=0;
  *psiLenAdj=0;
/*   printf("D%04u %s\n", __LINE__, cszLastPos); */

  if(*cszLastPos=='\n')
    cszLastPos++;
  while(stMaxBlockLen --){
/*   printf("%c", *cszLastPos); */
    switch(*cszLastPos++){
      case '\t':
        stCurOffset=cszLastPos - cszStr + stOffset;
        stTabStop=((stCurOffset + stTabLen  -1)/stTabLen*stTabLen) ;
        stTabStop-= stCurOffset;
        if(stMaxBlockLen>=stTabStop){
          *psiLenAdj +=(signed)stTabStop;
          stMaxBlockLen -=stTabStop;
        }else
          stMaxBlockLen=0;
      case '/':
      case ' ':
        *pstLastPos=cszLastPos - cszStr -1;
        break;
      case '\0':
        *pstLastPos=cszLastPos - cszStr -1;
        return EAPI_STATUS_SUCCESS;
      case '\n':
      case '\r':
        *pstLastPos=cszLastPos - cszStr -1;
        return EAPI_STATUS_MORE_DATA;
      default:
        break;
    }
  }
/*   printf("D%04u %s\n", __LINE__, cszLastPos); */
  if(!*cszLastPos){
    *pstLastPos=cszLastPos - cszStr;
    return EAPI_STATUS_SUCCESS;
  } else if(!*pstLastPos) {
    *pstLastPos=cszLastPos - cszStr;
  }
  return EAPI_STATUS_MORE_DATA;
}

EApiStatus_t
PrintStringBlock(
    FILE       *OutStream     ,
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    const char *cszPreamble   ,
    signed int  siLen         ,
    const char *cszPostamble
    )
{
  size_t stCurStrPos;
  size_t stOffset=strlen(cszPreamble);
  signed int siLenAdj;
  if(siLen>=0){
    if(siLen>(signed )stOffset)
      stOffset=siLen;
  }else if(- siLen>(signed )stOffset){
      stOffset= - siLen;
  }
  StringBlock(cszStr, stOffset, stMaxBlockLen, &stCurStrPos, &siLenAdj);
  fprintf(OutStream, "%-*.*s%s", (int)stMaxBlockLen - siLenAdj, (int)stCurStrPos, cszStr, cszPostamble );
  while(stCurStrPos){
    int FirstEntry=0;
    int KeepLooping;
    cszStr+=stCurStrPos;

    for(KeepLooping=0;!KeepLooping;){
      switch(*cszStr){
        case '\n':
          if(FirstEntry++)
            fprintf( OutStream, "%*s%-*s%s", siLen, cszPreamble, (int)stMaxBlockLen, "", cszPostamble );
        case '\r':
          ++cszStr;
          break;
        case '\t':
        case ' ':
          ++cszStr;
        default:
          ++KeepLooping;
          break;
      }
    }
    StringBlock(cszStr, stOffset, stMaxBlockLen, &stCurStrPos, &siLenAdj);
    if(stCurStrPos)
      fprintf( OutStream, "%*s%-*.*s%s", siLen, cszPreamble, (int)stMaxBlockLen - siLenAdj, (int)stCurStrPos, cszStr, cszPostamble);
  };
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
PrintStringBlockA(
    FILE       *OutStream     ,
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    const char *cszPreamble   ,
    signed int  siLen         ,
    const char *cszPostamble
    )
{
  fprintf(OutStream, "%*s", siLen, cszPreamble);
  return PrintStringBlock(OutStream, 
            cszStr, stMaxBlockLen, cszPreamble,
            siLen, cszPostamble
          );
}


#if TEST_STRPRINT
typedef struct TestCases_s{
  const int   siDepth    ;
  const char *cszPreamble;
  const char *cszPostamble;
  const int   siWidth    ;
  const char *cszString  ;
}TestCases_t;
TestCases_t TestCases[]={
  { 4, ">", "<\n", 50,  "TEst Strin\tg\n\n\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  {-4, ">", "<\n", 50,  "TEst Strin\tg\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  { 4, ">", "<\n", 40,  "TEst Strin\tg\n\n\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  {-4, ">", "<\n", 40,  "TEst Strin\tg\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  { 4, ">", "<\n", 10,  "TEst Strin\tg\n\n\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  {-4, ">", "<\n", 10,  "TEst Strin\tg\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  { 20, ">", "<\n",  5,  "TEst Strin\tg\n\n\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  {-20, ">", "<\n",  5,  "TEst Strin\tg\nhelp\r what should I Type Here Not Idea I fear. Oh well I guess this will just have to do ;)"},
  {-20, ">", "<\n",  5,  "12345 12345\n12345\t12345\r\n12345\n\n12345\n\n"},
};

#define DO_MAIN(x)  \
  printf(        \
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
  int i;
#ifdef _DEBUG
  _CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag());
#endif
  for(i=0; i<ARRAY_SIZE(TestCases); i++){
      printf("%*s%*s<\n", TestCases[i].siDepth>0?TestCases[i].siDepth:-TestCases[i].siDepth,">", TestCases[i].siWidth, "");
      printf("%*s", TestCases[i].siDepth, TestCases[i].cszPreamble);
      DO(PrintStringBlock(stdout, TestCases[i].cszString, TestCases[i].siWidth, TestCases[i].cszPreamble, TestCases[i].siDepth, TestCases[i].cszPostamble ));

  }
  for(i=0; i<ARRAY_SIZE(TestCases); i++){
      printf("%*s%*s<\n", TestCases[i].siDepth>0?TestCases[i].siDepth:-TestCases[i].siDepth,">", TestCases[i].siWidth, "");
      printf("%*s", TestCases[i].siDepth, TestCases[i].cszPreamble);
      DO(PrintStringBlock(stdout, TestCases[i].cszString, TestCases[i].siWidth, TestCases[i].cszPreamble, TestCases[i].siDepth, TestCases[i].cszPostamble ));

  }

EAPI_APP_ASSERT_EXIT
  exit(StatusCode);
}

#endif
