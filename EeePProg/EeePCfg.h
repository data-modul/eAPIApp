/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/EeePCfg.h $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2010, Kontron Embedded Modules GmbH
 *I      Author: John Kearney,                  John.Kearney@kontron.com
 *I
 *I     License: This program contains proprietary and confidential 
 *I              information. All rights reserved except as may be 
 *I              permitted by prior written consent.
 *I
 *I Description: Auto Created for EeePCfg.c
 *I
 *+-------------------------------------------------------------------------
 *I
 *I  File Name            : EeePCfg.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: EeePCfg.h 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __EEEPCFG_H__
#define __EEEPCFG_H__

#ifdef __cplusplus
extern "C" {
#endif

EApiStatus_t
EeeP_CreateCOM0R20_CBImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    );

EApiStatus_t
EeeP_CreateCOM0R20_MEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    );

EApiStatus_t
EeeP_CreateEeePExtEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    );

EApiStatus_t
EeeP_CreateCOM0R20_CBCfg(
    __OUT  FILE           * OutStream
    );

EApiStatus_t
EeeP_CreateCOM0R20_MEEPCfg(
    __OUT  FILE           * OutStream
    );

EApiStatus_t
EeeP_CreateEeePExtEEPCfg(
    __OUT  FILE           * OutStream
    );

extern TokenListDesc_t SmbiosStructureTypesTL;
extern TokenListDesc_t SmbiosBoardTypesTL;
extern TokenListDesc_t SmbiSmbiosModuleFeatureFlagsTL;
extern TokenListDesc_t SmbiosChassisTypesTL;
extern TokenListDesc_t IRQTL;
extern TokenListDesc_t I2CBusTL;
extern TokenListDesc_t DDI1TL;
extern TokenListDesc_t DisplayInterfaceTL;
extern TokenListDesc_t ImpNotImpTL;
extern TokenListDesc_t SasTL;

extern TokenDesc_t PCIeGeneration[];
extern TokenDesc_t PCIeLaneWidths[];
#ifdef __cplusplus
}
#endif
#endif /* __EEEPCFG_H__ */
