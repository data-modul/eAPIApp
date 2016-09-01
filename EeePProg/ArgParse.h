/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/ArgParse.h $
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
 *I  File Name            : ArgParse.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: ArgParse.h 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __ARGPARSE_H__
#define __ARGPARSE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ArgDesc_s{
  void *pValue;
  size_t stValueSize;
  const char *cszHelp;
  EApiStatus_t (*Handle)(struct ArgDesc_s  *pArgs, void * pCurArg,  const char *cszArg );
}ArgDesc_t;

typedef struct CmdDesc_s{
  const char  cShort;
  const char *cszLong;
  unsigned int *puiResult;
  const char *cszHelp;
  ArgDesc_t  *pArgs;
  size_t     stArgs;
  void *     pArgData;
  EApiStatus_t (*handler)(void *pArgsData);
}CmdDesc_t;

typedef EApiStatus_t CmdArgHandler_t(
    struct ArgDesc_s  *pArgs, 
    void * pCurArg, 
    const char *cszArg 
    );

CmdArgHandler_t StringArg;
CmdArgHandler_t NumberArg;

EApiStatus_t
PrintUsage(
    FILE      *OutStream    , 
    CmdDesc_t *pCmdDesc     ,
    size_t    stArgDescCnt
    );

EApiStatus_t
ParseArgs(
    signed int siArgc,
    const char**pszArgv,
    CmdDesc_t *pCmdDesc,
    size_t    stArgDescCnt
    );

#ifdef __cplusplus
}
#endif
#endif /* __ARGPARSE_H__ */
