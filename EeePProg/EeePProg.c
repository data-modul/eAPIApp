/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/EeePProg.c $
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
 *I  File Name            : EeePProg.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: EeePProg.c 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EeePApp.h>

const char cszTitle[]= 
  "+=============================================================================+\n"
  "| EeePProg.exe  Copyright (C) Kontron Embedded Modules GmbH 2010   V %u.%u.%04u |\n"
  "+=============================================================================+\n"
  "\n"
;

const char syntaxErrMes[]  = "Syntax error / Use -h for info";


Options_t CurOptions;

ArgDesc_t  COM0R20M_Cfg[]={
  {
  &CurOptions.szCOM0R20M_Cfg_File        ,
  sizeof(CurOptions.szCOM0R20M_Cfg_File) ,
  "<Filename|stdout>  Destination File"  ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_Img[]={
  {
  &CurOptions.CreateCOM0R20M.InFile       ,
  sizeof(CurOptions.CreateCOM0R20M.InFile) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.CreateCOM0R20M.OutFile        ,
  sizeof(CurOptions.CreateCOM0R20M.OutFile) ,
  "<Filename>  Destination File"         ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_EEP[]={
  {
  &CurOptions.szCOM0R20M_S2Cfg_File        ,
  sizeof(CurOptions.szCOM0R20M_S2Cfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
};
ArgDesc_t  COM0R20CB_Cfg[]={
  {
  &CurOptions.szCOM0R20CB_Cfg_File       ,
  sizeof(CurOptions.szCOM0R20CB_Cfg_File),
  "<Filename|stdout>  Destination File"  ,
  StringArg
  },
};
ArgDesc_t  COM0R20CB_Img[]={
  {
  &CurOptions.CreateCOM0R20CB.InFile       ,
  sizeof(CurOptions.CreateCOM0R20CB.InFile) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.CreateCOM0R20CB.OutFile       ,
  sizeof(CurOptions.CreateCOM0R20CB.OutFile),
  "<Filename>  Destination File"          ,
  StringArg
  },
};
ArgDesc_t  COM0R20CB_EEP[]={
  {
  &CurOptions.szCOM0R20CB_S2Cfg_File        ,
  sizeof(CurOptions.szCOM0R20CB_S2Cfg_File) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_Cfg[]={
  {
  &CurOptions.szEeePExpEEP_Cfg_File        ,
  sizeof(CurOptions.szEeePExpEEP_Cfg_File) ,
  "<Filename|stdout>  Destination File"  ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_Img[]={
  {
  &CurOptions.CreateEeePExpEEP.InFile       ,
  sizeof(CurOptions.CreateEeePExpEEP.InFile) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.CreateEeePExpEEP.OutFile       ,
  sizeof(CurOptions.CreateEeePExpEEP.OutFile) ,
  "<Filename>  Destination File"            ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_EEP[]={
  {
  &CurOptions.CreateEeePExpEEP_EEP.FileName   ,
  sizeof(CurOptions.CreateEeePExpEEP_EEP.FileName) ,
  "<Filename>  Configuration Filename"   ,
  StringArg
  },
  {
  &CurOptions.CreateEeePExpEEP_EEP.I2CBus     ,
  sizeof(CurOptions.CreateEeePExpEEP_EEP.I2CBus),
  "<EApi Id>      EApi Bus Id"             ,
  NumberArg
  },
  {
  &CurOptions.CreateEeePExpEEP_EEP.I2CDevAddr     ,
  sizeof(CurOptions.CreateEeePExpEEP_EEP.I2CDevAddr),
  "<I2C Address>  EEPROM Device Address"   ,
  NumberArg
  },
};
ArgDesc_t  EeePExpEEP_PEEP[]={
  {
  &CurOptions.ProgramEeePExpEEP_EEP.FileName   ,
  sizeof(CurOptions.ProgramEeePExpEEP_EEP.FileName) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
  {
  &CurOptions.ProgramEeePExpEEP_EEP.I2CBus   ,
  sizeof(CurOptions.ProgramEeePExpEEP_EEP.I2CBus) ,
  "<EApi Id>      EApi Bus Id"             ,
  NumberArg
  },
  {
  &CurOptions.ProgramEeePExpEEP_EEP.I2CDevAddr   ,
  sizeof(CurOptions.ProgramEeePExpEEP_EEP.I2CDevAddr) ,
  "<I2C Address>  EEPROM Device Address"   ,
  NumberArg
  },
};
ArgDesc_t  COM0R20CB_IMG[]={
  {
  &CurOptions.szCOM0R20CBEEP_To_Img_FName        ,
  sizeof(CurOptions.szCOM0R20CBEEP_To_Img_FName) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_IMG[]={
  {
  &CurOptions.szCOM0R20MEEP_To_Img_FName        ,
  sizeof(CurOptions.szCOM0R20MEEP_To_Img_FName) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  EeePExpEEP_IMG[]={
  {
  &CurOptions.StoreEeePExpEEP_EEP.FileName   ,
  sizeof(CurOptions.StoreEeePExpEEP_EEP.FileName) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
  {
  &CurOptions.StoreEeePExpEEP_EEP.I2CBus     ,
  sizeof(CurOptions.StoreEeePExpEEP_EEP.I2CBus),
  "<EApi Id>      EApi Bus Id"             ,
  NumberArg
  },
  {
  &CurOptions.StoreEeePExpEEP_EEP.I2CDevAddr     ,
  sizeof(CurOptions.StoreEeePExpEEP_EEP.I2CDevAddr),
  "<I2C Address>  EEPROM Device Address"   ,
  NumberArg
  },
};
ArgDesc_t  COM0R20CB_PEEP[]={
  {
  &CurOptions.szCOM0R20CB_SBIN_File        ,
  sizeof(CurOptions.szCOM0R20CB_SBIN_File) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  COM0R20M_PEEP[]={
  {
  &CurOptions.szCOM0R20M_SBIN_File        ,
  sizeof(CurOptions.szCOM0R20M_SBIN_File) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  GEN_LIST_DBLOCKS_FILE[]={
  {
  &CurOptions.szGEN_List_DBlocks_File        ,
  sizeof(CurOptions.szGEN_List_DBlocks_File) ,
  "<Filename>  Binary Image Filename"       ,
  StringArg
  },
};
ArgDesc_t  GEN_LIST_DBLOCKS_EEP[]={
  {
  &CurOptions.ulEEP_Img.I2CBus                ,
  sizeof(CurOptions.ulEEP_Img.I2CBus)         ,
  "<EApi Id>      EApi Bus Id"                ,
  NumberArg
  },
  {
  &CurOptions.ulEEP_Img.I2CDevAddr            ,
  sizeof(CurOptions.ulEEP_Img.I2CDevAddr)     ,
  "<I2C Address>  EEPROM Device Address"      ,
  NumberArg
  },
};

EApiStatus_t
CreateTxtFilePtr(
    const char *Destination,
    FILE **     FilePtr
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  if(!strcmp(Destination, "stdout")){
     *FilePtr=stdout;
  }else if(!strcmp(Destination, "&1")){
     *FilePtr=stdout;
  }else if(!strcmp(Destination, "stderr")){
     *FilePtr=stderr;
  }else if(!strcmp(Destination, "&2")){
     *FilePtr=stderr;
  }else {
    *FilePtr=fopen(Destination, "w");
    EAPI_APP_RETURN_ERROR_IF_S(
         CreateTxtFilePtr,
         (*FilePtr==NULL),
         EAPI_STATUS_WRITE_ERROR
      );
  }
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
FreeFilePtr(
    FILE **     FilePtr
    )
{
  FILE *     LclFilePtr=*FilePtr;
  if(LclFilePtr!=stdout&&LclFilePtr!=stderr&&LclFilePtr!=NULL){
    fclose(LclFilePtr);
  };
  *FilePtr=NULL;
  return EAPI_STATUS_SUCCESS;
}
#define FREE_BUFFER(x) \
      if(x!=NULL){\
          free(x);\
          x=NULL;\
      }

EApiStatus_t 
CMD_CreateCOM0R20_MEEPCfg(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  FILE *lclStream=NULL;

  DO(CreateTxtFilePtr(*(char**)pArgData, &lclStream));
  DO(EeeP_CreateCOM0R20_MEEPCfg(lclStream));

EAPI_APP_ASSERT_EXIT
  FreeFilePtr(&lclStream);
  return StatusCode;
}
EApiStatus_t 
CMD_CreateCOM0R20_CBCfg(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  FILE *lclStream=NULL;

  DO(CreateTxtFilePtr(*(char**)pArgData, &lclStream));
  DO(EeeP_CreateCOM0R20_CBCfg(lclStream));

EAPI_APP_ASSERT_EXIT
  FreeFilePtr(&lclStream);
  return StatusCode;
}
EApiStatus_t 
CMD_CreateCOM0R20_EeePExtCfg(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  FILE *lclStream=NULL;

  DO(CreateTxtFilePtr(*(char**)pArgData, &lclStream));
  DO(EeeP_CreateEeePExtEEPCfg(lclStream));

EAPI_APP_ASSERT_EXIT
  FreeFilePtr(&lclStream);
  return StatusCode;
}

EApiStatus_t 
CMD_CreateCOM0R20CB_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeeP_CreateCOM0R20_CBImage(
        &BHandel                              ,
        *(char**)pArgData
      ));
  DO(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}

EApiStatus_t 
CMD_CreateCOM0R20M_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeeP_CreateCOM0R20_MEEPImage(
        &BHandel                              ,
        *(char**)pArgData
      ));
  DO(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}

EApiStatus_t 
CMD_CreateEeePExt_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeeP_CreateEeePExtEEPImage(
        &BHandel                              ,
        ((WriteEepCfg_t*)pArgData)->FileName
      ));
  DO(EeePWriteBufferToEEP(BHandel, 
        (uint16_t)((WriteEepCfg_t*)pArgData)->I2CBus, 
        (uint16_t)((WriteEepCfg_t*)pArgData)->I2CDevAddr
        )
      );

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}


EApiStatus_t 
CMD_ProgramCOM0R20CB_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeePReadBufferFromFile(
        &BHandel                              ,
        *(char**)pArgData
      ));
  if(memcmp(((COM0R20_CB_t *)BHandel)->GenId, COM0R20_CB_HEADER_ID, sizeof(COM0R20_CB_HEADER_ID)-1)){
    EAPI_APP_RETURN_ERROR(
        CMD_ProgramCOM0R20CB_EEP,
        EAPI_STATUS_ERROR,
        "Not Valid COM0 R2.0 Carrier Board Image"
      );
  }
  DO(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}

EApiStatus_t 
CMD_ProgramCOM0R20M_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeePReadBufferFromFile(
        &BHandel                              ,
        *(char**)pArgData
      ));
  if(memcmp(((COM0R20_M_t *)BHandel)->GenId, COM0R20_M_HEADER_ID, sizeof(COM0R20_M_HEADER_ID)-1)){
    EAPI_APP_RETURN_ERROR(
        CMD_ProgramCOM0R20M_EEP,
        EAPI_STATUS_ERROR,
        "Not Valid COM0 R2.0 Module Image"
      );
  }
  DO(EeePWriteBufferToEEP(BHandel, EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}


EApiStatus_t 
CMD_ProgramEeePExt_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeePReadBufferFromFile(
        &BHandel                              ,
        ((WriteEepCfg_t*)pArgData)->FileName
      ));
  if(memcmp(((Exp_EEP_t *)BHandel)->GenId, EEEP_EXP_HEADER_ID, sizeof(EEEP_EXP_HEADER_ID)-1)){
    EAPI_APP_RETURN_ERROR(
        CMD_ProgramEeePExt_EEP,
        EAPI_STATUS_ERROR,
        "Not Valid EeeP Extended EEP Image"
      );
  }
  DO(EeePWriteBufferToEEP(
          BHandel, 
          (uint16_t)((WriteEepCfg_t*)pArgData)->I2CBus, 
          (uint16_t)((WriteEepCfg_t*)pArgData)->I2CDevAddr
      ));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}

EApiStatus_t 
CMD_StoreEeePExt_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;
  DO(EeePReadBufferFromEEP(
          &BHandel, 
          (uint16_t)((WriteEepCfg_t*)pArgData)->I2CBus, 
          (uint16_t)((WriteEepCfg_t*)pArgData)->I2CDevAddr
      ));
  DO(EeePWriteBufferToFile(BHandel, ((WriteEepCfg_t*)pArgData)->FileName));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}

EApiStatus_t 
CMD_StoreCOM0R20_CB_EEP(
    void *pArgData
    )
{
  WriteEepCfg_t WriteEep={NULL, EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR};
  WriteEep.FileName=*(char**)pArgData;
  return CMD_StoreEeePExt_EEP(&WriteEep);
}

EApiStatus_t 
CMD_StoreCOM0R20_M_EEP(
    void *pArgData
    )
{
  WriteEepCfg_t WriteEep={NULL, EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR};
  WriteEep.FileName=*(char**)pArgData;
  return CMD_StoreEeePExt_EEP(&WriteEep);
}

EApiStatus_t 
CMD_ListDBlocksEeePExt_EEP(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;
  DO(EeePReadBufferFromEEP(
          &BHandel, 
          (uint16_t)((I2CAddrCfg_t*)pArgData)->I2CBus, 
          (uint16_t)((I2CAddrCfg_t*)pArgData)->I2CDevAddr
      ));
  DO(EeePListBlocks( BHandel, 0));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}


EApiStatus_t 
CMD_ListDBlocksCOM0R20_CB_EEP(
    void *pArgData
    )
{
  I2CAddrCfg_t DevDesc={EAPI_ID_I2C_EXTERNAL, COM0R20_CB_EEP_DEV_ADDR};
  pArgData=pArgData;
  return CMD_ListDBlocksEeePExt_EEP(&DevDesc);
}
EApiStatus_t 
CMD_ListDBlocksCOM0R20_M_EEP(
    void *pArgData
    )
{
  I2CAddrCfg_t DevDesc={EAPI_ID_I2C_EXTERNAL, COM0R20_M_EEP_DEV_ADDR};
  pArgData=pArgData;
  return CMD_ListDBlocksEeePExt_EEP(&DevDesc);
}

EApiStatus_t 
CMD_CreateExtEepEEP_IMG(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeeP_CreateEeePExtEEPImage(
        &BHandel                              ,
        ((InOutFiles_t*)pArgData)->InFile
      ));
  DO(EeePWriteBufferToFile(BHandel, ((InOutFiles_t*)pArgData)->OutFile));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}
EApiStatus_t 
CMD_CreateCOM0R20M_IMG(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeeP_CreateCOM0R20_MEEPImage(
        &BHandel                              ,
        ((InOutFiles_t*)pArgData)->InFile
      ));
  DO(EeePWriteBufferToFile(BHandel, ((InOutFiles_t*)pArgData)->OutFile));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}
EApiStatus_t 
CMD_CreateCOM0R20CB_IMG(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeeP_CreateCOM0R20_CBImage(
        &BHandel                              ,
        ((InOutFiles_t*)pArgData)->InFile
      ));
  DO(EeePWriteBufferToFile(BHandel, ((InOutFiles_t*)pArgData)->OutFile));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}

EApiStatus_t 
CMD_ListDBlocks_IMG(
    void *pArgData
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t BHandel=NULL;

  DO(EeePReadBufferFromFile(
        &BHandel                              ,
        *(char**)pArgData
      ));
  DO(EeePListBlocks( BHandel, 0));

EAPI_APP_ASSERT_EXIT
  EeePFreeBuffer(&BHandel);
  return StatusCode;
}



CmdDesc_t ArgsDesc[]={
  {
    'q'                                             , 
    "quiet"                                         , 
    &CurOptions.uiQuiet                             , 
    "Minimises Output"                              , 
    NULL                                            ,
    0                                               ,
    NULL                                            ,
    NULL
  },
  {
    'h'                                             , 
    "help"                                          , 
    &CurOptions.uiHelp                              , 
    "Print this usage message"                      , 
    NULL                                            ,
    0                                               ,
    NULL                                            ,
    NULL
  },
  {
    '?'                                             , 
    NULL                                            , 
    &CurOptions.uiHelp                              , 
    "Print this usage message"                      , 
    NULL                                            ,
    0                                               ,
    NULL                                            ,
    NULL
  },
  {
    'v'                                             , 
    "verbose"                                       , 
    &CurOptions.uiVerbose                           , 
    "Increases Verbosity Level"                     , 
    NULL                                            ,
    0                                               ,
    NULL                                            ,
    NULL
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-CFG"                           , 
    &CurOptions.uiCreateCOM0R20M_CFG                , 
    "Create COM0 Module Config File Template"       , 
    COM0R20M_Cfg                                    ,
    ARRAY_SIZE(COM0R20M_Cfg)                        ,
    &CurOptions.szCOM0R20M_Cfg_File                 ,
    CMD_CreateCOM0R20_MEEPCfg
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-IMG"                           , 
    &CurOptions.uiCreateCOM0R20M_IMG                , 
    "Create COM0 Module Binary File"                , 
    COM0R20M_Img                                    ,
    ARRAY_SIZE(COM0R20M_Img)                        ,
    &CurOptions.CreateCOM0R20M                      ,
    CMD_CreateCOM0R20M_IMG
  },
  {
    0x00                                            , 
    "CREATE-COM0R20M-EEP"                           , 
    &CurOptions.uiCreateCOM0R20M_EEP                , 
    "Create COM0 Module Content and Program over EApi", 
    COM0R20M_EEP                                    ,
    ARRAY_SIZE(COM0R20M_EEP)                        ,
    &CurOptions.szCOM0R20M_S2Cfg_File               ,
    CMD_CreateCOM0R20M_EEP
  },
  {
    0x00, 
    "CREATE-COM0R20CB-CFG" , 
    &CurOptions.uiCreateCOM0R20CB_CFG               , 
    "Create COM0 Carrier Config File Template"      , 
    COM0R20CB_Cfg                                   ,
    ARRAY_SIZE(COM0R20CB_Cfg)                       ,
    &CurOptions.szCOM0R20CB_Cfg_File                ,
    CMD_CreateCOM0R20_CBCfg
  },
  {
    0x00                                            , 
    "CREATE-COM0R20CB-EEP"                          , 
    &CurOptions.uiCreateCOM0R20CB_EEP               , 
    "Create COM0 Carrier Content and Program over EApi", 
    COM0R20CB_EEP                                   ,
    ARRAY_SIZE(COM0R20CB_EEP)                       ,
    &CurOptions.szCOM0R20CB_S2Cfg_File              ,
    CMD_CreateCOM0R20CB_EEP
  },
  {
    0x00                                            , 
    "CREATE-COM0R20CB-IMG"                          , 
    &CurOptions.uiCreateCOM0R20CB_IMG               , 
    "Create COM0 Carrier Binary File"               , 
    COM0R20CB_Img                                   ,
    ARRAY_SIZE(COM0R20CB_Img)                       ,
    &CurOptions.CreateCOM0R20CB                     ,
    CMD_CreateCOM0R20CB_IMG
  },
  {
    0x00                                            , 
    "CREATE-EeePExpEEP-CFG"                         , 
    &CurOptions.uiCreateEeePExpEEP_CFG              , 
    "Create EeeP Expansion EEP Config File Template", 
    EeePExpEEP_Cfg                                  ,
    ARRAY_SIZE(EeePExpEEP_Cfg)                      ,
    &CurOptions.szEeePExpEEP_Cfg_File               ,
    CMD_CreateCOM0R20_EeePExtCfg
  },
  {
    0x00                                            , 
    "CREATE-EeePExpEEP-IMG"                         , 
    &CurOptions.uiCreateEeePExpEEP_IMG              , 
    "Create EeeP Expansion EEP Binary File"         , 
    EeePExpEEP_Img                                  ,
    ARRAY_SIZE(EeePExpEEP_Img)                      ,
    &CurOptions.CreateEeePExpEEP                    ,
    CMD_CreateExtEepEEP_IMG
  },
  {
    0x00                                            , 
    "CREATE-EeePExpEEP-EEP"                         , 
    &CurOptions.uiCreateEeePExpEEP_EEP              , 
    "Create EeeP Expansion EEP Image and Program over EApi", 
    EeePExpEEP_EEP                                  ,
    ARRAY_SIZE(EeePExpEEP_EEP)                      ,
    &CurOptions.CreateEeePExpEEP_EEP                ,
    CMD_CreateEeePExt_EEP
  },
  {
    0x00                                            , 
    "PROGRAM-EeePExpEEP-EEP"                        , 
    &CurOptions.uiProgramEeePExpEEP_EEP             , 
    "Program EeeP Expansion EEP Image file over EApi", 
    EeePExpEEP_PEEP                                 ,
    ARRAY_SIZE(EeePExpEEP_PEEP)                     ,
    &CurOptions.ProgramEeePExpEEP_EEP               ,
    CMD_ProgramEeePExt_EEP
  },
  {
    0x00                                            , 
    "PROGRAM-COM0R20CB-EEP"                         , 
    &CurOptions.uiProgramCOM0R20CB_EEP              , 
    "Program COM0 R2.0 Carrier Board EEP Image file over EApi", 
    COM0R20CB_PEEP                                  ,
    ARRAY_SIZE(COM0R20CB_PEEP)                      ,
    &CurOptions.szCOM0R20CB_SBIN_File               ,
    CMD_ProgramCOM0R20CB_EEP
  },
  {
    0x00                                            , 
    "PROGRAM-COM0R20M-EEP"                          , 
    &CurOptions.uiProgramCOM0R20M_EEP               , 
    "Program COM0 R2.0 Module EEP Image file over EApi", 
    COM0R20M_PEEP                                   ,
    ARRAY_SIZE(COM0R20M_PEEP)                       ,
    &CurOptions.szCOM0R20M_SBIN_File                ,
    CMD_ProgramCOM0R20M_EEP
  },
  {
    0x00                                                , 
    "SAVE-EeePExpEEP-IMG"                               , 
    &CurOptions.uiStoreEeePExpEEP_EEP                   , 
    "Stores EeeP Expansion EEP to Image file over EApi" , 
    EeePExpEEP_IMG                                      ,
    ARRAY_SIZE(EeePExpEEP_IMG)                          ,
    &CurOptions.StoreEeePExpEEP_EEP                     ,
    CMD_StoreEeePExt_EEP
  },
  {
    0x00                                                , 
    "SAVE-COM0R20CB-IMG"                                , 
    &CurOptions.uiStoreCOM0R20CB_EEP                    ,
    "Stores COM0 R2.0 Carrier Board EEP to Image file over EApi", 
    COM0R20CB_IMG                                       ,
    ARRAY_SIZE(COM0R20CB_IMG )                          ,
    &CurOptions.szCOM0R20CBEEP_To_Img_FName             ,
    CMD_StoreCOM0R20_CB_EEP
  },
  {
    0x00                                                ,
    "SAVE-COM0R20M-IMG"                                 ,
    &CurOptions.uiStoreCOM0R20M_EEP                     ,
    "Stores COM0 R2.0 Module EEP to Image file over EApi", 
    COM0R20M_IMG                                        ,
    ARRAY_SIZE(COM0R20M_IMG)                            ,
    &CurOptions.szCOM0R20MEEP_To_Img_FName              ,
    CMD_StoreCOM0R20_M_EEP
  },
  {
    0x00                                            , 
    "LIST-DBLOCKS-IMG"                              , 
    &CurOptions.uiListDBlocks_IMG                   , 
    "Lists Dynamic Blocks in Binary Image file"     , 
    GEN_LIST_DBLOCKS_FILE                           ,
    ARRAY_SIZE(GEN_LIST_DBLOCKS_FILE)               ,
    &CurOptions.szGEN_List_DBlocks_File             ,
    CMD_ListDBlocks_IMG
  },
  {
    0x00                                            , 
    "LIST-DBLOCKS-EEP"                              , 
    &CurOptions.uiListDBlocks_EEP                   , 
    "Lists Dynamic Blocks in Binary Image file"     , 
    GEN_LIST_DBLOCKS_EEP                            ,
    ARRAY_SIZE(GEN_LIST_DBLOCKS_EEP)                ,
    &CurOptions.ulEEP_Img                           ,
    CMD_ListDBlocksEeePExt_EEP
  },
  {
    0x00                                            , 
    "LIST-DBLOCKS-COM0R20CBEEP"                     , 
    &CurOptions.uiListDBlocks_COM0R20_CB_EEP        , 
    "Lists Dynamic Blocks in COM0 R2.0 Carrier Board EEPROM", 
    NULL                                            ,
    0                                               ,
    NULL                                            ,
    CMD_ListDBlocksCOM0R20_CB_EEP                                
  },
  {
    0x00                                              , 
    "LIST-DBLOCKS-COM0R20MEEP"                        , 
    &CurOptions.uiListDBlocks_COM0R20_M_EEP           , 
    "Lists Dynamic Blocks in COM0 R2.0 Module EEPROM" , 
    NULL                                              ,
    0                                                 ,
    NULL                                              ,
    CMD_ListDBlocksCOM0R20_M_EEP                                 
  },
};

  




#define DO_MAIN(x) \
  StatusCode=x;\
  if(!EAPI_TEST_SUCCESS(StatusCode)){ \
    EAPI_FORMATED_MES('E', main, StatusCode, #x);\
    goto ExitPoint;\
  }

/*
 * Create Block Content
 */
int 
__cdecl 
main(
    signed int argc,
    const char **argv
  )
{
  EApiStatus_t StatusCode;

  DO_MAIN(EApiLibInitialize());

  StatusCode=ParseArgs(argc - 1, argv + 1, ArgsDesc, ARRAY_SIZE(ArgsDesc));
  switch(StatusCode){
    case EAPI_STATUS_INVALID_PARAMETER:
      printf("%s", syntaxErrMes);
      exit(StatusCode);
      break;
    case EAPI_STATUS_SUCCESS:
      break;
    default:
      EAPI_FORMATED_MES('E', main, StatusCode, "ParseArgs(argc, argv, ArgsDesc, ARRAY_SIZE(ArgsDesc))");
      exit(StatusCode);
      break;
  }

  if(!CurOptions.uiQuiet){
    fprintf(stderr, cszTitle, APP_VERSION, APP_REVISION, APP_BUILD);
  }

  if(CurOptions.uiHelp){
    PrintUsage(stderr, ArgsDesc, ARRAY_SIZE(ArgsDesc));
    goto ErrorExit;
  }
  /*
   *
   */
  
ErrorExit:
EAPI_APP_ASSERT_EXIT
  DO_MAIN(EApiLibUnInitialize());
  exit(StatusCode);
}
