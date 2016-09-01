/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/EeePArg.h $
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
 *I  File Name            : EeePArg.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 60 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-02-28 21:53:20 +0100 (Sun, 28 Feb 2010) $
 *I  ID                   : $Id: EeePArg.h 60 2010-02-28 20:53:20Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __EEEPARG_H__
#define __EEEPARG_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct I2CAddrCfg_s{
  unsigned long I2CBus;
  unsigned long I2CDevAddr;
}I2CAddrCfg_t;

typedef struct WriteEepCfg_s{
  char *FileName;
  unsigned long I2CBus;
  unsigned long I2CDevAddr;
}WriteEepCfg_t;

typedef struct InOutFiles_s{
  char *InFile;
  char *OutFile;
}InOutFiles_t;

typedef struct Options_s{
  unsigned int uiHelp;
  unsigned int uiQuiet;
  unsigned int uiVerbose;
  unsigned int uiCreateCOM0R20M_CFG;
  char  *szCOM0R20M_Cfg_File;
  unsigned int uiCreateCOM0R20M_IMG;
    InOutFiles_t CreateCOM0R20M;
  
  unsigned int uiCreateCOM0R20M_EEP;
    char  *szCOM0R20M_S2Cfg_File;
  
  unsigned int uiCreateCOM0R20CB_CFG;
    char  *szCOM0R20CB_Cfg_File;
  
  unsigned int uiCreateCOM0R20CB_IMG;
    InOutFiles_t CreateCOM0R20CB;
  
  unsigned int uiCreateCOM0R20CB_EEP;
    char  *szCOM0R20CB_S2Cfg_File;

  unsigned int uiCreateEeePExpEEP_CFG;
    char  *szEeePExpEEP_Cfg_File;
  
  unsigned int uiCreateEeePExpEEP_IMG;
    InOutFiles_t CreateEeePExpEEP;
  
  unsigned int uiCreateEeePExpEEP_EEP;
    WriteEepCfg_t CreateEeePExpEEP_EEP;
  
  unsigned int uiProgramEeePExpEEP_EEP;
    WriteEepCfg_t ProgramEeePExpEEP_EEP;
  
  unsigned int uiProgramCOM0R20CB_EEP;
    char  *szCOM0R20CB_SBIN_File;
  
  unsigned int uiProgramCOM0R20M_EEP;
    char  *szCOM0R20M_SBIN_File;
  
  unsigned int uiListDBlocks_IMG;
    char  *szGEN_List_DBlocks_File;
  
  unsigned int uiListDBlocks_EEP;
    I2CAddrCfg_t  ulEEP_Img;
  
  unsigned int uiListDBlocks_COM0R20_CB_EEP;
  
  unsigned int uiListDBlocks_COM0R20_M_EEP;
  
  unsigned int uiStoreEeePExpEEP_EEP;
    WriteEepCfg_t StoreEeePExpEEP_EEP;
  
  unsigned int uiStoreCOM0R20CB_EEP;
    char  *        szCOM0R20CBEEP_To_Img_FName  ;
  
  unsigned int uiStoreCOM0R20M_EEP;
    char  *        szCOM0R20MEEP_To_Img_FName  ;
}Options_t;

extern Options_t CurOptions;

#ifdef __cplusplus
}
#endif
#endif /* __EEEPARG_H__ */
