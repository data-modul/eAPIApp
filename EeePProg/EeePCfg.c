/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/EeePCfg.c $
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
 *I  File Name            : EeePCfg.c
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 75 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-29 01:50:38 +0200 (Tue, 29 Jun 2010) $
 *I  ID                   : $Id: EeePCfg.c 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
  #include <EeePApp.h>

ElementHandler_t COM0PCIe_Element;
ElementHandler_t SMBIOS_CE_Element;

ElementHelpTxt_t COM0PCIe_Help;
ElementHelpTxt_t SMBIOS_CE_Help;
/*  */

Handlers_t  COM0PCIe_Element_funcs ={ COM0PCIe_Element , GenClear_Element , COM0PCIe_Help   , No_Default_Txt};
Handlers_t  SMBIOS_CE_Element_funcs={ SMBIOS_CE_Element, GenClear_Element , SMBIOS_CE_Help  , No_Default_Txt};

TokenDesc_t  SmbiosStructureTypesTokens[]={
  {"BIOS_INFORMATION"                               ,  SMBIOS_TypeBIOS_INFORMATION                    },
  {"SYSTEM_INFORMATION"                             ,  SMBIOS_TypeSYSTEM_INFORMATION                  },
  {"BASE_BOARD_(OR_MODULE)_INFORMATION"             ,  SMBIOS_TypeBASE_BOARD_MODULE_INFORMATION       },
  {"SYSTEM_ENCLOSURE_OR_CHASSIS"                    ,  SMBIOS_TypeSYSTEM_ENCLOSURE_OR_CHASSIS         },
  {"PROCESSOR_INFORMATION"                          ,  SMBIOS_TypePROCESSOR_INFORMATION               },
  {"MEMORY_CONTROLLER_INFORMATION"                  ,  SMBIOS_TypeMEMORY_CONTROLLER_INFORMATION       },
  {"MEMORY_MODULE_INFORMATION"                      ,  SMBIOS_TypeMEMORY_MODULE_INFORMATION           },
  {"CACHE_INFORMATION"                              ,  SMBIOS_TypeCACHE_INFORMATION                   },
  {"PORT_CONNECTOR_INFORMATION"                     ,  SMBIOS_TypePORT_CONNECTOR_INFORMATION          },
  {"SYSTEM_SLOTS"                                   ,  SMBIOS_TypeSYSTEM_SLOTS                        },
  {"ON_BOARD_DEVICES_INFORMATION"                   ,  SMBIOS_TypeON_BOARD_DEVICES_INFORMATION        },
  {"OEM_STRINGS"                                    ,  SMBIOS_TypeOEM_STRINGS                         },
  {"SYSTEM_CONFIGURATION_OPTIONS"                   ,  SMBIOS_TypeSYSTEM_CONFIGURATION_OPTIONS        },
  {"BIOS_LANGUAGE_INFORMATION"                      ,  SMBIOS_TypeBIOS_LANGUAGE_INFORMATION           },
  {"GROUP_ASSOCIATIONS"                             ,  SMBIOS_TypeGROUP_ASSOCIATIONS                  },
  {"SYSTEM_EVENT_LOG"                               ,  SMBIOS_TypeSYSTEM_EVENT_LOG                    },
  {"PHYSICAL_MEMORY_ARRAY"                          ,  SMBIOS_TypePHYSICAL_MEMORY_ARRAY               },
  {"MEMORY_DEVICE"                                  ,  SMBIOS_TypeMEMORY_DEVICE                       },
  {"32_BIT_MEMORY_ERROR_INFORMATION"                ,  SMBIOS_Type32_BIT_MEMORY_ERROR_INFORMATION     },
  {"MEMORY_ARRAY_MAPPED_ADDRESS"                    ,  SMBIOS_TypeMEMORY_ARRAY_MAPPED_ADDRESS         },
  {"MEMORY_DEVICE_MAPPED_ADDRESS"                   ,  SMBIOS_TypeMEMORY_DEVICE_MAPPED_ADDRESS        },
  {"BUILT_IN_POINTING_DEVICE"                       ,  SMBIOS_TypeBUILT_IN_POINTING_DEVICE            },
  {"PORTABLE_BATTERY"                               ,  SMBIOS_TypePORTABLE_BATTERY                    },
  {"SYSTEM_RESET"                                   ,  SMBIOS_TypeSYSTEM_RESET                        },
  {"HARDWARE_SECURITY"                              ,  SMBIOS_TypeHARDWARE_SECURITY                   },
  {"SYSTEM_POWER_CONTROLS"                          ,  SMBIOS_TypeSYSTEM_POWER_CONTROLS               },
  {"VOLTAGE_PROBE"                                  ,  SMBIOS_TypeVOLTAGE_PROBE                       },
  {"COOLING_DEVICE"                                 ,  SMBIOS_TypeCOOLING_DEVICE                      },
  {"TEMPERATURE_PROBE"                              ,  SMBIOS_TypeTEMPERATURE_PROBE                   },
  {"ELECTRICAL_CURRENT_PROBE"                       ,  SMBIOS_TypeELECTRICAL_CURRENT_PROBE            },
  {"OUT_OF_BAND_REMOTE_ACCESS"                      ,  SMBIOS_TypeOUT_OF_BAND_REMOTE_ACCESS           },
  {"BOOT_INTEGRITY_SERVICES_(BIS)_ENTRY_POINT"      ,  SMBIOS_TypeBOOT_INTEGRITY_SERVICES_ENTRY_POINT },
  {"SYSTEM_BOOT_INFORMATION"                        ,  SMBIOS_TypeSYSTEM_BOOT_INFORMATION             },
  {"64_BIT_MEMORY_ERROR_INFORMATION"                ,  SMBIOS_Type64_BIT_MEMORY_ERROR_INFORMATION     },
  {"MANAGEMENT_DEVICE"                              ,  SMBIOS_TypeMANAGEMENT_DEVICE                   },
  {"MANAGEMENT_DEVICE_COMPONENT"                    ,  SMBIOS_TypeMANAGEMENT_DEVICE_COMPONENT         },
  {"MANAGEMENT_DEVICE_THRESHOLD_DATA"               ,  SMBIOS_TypeMANAGEMENT_DEVICE_THRESHOLD_DATA    },
  {"MEMORY_CHANNEL"                                 ,  SMBIOS_TypeMEMORY_CHANNEL                      },
  {"IPMI_DEVICE_INFORMATION"                        ,  SMBIOS_TypeIPMI_DEVICE_INFORMATION             },
  {"SYSTEM_POWER_SUPPLY"                            ,  SMBIOS_TypeSYSTEM_POWER_SUPPLY                 },
  {"INACTIVE"                                       ,  SMBIOS_TypeINACTIVE                            },
  {"END_OF_TABLE"                                   ,  SMBIOS_TypeEND_OF_TABLE                        },
};
PCFG_TOKEN_LIST_DESC(SmbiosStructureTypesTL, SmbiosStructureTypesTokens);

TokenDesc_t  SmbiosBoardTypesTokens[]={
  {"Unknown"	                , SMBIOS_BoardType_Unknown                },
  {"Other"	                	, SMBIOS_BoardType_Other                  },
  {"ServerBlade"	        	, SMBIOS_BoardType_ServerBlade            },
  {"ConnectivitySwitch"	        , SMBIOS_BoardType_ConnectivitySwitch     },
  {"SystemManagementModule"     , SMBIOS_BoardType_SystemManagementModule },
  {"ProcessorModule"	        , SMBIOS_BoardType_ProcessorModule        },
  {"IO_Module"	                , SMBIOS_BoardType_IO_Module              },
  {"Memory_Module"	        	, SMBIOS_BoardType_Memory_Module          },
  {"DaughterBoard"	        	, SMBIOS_BoardType_DaughterBoard          },
  {"Motherboard"	        	, SMBIOS_BoardType_Motherboard            },
  {"ProcessorMemory_Module"		, SMBIOS_BoardType_ProcessorMemory_Module },
  {"Interconnect_Board"	        , SMBIOS_BoardType_Interconnect_Board     },
};
PCFG_TOKEN_LIST_DESC(SmbiosBoardTypesTL, SmbiosBoardTypesTokens);

EApiStatus_t
SMBIOS_CE_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  unsigned int i;
  int len=0;
  pElementDesc=pElementDesc;
  len+=EApiSprintfA(szHelpBuf+len , stHBufLen-len , 
      "SMBios Contained Element Description\n"
      "  Format:\n"
      "    Element Type, Minimum Count, Maximum Count\n"
      "  Examples:\n"
      "    SYSTEM_POWER_SUPPLY,  1, 1\n"
      "    ServerBlade        ,  1, 5\n"
      "  Element Type Tokens:\n"  );
  for(i=0;i<ARRAY_SIZE(SmbiosBoardTypesTokens);i++){
    len+=EApiSprintfA(szHelpBuf+len , stHBufLen-len ,
                "     %s\n", SmbiosBoardTypesTokens[i].pszTokenList);
  }
  for(i=0;i<ARRAY_SIZE(SmbiosStructureTypesTokens);i++){
    len+=EApiSprintfA(szHelpBuf+len , stHBufLen-len ,
                "     %s\n", SmbiosStructureTypesTokens[i].pszTokenList);
  }
  len+=EApiSprintfA(szHelpBuf+len , stHBufLen-len ,
              "  Minimum Count:\n"
              "    0 - 255     \n"
              "  Maximum Count:\n"
              "    0 - 255     \n");
  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t
SMBIOS_CE_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void   *pElement,
    char   *pszValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  CCElement_t *pCurElement=pElement;
  char *pszCEType, *pszMinCount, *pszMaxCount;
  unsigned long uiCEType, uiMinCount, uiMaxCount;
  pszCEType=pszValue;
  pElementDesc=pElementDesc;

  pszMinCount=strchr(pszCEType, ',');
  if(pszMinCount==NULL ){
    StatusCode=EAPI_STATUS_ERROR;
    EAPI_APP_EXIT;
  }
  *pszMinCount++='\0';
  
  pszMaxCount=strchr(pszMinCount, ',');
  if(pszMaxCount==NULL ){
    StatusCode=EAPI_STATUS_ERROR;
    EAPI_APP_EXIT;
  }
  *pszMaxCount++='\0';

  StatusCode=GetTokenValueStrip(
      &SmbiosStructureTypesTL, 
      pszCEType, 
      &uiCEType
    );
  if(!EAPI_TEST_SUCCESS(StatusCode))
    StatusCode=GetTokenValueStrip(
        &SmbiosBoardTypesTL, 
        pszCEType, 
        &uiCEType
      );
  else
    uiCEType|=0x80;

  if(!EAPI_TEST_SUCCESS(StatusCode)){
    printf("SMBIOS_CE_Element = Unknown Token, %s\n", pszValue);
    EAPI_APP_EXIT;
  }

  uiMinCount=ulConvertStr2NumEx(pszMinCount, NULL                  );
  uiMaxCount=ulConvertStr2NumEx(pszMaxCount, NULL                  );
  if(uiMinCount>UINT8_MAX){
    printf("SMBIOS_CE_Element = Invalid MinCount, %s\n", pszMinCount);
    StatusCode=EAPI_STATUS_ERROR;
    EAPI_APP_EXIT;
  }
  if(uiMaxCount>UINT8_MAX){
    printf("SMBIOS_CE_Element = Invalid MaxCount, %s\n", pszMaxCount);
    StatusCode=EAPI_STATUS_ERROR;
    EAPI_APP_EXIT;
  }


  pCurElement->ElementType=(uint8_t)uiCEType;
  pCurElement->MinNum=(uint8_t)uiMinCount;
  pCurElement->MaxNum=(uint8_t)uiMaxCount;
/*   PrintHexAsciiTableEx( */
/*       pCurElement,  */
/*       3,  */
/*       pCurElement,  */
/*       NULL, */
/*       HEXTBL_8BIT_ELEMENT|3 */
/*     ); */
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}



TokenDesc_t  PCIeLaneWidths[]={
  {"x1"	, 1  },
  {"x2"	, 2  },
  {"x4"	, 3  },
  {"x8"	, 4  },
  {"x16", 5  },
  {"x32", 6  },
};
PCFG_TOKEN_LIST_DESC(PCIeLaneWidthsTL, PCIeLaneWidths);

TokenDesc_t  PCIeGeneration[]={
  {"Gen1"	, COM0R20_PCIe_GEN1  },
  {"Gen2"	, COM0R20_PCIe_GEN2  },
  {"Gen3"	, COM0R20_PCIe_GEN3  },
};
PCFG_TOKEN_LIST_DESC(PCIeGenerationTL, PCIeGeneration);


EApiStatus_t
COM0PCIe_Help(
    __IN  struct CfgElementDesc_s *pElementDesc, 
    __OUT char *szHelpBuf, 
    __IN  size_t stHBufLen 
  )
{ 
  unsigned int i;
  int len=0;
  pElementDesc=pElementDesc;
  len+=EApiSprintfA(szHelpBuf+len , stHBufLen-len , 
  "COM0 PCIe Port Description\n"                     
  "  Format:\n"                                      
  "    Starting Lane, Link Width, PCIe Generation\n" 
  "  Examples:\n"                                    
  "     0,   x1, Gen1\n"                             
  "    16,  x16, Gen2\n"                             
  "  Starting Lanes:\n"                              
  "    0 - 31      \n"                               
  "  Link Widths Tokens:\n"                          );
  for(i=0;i<ARRAY_SIZE(PCIeLaneWidths);i++){
    EApiSprintfA(szHelpBuf+len , stHBufLen-len , "     %s\n", PCIeLaneWidths[i].pszTokenList);
  }
  len+=EApiSprintfA(szHelpBuf+len, stHBufLen-len, "  Generations Tokens:\n"  );
  for(i=0;i<ARRAY_SIZE(PCIeGeneration);i++){
    len+=EApiSprintfA(szHelpBuf+len , stHBufLen-len , "     %s\n", PCIeGeneration[i].pszTokenList);
  }
  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t
COM0PCIe_Element(
    struct  CfgElementDesc_s *pElementDesc, 
    void          *pCurElement,
    char          *pszValue
  )
{ 
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  char *pszStartingLane, *pszWidth, *pszGen;
  unsigned long uiStartingLane, uiWidth, uiGen;
  pszStartingLane=pszValue;
  memset(pCurElement, 0x00, pElementDesc->Instances.stElementSize);
  EAPI_APP_ASSERT_PARAMATER_CHECK_S(
          COM0PCIe_Element,
          EAPI_STATUS_INVALID_PARAMETER,
          pElementDesc->Instances.stElementSize < sizeof(unsigned long)
        );

  pszWidth=strchr(pszStartingLane, ',');
  if(pszWidth==NULL ){
    StatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *pszWidth++='\0';
  
  pszGen=strchr(pszWidth, ',');
  if(pszGen==NULL  ) {
    StatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *pszGen++='\0';

  uiStartingLane=ulConvertStr2NumEx(pszStartingLane, NULL                  );
  if(uiStartingLane>31){
    printf("COM0PCIe_Element = Invalid Starting Lane, %s\n", pszStartingLane);
    StatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }

  StatusCode=GetTokenValueStrip(
      &PCIeLaneWidthsTL, 
      pszWidth, 
      &uiWidth
    );
  if(!EAPI_TEST_SUCCESS(StatusCode)){
    printf("COM0PCIe_Element = Unknown Token, %s\n", pszWidth);
    goto ErrorExit;
  }

  StatusCode=GetTokenValueStrip(
      &PCIeGenerationTL, 
      pszGen, 
      &uiGen
    );
  if(!EAPI_TEST_SUCCESS(StatusCode)){
    printf("COM0PCIe_Element = Unknown Token, %s\n", pszGen);
    goto ErrorExit;
  }
  if(uiStartingLane&((1<<(uiWidth - 1))-1)){
    printf("COM0PCIe_Element = Invalid Starting Lane/Width, %s/%s\n", pszStartingLane, pszWidth);
    StatusCode=EAPI_STATUS_ERROR;
    goto ErrorExit;
  }
  *(unsigned long*)pCurElement=(uiStartingLane<<16)|(uiWidth<<8)|(uiGen);
#if TEST_EEPCFG
/*   printf("COM0PCIe_Element = 0x%06lX, %s\n", *pCurElement, pszValue); */
#endif
EAPI_APP_ASSERT_EXIT
ErrorExit:
  return StatusCode;
}

   

TokenDesc_t  SasTokens[]={
  {"NotImplemented"	, 0  },
  {"SAS"            , COM0R20_SAS_CONNECTOR_PRESENT|COM0R20_SATA_SAS_DEVICE },
  {"SATA"           , COM0R20_SAS_CONNECTOR_PRESENT },
};
PCFG_TOKEN_LIST_DESC(SasTL, SasTokens);

TokenDesc_t  ImpNotImpTokens[]={
  {"NotImplemented"	, 0  },
  {"Implemented"    , 1  },
};
PCFG_TOKEN_LIST_DESC(ImpNotImpTL, ImpNotImpTokens);

TokenDesc_t  DDI1Tokens[]={
  {"NotImplemented"	, COM0R20_DDI_NOT_USED },
  {"eDisplayPort"   , COM0R20_DDI_eDispPort},
  {"DisplayPort"    , COM0R20_DDI_DispPort },
  {"HDMI/DVI"       , COM0R20_DDI_HDMI     },
  {"SDVO"           , COM0R20_DDI_SDVO     },
};
PCFG_TOKEN_LIST_DESC(DDI1TL, DDI1Tokens);

TokenDesc_t  DDI2Tokens[]={
  {"NotImplemented"	, COM0R20_DDI_NOT_USED },
  {"eDisplayPort"   , COM0R20_DDI_eDispPort},
  {"DisplayPort"    , COM0R20_DDI_DispPort },
  {"HDMI/DVI"       , COM0R20_DDI_HDMI     },
};
PCFG_TOKEN_LIST_DESC(DDI2TL, DDI2Tokens);

TokenDesc_t  DisplayInterfaceTokens[]={
  {"LVDS"	, EEEP_DISP_INT_LVDS  },
  {"SDVOB", EEEP_DISP_INT_SDVOB },
  {"SDVOC", EEEP_DISP_INT_SDVOC },
  {"DDI1" , EEEP_DISP_INT_DDI1	},
  {"DDI2" , EEEP_DISP_INT_DDI2	},
  {"DDI3" , EEEP_DISP_INT_DDI3	},
};
PCFG_TOKEN_LIST_DESC(DisplayInterfaceTL, DisplayInterfaceTokens);

TokenDesc_t  I2CBusTokens[]={
  {"I2C"	, EEEP_I2CBuSID_I2C  },
  {"SMB"	, EEEP_I2CBuSID_SMB  },
  {"LVDS" , EEEP_I2CBuSID_LVDS },
  {"DDI1" , EEEP_I2CBuSID_DDI1 },
  {"DDI2" , EEEP_I2CBuSID_DDI2 },
  {"DDI3" , EEEP_I2CBuSID_DDI3 },
  {"SDVOB", EEEP_I2CBuSID_SDVOB},
  {"SDVOC", EEEP_I2CBuSID_SDVOC},
  {"CRT"  , EEEP_I2CBuSID_CRT  },
};
PCFG_TOKEN_LIST_DESC(I2CBusTL, I2CBusTokens);

TokenDesc_t  StandardExtendedTokens[]={
  {"Extended"	, 1  },
  {"Standard"	, 0  },
};
PCFG_TOKEN_LIST_DESC(StandardExtendedTL, StandardExtendedTokens);



TokenDesc_t  SmbiosModuleFeatureFlagsTokens[]={
  {"IS_Motherboard"    , SMBIOS_IS_Motherboard },
  {"REQUIRES_DAUGHTER" , SMBIOS_REQ_DAUGHTER   },
  {"REMOVABLE"         , SMBIOS_REMOVABLE      },
  {"REPLACEABLE"       , SMBIOS_REPLACEABLE    },
  {"HOT_SWAP_CAPABLE"	 , SMBIOS_HOT_SWAP_CAP   },
};
PCFG_TOKEN_LIST_DESC(SmbiSmbiosModuleFeatureFlagsTL, SmbiosModuleFeatureFlagsTokens);

TokenDesc_t  SmbiosChassisTypesTokens[]={
  {"Other"                        , SMBIOS_ChassisType_Other                 },
  {"Unknown"                      , SMBIOS_ChassisType_Unknown               },
  {"Desktop"                      , SMBIOS_ChassisType_Desktop               },
  {"Low_Profile_Desktop"          , SMBIOS_ChassisType_Low_Profile_Desktop   },
  {"Pizza_Box"             	      , SMBIOS_ChassisType_Pizza_Box             },
  {"Mini_Tower"                   , SMBIOS_ChassisType_Mini_Tower            },
  {"Tower"                        , SMBIOS_ChassisType_Tower                 },
  {"Portable"                     , SMBIOS_ChassisType_Portable              },
  {"Laptop"                       , SMBIOS_ChassisType_Laptop                },
  {"Notebook"                     , SMBIOS_ChassisType_Notebook              },
  {"Hand_Held"                    , SMBIOS_ChassisType_Hand_Held             },
  {"Docking_Station"              , SMBIOS_ChassisType_Docking_Station       },
  {"All_In_One"            	      , SMBIOS_ChassisType_All_In_One            },
  {"Sub_Notebook"          	      , SMBIOS_ChassisType_Sub_Notebook          },
  {"Space_saving_Lunch_Box"	      , SMBIOS_ChassisType_Space_saving_Lunch_Box},
  {"Main_Server_Chassis"   	      , SMBIOS_ChassisType_Main_Server_Chassis   },
  {"Expansion_Chassis"            , SMBIOS_ChassisType_Expansion_Chassis     },
  {"SubChassis"            	      , SMBIOS_ChassisType_SubChassis            },
  {"Bus_Expansion_Chassis" 	      , SMBIOS_ChassisType_Bus_Expansion_Chassis },
  {"Peripheral_Chassis"    	      , SMBIOS_ChassisType_Peripheral_Chassis    },
  {"RAID_Chassis"          	      , SMBIOS_ChassisType_RAID_Chassis          },
  {"Rack_Mount_Chassis"    	      , SMBIOS_ChassisType_Rack_Mount_Chassis    },
  {"Sealed_case_PC"        	      , SMBIOS_ChassisType_Sealed_case_PC        },
  {"Multi_system_chassis"  	      , SMBIOS_ChassisType_Multi_system_chassis  },
};
PCFG_TOKEN_LIST_DESC(SmbiosChassisTypesTL, SmbiosChassisTypesTokens);

NumberRange_t ValidHandles[]={
  {0xE000, 0xFFFF, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidHandlesDesc, ValidHandles);

TokenDesc_t  IRQTokens[]={
  {"Auto"	  , 0},
  {"No_IRQ"	, 1},
  {"IRQ3"	  , 3},
  {"IRQ4"	  , 4},
  {"IRQ5"	  , 5},
  {"IRQ6"	  , 6},
  {"IRQ7"	  , 7},
  {"IRQ8"	  , 8},
  {"IRQ9"	  , 9},
  {"IRQ10"	, 10},
  {"IRQ11"	, 11},
  {"IRQ12"	, 12},
  {"IRQ13"	, 13},
  {"IRQ14"	, 14},
  {"IRQ15"	, 15},
};
PCFG_TOKEN_LIST_DESC(IRQTL, IRQTokens);

typedef struct SmbiosModule_s{
  uint16_t      au16Handle        [1];
  char *        aszManuf          [1];
  char *        aszProduct        [1];
  char *        aszVersion        [1];
  char *        aszSerialNum      [1];
  char *        aszAssetTag       [1];
  uint8_t       au8FeatureFlag    [5];
  char *        aszLocation       [1];
  uint16_t      au16LocationHandle[1];
  uint8_t       au8BoardType      [1];
  unsigned long aulInsideCrc      [1];
  unsigned long aulMinSize        [1];
  uint8_t       au8FillChar       [1];
  uint16_t      au16Handles       [20];
}SmbiosModule_t;

SmbiosModule_t COM0_SMBIOS_Module ={{0xE000},{NULL},{NULL},{NULL},{NULL},{NULL},{0},{NULL},{0},{0},{0},{0},{0},{0}};
SmbiosModule_t COM0_SMBIOS_Carrier={{0xE001},{NULL},{NULL},{NULL},{NULL},{NULL},{0},{NULL},{0},{0},{0},{0},{0},{0}};


typedef struct SmbiosSystem_s{
  uint16_t      au16Handle        [1];
  char *        aszManuf          [1];
  char *        aszProduct        [1];
  char *        aszVersion        [1];
  char *        aszSerialNum      [1];
  EeePGUID_t    aUUID             [1];
  char *        aszSKU_Number     [1];
  unsigned long aulInsideCrc      [1];
  unsigned long aulMinSize        [1];
  uint8_t       au8FillChar       [1];
  char *        aszFamily         [1];
}SmbiosSystem_t;

SmbiosSystem_t COM0_SMBIOS_System={{0xE002},{NULL},{NULL},{NULL},{NULL},{{{{0}},{{{0}}},{0}}},{NULL},{0},{0},{0},{NULL}};

typedef struct SmbiosChassis_s{
  uint16_t      au16Handle        [1];
  char *        aszManuf          [1];
  uint8_t       au8ChassisType    [1];
  char *        aszVersion        [1];
  char *        aszSerialNum      [1];
  char *        aszAssetTag       [1];
  uint32_t      au32OEM           [1];
  uint8_t       au8Height         [1];
  uint8_t       au8NumPowerCords  [1];
  unsigned long aulInsideCrc      [1];
  unsigned long aulMinSize        [1];
  uint8_t       au8FillChar       [1];
  CCElement_t   aCElements        [20];
}SmbiosChassis_t;

SmbiosChassis_t COM0_SMBIOS_Chassis={{0xE003},{NULL},{0},{NULL},{NULL},{NULL},{0},{0},{0},{0},{0},{0},{{0,0,0}}};

typedef struct EeePLFP_s{
  uint8_t       au8Interface    [1];
  char *        aszFilename     [1];
  unsigned long aulInsideCrc    [1];
  unsigned long aulMinSize      [1];
  uint8_t       au8FillChar     [1];
}EeePLFP_t;

EeePLFP_t EeeP_LFP0_Cfg={{0},{0},{0},{0},{0}};
EeePLFP_t EeeP_LFP1_Cfg={{0},{0},{0},{0},{0}};
EeePLFP_t EeeP_LFP2_Cfg={{0},{0},{0},{0},{0}};
EeePLFP_t EeeP_LFP3_Cfg={{0},{0},{0},{0},{0}};

typedef struct EeePVendorBlock_s{
  char *        aszFilename   [1];
  uint16_t      au16VendorId  [1];
  unsigned long aulInsideCrc  [1];
  unsigned long aulMinSize    [1];
  uint8_t       au8FillChar   [1];
  uint8_t       au8VSBlockId  [1];
}EeePVendorBlock_t;

EeePVendorBlock_t EeeP_VendorBlock0_Cfg={{0},{0},{0},{0},{0},{0}};
EeePVendorBlock_t EeeP_VendorBlock1_Cfg={{0},{0},{0},{0},{0},{0}};
EeePVendorBlock_t EeeP_VendorBlock2_Cfg={{0},{0},{0},{0},{0},{0}};
EeePVendorBlock_t EeeP_VendorBlock3_Cfg={{0},{0},{0},{0},{0},{0}};
EeePVendorBlock_t EeeP_VendorBlock4_Cfg={{0},{0},{0},{0},{0},{0}};
EeePVendorBlock_t EeeP_VendorBlock5_Cfg={{0},{0},{0},{0},{0},{0}};
EeePVendorBlock_t EeeP_VendorBlock6_Cfg={{0},{0},{0},{0},{0},{0}};

typedef struct EeePCustomBlock_s{
  uint8_t       au8BlockId    [1];
  char *        aszFilename   [1];
  unsigned long aulInsideCrc  [1];
  unsigned long aulMinSize    [1];
  uint8_t       au8FillChar   [1];
}EeePCustomBlock_t;

EeePCustomBlock_t EeeP_CustomBlock0_Cfg={{0},{0},{0},{0},{0}};
EeePCustomBlock_t EeeP_CustomBlock1_Cfg={{0},{0},{0},{0},{0}};
EeePCustomBlock_t EeeP_CustomBlock2_Cfg={{0},{0},{0},{0},{0}};
EeePCustomBlock_t EeeP_CustomBlock3_Cfg={{0},{0},{0},{0},{0}};
EeePCustomBlock_t EeeP_CustomBlock4_Cfg={{0},{0},{0},{0},{0}};
EeePCustomBlock_t EeeP_CustomBlock5_Cfg={{0},{0},{0},{0},{0}};
EeePCustomBlock_t EeeP_CustomBlock6_Cfg={{0},{0},{0},{0},{0}};

typedef struct EeePExtI2CDevice_s{
  uint16_t      au16Addr     [1];
  uint8_t       au8Bus       [1];
  uint8_t       au8DeviceDesc[1];
  unsigned long aulInsideCrc [1];
  unsigned long aulMinSize   [1];
  uint8_t       au8FillChar  [1];
}EeePExtI2CDevice_t;

EeePExtI2CDevice_t EeePExtI2CDevice0={{0},{0},{0},{0},{0},{0}};
EeePExtI2CDevice_t EeePExtI2CDevice1={{0},{0},{0},{0},{0},{0}};

typedef struct EeePI2CDevice_s{
  uint8_t       au8DeviceDesc [1];
  unsigned long aulInsideCrc  [1];
  unsigned long aulMinSize    [1];
  uint8_t       au8FillChar   [1];
}EeePI2CDevice_t;

EeePI2CDevice_t EeePI2CDevice={{0},{0},{0},{0}};

typedef struct COM0R20_CB_HDR_s{
  uint8_t       au8DeviceDesc [1];
  uint16_t      au16VendorId  [1];
  uint16_t      au16DeviceId  [1];
  uint8_t       au8DeviceFlav [1];
  uint8_t       au8RevId      [1];
  uint8_t       au8CBType     [1];
  uint8_t       au8SpecRev    [1];
  uint8_t       au8USBDesc    [1];
  uint8_t       au8SASDesc    [1];
  uint8_t       au8LanDesc    [1];
  uint8_t       au8MiscIO1    [1];
  uint8_t       au8MiscIO2    [1];
  uint8_t       au8DDI1       [1];
  uint8_t       au8DDI2       [1];
  unsigned long aulPCIePorts  [32];
}COM0R20_CB_HDR_t;

COM0R20_CB_HDR_t COM0R20_CB_cgf={{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};

typedef struct COM0R20_M_HDR_s{
  uint8_t       au8DeviceDesc  [1];
  uint16_t      au16VendorId   [1];
  uint16_t      au16DeviceId   [1];
  uint8_t       au8DeviceFlav  [1];
  uint8_t       au8RevId       [1];
  uint8_t       au8MType       [1];
  uint8_t       au8SpecRev     [1];
}COM0R20_M_HDR_t;

COM0R20_M_HDR_t COM0R20_M_cgf={{0},{0},{0},{0},{0},{0},{0}};

typedef struct COM0R20_ECard_s{
  uint8_t       au8ExpCardNum [1];
  uint8_t       au8PortDesc   [1];
  uint8_t       au8SwitchPFA  [30];
  unsigned long aulInsideCrc  [1];
  unsigned long aulMinSize    [1];
  uint8_t       au8FillChar   [1];
}COM0R20_ECard_t;

COM0R20_ECard_t COM0R20_ECard0_cgf={{0},{0},{0},{0},{0},{0}};
COM0R20_ECard_t COM0R20_ECard1_cgf={{1},{0},{0},{0},{0},{0}};

typedef struct COM0R20_SERIAL_s{
  uint16_t      au16SER0_IOADDRESS        [1];
  uint8_t       au8SER_IRQ                [1];
  uint16_t      au16SER1_IOADDRESS        [1];
  unsigned long aulInsideCrc              [1];
  unsigned long aulMinSize                [1];
  uint8_t       au8FillChar               [1];
}COM0R20_SERIAL_t;

COM0R20_SERIAL_t COM0R20_SER_cgf={{0},{0},{0},{0},{0},{0}};

typedef struct EeeP_Exp_Hdr_s{
  uint8_t       au8DeviceDesc  [1];
  uint16_t      au16VendorId   [1];
  uint16_t      au16DeviceId   [1];
  uint8_t       au8DeviceFlav  [1];
  uint8_t       au8RevId       [1];
  unsigned long aulInsideCrc   [1];
}EeeP_Exp_Hdr_t;

EeeP_Exp_Hdr_t EeePExpHdr_cgf={{0},{0},{0},{0},{0},{0}};
NumberRange_t ValidMinSize[]={
  {0x0, 0xFFFE*EEEP_SIZE_UNITS, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidMinSizeDesc, ValidMinSize);



CfgElementDesc_t SmbiosModuleDesc[]={
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_Module.aulInsideCrc      , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , COM0_SMBIOS_Module.aulMinSize        , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , COM0_SMBIOS_Module.au8FillChar       , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_Module.aszManuf          , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Product"       , COM0_SMBIOS_Module.aszProduct        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_Module.aszVersion        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_Module.aszSerialNum      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("AssetTag"      , COM0_SMBIOS_Module.aszAssetTag       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("FeatureFlag"   , COM0_SMBIOS_Module.au8FeatureFlag    , &Token_Element_funcs , &SmbiSmbiosModuleFeatureFlagsTL, ELEMENT_REQUIRED)
  ELEMENT_DESC("Location"      , COM0_SMBIOS_Module.aszLocation       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("LocationHandle", COM0_SMBIOS_Module.au16LocationHandle , &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BoardType"     , COM0_SMBIOS_Module.au8BoardType      , &Token_Element_funcs , &SmbiosBoardTypesTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("Handles"       , COM0_SMBIOS_Module.au16Handles        , &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
};                                
CfgElementDesc_t SmbiosCarrierDesc[]={  
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_Carrier.aulInsideCrc     , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , COM0_SMBIOS_Carrier.aulMinSize       , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , COM0_SMBIOS_Carrier.au8FillChar      , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_Carrier.aszManuf         , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Product"       , COM0_SMBIOS_Carrier.aszProduct       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_Carrier.aszVersion       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_Carrier.aszSerialNum     , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("AssetTag"      , COM0_SMBIOS_Carrier.aszAssetTag      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("FeatureFlag"   , COM0_SMBIOS_Carrier.au8FeatureFlag   , &Token_Element_funcs , &SmbiSmbiosModuleFeatureFlagsTL, ELEMENT_REQUIRED)
  ELEMENT_DESC("Location"      , COM0_SMBIOS_Carrier.aszLocation      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("LocationHandle", COM0_SMBIOS_Carrier.au16LocationHandle, &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BoardType"     , COM0_SMBIOS_Carrier.au8BoardType     , &Token_Element_funcs , &SmbiosBoardTypesTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("Handles"       , COM0_SMBIOS_Carrier.au16Handles       , &Number_Element_funcs, &ValidHandlesDesc              , ELEMENT_OPTIONAL)
};
CfgElementDesc_t SmbiosSystemDesc[]={
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_System.aulInsideCrc      , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , COM0_SMBIOS_System.aulMinSize        , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , COM0_SMBIOS_System.au8FillChar       , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_System.aszManuf          , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Product"       , COM0_SMBIOS_System.aszProduct        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_System.aszVersion        , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_System.aszSerialNum      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("UUID"          , COM0_SMBIOS_System.aUUID             , &GUID_Element_funcs  , NULL                           , ELEMENT_OPTIONAL)
  ELEMENT_DESC("SKU_Number"    , COM0_SMBIOS_System.aszSKU_Number     , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Family"        , COM0_SMBIOS_System.aszFamily         , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
};                                                         
                                                           
CfgElementDesc_t SmbiosChassisDesc[]={                     
  ELEMENT_DESC("InsideCRC"     , COM0_SMBIOS_Chassis.aulInsideCrc     , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , COM0_SMBIOS_Chassis.aulMinSize       , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , COM0_SMBIOS_Chassis.au8FillChar      , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Manufacturer"  , COM0_SMBIOS_Chassis.aszManuf         , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("Type"          , COM0_SMBIOS_Chassis.au8ChassisType   , &Token_Element_funcs , &SmbiosChassisTypesTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("Version"       , COM0_SMBIOS_Chassis.aszVersion       , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_REQUIRED)
  ELEMENT_DESC("SerialNumber"  , COM0_SMBIOS_Chassis.aszSerialNum     , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("AssetTag"      , COM0_SMBIOS_Chassis.aszAssetTag      , &String_Element_funcs, &PreserveTrailingSpaces        , ELEMENT_OPTIONAL)
  ELEMENT_DESC("OEM"           , COM0_SMBIOS_Chassis.au32OEM           , &Number_Element_funcs, &UINT32RangeDesc               , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Height"        , COM0_SMBIOS_Chassis.au8Height        , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("NumPowerCords" , COM0_SMBIOS_Chassis.au8NumPowerCords , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("CElements"     , COM0_SMBIOS_Chassis.aCElements       , &SMBIOS_CE_Element_funcs, NULL                        , ELEMENT_OPTIONAL)
};

CfgElementDesc_t LFPData0Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP0_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_LFP0_Cfg.aulMinSize           , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_LFP0_Cfg.au8FillChar          , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Interface"     , EeeP_LFP0_Cfg.au8Interface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP0_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t LFPData1Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP1_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_LFP1_Cfg.aulMinSize           , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_LFP1_Cfg.au8FillChar          , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Interface"     , EeeP_LFP1_Cfg.au8Interface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP1_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t LFPData2Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP2_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_LFP2_Cfg.aulMinSize           , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_LFP2_Cfg.au8FillChar          , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Interface"     , EeeP_LFP2_Cfg.au8Interface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP2_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t LFPData3Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_LFP3_Cfg.aulInsideCrc         , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_LFP3_Cfg.aulMinSize           , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_LFP3_Cfg.au8FillChar          , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("Interface"     , EeeP_LFP3_Cfg.au8Interface         , &Token_Element_funcs , &DisplayInterfaceTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_LFP3_Cfg.aszFilename          , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};

CfgElementDesc_t VendorBlock0Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock0_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"         , EeeP_VendorBlock0_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar"        , EeeP_VendorBlock0_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_OPTIONAL)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock0_Cfg.au16VendorId , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock0_Cfg.au8VSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock0_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock1Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock1_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"         , EeeP_VendorBlock1_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar"        , EeeP_VendorBlock1_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_OPTIONAL)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock1_Cfg.au16VendorId , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock1_Cfg.au8VSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock1_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock2Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock2_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"         , EeeP_VendorBlock2_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar"        , EeeP_VendorBlock2_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_OPTIONAL)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock2_Cfg.au16VendorId , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock2_Cfg.au8VSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock2_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock3Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock3_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"         , EeeP_VendorBlock3_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar"        , EeeP_VendorBlock3_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_OPTIONAL)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock3_Cfg.au16VendorId , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock3_Cfg.au8VSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock3_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock4Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock4_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"         , EeeP_VendorBlock4_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar"        , EeeP_VendorBlock4_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_OPTIONAL)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock4_Cfg.au16VendorId , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock4_Cfg.au8VSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock4_Cfg.aszFilename  , &String_Element_funcs, NULL                    , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock5Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock5_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"         , EeeP_VendorBlock5_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar"        , EeeP_VendorBlock5_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_OPTIONAL)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock5_Cfg.au16VendorId , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock5_Cfg.au8VSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock5_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};
CfgElementDesc_t VendorBlock6Desc[]={
  ELEMENT_DESC("InsideCRC"            , EeeP_VendorBlock6_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL            , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"         , EeeP_VendorBlock6_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar"        , EeeP_VendorBlock6_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_OPTIONAL)
  ELEMENT_DESC("VendorId"             , EeeP_VendorBlock6_Cfg.au16VendorId , &PNPID_Element_funcs , NULL                    , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorSpecificBlockId", EeeP_VendorBlock6_Cfg.au8VSBlockId , &Number_Element_funcs, &UINT8RangeDesc         , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"             , EeeP_VendorBlock6_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces   , ELEMENT_REQUIRED)
};

CfgElementDesc_t CustomBlock0Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock0_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_CustomBlock0_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_CustomBlock0_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock0_Cfg.au8BlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock0_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock1Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock1_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_CustomBlock1_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_CustomBlock1_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock1_Cfg.au8BlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock1_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock2Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock2_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_CustomBlock2_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_CustomBlock2_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock2_Cfg.au8BlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock2_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock3Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock3_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_CustomBlock3_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_CustomBlock3_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock3_Cfg.au8BlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock3_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock4Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock4_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_CustomBlock4_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_CustomBlock4_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock4_Cfg.au8BlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock4_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock5Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock5_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_CustomBlock5_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_CustomBlock5_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock5_Cfg.au8BlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock5_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
CfgElementDesc_t CustomBlock6Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeeP_CustomBlock6_Cfg.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL                   , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeeP_CustomBlock6_Cfg.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeeP_CustomBlock6_Cfg.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockId"       , EeeP_CustomBlock6_Cfg.au8BlockId   , &Number_Element_funcs, &UINT8RangeDesc                , ELEMENT_REQUIRED)
  ELEMENT_DESC("FileName"      , EeeP_CustomBlock6_Cfg.aszFilename  , &String_Element_funcs, &DeleteTrailingSpaces          , ELEMENT_REQUIRED)
};
TokenDesc_t  EEPDeviceSizeTokens[]={
  {"256Bytes"	  , 0},
  {"512Bytes"	  , 1},
  {"1KBytes"	  , 2},
  {"2KBytes"	  , 3},
  {"4KBytes"	  , 4},
  {"8KBytes"	  , 5},
  {"16KBytes"	  , 6},
  {"32KBytes"	  , 7},
  {"64KBytes"	  , 8},
  {"128KBytes"	, 9},
  {"256KBytes"  , 10},
  {"512KBytes"  , 11},
  {"2Kbits"     , 0},
  {"4Kbits"     , 1},
  {"8Kbits"     , 2},
  {"16Kbits"    , 3},
  {"32Kbits"    , 4},
  {"64Kbits"    , 5},
  {"128Kbits"   , 6},
  {"256Kbits"   , 7},
  {"512Kbits"   , 8},
  {"1Mbits"     , 9},
  {"2Mbits"     , 10},
  {"4Mbits"     , 11},
};
PCFG_TOKEN_LIST_DESC(EEPDeviceSizeTL, EEPDeviceSizeTokens);

TokenDesc_t  EeePEEPWriteLenTokens[]={
  {"1"	  , 0},
  {"8"	  , 1},
  {"16"	  , 2},
  {"32"	  , 3},
  {"64"	  , 4},
  {"128"  , 5},
  {"256"  , 6},
  {"512"  , 7},
};
PCFG_TOKEN_LIST_DESC(EeePEEPWriteLenTL, EeePEEPWriteLenTokens);


CfgElementDesc_t ExtI2CDevice0Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeePExtI2CDevice0.aulInsideCrc   , &Token_Element_funcs  , &InsideCrcTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeePExtI2CDevice0.aulMinSize     , &Number_Element_funcs , &ValidMinSizeDesc     , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeePExtI2CDevice0.au8FillChar    , &Number_Element_funcs , &UINT8RangeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("DeviceBus"     , EeePExtI2CDevice0.au8Bus         , &Token_Element_funcs  , &I2CBusTL             , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceAddr"    , EeePExtI2CDevice0.au16Addr       , &I2C_EEPROM_Addr_funcs, NULL                  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DeviceType"    , EeePExtI2CDevice0.au8DeviceDesc  , EEEP_DEVICE_TYPE_OFFSET      , 1, &Token_Element_funcs  , &StandardExtendedTL  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DeviceSize"    , EeePExtI2CDevice0.au8DeviceDesc  , 0                            , 4, &Token_Element_funcs  , &EEPDeviceSizeTL     , ELEMENT_REQUIRED)
};
CfgElementDesc_t ExtI2CDevice1Desc[]={
  ELEMENT_DESC("InsideCRC"     , EeePExtI2CDevice1.aulInsideCrc   , &Token_Element_funcs  , &InsideCrcTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , EeePExtI2CDevice1.aulMinSize     , &Number_Element_funcs , &ValidMinSizeDesc     , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , EeePExtI2CDevice1.au8FillChar    , &Number_Element_funcs , &UINT8RangeDesc       , ELEMENT_OPTIONAL)
  ELEMENT_DESC("DeviceBus"     , EeePExtI2CDevice1.au8Bus         , &Token_Element_funcs  , &I2CBusTL             , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceAddr"    , EeePExtI2CDevice1.au16Addr       , &I2C_EEPROM_Addr_funcs, NULL                  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DeviceType"    , EeePExtI2CDevice1.au8DeviceDesc  , EEEP_DEVICE_TYPE_OFFSET      , 1, &Token_Element_funcs  , &StandardExtendedTL  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DeviceSize"    , EeePExtI2CDevice1.au8DeviceDesc  , 0                            , 4, &Token_Element_funcs  , &EEPDeviceSizeTL     , ELEMENT_REQUIRED)
};

NumberRange_t ValidUsbHSRange[]={
  {0x0000, 0x0008, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidUsbHSRangeDesc, ValidUsbHSRange);

NumberRange_t ValidUsbSSRange[]={
  {0x0000, 0x0004, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidUsbSSRangeDesc, ValidUsbSSRange);

NumberRange_t ValidModuleTypes[]={
  {0x0000, 0x0006, RANGE_INCLUSIVE},
  {0x000A, 0x000A, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidModuleTypesDesc, ValidModuleTypes);

CfgElementDesc_t COM0R20_CB_Desc[]={
 ELEMENT_BDESC("EepDeviceType" , COM0R20_CB_cgf.au8DeviceDesc , EEEP_DEVICE_TYPE_OFFSET      , 1, &Token_Element_funcs  , &StandardExtendedTL  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("EepDeviceSize" , COM0R20_CB_cgf.au8DeviceDesc , 0                            , 4, &Token_Element_funcs  , &EEPDeviceSizeTL     , ELEMENT_REQUIRED)
 ELEMENT_BDESC("WriteLength"   , COM0R20_CB_cgf.au8DeviceDesc , EEEP_DEVICE_WRITE_LEN_OFFSET , 3, &Token_Element_funcs  , &EeePEEPWriteLenTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"      , COM0R20_CB_cgf.au16VendorId  , &PNPID_Element_funcs   , NULL                  , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceId"      , COM0R20_CB_cgf.au16DeviceId  , &Number_Element_funcs  , &UINT16RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceFlav"    , COM0R20_CB_cgf.au8DeviceFlav , &Number_Element_funcs  , &UINT8RangeDesc       , ELEMENT_REQUIRED)
  ELEMENT_DESC("RevId"         , COM0R20_CB_cgf.au8RevId      , &Number_Element_funcs  , &UINT8RangeDesc       , ELEMENT_REQUIRED)
  ELEMENT_DESC("CBType"        , COM0R20_CB_cgf.au8CBType     , &Number_Element_funcs  , &ValidModuleTypesDesc , ELEMENT_REQUIRED)
  ELEMENT_DESC("SpecRevision"  , COM0R20_CB_cgf.au8SpecRev    , &SpecRev_Element_funcs , NULL                  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("USBHSCount"    , COM0R20_CB_cgf.au8USBDesc    , COM0R20_USB_PCNT_OFFSET  , 4, &Number_Element_funcs  , &ValidUsbHSRangeDesc  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("USBSSCount"    , COM0R20_CB_cgf.au8USBDesc    , COM0R20_USBSS_PCNT_OFFSET, 3, &Number_Element_funcs  , &ValidUsbHSRangeDesc  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SASPort0"      , COM0R20_CB_cgf.au8SASDesc    , COM0R20_SAS_CHANNEL_0    , 2, &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SASPort1"      , COM0R20_CB_cgf.au8SASDesc    , COM0R20_SAS_CHANNEL_1    , 2, &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SASPort2"      , COM0R20_CB_cgf.au8SASDesc    , COM0R20_SAS_CHANNEL_2    , 2, &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SASPort3"      , COM0R20_CB_cgf.au8SASDesc    , COM0R20_SAS_CHANNEL_3    , 2, &Token_Element_funcs   , &SasTL                , ELEMENT_REQUIRED)
 ELEMENT_BDESC("GBE0"          , COM0R20_CB_cgf.au8LanDesc    , 0                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("GBE1"          , COM0R20_CB_cgf.au8LanDesc    , 1                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("GBE2"          , COM0R20_CB_cgf.au8LanDesc    , 2                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("WAKE0"         , COM0R20_CB_cgf.au8MiscIO1    , 0                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("WAKE1"         , COM0R20_CB_cgf.au8MiscIO1    , 1                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SUS"           , COM0R20_CB_cgf.au8MiscIO1    , 2                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("BatLow"        , COM0R20_CB_cgf.au8MiscIO1    , 3                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("THRMP"         , COM0R20_CB_cgf.au8MiscIO1    , 4                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("EBROM"         , COM0R20_CB_cgf.au8MiscIO1    , 5                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("WDT"           , COM0R20_CB_cgf.au8MiscIO1    , 6                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("AC97/HDA"      , COM0R20_CB_cgf.au8MiscIO1    , 7                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SSC"           , COM0R20_CB_cgf.au8MiscIO2    , 0                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SDIO"          , COM0R20_CB_cgf.au8MiscIO2    , 1                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("LID"           , COM0R20_CB_cgf.au8MiscIO2    , 2                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("Sleep"         , COM0R20_CB_cgf.au8MiscIO2    , 3                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("FAN0"          , COM0R20_CB_cgf.au8MiscIO2    , 4                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SER0"          , COM0R20_CB_cgf.au8MiscIO2    , 5                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("SER1"          , COM0R20_CB_cgf.au8MiscIO2    , 6                        , 1, &Token_Element_funcs   , &ImpNotImpTL          , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DDI0"          , COM0R20_CB_cgf.au8DDI1       , COM0R20_DDI0_OFFSET      , 3, &Token_Element_funcs   , &DDI1TL               , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DDI1"          , COM0R20_CB_cgf.au8DDI1       , COM0R20_DDI1_OFFSET      , 3, &Token_Element_funcs   , &DDI1TL               , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DDI2"          , COM0R20_CB_cgf.au8DDI2       , COM0R20_DDI2_OFFSET      , 2, &Token_Element_funcs   , &DDI2TL               , ELEMENT_REQUIRED)
 ELEMENT_BDESC("DDI3"          , COM0R20_CB_cgf.au8DDI2       , COM0R20_DDI3_OFFSET      , 2, &Token_Element_funcs   , &DDI2TL               , ELEMENT_REQUIRED)
  ELEMENT_DESC("PCIePorts"     , COM0R20_CB_cgf.aulPCIePorts  , &COM0PCIe_Element_funcs, NULL                  , ELEMENT_REQUIRED)
};
CfgElementDesc_t COM0R20_M_Desc[]={
 ELEMENT_BDESC("EepDeviceType" , COM0R20_M_cgf.au8DeviceDesc  , EEEP_DEVICE_TYPE_OFFSET      , 1, &Token_Element_funcs  , &StandardExtendedTL  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("EepDeviceSize" , COM0R20_M_cgf.au8DeviceDesc  , 0                            , 4, &Token_Element_funcs  , &EEPDeviceSizeTL     , ELEMENT_REQUIRED)
 ELEMENT_BDESC("WriteLength"   , COM0R20_M_cgf.au8DeviceDesc  , EEEP_DEVICE_WRITE_LEN_OFFSET , 3, &Token_Element_funcs  , &EeePEEPWriteLenTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"      , COM0R20_M_cgf.au16VendorId   , &PNPID_Element_funcs  , NULL                 , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceId"      , COM0R20_M_cgf.au16DeviceId   , &Number_Element_funcs , &UINT16RangeDesc     , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceFlav"    , COM0R20_M_cgf.au8DeviceFlav  , &Number_Element_funcs , &UINT8RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("RevId"         , COM0R20_M_cgf.au8RevId       , &Number_Element_funcs , &UINT8RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("MType"         , COM0R20_M_cgf.au8MType       , &Number_Element_funcs , &ValidModuleTypesDesc, ELEMENT_REQUIRED)
  ELEMENT_DESC("SpecRevision"  , COM0R20_M_cgf.au8SpecRev     , &SpecRev_Element_funcs, NULL                 , ELEMENT_REQUIRED)
};
CfgElementDesc_t EeePExpHdr_Desc[]={
 ELEMENT_BDESC("EepDeviceType" , EeePExpHdr_cgf.au8DeviceDesc  , EEEP_DEVICE_TYPE_OFFSET      , 1, &Token_Element_funcs  , &StandardExtendedTL  , ELEMENT_REQUIRED)
 ELEMENT_BDESC("EepDeviceSize" , EeePExpHdr_cgf.au8DeviceDesc  , 0                            , 4, &Token_Element_funcs  , &EEPDeviceSizeTL     , ELEMENT_REQUIRED)
 ELEMENT_BDESC("WriteLength"   , EeePExpHdr_cgf.au8DeviceDesc  , EEEP_DEVICE_WRITE_LEN_OFFSET , 3, &Token_Element_funcs  , &EeePEEPWriteLenTL   , ELEMENT_REQUIRED)
  ELEMENT_DESC("VendorId"      , EeePExpHdr_cgf.au16VendorId   , &PNPID_Element_funcs , NULL                 , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceId"      , EeePExpHdr_cgf.au16DeviceId   , &Number_Element_funcs, &UINT16RangeDesc     , ELEMENT_REQUIRED)
  ELEMENT_DESC("DeviceFlav"    , EeePExpHdr_cgf.au8DeviceFlav  , &Number_Element_funcs, &UINT8RangeDesc      , ELEMENT_REQUIRED)
  ELEMENT_DESC("RevId"         , EeePExpHdr_cgf.au8RevId       , &Number_Element_funcs, &UINT8RangeDesc      , ELEMENT_REQUIRED)
};
NumberRange_t ValidCOM0PCIePort[]={
  {0, 31, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidCOM0PCIePortDesc, ValidCOM0PCIePort);

NumberRange_t ValidCOM0USBPort[]={
  {0, 7, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidCOM0USBPortDesc, ValidCOM0USBPort);

CfgElementDesc_t COM0R20_ExpCard0Desc[]={
  ELEMENT_DESC("InsideCRC"     , COM0R20_ECard0_cgf.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , COM0R20_ECard0_cgf.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc     , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , COM0R20_ECard0_cgf.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc       , ELEMENT_OPTIONAL)
 ELEMENT_BDESC("COM0_PCIe_Port", COM0R20_ECard0_cgf.au8PortDesc  , 0, 5 , &Number_Element_funcs, &ValidCOM0PCIePortDesc, ELEMENT_REQUIRED)
 ELEMENT_BDESC("COM0_USB_Port" , COM0R20_ECard0_cgf.au8PortDesc  , 5, 3 , &Number_Element_funcs, &ValidCOM0USBPortDesc , ELEMENT_REQUIRED)
  ELEMENT_DESC("SwitchPFA"     , COM0R20_ECard0_cgf.au8SwitchPFA , &Number_Element_funcs, &UINT8RangeDesc       , ELEMENT_OPTIONAL)
};

CfgElementDesc_t COM0R20_ExpCard1Desc[]={
  ELEMENT_DESC("InsideCRC"     , COM0R20_ECard1_cgf.aulInsideCrc , &Token_Element_funcs , &InsideCrcTL          , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , COM0R20_ECard1_cgf.aulMinSize   , &Number_Element_funcs, &ValidMinSizeDesc     , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , COM0R20_ECard1_cgf.au8FillChar  , &Number_Element_funcs, &UINT8RangeDesc       , ELEMENT_OPTIONAL)
 ELEMENT_BDESC("COM0_PCIe_Port", COM0R20_ECard1_cgf.au8PortDesc  , 0, 5 , &Number_Element_funcs, &ValidCOM0PCIePortDesc, ELEMENT_REQUIRED)
 ELEMENT_BDESC("COM0_USB_Port" , COM0R20_ECard1_cgf.au8PortDesc  , 5, 3 , &Number_Element_funcs, &ValidCOM0USBPortDesc , ELEMENT_REQUIRED)
  ELEMENT_DESC("SwitchPFA"     , COM0R20_ECard1_cgf.au8SwitchPFA , &Number_Element_funcs, &UINT8RangeDesc       , ELEMENT_OPTIONAL)
};

NumberRange_t ValidIOAddrPort[]={
  {0x200, 0xFFF8, RANGE_INCLUSIVE},
};
PCFG_RANGE_LIST_DESC(ValidIOAddrPortDesc, ValidIOAddrPort);

CfgElementDesc_t COM0R20_SerialPortsDesc[]={
  ELEMENT_DESC("InsideCRC"     , COM0R20_SER_cgf.aulInsideCrc              , &Token_Element_funcs , &InsideCrcTL        , ELEMENT_REQUIRED)
  ELEMENT_DESC("MinBlockSize"  , COM0R20_SER_cgf.aulMinSize                , &Number_Element_funcs, &ValidMinSizeDesc   , ELEMENT_OPTIONAL)
  ELEMENT_DESC("BlockFillChar" , COM0R20_SER_cgf.au8FillChar               , &Number_Element_funcs, &UINT8RangeDesc     , ELEMENT_OPTIONAL)
  ELEMENT_DESC("SER0_IOADDRESS", COM0R20_SER_cgf.au16SER0_IOADDRESS        , &Number_Element_funcs, &ValidIOAddrPortDesc, ELEMENT_OPTIONAL)
 ELEMENT_BDESC("SER0_IRQ"      , COM0R20_SER_cgf.au8SER_IRQ      , 0, 4    , &Token_Element_funcs , &IRQTL              , ELEMENT_OPTIONAL)
  ELEMENT_DESC("SER1_IOADDRESS", COM0R20_SER_cgf.au16SER1_IOADDRESS        , &Number_Element_funcs, &ValidIOAddrPortDesc, ELEMENT_OPTIONAL)
 ELEMENT_BDESC("SER1_IRQ"      , COM0R20_SER_cgf.au8SER_IRQ      , 4, 4    , &Token_Element_funcs , &IRQTL              , ELEMENT_OPTIONAL)
};

EApiStatus_t
HandleCOM0R20CBHeaderBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  COM0R20_CB_t *pHeader=BHandel;
  size_t i, i2;
  COM0R20_CB_HDR_t *pCOM0R20_CB_cgf=pDesc->pDataContainer;
  CfgElementDesc_t   *pElementsDesc;

  DO(GetElementDesc((CfgNodeGen_t*)pDesc, (CfgNodeGen_t**)&pElementsDesc, "PCIePorts", CfgElementNode));
  memset(pHeader->GenId, 0x00, sizeof(*pHeader) - sizeof(EeePCmn_t));

  pHeader->EeePHdr.DeviceDesc =pCOM0R20_CB_cgf->au8DeviceDesc[0];

  memcpy(pHeader->GenId, COM0R20_CB_HEADER_ID, STRLEN(COM0R20_CB_HEADER_ID));

  EeeP_Set16BitValue_BE(pHeader->DevId.VendId  , pCOM0R20_CB_cgf->au16VendorId[0]);
  EeeP_Set16BitValue_BE(pHeader->DevId.DeviceId, pCOM0R20_CB_cgf->au16DeviceId[0]);
  pHeader->DevId.DeviceFlav=pCOM0R20_CB_cgf->au8DeviceFlav[0];
  pHeader->DevId.RevId     =pCOM0R20_CB_cgf->au8RevId[0];

  pHeader->CBType          =pCOM0R20_CB_cgf->au8CBType[0];
  pHeader->SpecRev         =pCOM0R20_CB_cgf->au8SpecRev[0];

  pHeader->UsbDesc         =pCOM0R20_CB_cgf->au8USBDesc[0];

  pHeader->SasDesc         =pCOM0R20_CB_cgf->au8SASDesc[0];

  pHeader->LanDesc         =pCOM0R20_CB_cgf->au8LanDesc[0];

  pHeader->MiscIo1         =pCOM0R20_CB_cgf->au8MiscIO1[0];
  pHeader->MiscIo2         =pCOM0R20_CB_cgf->au8MiscIO2[0];


  pHeader->DDIDesc[0]      =pCOM0R20_CB_cgf->au8DDI1[0];
  pHeader->DDIDesc[1]      =pCOM0R20_CB_cgf->au8DDI2[0];

  if(pElementsDesc->Instances.stUsedCnt){
    unsigned long *pulCurPort;
    unsigned int  uiBasePort;
    unsigned int  uiEncWidth;
    unsigned int  uiEndPort ;
    unsigned int  uiGen     ;
    for(
        i=pElementsDesc->Instances.stUsedCnt, 
        pulCurPort=pCOM0R20_CB_cgf->aulPCIePorts; 
        i; 
        i--,pulCurPort++
        )
    {
      uiBasePort=*pulCurPort>>16;
      uiEncWidth=((*pulCurPort>>8)&UINT8_MAX);
      uiEndPort =uiBasePort+(1<<(uiEncWidth-1));
      uiGen     =(*pulCurPort&UINT8_MAX);
      for(i2=uiBasePort;i2<uiEndPort;i2++){
        EAPI_APP_RETURN_ERROR_IF_S(
            HandleCOM0R20CBHeaderBlock,
            i2>=ARRAY_SIZE(pCOM0R20_CB_cgf->aulPCIePorts),
            EAPI_STATUS_ERROR
          );
        /*
         *  4 PCIe Gen Per Byte
         */
        pHeader->PCIeGen[i2/4]|=uiGen<<((i2%4)*2);
        /*
         *  2 PCIe Lane Widths Per Byte
         */
        pHeader->LaneMap[i2/2]|=uiEncWidth<<((i2%2)*4);
      }

    }
  }
EAPI_APP_ASSERT_EXIT
  return EAPI_STATUS_SUCCESS;
}
EApiStatus_t
HandleCOM0R20MHeaderBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  COM0R20_M_t *pHeader=BHandel;
  COM0R20_M_HDR_t *pCOM0R20_M_cgf=pDesc->pDataContainer;


  memset(pHeader->GenId, 0x00, sizeof(*pHeader) - sizeof(EeePCmn_t));
  pHeader->EeePHdr.DeviceDesc =pCOM0R20_M_cgf->au8DeviceDesc[0];

  memcpy(pHeader->GenId, COM0R20_M_HEADER_ID, STRLEN(COM0R20_M_HEADER_ID));

  EeeP_Set16BitValue_BE(pHeader->DevId.VendId  , pCOM0R20_M_cgf->au16VendorId[0]);
  EeeP_Set16BitValue_BE(pHeader->DevId.DeviceId, pCOM0R20_M_cgf->au16DeviceId[0]);
  pHeader->DevId.DeviceFlav=pCOM0R20_M_cgf->au8DeviceFlav[0];
  pHeader->DevId.RevId=pCOM0R20_M_cgf->au8RevId[0];

  pHeader->MType=pCOM0R20_M_cgf->au8MType[0];
  pHeader->SpecRev=pCOM0R20_M_cgf->au8SpecRev[0];

  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t
HandleEeePExpEepHeaderBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  Exp_EEP_t *pHeader=BHandel;
  EeeP_Exp_Hdr_t *pEeePExp_cgf=pDesc->pDataContainer;
  pHeader=BHandel;


  memset(pHeader->GenId, 0x00, sizeof(*pHeader) - sizeof(EeePCmn_t));
  pHeader->EeePHdr.DeviceDesc =pEeePExp_cgf->au8DeviceDesc[0];

  memcpy(pHeader->GenId, EEEP_EXP_HEADER_ID, STRLEN(EEEP_EXP_HEADER_ID));

  EeeP_Set16BitValue_BE(pHeader->DevId.VendId  , pEeePExp_cgf->au16VendorId[0]);
  EeeP_Set16BitValue_BE(pHeader->DevId.DeviceId, pEeePExp_cgf->au16DeviceId[0]);
  pHeader->DevId.DeviceFlav=(uint8_t)pEeePExp_cgf->au8DeviceFlav[0];
  pHeader->DevId.RevId=(uint8_t)pEeePExp_cgf->au8RevId[0];

  return EAPI_STATUS_SUCCESS;
}

EApiStatus_t
DBlockAllocWrap(
    DBlockIdHdr_t**pvBuffer    ,
    uint8_t       u8BlockId   ,
    size_t        stBlockLength,
    size_t        stMinBlckLen,
    uint8_t       u8FillChar
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  stMinBlckLen=EeePAlignLength(stMinBlckLen);
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleSmbiosChassisBlock ,
        EAPI_STATUS_INVALID_PARAMETER,
        pvBuffer
      );

  if(stMinBlckLen<stBlockLength){
    stMinBlckLen=stBlockLength;
  }
  *pvBuffer=malloc(stMinBlckLen);
  EAPI_APP_ASSERT_PARAMATER_NULL(
        HandleSmbiosChassisBlock ,
        EAPI_STATUS_ALLOC_ERROR,
        *pvBuffer
      );
  if(stMinBlckLen > stBlockLength){
    memset(EAPI_CREATE_PTR(*pvBuffer, stBlockLength, void*), u8FillChar, stMinBlckLen - stBlockLength);
  }
  memset(*pvBuffer, 0x00, stBlockLength);
  DO(SetDynBlockHeader(*pvBuffer, u8BlockId, stMinBlckLen));
EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


EApiStatus_t
HandleEeePExpI2CBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePExtI2CDeviceDesc_t *pHeader=NULL;
  DBlockIdHdr_t *pdHeader=NULL;
  EeePExtI2CDevice_t *pExtI2C_cgf=pDesc->pDataContainer;
  size_t stBlockLength=EeePAlignLength(sizeof(*pHeader));

  DO(DBlockAllocWrap(
        &pdHeader, 
        EEEP_BLOCK_ID_EXP_EEPROM, 
        stBlockLength, 
        pExtI2C_cgf->aulMinSize[0], 
        pExtI2C_cgf->au8FillChar[0]
      ));
  pHeader=(EeePExtI2CDeviceDesc_t*)pdHeader;


  EeeP_Set16BitValue_BE(pHeader->DeviceAddr  , pExtI2C_cgf->au16Addr[0]);

  pHeader->DeviceBus  =pExtI2C_cgf->au8Bus[0];

  pHeader->DeviceDesc =pExtI2C_cgf->au8DeviceDesc[0];

  DO(EeePAddBlock(BHandel, pHeader, NULL, pExtI2C_cgf->aulInsideCrc[0]));

EAPI_APP_ASSERT_EXIT
  if(pHeader) free(pHeader);
  return StatusCode;
}


EApiStatus_t
HandleCOM0R20SerialCfgBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  SerPortCfgBlock_t*pHeader=NULL;
  DBlockIdHdr_t *pdHeader=NULL;
  COM0R20_SERIAL_t *pCOM0Serial_cgf=pDesc->pDataContainer;
  size_t stBlockLength=EeePAlignLength(sizeof(*pHeader));


  DO(DBlockAllocWrap(
        &pdHeader, 
        COM0R20_BLOCK_ID_SERIO_DESC, 
        stBlockLength, 
        pCOM0Serial_cgf->aulMinSize[0], 
        pCOM0Serial_cgf->au8FillChar[0]
      ));
  pHeader=(SerPortCfgBlock_t*)pdHeader;

  EeeP_Set16BitValue_BE(pHeader->Ser0BaseAddr  , pCOM0Serial_cgf->au16SER0_IOADDRESS[0]);
  EeeP_Set16BitValue_BE(pHeader->Ser1BaseAddr  , pCOM0Serial_cgf->au16SER1_IOADDRESS[0]);

  pHeader->SerIRQ =pCOM0Serial_cgf->au8SER_IRQ[0];

  DO(EeePAddBlock(BHandel, pHeader, NULL, pCOM0Serial_cgf->aulInsideCrc[0]));

EAPI_APP_ASSERT_EXIT
  if(pHeader) free(pHeader);
  return StatusCode;
}


EApiStatus_t
HandleCOM0R20ExpCardCfgBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  ExpCardBlock_t   *pHeader=NULL;
  DBlockIdHdr_t *pdHeader=NULL;
  COM0R20_ECard_t  *pCOM0ExpCard_cgf=pDesc->pDataContainer;
  CfgElementDesc_t   *pElementsDesc;
  size_t stElementCnt ;
  size_t stBlockLength;
  uint8_t *pSwitchDevFuncAddr;
  uint8_t *pu8SwitchDevFuncAddr;
  DO(GetElementDesc((CfgNodeGen_t*)pDesc, (CfgNodeGen_t**)&pElementsDesc, "SwitchPFA", CfgElementNode));
  stElementCnt =pElementsDesc->Instances.stUsedCnt;
  stBlockLength=EeePAlignLength(
            sizeof(*pHeader)- 
            sizeof(pHeader->SwitchDevFuncAddr)+
            (stElementCnt*sizeof(pHeader->SwitchDevFuncAddr[0]))
          );

  DO(DBlockAllocWrap(
        &pdHeader, 
        COM0R20_BLOCK_ID_EXP_CARD_DESC, 
        stBlockLength, 
        pCOM0ExpCard_cgf->aulMinSize[0], 
        pCOM0ExpCard_cgf->au8FillChar[0]
      ));
  pHeader=(ExpCardBlock_t*)pdHeader;

  pHeader->ExpressCardNumber=pCOM0ExpCard_cgf->au8ExpCardNum[0];
  pHeader->ComExpressPort   =pCOM0ExpCard_cgf->au8PortDesc[0];


  for(
        pSwitchDevFuncAddr=pHeader->SwitchDevFuncAddr,
        pu8SwitchDevFuncAddr=pCOM0ExpCard_cgf->au8SwitchPFA;
        stElementCnt --;
        pSwitchDevFuncAddr++,
        pu8SwitchDevFuncAddr++
      )
  {
    *pSwitchDevFuncAddr=*pu8SwitchDevFuncAddr;
  }

  *pSwitchDevFuncAddr=COM0R20_EXPCARD_MAP_EOL;

  DO(EeePAddBlock(BHandel, pHeader, NULL, pCOM0ExpCard_cgf->aulInsideCrc[0]));

EAPI_APP_ASSERT_EXIT
  if(pHeader) free(pHeader);
  return StatusCode;
}

#define COUNT_STRLEN(StrName) \
  if(StrName!=NULL) stBlockLength+=strlen(StrName)+1;


#define APPEND_STRING(String, VarName)  \
  if(String    !=NULL){                 \
    VarName=(uint8_t)++i;                        \
    strcpy(pszStrBuffer, String);       \
    pszStrBuffer+=strlen(String)+1;     \
  }


EApiStatus_t
HandleSmbiosChassisBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePChassisInfo_t *pHeader;
  DBlockIdHdr_t *pdHeader=NULL;
  unsigned int i;
  SmbiosChassis_t *pSmbiosChassis_cgf=pDesc->pDataContainer;
  size_t stHeaderLength=sizeof(*pHeader)- sizeof(pHeader->CElement[0]);
  size_t stBlockLength=0;
  CCElement_t *pHandles1;
  CCElement_t *pHandles2;
  char *pszStrBuffer;
  CfgElementDesc_t   *pElementsDesc;

  DO(GetElementDesc((CfgNodeGen_t*)pDesc, (CfgNodeGen_t**)&pElementsDesc, "CElements", CfgElementNode));

  COUNT_STRLEN(pSmbiosChassis_cgf->aszManuf[0]     );
  COUNT_STRLEN(pSmbiosChassis_cgf->aszVersion[0]   );
  COUNT_STRLEN(pSmbiosChassis_cgf->aszSerialNum[0] );
  COUNT_STRLEN(pSmbiosChassis_cgf->aszAssetTag[0]  );

  stHeaderLength +=pElementsDesc->Instances.stUsedCnt*sizeof(pHeader->CElement[0]);
  stBlockLength  +=stHeaderLength+1;
  stBlockLength   =EeePAlignLength(stBlockLength);

  stHeaderLength -=sizeof(DBlockIdHdr_t) ;
  DO(DBlockAllocWrap(
        &pdHeader, 
        EEEP_BLOCK_ID_SMBIOS, 
        stBlockLength, 
        pSmbiosChassis_cgf->aulMinSize[0], 
        pSmbiosChassis_cgf->au8FillChar[0]
      ));
  pHeader=(EeePChassisInfo_t*)pdHeader;

  pHeader->Type         =pSmbiosChassis_cgf->au8ChassisType[0]     ;
  EeeP_Set32BitValue_BE(pHeader->OEM.b  , (uint32_t)pSmbiosChassis_cgf->au32OEM[0]);
  pHeader->Height       =pSmbiosChassis_cgf->au8Height[0]     ;
  pHeader->NumPowerCords=pSmbiosChassis_cgf->au8NumPowerCords[0]     ;
  pHeader->CElementCnt  =(uint8_t)pElementsDesc->Instances.stUsedCnt;
  pHeader->CElementSize =(uint8_t)sizeof(pHeader->CElement[0]);
  for(
        i=pHeader->CElementCnt,
        pHandles1=pHeader->CElement,
        pHandles2=pSmbiosChassis_cgf->aCElements;
        i;
        i--,
        pHandles1++,
        pHandles2++
      )
  {
    *pHandles1=*pHandles2;
  }

  pszStrBuffer=(char*)pHandles1;
  i=0;

  APPEND_STRING(pSmbiosChassis_cgf->aszManuf[0]     , pHeader->Manufacturer  );
  APPEND_STRING(pSmbiosChassis_cgf->aszVersion[0]   , pHeader->Version       );
  APPEND_STRING(pSmbiosChassis_cgf->aszSerialNum[0] , pHeader->SerialNumber  );
  APPEND_STRING(pSmbiosChassis_cgf->aszAssetTag[0]  , pHeader->AssetTagNumber);


  pHeader->SDBHdr.Type=SMBIOS_TypeSYSTEM_ENCLOSURE_OR_CHASSIS;
  pHeader->SDBHdr.Length=(uint8_t)stHeaderLength;
  EeeP_Set16BitValue_BE(pHeader->SDBHdr.Handle.b, pSmbiosChassis_cgf->au16Handle[0]);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pSmbiosChassis_cgf->aulInsideCrc[0]));
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}

EApiStatus_t
HandleSmbiosSystemBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePSystemInfo_t *pHeader;
  DBlockIdHdr_t *pdHeader=NULL;
  unsigned int i;
  SmbiosSystem_t *pSmbiosSystem_cgf=pDesc->pDataContainer;
  size_t stHeaderLength=sizeof(*pHeader);
  size_t stBlockLength=0;
  char *pszStrBuffer;

  COUNT_STRLEN(pSmbiosSystem_cgf->aszManuf[0]     );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszProduct[0]   );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszVersion[0]   );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszSerialNum[0] );
  COUNT_STRLEN(pSmbiosSystem_cgf->aszSKU_Number[0]);
  COUNT_STRLEN(pSmbiosSystem_cgf->aszFamily[0]    );

  stBlockLength  +=stHeaderLength+1;
  stBlockLength   =EeePAlignLength(stBlockLength);

  stHeaderLength -=sizeof(DBlockIdHdr_t) ;

  DO(DBlockAllocWrap(
        &pdHeader, 
        EEEP_BLOCK_ID_SMBIOS,
        stBlockLength, 
        pSmbiosSystem_cgf->aulMinSize[0], 
        pSmbiosSystem_cgf->au8FillChar[0]
      ));
  pHeader=(EeePSystemInfo_t*)pdHeader;


  pHeader->UUID=pSmbiosSystem_cgf->aUUID[0];
  
  pszStrBuffer =(char*)pHeader;
  pszStrBuffer+=sizeof(*pHeader);
  i=0;

  APPEND_STRING(pSmbiosSystem_cgf->aszManuf[0]     , pHeader->Manufacturer);
  APPEND_STRING(pSmbiosSystem_cgf->aszProduct[0]   , pHeader->ProductName );
  APPEND_STRING(pSmbiosSystem_cgf->aszVersion[0]   , pHeader->Version     );
  APPEND_STRING(pSmbiosSystem_cgf->aszSerialNum[0] , pHeader->SerialNumber);
  APPEND_STRING(pSmbiosSystem_cgf->aszSKU_Number[0], pHeader->SKU_Number  );
  APPEND_STRING(pSmbiosSystem_cgf->aszFamily[0]    , pHeader->Family      );

  pHeader->SDBHdr.Type=SMBIOS_TypeSYSTEM_INFORMATION;
  pHeader->SDBHdr.Length=(uint8_t)stHeaderLength;
  EeeP_Set16BitValue_BE(pHeader->SDBHdr.Handle.b, pSmbiosSystem_cgf->au16Handle[0]);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pSmbiosSystem_cgf->aulInsideCrc[0]));
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


EApiStatus_t
HandleSmbiosModuleBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePModuleInfo_t *pHeader;
  DBlockIdHdr_t *pdHeader=NULL;
  unsigned int i;
  SmbiosModule_t *pSmbiosModule_cgf=pDesc->pDataContainer;
  size_t stHeaderLength=sizeof(*pHeader)- sizeof(pHeader->Handles[0].b);
  size_t stBlockLength=0;
  SmbiosHandle_t *pHandles1;
  uint16_t      *pu16Handles2;
  uint8_t       *pu8Handles2;
  char *pszStrBuffer;
  CfgElementDesc_t   *pElementsDesc=EAPI_CREATE_PTR(pDesc->Elements.pIndx, pDesc->Elements.stElementSize*(pDesc->Elements.stUsedCnt - 1), void*);


  COUNT_STRLEN(pSmbiosModule_cgf->aszManuf[0]     );
  COUNT_STRLEN(pSmbiosModule_cgf->aszProduct[0]   );
  COUNT_STRLEN(pSmbiosModule_cgf->aszVersion[0]   );
  COUNT_STRLEN(pSmbiosModule_cgf->aszSerialNum[0] );
  COUNT_STRLEN(pSmbiosModule_cgf->aszAssetTag[0]  );
  COUNT_STRLEN(pSmbiosModule_cgf->aszLocation[0]  );

  stHeaderLength +=pElementsDesc->Instances.stUsedCnt*sizeof(pHeader->Handles[0].b);
  stBlockLength  +=stHeaderLength+1;
  stBlockLength   =EeePAlignLength(stBlockLength);

  stHeaderLength -=sizeof(DBlockIdHdr_t) ;

  DO(DBlockAllocWrap(
        &pdHeader, 
        EEEP_BLOCK_ID_SMBIOS,
        stBlockLength, 
        pSmbiosModule_cgf->aulMinSize[0], 
        pSmbiosModule_cgf->au8FillChar[0]
      ));
  pHeader=(EeePModuleInfo_t*)pdHeader;

  pHeader->FeatureFlag   =0   ;
  for(
        i=ARRAY_SIZE(pSmbiosModule_cgf->au8FeatureFlag),
        pu8Handles2=pSmbiosModule_cgf->au8FeatureFlag;
        i;
        i--,
        pu8Handles2++
      )
  {
    pHeader->FeatureFlag   |=*pu8Handles2;
  }
  EeeP_Set16BitValue_BE(pHeader->LocHdl.b  , pSmbiosModule_cgf->au16LocationHandle[0]);
  pHeader->BoardType     =(uint8_t)pSmbiosModule_cgf->au8BoardType[0]     ;
  pHeader->ContainedHndls=(uint8_t)pElementsDesc->Instances.stUsedCnt;
  for(
        i=pHeader->ContainedHndls,
        pHandles1=pHeader->Handles,
        pu16Handles2=pSmbiosModule_cgf->au16Handles;
        i;
        i--,
        pHandles1++,
        pu16Handles2++
      )
  {
    EeeP_Set16BitValue_BE(pHandles1->b  , *pu16Handles2);
  }

  pszStrBuffer=(char*)pHandles1;
  i=0;

  APPEND_STRING(pSmbiosModule_cgf->aszManuf[0]      , pHeader->Manufacturer);
  APPEND_STRING(pSmbiosModule_cgf->aszProduct[0]    , pHeader->Product     );
  APPEND_STRING(pSmbiosModule_cgf->aszVersion[0]    , pHeader->Version     );
  APPEND_STRING(pSmbiosModule_cgf->aszSerialNum[0]  , pHeader->SerialNumber);
  APPEND_STRING(pSmbiosModule_cgf->aszAssetTag[0]   , pHeader->AssetTag    );
  APPEND_STRING(pSmbiosModule_cgf->aszLocation[0]   , pHeader->Location    );


  pHeader->SDBHdr.Type=SMBIOS_TypeBASE_BOARD_MODULE_INFORMATION;
  pHeader->SDBHdr.Length=(uint8_t)stHeaderLength;
  EeeP_Set16BitValue_BE(pHeader->SDBHdr.Handle.b, pSmbiosModule_cgf->au16Handle[0]);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pSmbiosModule_cgf->aulInsideCrc[0]));
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


EApiStatus_t
HandleVendorBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePVendBlockHdr_t *pHeader;
  DBlockIdHdr_t *pdHeader=NULL;
  void *pvFileBuffer;
  size_t stFileSize;
  size_t stBlockLength;
  EeePVendorBlock_t *pVendorBlock=pDesc->pDataContainer;
  StatusCode=ReadBinaryFile(pVendorBlock->aszFilename[0], &pvFileBuffer, &stFileSize);
  if(!EAPI_TEST_SUCCESS(StatusCode)){
        fprintf(stderr, "ERROR: Opening %s\n", pVendorBlock->aszFilename[0]);
        return StatusCode;
  }
  stBlockLength=EeePAlignLength(stFileSize+sizeof(*pHeader));

  DO(DBlockAllocWrap(
        &pdHeader, 
        EEEP_BLOCK_ID_VENDOR_SPECIFIC, 
        stBlockLength, 
        pVendorBlock->aulMinSize[0], 
        pVendorBlock->au8FillChar[0]
      ));
  pHeader=(EeePVendBlockHdr_t*)pdHeader;

  EeeP_Set16BitValue_BE(pHeader->VendId, (uint16_t)pVendorBlock->au16VendorId[0]);
  pHeader->VendBlockId=pVendorBlock->au8VSBlockId[0];
  memcpy(
      EAPI_CREATE_PTR(pHeader, sizeof(*pHeader), void*), 
      pvFileBuffer, 
      stFileSize
    );

  DO(EeePAddBlock(BHandel, pHeader, NULL, pVendorBlock->aulInsideCrc[0]));
  free(pvFileBuffer);
  pvFileBuffer=NULL;
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


EApiStatus_t
HandleLFPDescBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePLFPDataBlock_t *pHeader;
  DBlockIdHdr_t *pdHeader=NULL;
  void *pvFileBuffer;
  size_t stFileSize;
  size_t stBlockLength;
  EeePLFP_t *pLfpBlock=pDesc->pDataContainer;
  StatusCode=ReadBinaryFile(pLfpBlock->aszFilename[0], &pvFileBuffer, &stFileSize);
  if(!EAPI_TEST_SUCCESS(StatusCode)){
        fprintf(stderr, "ERROR: Opening %s\n", pLfpBlock->aszFilename[0]);
        return StatusCode;
  }
  stBlockLength=EeePAlignLength(stFileSize+sizeof(*pHeader) - sizeof(pHeader->RawData));

  DO(DBlockAllocWrap(
        &pdHeader, 
        EEEP_BLOCK_ID_LFP, 
        stBlockLength, 
        pLfpBlock->aulMinSize[0], 
        pLfpBlock->au8FillChar[0]
      ));
  pHeader=(EeePLFPDataBlock_t*)pdHeader;

  pHeader->Interface=pLfpBlock->au8Interface[0];

  memcpy( pHeader->RawData, pvFileBuffer, stFileSize);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pLfpBlock->aulInsideCrc[0]));
  free(pvFileBuffer);
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


EApiStatus_t
HandleCustomBlock(
    struct CfgBlockDesc_s *pDesc,
    EeePHandel_t      BHandel
  )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  DBlockIdHdr_t *pHeader=NULL;
  void *pvFileBuffer;
  size_t stFileSize;
  size_t stBlockLength;
  EeePCustomBlock_t *pCustomBlock=pDesc->pDataContainer;
  StatusCode=ReadBinaryFile(pCustomBlock->aszFilename[0], &pvFileBuffer, &stFileSize);
  if(!EAPI_TEST_SUCCESS(StatusCode)){
        fprintf(stderr, "ERROR: Opening %s\n", pCustomBlock->aszFilename[0]);
        return StatusCode;
  }
  stBlockLength=EeePAlignLength(stFileSize+sizeof(*pHeader));

  DO(DBlockAllocWrap(
        &pHeader, 
        pCustomBlock->au8BlockId[0], 
        stBlockLength, 
        pCustomBlock->aulMinSize[0], 
        pCustomBlock->au8FillChar[0]
      ));

  memcpy( EAPI_CREATE_PTR(pHeader, sizeof(*pHeader), void*), pvFileBuffer, stFileSize);

  DO(EeePAddBlock(BHandel, pHeader, NULL, pCustomBlock->aulInsideCrc[0]));
  free(pvFileBuffer);
  free(pHeader);
  pHeader=NULL;

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}


CfgBlockDesc_t COM0R20_CB_CfgDesc[]={
  BLOCK_DESC("COM0R20_CB"         , COM0R20_CB_Desc        , &COM0R20_CB_cgf        , HandleCOM0R20CBHeaderBlock  , BLOCK_REQUIRED)
  BLOCK_DESC("SmbiosCarrier"      , SmbiosCarrierDesc      , &COM0_SMBIOS_Carrier   , HandleSmbiosModuleBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosSystem"       , SmbiosSystemDesc       , &COM0_SMBIOS_System    , HandleSmbiosSystemBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosChassis"      , SmbiosChassisDesc      , &COM0_SMBIOS_Chassis   , HandleSmbiosChassisBlock    , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData0"           , LFPData0Desc           , &EeeP_LFP0_Cfg         , HandleLFPDescBlock          , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData1"           , LFPData1Desc           , &EeeP_LFP1_Cfg         , HandleLFPDescBlock          , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice0"      , ExtI2CDevice0Desc      , &EeePExtI2CDevice0     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice1"      , ExtI2CDevice1Desc      , &EeePExtI2CDevice1     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp0Card"   , COM0R20_ExpCard0Desc   , &COM0R20_ECard0_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp1Card"   , COM0R20_ExpCard1Desc   , &COM0R20_ECard1_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_SerialPorts", COM0R20_SerialPortsDesc, &COM0R20_SER_cgf       , HandleCOM0R20SerialCfgBlock , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock0"       , VendorBlock0Desc       , &EeeP_VendorBlock0_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock1"       , VendorBlock1Desc       , &EeeP_VendorBlock1_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock2"       , VendorBlock2Desc       , &EeeP_VendorBlock2_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock3"       , VendorBlock3Desc       , &EeeP_VendorBlock3_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock4"       , VendorBlock4Desc       , &EeeP_VendorBlock4_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock5"       , VendorBlock5Desc       , &EeeP_VendorBlock5_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock6"       , VendorBlock6Desc       , &EeeP_VendorBlock6_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock0"       , CustomBlock0Desc       , &EeeP_CustomBlock0_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock1"       , CustomBlock1Desc       , &EeeP_CustomBlock1_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock2"       , CustomBlock2Desc       , &EeeP_CustomBlock2_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock3"       , CustomBlock3Desc       , &EeeP_CustomBlock3_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock4"       , CustomBlock4Desc       , &EeeP_CustomBlock4_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock5"       , CustomBlock5Desc       , &EeeP_CustomBlock5_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock6"       , CustomBlock6Desc       , &EeeP_CustomBlock6_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
};

CfgBlockDesc_t COM0R20_M_CfgDesc[]={
  BLOCK_DESC("COM0R20_M"          , COM0R20_M_Desc         , &COM0R20_M_cgf         , HandleCOM0R20MHeaderBlock, BLOCK_REQUIRED)
  BLOCK_DESC("SmbiosModule"       , SmbiosModuleDesc       , &COM0_SMBIOS_Module    , HandleSmbiosModuleBlock  , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData0"           , LFPData0Desc           , &EeeP_LFP0_Cfg         , HandleLFPDescBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData1"           , LFPData1Desc           , &EeeP_LFP1_Cfg         , HandleLFPDescBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock0"       , VendorBlock0Desc       , &EeeP_VendorBlock0_Cfg , HandleVendorBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock1"       , VendorBlock1Desc       , &EeeP_VendorBlock1_Cfg , HandleVendorBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock2"       , VendorBlock2Desc       , &EeeP_VendorBlock2_Cfg , HandleVendorBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock3"       , VendorBlock3Desc       , &EeeP_VendorBlock3_Cfg , HandleVendorBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock4"       , VendorBlock4Desc       , &EeeP_VendorBlock4_Cfg , HandleVendorBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock5"       , VendorBlock5Desc       , &EeeP_VendorBlock5_Cfg , HandleVendorBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock6"       , VendorBlock6Desc       , &EeeP_VendorBlock6_Cfg , HandleVendorBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock0"       , CustomBlock0Desc       , &EeeP_CustomBlock0_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock1"       , CustomBlock1Desc       , &EeeP_CustomBlock1_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock2"       , CustomBlock2Desc       , &EeeP_CustomBlock2_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock3"       , CustomBlock3Desc       , &EeeP_CustomBlock3_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock4"       , CustomBlock4Desc       , &EeeP_CustomBlock4_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock5"       , CustomBlock5Desc       , &EeeP_CustomBlock5_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock6"       , CustomBlock6Desc       , &EeeP_CustomBlock6_Cfg , HandleCustomBlock        , BLOCK_OPTIONAL)
};

CfgBlockDesc_t EeePExpEEP_CfgDesc[]={
  BLOCK_DESC("EeePExpEEP"         , EeePExpHdr_Desc        , &EeePExpHdr_cgf        , HandleEeePExpEepHeaderBlock , BLOCK_REQUIRED)
  BLOCK_DESC("SmbiosCarrier"      , SmbiosCarrierDesc      , &COM0_SMBIOS_Carrier   , HandleSmbiosModuleBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosSystem"       , SmbiosSystemDesc       , &COM0_SMBIOS_System    , HandleSmbiosSystemBlock     , BLOCK_OPTIONAL)
  BLOCK_DESC("SmbiosChassis"      , SmbiosChassisDesc      , &COM0_SMBIOS_Chassis   , HandleSmbiosChassisBlock    , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData0"           , LFPData0Desc           , &EeeP_LFP0_Cfg         , HandleLFPDescBlock          , BLOCK_OPTIONAL)
  BLOCK_DESC("LFPData1"           , LFPData1Desc           , &EeeP_LFP1_Cfg         , HandleLFPDescBlock          , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice0"      , ExtI2CDevice0Desc      , &EeePExtI2CDevice0     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("ExtI2CDevice1"      , ExtI2CDevice1Desc      , &EeePExtI2CDevice1     , HandleEeePExpI2CBlock       , BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp0Card"   , COM0R20_ExpCard0Desc   , &COM0R20_ECard0_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_Exp1Card"   , COM0R20_ExpCard1Desc   , &COM0R20_ECard1_cgf    , HandleCOM0R20ExpCardCfgBlock, BLOCK_OPTIONAL)
  BLOCK_DESC("COM0R20_SerialPorts", COM0R20_SerialPortsDesc, &COM0R20_SER_cgf       , HandleCOM0R20SerialCfgBlock , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock0"       , VendorBlock0Desc       , &EeeP_VendorBlock0_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock1"       , VendorBlock1Desc       , &EeeP_VendorBlock1_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock2"       , VendorBlock2Desc       , &EeeP_VendorBlock2_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock3"       , VendorBlock3Desc       , &EeeP_VendorBlock3_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock4"       , VendorBlock4Desc       , &EeeP_VendorBlock4_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock5"       , VendorBlock5Desc       , &EeeP_VendorBlock5_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("VendorBlock6"       , VendorBlock6Desc       , &EeeP_VendorBlock6_Cfg , HandleVendorBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock0"       , CustomBlock0Desc       , &EeeP_CustomBlock0_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock1"       , CustomBlock1Desc       , &EeeP_CustomBlock1_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock2"       , CustomBlock2Desc       , &EeeP_CustomBlock2_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock3"       , CustomBlock3Desc       , &EeeP_CustomBlock3_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock4"       , CustomBlock4Desc       , &EeeP_CustomBlock4_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock5"       , CustomBlock5Desc       , &EeeP_CustomBlock5_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
  BLOCK_DESC("CustomBlock6"       , CustomBlock6Desc       , &EeeP_CustomBlock6_Cfg , HandleCustomBlock           , BLOCK_OPTIONAL)
};



EApiStatus_t
EeeP_CreateEEPROMImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName,
    __IN   CfgBlockDesc_t * pCfgBlockDesc ,
    __IN   size_t           stCfgBlockCnt ,
    __IN   uint8_t         *pu8DevDesc    ,
    __IN   size_t           stHeaderSize 
    )
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  CfgBlockDesc_t *pDesc;
  size_t i;

  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        cszCfgFileName
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        pCfgBlockDesc
      );
  EAPI_APP_ASSERT_PARAMATER_NULL(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        pu8DevDesc
      );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        stCfgBlockCnt
      );
  EAPI_APP_ASSERT_PARAMATER_ZERO(
        EeeP_CreateEEPROMImage,
        EAPI_STATUS_INVALID_PARAMETER,
        stHeaderSize
      );
  /*
   * 
   */
  DO(ParseCfgFile(cszCfgFileName, pCfgBlockDesc, stCfgBlockCnt));
  /*
   * 
   */
  DO(EeePCreateNewBuffer(pBHandel, 256<<(*pu8DevDesc&EEEP_DEVICE_SIZE_MASK), stHeaderSize, EEEP_INIT_INCLUDE_CRC));
  /*
   * 
   */
  for(i=stCfgBlockCnt, pDesc=pCfgBlockDesc; i; i--, pDesc++){
    if(pDesc->stFound&&(pDesc->Handler!=NULL))
      DO(pDesc->Handler(pDesc, *pBHandel));
  }
  DO(EeePSetCRC(*pBHandel));
  /*
   * 
   */
  DO(CleanStruct(pCfgBlockDesc, stCfgBlockCnt));

EAPI_APP_ASSERT_EXIT
  return StatusCode;
}
EApiStatus_t
EeeP_CreateCOM0R20_CBImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    )
{
  return EeeP_CreateEEPROMImage(
        pBHandel                              ,
        cszCfgFileName                        ,
        COM0R20_CB_CfgDesc                    , 
        ARRAY_SIZE(COM0R20_CB_CfgDesc)        ,
        COM0R20_CB_cgf.au8DeviceDesc          ,
        sizeof(COM0R20_CB_t)
      );
}
EApiStatus_t
EeeP_CreateCOM0R20_MEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    )
{
  return EeeP_CreateEEPROMImage(
        pBHandel                              ,
        cszCfgFileName                        ,
        COM0R20_M_CfgDesc                     , 
        ARRAY_SIZE(COM0R20_M_CfgDesc)         ,
        COM0R20_M_cgf.au8DeviceDesc           ,
        sizeof(COM0R20_M_t)
      );
}
EApiStatus_t
EeeP_CreateEeePExtEEPImage(
    __OUT  EeePHandel_t   * pBHandel      ,
    __IN   const char     * cszCfgFileName
    )
{
  return EeeP_CreateEEPROMImage(
        pBHandel                              ,
        cszCfgFileName                        ,
        EeePExpEEP_CfgDesc                    ,
        ARRAY_SIZE(EeePExpEEP_CfgDesc)        ,
        EeePExpHdr_cgf.au8DeviceDesc          ,
        sizeof(Exp_EEP_t)
      );
}

EApiStatus_t
EeeP_CreateCOM0R20_CBCfg(
    __OUT  FILE           * OutStream
    )
{
  return  PrintCfgFile(
      COM0R20_CB_CfgDesc, 
      ARRAY_SIZE(COM0R20_CB_CfgDesc), 
      OutStream
    );
}

EApiStatus_t
EeeP_CreateCOM0R20_MEEPCfg(
    __OUT  FILE           * OutStream
    )
{
  return  PrintCfgFile(
      COM0R20_M_CfgDesc, 
      ARRAY_SIZE(COM0R20_M_CfgDesc), 
      OutStream
    );
}

EApiStatus_t
EeeP_CreateEeePExtEEPCfg(
    __OUT  FILE           * OutStream
    )
{
  return  PrintCfgFile(
      EeePExpEEP_CfgDesc, 
      ARRAY_SIZE(EeePExpEEP_CfgDesc), 
      OutStream
    );
}

#if TEST_EEPCFG
#define DO_MAIN(x)  \
  do{\
  EAPI_printf(        \
      TEXT("#####\n") \
      TEXT("#\t%s\n") \
      TEXT("#####\n"),\
      TEXT(#x)        \
    );                \
  StatusCode=x;   \
  if(!EAPI_TEST_SUCCESS(StatusCode)) \
    goto ErrorExit; \
  }while(0)

/*
 * Create Block Content
 */
int 
__cdecl 
main(void)
{
  EApiStatus_t StatusCode=EAPI_STATUS_SUCCESS;
  EeePHandel_t     BHandel ;

#ifdef _DEBUG
  _CrtSetDbgFlag( _CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag());
#endif

  DO_MAIN(EeeP_CreateCOM0R20_CBImage(
        &BHandel                              ,
        "COM0R20_CB.cfg"
      ));
  DO(EeePFreeBuffer(&BHandel));
  DO_MAIN(EeeP_CreateCOM0R20_MEEPImage(
        &BHandel                              ,
        "COM0R20_M.cfg"
      ));
  DO(EeePFreeBuffer(&BHandel));
  DO_MAIN(EeeP_CreateEeePExtEEPImage(
        &BHandel                              ,
        "EeePExpEEP.cfg"
      ));
  DO(EeePFreeBuffer(&BHandel));


  DO_MAIN(EeeP_CreateCOM0R20_CBCfg(stdout));
  DO_MAIN(EeeP_CreateCOM0R20_MEEPCfg(stdout));
  DO_MAIN(EeeP_CreateEeePExtEEPCfg(stdout));

EAPI_APP_ASSERT_EXIT
  exit(StatusCode);
}

#endif
