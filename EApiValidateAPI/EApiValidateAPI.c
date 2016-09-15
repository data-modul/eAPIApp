/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EApiValidateAPI/EApiValidateAPI.c $
 *+=========================================================================
 *I   Copyright: Copyright (c) 2002-2009, Kontron Embedded Modules GmbH
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
 *I  File Name            : EApiValidateAPI.c
 *I  File Location        : apps\EApiValidateAPI
 *I  Last committed       : $Revision: 74 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-06-23 21:26:50 +0200 (Wed, 23 Jun 2010) $
 *I  ID                   : $Id: EApiValidateAPI.c 74 2010-06-23 19:26:50Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#include <EApiApp.h>


#define END_OF_LIST_MARK ((uint32_t)-1)
typedef void EApiValidateTestFunction(void);
#define DESTRUCTIVE_ALLOWED 1
#define I2CBUS 10

/*  */
FILE *LogStream;

EApiStatus_t
EApiGetErrorStringA(
        __OUT const char  **const pszString     ,
        __IN EApiStatus_t StatusCode
        );

signed int
__cdecl
siFFormattedMessage_SC(
        FILE       *  OutStream   ,
        char          cType       ,
        const char *  cszFileName ,
        const char *  cszFuncName ,
        unsigned int  uiLineNum   ,
        EApiStatus_t  StatusCode  ,
        const char *  cszFormat   ,
        ...
        )
EAPI_PRINTF_ARG(7, 8);

signed int
__cdecl
siFFormattedMessage_SC(
        FILE       *  OutStream   ,
        char          cType       ,
        const char *  cszFileName ,
        const char *  cszFuncName ,
        unsigned int  uiLineNum   ,
        EApiStatus_t  StatusCode  ,
        const char *  cszFormat   ,
        ...
        )
{
    signed int Ret;
    va_list _ArgList;
    const char *szStatusDesc;
    cszFileName=cszFileName;
    va_start(_ArgList, cszFormat);
    EApiGetErrorStringA(&szStatusDesc, StatusCode);
    Ret = fprintf(
                OutStream,
                "%c%04i %-30s | ",
                cType       ,
                uiLineNum   ,
                cszFuncName
                );
    if(szStatusDesc==NULL){
        fprintf(OutStream, "               0x%08"PRIX32" | ", StatusCode);
    }else{
        fprintf(OutStream, "%-25s | ", szStatusDesc);
    }
    Ret += vfprintf(OutStream, cszFormat, _ArgList);
    va_end(_ArgList);
    return Ret;
}

#define EAPI_LOG_FORMATED_MES(type, func, err, desc) \
    siFFormattedMessage_SC(LogStream, type, __FILE__, #func,  __LINE__, err, "%s\n", desc )
#define EAPI_LOG_RETURN_VALUE(func, tblRef) \
    siFFormattedMessage_SC(LogStream, 'L', __FILE__, #func, __LINE__, StatusCode, "   %2d    %2d    [%s]\n", \
    i, i2, FailPass[((tblRef[i2].StatusCode1==StatusCode)||(tblRef[i2].StatusCode2==StatusCode)||(tblRef[i2].StatusCode3==StatusCode))])



EApiValidateTestFunction EApiValidateStringApi ;
EApiValidateTestFunction EApiValidateValuesApi ;
EApiValidateTestFunction EApiValidateI2CApi    ;
//EApiValidateTestFunction EApiValidateStorageApi;
//EApiValidateTestFunction EApiValidateGPIOApi   ;



TCHAR Buffer[1024]={0};
uint32_t BufPtrLen=ARRAY_SIZE(Buffer);

const char *FailPass[]={
    "FAIL",
    "PASS",
};

/*
 * Test String Function Table
 *
 */
typedef struct EApiStringType_s{
    const EApiId_t Id  ;
    const TCHAR *const   Desc;
}EApiStringType_t;
const EApiStringType_t EApiStrings[]={
    {EAPI_ID_BOARD_MANUFACTURER_STR  , TEXT("Manufacturer"        )},
    {EAPI_ID_BOARD_NAME_STR          , TEXT("Board Name"          )},
    {EAPI_ID_BOARD_SERIAL_STR        , TEXT("Board Serial Number" )},
    {EAPI_ID_BOARD_BIOS_REVISION_STR , TEXT("Bios Revision"       )},
    {EAPI_ID_BOARD_PLATFORM_TYPE_STR , TEXT("Platform Type"       )},
    {EAPI_ID_BOARD_HW_REVISION_STR ,   TEXT("HW Revision"       )},
    {EAPI_ID_BOARD_REVISION_STR ,      TEXT("Board Revision"       )},
    {EAPI_DMO_ID_BOARD_MANUFACTURING_DATE_STR , TEXT("Manufacturing Date"       )},
};
void EApiValidateStringApi (void)
{
    EApiStatus_t StatusCode;
    char * pBuffer;
    uint32_t pBufferLen;

    pBufferLen = 100;
    pBuffer=(char *)malloc((pBufferLen) * sizeof(char));

    printf("\n");
    for(unsigned i=0;i<ARRAY_SIZE(EApiStrings);i++){
        pBufferLen = 100;
        StatusCode = EApiBoardGetStringA(EApiStrings[i].Id, pBuffer,&pBufferLen);
        if (StatusCode == EAPI_STATUS_SUCCESS)
        {
            EAPI_MSG_OUT(
                        TEXT("%-30s : %s\n"),
                        EApiStrings[i].Desc,
                        pBuffer
                        );
        }
        else
            EAPI_MSG_OUT(
                        TEXT("%-30s : EAPI_STATUS_UNSUPPORTED\n"),
                        EApiStrings[i].Desc
                        );
    }
    free(pBuffer);
    return;
}



/*
 * Test Value Function Table
 *
 */

typedef struct EApiValueType_s{
    const EApiId_t  Id  ;
    const TCHAR *const   Desc;
    CreateStringFunction *const CreateString;
}EApiValueType_t;

const EApiValueType_t EApiValues[]={
    {EAPI_ID_GET_EAPI_SPEC_VERSION        , TEXT("EApi Spec Version"   ), EApiAHCreateSVersionString   },
    {EAPI_ID_BOARD_BOOT_COUNTER_VAL       , TEXT("Boot Counter"        ), EApiAHCreateDecimalString    },
    {EAPI_ID_BOARD_RUNNING_TIME_METER_VAL , TEXT("Running Time Meter"  ), EApiAHCreateTimeString       },
    {EAPI_ID_BOARD_PNPID_VAL              , TEXT("Manufacturer PNP ID" ), EApiAHCreatePNPIDString      },
    {EAPI_ID_BOARD_PLATFORM_REV_VAL       , TEXT("Platform Revision"   ), EApiAHCreateSVersionString   },
    {EAPI_ID_BOARD_DRIVER_VERSION_VAL     , TEXT("Driver Version"      ), EApiAHCreateVersionString    },
    {EAPI_ID_BOARD_LIB_VERSION_VAL        , TEXT("LIB Version"         ), EApiAHCreateVersionString    },
    /* HW Monitoring  */
    /* Temperature  */
    {EAPI_ID_HWMON_CPU_TEMP               , TEXT("CPU Temperature"     ), EApiAHCreateTempString       },
    {EAPI_ID_HWMON_CHIPSET_TEMP           , TEXT("Chipset Temperature" ), EApiAHCreateTempString       },
    {EAPI_ID_HWMON_SYSTEM_TEMP            , TEXT("System Temperature"  ), EApiAHCreateTempString       },
    /* Voltage */
    {EAPI_ID_HWMON_VOLTAGE_VCORE          , TEXT("VCORE"               ), EApiAHCreateVoltageString    },
    {EAPI_ID_HWMON_VOLTAGE_2V5            , TEXT("2.5V"                ), EApiAHCreateVoltageString    },
    {EAPI_ID_HWMON_VOLTAGE_3V3            , TEXT("3.3V"                ), EApiAHCreateVoltageString    },
    {EAPI_ID_HWMON_VOLTAGE_VBAT           , TEXT("VBAT"                ), EApiAHCreateVoltageString    },
    {EAPI_ID_HWMON_VOLTAGE_5V             , TEXT("5V"                  ), EApiAHCreateVoltageString    },
    {EAPI_ID_HWMON_VOLTAGE_5VSB           , TEXT("5VSB"                ), EApiAHCreateVoltageString    },
    {EAPI_ID_HWMON_VOLTAGE_12V            , TEXT("12V"                 ), EApiAHCreateVoltageString    },
    /* Fan Rotations */
    {EAPI_ID_HWMON_FAN_CPU                , TEXT("Cpu Fan"             ), EApiAHCreateRotationsString  },
    {EAPI_ID_HWMON_FAN_SYSTEM             , TEXT("System Fan"          ), EApiAHCreateRotationsString  },
};


void EApiValidateValuesApi (void)
{

    EApiStatus_t StatusCode;
    uint32_t Value;
    unsigned i;


    TCHAR TmpStrBuf[1024];
    printf("\n");

    for(i=0;i<ARRAY_SIZE(EApiValues);i++){
        if((StatusCode=EApiBoardGetValue(EApiValues[i].Id, &Value))==EAPI_STATUS_SUCCESS)
        {
            EApiValues[i].CreateString(Value, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30s : %s\n"), EApiValues[i].Desc, TmpStrBuf);
        }else{
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30s : %s\n"), EApiValues[i].Desc, TmpStrBuf);
        }
    }
    return ;
}

/*
 * Test I2C Function
 *
 */
//const EApiI2CType_t EApiI2CBuses[]={
//    {EAPI_ID_I2C_EXTERNAL, TEXT("External I2C"  )},
//    {EAPI_ID_I2C_LVDS_1  , TEXT("LVDS 1 I2C/DDC")},
//    {EAPI_ID_I2C_LVDS_2  , TEXT("LVDS 2 I2C/DDC")},
//    {0x00000F00          , TEXT("Unsupported"   )},
//};
void printHex(
        __IN FILE*  OutStream,
        __IN void * pBuffer  ,
        __IN size_t ByteCount
        )
{
    for(; ByteCount --; ){
        EAPI_fprintf(OutStream, TEXT("%02")TEXT(PRIX8), *((uint8_t*)pBuffer));
        pBuffer=((uint8_t*)pBuffer)+1;
    }
}
void EApiValidateI2CApi (void)
{
    EApiStatus_t StatusCode;

    //_________ simulate ___________________________________

    uint8_t pBuffer0[60]="I find fictional characters to be better than real people.";
    StatusCode=EApiI2CWriteTransfer(
                I2CBUS,
                0x64,
                EAPI_I2C_ENC_STD_CMD(0),
                pBuffer0,
                60
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
        printf("successfull\n");
    else
        printf("It is an error\n");

    printf("\n");
    uint8_t prBuffer00[60];
    StatusCode=EApiI2CReadTransfer(
                I2CBUS,
                0x64,
                EAPI_I2C_ENC_STD_CMD(0),
                prBuffer00,
                60,
                60
                );

    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        for(int j =0 ; j < 60; j++)
            printf("%c  ",prBuffer00[j]);
    }
    else
        printf("It is an error.\n");

    printf("\n");

    //____________ i2c ________________________________

    uint8_t prBuffer2[8];

    StatusCode=EApiI2CReadTransfer(
                I2CBUS,
                0x27,
                EAPI_I2C_ENC_STD_CMD(0),
                prBuffer2,
                8,
                8
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        for (int i =0 ; i < 8 ; i++)
            printf("%x  ",prBuffer2[i]);
    }
    else
        printf("It is an error.\n");
    printf("\n");

    //____________________________________________

    uint8_t pBuffer3[6];
    for(int j=0; j< 6; j++)
        pBuffer3[j]=j;
    pBuffer3[4]=0x00;

    StatusCode=EApiI2CWriteTransfer(
                I2CBUS,
                0x27,
                EAPI_I2C_ENC_STD_CMD(2),
                pBuffer3,
                6
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
        printf("successfull\n");
    else
        printf("It is an error\n");


    StatusCode=EApiI2CReadTransfer(
                I2CBUS,
                0x27,
                EAPI_I2C_ENC_STD_CMD(0),
                prBuffer2,
                8,
                8
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        for (int i =0 ; i < 8 ; i++)
            printf("%x  ",prBuffer2[i]);
    }
    else
        printf("It is an error.\n");
    /*****************************/

    for (int j=0; j <6 ; j++)
    {
        StatusCode=EApiI2CWriteTransfer(
                    I2CBUS,
                    0x27,
                    EAPI_I2C_ENC_STD_CMD(2),
                    &pBuffer3[j],
                    1
                    );
        if(EAPI_TEST_SUCCESS(StatusCode))
            printf("successfull\n");
        else
            printf("It is an error\n");
        sleep(1);
    }

    StatusCode=EApiI2CReadTransfer(
                I2CBUS,
                0x27,
                EAPI_I2C_ENC_STD_CMD(0),
                prBuffer2,
                8,
                8
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        for (int i =0 ; i < 8 ; i++)
            printf("%x  ",prBuffer2[i]);
    }
    else
        printf("It is an error.\n");

    //__ eeprom __________________________________________

    uint8_t outvalue;
    FILE *file;
    int j =0;
    file = fopen("eeprom.bak","r");

    outvalue = fgetc(file);
    while ( !feof(file) && (j < 208))
    {
        StatusCode=EApiI2CWriteTransfer(
                    I2CBUS,
                    0x50,
                    EAPI_I2C_ENC_EXT_CMD(j),
                    &outvalue,
                    1
                    );
        if(EAPI_TEST_SUCCESS(StatusCode))
            printf("successfull\n");
        else
            printf("Error\n");
        sleep(1);

        j++;
        outvalue = fgetc(file);
    }
    fclose(file);
    //********************************

    uint8_t prBuffer1[208];
    StatusCode=EApiI2CReadTransfer(
                I2CBUS,
                0x50,
                EAPI_I2C_ENC_EXT_CMD(0x00),
                prBuffer1,
                208,
                208
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        int k =0;
        for (int i =0 ; i < 208 ; i++){
            if((k % 16) == 0)
                printf("\n");
            else if ( (k % 8) == 0)
                printf(" ");
            k++;

            printf("%02x  ",prBuffer1[i]);
        }

        printf("\n");
    }
    else
        printf("It is an error\n");

    return;
}
/*
 * Test Storage Function
 *
 */

//typedef struct EApiStorageType_s{
//    const EApiId_t  Id     ;
//    const TCHAR *const   Desc   ;
//    const uint32_t  Length ;
//}EApiStorageType_t;

//const EApiStorageType_t EApiStorageDevices[]={
//    {EAPI_ID_STORAGE_STD        , TEXT("Standard Storage"   ), 0x20},
//    {EAPI_PMG_ID_STORAGE_SAMPLE , TEXT("Dummy PICMG Storage"), 0x80},
//    {0x00000F00                 , TEXT("Unsupported"        ), 0x20},
//};

//typedef struct EApiStorageValidate_s{
//    const uint32_t  Offset      ; /* Read Offset */
//    void *    BufPtr      ; /* Buffer Pointer */
//    const uint32_t  BufPtrLen   ; /* Buffer Length */
//    const uint32_t  ByteCnt     ; /* Byte Count  */
//    const EApiStatus_t  StatusCode1 ; /* Allowed Return Value 1 */
//    const EApiStatus_t  StatusCode2 ; /* Allowed Return Value 2 */
//    const EApiStatus_t  StatusCode3 ; /* Allowed Return Value 3 */
//}EApiStorageValidate_t;
//const EApiStorageValidate_t StorageValidate[]={
//    {0x0000, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_SUCCESS             , EAPI_STATUS_UNSUPPORTED         , EAPI_STATUS_UNSUPPORTED       },
//    {0x0000, NULL  , ARRAY_SIZE(Buffer), 100, EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_PARAMETER },
//    {0x0021, Buffer,            0x0000 ,  20, EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_BLOCK_LENGTH, EAPI_STATUS_UNSUPPORTED       },
//    {0x0021, Buffer,            0x0010 ,  20, EAPI_STATUS_INVALID_BLOCK_LENGTH, EAPI_STATUS_SUCCESS             , EAPI_STATUS_UNSUPPORTED       },
//    {0x0021, Buffer, ARRAY_SIZE(Buffer),   0, EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_INVALID_PARAMETER   , EAPI_STATUS_UNSUPPORTED       },
//    {0x0001, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_SUCCESS             , EAPI_STATUS_UNSUPPORTED         , EAPI_STATUS_UNSUPPORTED       },
//};
//typedef struct EApiStorageCapValidate_s{
//    uint32_t *pStorgeSize ; /* Read Offset */
//    uint32_t *pBlockLen   ; /* Buffer Pointer */
//    const EApiStatus_t  StatusCode1 ; /* Allowed Return Value 1 */
//    const EApiStatus_t  StatusCode2 ; /* Allowed Return Value 2 */
//    const EApiStatus_t  StatusCode3 ; /* Allowed Return Value 3 */
//}EApiStorageCapValidate_t;
//uint32_t StorageSize;
//uint32_t BlockLength;
//const EApiStorageCapValidate_t StorageCapValidate[]={
//    {&StorageSize, &BlockLength, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
//    {&StorageSize, NULL        , EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
//    {NULL        , &BlockLength, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
//    {NULL        , NULL        , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
//};
//void EApiValidateStorageApi(void)
//{
//    TCHAR TmpStrBuf[1024];
//    unsigned i,i2;
//    EApiStatus_t StatusCode;

//    for(i=0;i<ARRAY_SIZE(EApiStorageDevices);i++){
//        StatusCode=EApiStorageAreaRead(
//                    EApiStorageDevices[i].Id,
//                    0,
//                    TmpStrBuf,
//                    ARRAY_SIZE(TmpStrBuf) , /* For Debug Purposes */
//                    EApiStorageDevices[i].Length
//                    );
//        if(EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EAPI_MSG_OUT(
//                        TEXT("%-30s : "),
//                        EApiStorageDevices[i].Desc
//                        );
//            printHex(stdout, TmpStrBuf, 16);
//            EAPI_MSG_OUT(TEXT("\n"));
//#if DESTRUCTIVE_ALLOWED
//            StatusCode=EApiAHWriteStorage(
//                        EApiStorageDevices[i].Id      ,
//                        13                            ,
//                        TmpStrBuf                     ,
//                        EApiStorageDevices[i].Length/5
//                        );
//            if(EAPI_TEST_SUCCESS(StatusCode))
//            {
//                EAPI_MSG_OUT(
//                            TEXT("%-30s : "),
//                            EApiStorageDevices[i].Desc
//                            );
//                printHex(stdout, TmpStrBuf, 16);
//                EAPI_MSG_OUT(TEXT("\n"));
//            }
//            else
//            {
//                EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//                EAPI_MSG_OUT(
//                            TEXT("%-30s : %02")TEXT(PRIX8)TEXT(" %s\n")      ,
//                            EApiStorageDevices[i].Desc,
//                            I2CDevices[i].DeviceAddr  ,
//                            TmpStrBuf
//                            );
//            }
//#endif
//        }
//        else
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(TEXT("%-30s : %s\n"), EApiStorageDevices[i].Desc, TmpStrBuf);
//        }
//    }
//    /*
//   * More Rigorous Interfaces Verification
//   */
//    for(i=0;i<10;i++) /* Iterate thought Ids */
//    {
//        for(i2=0;i2<ARRAY_SIZE(StorageValidate);i2++) /* Iterated thought test cases */
//        {
//            StatusCode=EApiStorageAreaRead(
//                        i                             ,
//                        StorageValidate[i2].Offset    ,
//                        StorageValidate[i2].BufPtr    ,
//                        StorageValidate[i2].BufPtrLen ,
//                        StorageValidate[i2].ByteCnt
//                        );
//            EAPI_LOG_RETURN_VALUE(EApiStorageAreaRead, StorageValidate);
//#if DESTRUCTIVE_ALLOWED
//            StatusCode=EApiStorageAreaWrite(
//                        i                           ,
//                        StorageValidate[i2].Offset  ,
//                        StorageValidate[i2].BufPtr  ,
//                        StorageValidate[i2].ByteCnt
//                        );
//            EAPI_LOG_RETURN_VALUE(EApiStorageAreaWrite, StorageValidate);
//#endif
//        }
//    }
//    for(i=0;i<10;i++) /* Iterated thought Ids */
//    {
//        for(i2=0;i2<ARRAY_SIZE(StorageCapValidate);i2++) /* Iterated thought test cases */
//        {
//            StatusCode=EApiStorageCap(
//                        i                                 ,
//                        StorageCapValidate[i2].pStorgeSize,
//                        StorageCapValidate[i2].pBlockLen
//                        );
//            EAPI_LOG_RETURN_VALUE(EApiStorageCap, StorageCapValidate);
//        }
//    }
//    return ;
//}

/*
 * Test GPIO Function
 *
 */

//typedef struct EApiGpioValidate_s{
//    uint32_t *pInputs     ; /* Value Pointer*/
//    uint32_t *pOutputs    ; /* Value Pointer*/
//    const EApiStatus_t  StatusCode1 ; /* Allowed Return Value 1 */
//    const EApiStatus_t  StatusCode2 ; /* Allowed Return Value 2 */
//    const EApiStatus_t  StatusCode3 ; /* Allowed Return Value 3 */
//}EApiGpioValidate_t;
//uint32_t GpioInputs;
//uint32_t GpioOutputs;
//const EApiGpioValidate_t EApiGpioterfaceValidate[]={
//    {&GpioInputs, &GpioOutputs, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
//    {&GpioInputs, NULL        , EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
//    {NULL       , &GpioOutputs, EAPI_STATUS_SUCCESS          , EAPI_STATUS_UNSUPPORTED       , EAPI_STATUS_UNSUPPORTED       },
//    {NULL       , NULL        , EAPI_STATUS_INVALID_PARAMETER, EAPI_STATUS_INVALID_PARAMETER , EAPI_STATUS_INVALID_PARAMETER },
//};

//typedef struct EApiGpioType_s{
//    const EApiId_t  Id     ;
//    const TCHAR *const   Desc   ;
//}EApiGpioType_t;

//const EApiGpioType_t EApiGpioDevices[]={
//    {EAPI_ID_GPIO_BANK00   , TEXT("GPIO Bank0"      )},
//    {EAPI_GPIO_GPIO_ID(0)  , TEXT("GPIO GPIO0"      )},
//    {EAPI_GPIO_GPIO_ID(1)  , TEXT("GPIO GPIO1"      )},
//    {EAPI_GPIO_GPIO_ID(2)  , TEXT("GPIO GPIO2"      )},
//    {EAPI_GPIO_GPIO_ID(3)  , TEXT("GPIO GPIO3"      )},
//    {EAPI_GPIO_GPIO_ID(4)  , TEXT("GPIO GPIO4"      )},
//    {EAPI_GPIO_GPIO_ID(5)  , TEXT("GPIO GPIO5"      )},
//    {EAPI_GPIO_GPIO_ID(6)  , TEXT("GPIO GPIO6"      )},
//    {EAPI_GPIO_GPIO_ID(7)  , TEXT("GPIO GPIO7"      )},
//    {EAPI_GPIO_GPIO_ID(8)  , TEXT("GPIO GPIO8"      )},
//    {EAPI_GPIO_GPIO_ID(9)  , TEXT("GPIO GPIO9"      )},
//    {0x00000F00            , TEXT("Unsupported"     )},
//};


//void EApiValidateGPIOApi(void)
//{
//    TCHAR TmpStrBuf[1024];
//    unsigned i,i2;
//    uint32_t Direction;
//    uint32_t Level;
//    uint32_t Inputs;
//    uint32_t Outputs;
//    EApiStatus_t StatusCode;
//    for(i=0;i<ARRAY_SIZE(EApiGpioDevices);i++){
//        /*       *((int*)NULL)=0; */
//        StatusCode=EApiGPIOGetDirectionCaps(EApiGpioDevices[i].Id, &Inputs, &Outputs);
//        if(!EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(
//                        TEXT("%-15s %-25s : %s\n"),
//                        EApiGpioDevices[i].Desc,
//                        TEXT("EApiGPIOGetDirectionCaps"),
//                        TmpStrBuf
//                        );
//            continue;
//        }
//        EAPI_MSG_OUT(
//                    TEXT("%-15s %-25s : Inputs   =%08")TEXT(PRIX32)TEXT(" Outputs=%08")TEXT(PRIX32)TEXT("\n"),
//                    EApiGpioDevices[i].Desc,
//                    TEXT("EApiGPIOGetDirectionCaps"),
//                    Inputs,
//                    Outputs
//                    );
//        StatusCode=EApiGPIOGetDirection(EApiGpioDevices[i].Id, Inputs|Outputs, &Direction);
//        if(!EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(
//                        TEXT("%-15s %-25s : %s\n"),
//                        EApiGpioDevices[i].Desc,
//                        TEXT("EApiGPIOGetDirection"),
//                        TmpStrBuf
//                        );
//            continue;
//        }
//        EAPI_MSG_OUT(
//                    TEXT("%-15s %-25s : Direction=%08")TEXT(PRIX32)TEXT("\n"),
//                    EApiGpioDevices[i].Desc,
//                    TEXT("EApiGPIOGetDirection"),
//                    Direction
//                    );
//        StatusCode=EApiGPIOGetLevel(EApiGpioDevices[i].Id, Inputs|Outputs, &Level);
//        if(!EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(
//                        TEXT("%-15s %-25s : %s\n"),
//                        EApiGpioDevices[i].Desc,
//                        TEXT("EApiGPIOGetLevel"),
//                        TmpStrBuf
//                        );
//            continue;
//        }
//        EAPI_MSG_OUT(
//                    TEXT("%-15s %-25s : Level    =%08")TEXT(PRIX32)TEXT("\n"),
//                    EApiGpioDevices[i].Desc,
//                    TEXT("EApiGPIOGetLevel"),
//                    Level
//                    );
//        StatusCode=EApiGPIOSetDirection(
//                    EApiGpioDevices[i].Id,
//                    Inputs|Outputs,
//                    ((Inputs&0xFFFF))|((Outputs&0x0000))
//                    );
//        if(!EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(
//                        TEXT("%-15s %-25s : %s\n"),
//                        EApiGpioDevices[i].Desc,
//                        TEXT("EApiGPIOSetDirection"),
//                        TmpStrBuf
//                        );
//            continue;
//        }
//        StatusCode=EApiGPIOGetDirection(EApiGpioDevices[i].Id, Inputs|Outputs, &Direction);
//        if(!EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(
//                        TEXT("%-15s %-25s : %s\n"),
//                        EApiGpioDevices[i].Desc,
//                        TEXT("EApiGPIOGetDirection"),
//                        TmpStrBuf
//                        );
//            continue;
//        }
//        EAPI_MSG_OUT(
//                    TEXT("%-15s %-25s : Direction=%08")TEXT(PRIX32)TEXT("\n"),
//                    EApiGpioDevices[i].Desc,
//                    TEXT("EApiGPIOGetDirection"),
//                    Direction
//                    );
//        StatusCode=EApiGPIOSetLevel(EApiGpioDevices[i].Id, Outputs, Outputs);
//        if(!EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(
//                        TEXT("%-15s %-25s : %s\n"),
//                        EApiGpioDevices[i].Desc,
//                        TEXT("EApiGPIOSetLevel"),
//                        TmpStrBuf
//                        );
//            continue;
//        }
//        StatusCode=EApiGPIOGetLevel(EApiGpioDevices[i].Id, Inputs|Outputs, &Level);
//        if(!EAPI_TEST_SUCCESS(StatusCode))
//        {
//            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
//            EAPI_MSG_OUT(
//                        TEXT("%-15s %-25s : %s\n"),
//                        EApiGpioDevices[i].Desc,
//                        TEXT("EApiGPIOGetDirection"),
//                        TmpStrBuf
//                        );
//            continue;
//        }
//        EAPI_MSG_OUT(
//                    TEXT("%-15s %-25s : Level    =%08")TEXT(PRIX32)TEXT("\n"),
//                    EApiGpioDevices[i].Desc,
//                    TEXT("EApiGPIOSetLevel"),
//                    Level);
//    }
//    for(i=0;i<10;i++) /* Iterated throught Ids */
//    {
//        for(i2=0;i2<ARRAY_SIZE(EApiGpioterfaceValidate);i2++) /* Iterated thought test cases */
//        {
//            StatusCode=EApiGPIOGetDirectionCaps(
//                        i,
//                        EApiGpioterfaceValidate[i2].pInputs,
//                        EApiGpioterfaceValidate[i2].pOutputs
//                        );
//            EAPI_LOG_RETURN_VALUE(EApiGPIOGetDirectionCaps, EApiGpioterfaceValidate);
//        }
//    }
//    return ;
//}
/*
 * Test Functions Table
 *
 */
typedef struct TestFunctionsTbl_s{
    EApiValidateTestFunction *TestHandler;
    const TCHAR *const TestDesc;
}TestFunctionsTbl_t;
const TestFunctionsTbl_t TestFunctions[]={
    {EApiValidateValuesApi  , TEXT("Values Function"     )},
    {EApiValidateStringApi  , TEXT("Strings Function"    )},
    {EApiValidateI2CApi     , TEXT("I2C Function"        )},
    //{EApiValidateStorageApi , TEXT("Storage Function"    )},
    // {EApiValidateGPIOApi    , TEXT("Gpio Function"       )},
};
/* void __cdecl main( __IN  char *const *const  argv, __IN const int argc) */
typedef enum ProgramStatusCodes_e{
    PRG_RETURN_OK             =0,
    PRG_RETURN_ERROR            ,
    PRG_RETURN_LIB_INIT_ERROR   ,
    PRG_RETURN_LIB_UNINIT_ERROR
}ProgramStatusCodes_t;
int
__cdecl
main(void)
{
    //unsigned i;

    LogStream=EAPI_fopen(TEXT("EApiValidateAPI.log"), TEXT("w"));
    if(LogStream==NULL)
        LogStream=stdout;
    if(!EAPI_TEST_SUCCESS(EApiLibInitialize()))
    {
        exit(PRG_RETURN_LIB_INIT_ERROR);
    }
    EAPI_fprintf(
                LogStream,
                TEXT("L%04u %-30s | %-25s | %5s %5s    [%s]\n"),
                __LINE__              ,
                TEXT("Function Name") ,
                TEXT("Status Code")   ,
                TEXT("Id")            ,
                TEXT("Test#")         ,
                TEXT("Status")
                );

    EAPI_fprintf(
                stderr        ,
                TEXT("EApi(Embedded Application Interface)\n")
                TEXT("EApi Verification Tool                            Version %u.%u.%u\n"),
                APP_VERSION   ,
                APP_REVISION  ,
                APP_BUILD
                );

    /*for(i=0;i<ARRAY_SIZE(TestFunctions);i++){
    EAPI_MSG_OUT(
      TEXT("#\n")
      TEXT("# %s\n")
      TEXT("#\n"),  TestFunctions[i].TestDesc
      );

    TestFunctions[i].TestHandler();
  }*/

    //    for(i=0;i<2;i++){
    //      EAPI_MSG_OUT(
    //        TEXT("#\n")
    //        TEXT("# %s\n")
    //        TEXT("#\n"),  TestFunctions[i].TestDesc
    //        );

    //      TestFunctions[i].TestHandler();
    //    }

    TestFunctions[0].TestHandler();
    TestFunctions[1].TestHandler();
    TestFunctions[2].TestHandler();


    if(!EAPI_TEST_SUCCESS(EApiLibUnInitialize()))
    {
        exit(PRG_RETURN_LIB_UNINIT_ERROR);
    }
    exit(PRG_RETURN_OK);
}
