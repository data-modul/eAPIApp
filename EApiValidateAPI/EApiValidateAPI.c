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
#include <getopt.h>
#include <signal.h>

#define END_OF_LIST_MARK ((uint32_t)-1)
typedef void EApiValidateTestFunction(void);
#define DESTRUCTIVE_ALLOWED 1
unsigned int I2CBUS;
unsigned int watchdogLoop = 0;

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
EApiValidateTestFunction EApiValidateStorageApi;
EApiValidateTestFunction EApiValidateGPIOApi   ;
EApiValidateTestFunction EApiValidateWatchdogApi;
EApiValidateTestFunction EApiValidateBacklightApi;
EApiValidateTestFunction EApiValidatePwmEApi;


TCHAR Buffer[1024]={0};
TCHAR testw[67];
TCHAR startAddr[1]={0};
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
    {EAPI_DMO_ID_BOARD_ID_STR ,        TEXT("Board ID"       )},
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

     printf("\n********  EApiValidateStringApi ********\n");
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
     printf("\n********  EApiValidateValuesApi ********\n");

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
typedef struct EApiI2CLLInterfaceValidate_s{
    const uint32_t   Address     ; /* Address */
    void *    WBufPtr     ; /* Write Buffer Pointer */
    const uint32_t  WByteCnt    ; /* Write Byte Count  */
    void *    RBufPtr     ; /* Read  Buffer Pointer */
    const uint32_t  RBufPtrLen  ; /* Read  Buffer Length */
    const uint32_t  RByteCnt    ; /* Read  Byte Count  */
    const EApiStatus_t  StatusCode ; /* Allowed Return Value 1 */
}EApiI2CLLInterfaceValidate_t;
const EApiI2CLLInterfaceValidate_t EApiI2CLLValidate[]={
    {0x64, testw ,  68, NULL  ,                 0 ,   0, EAPI_STATUS_SUCCESS},
    {0x64, NULL  ,   0, NULL  ,                 0 ,   0, EAPI_STATUS_INVALID_PARAMETER },
    {0x64, NULL  ,  10, NULL  ,                 0 ,   0,  EAPI_STATUS_INVALID_PARAMETER},
    {0x64, NULL  ,   0, NULL  ,                10 ,   0,  EAPI_STATUS_INVALID_PARAMETER},
    {0x64, NULL  ,   0, NULL  ,                 0 ,  10,  EAPI_STATUS_INVALID_PARAMETER},
    {0x64, NULL  ,   0, NULL  ,                10 ,  20,  EAPI_STATUS_INVALID_PARAMETER},
    {0x64, testw  ,   2, Buffer,                10 ,  20,  EAPI_STATUS_MORE_DATA},
    {0x64, Buffer,   0, NULL  ,                 0 ,   0,  EAPI_STATUS_INVALID_PARAMETER},
    {0x64, testw  ,   2, Buffer, ARRAY_SIZE(Buffer),  16, EAPI_STATUS_SUCCESS},
};
typedef struct EApiI2CHLInterfaceValidate_s{
    const uint32_t          Address     ; /* Address */
    const uint32_t          Offset      ; /* Address */
    void  *                 BufPtr      ; /* Buffer Pointer */
    const uint32_t          BufPtrLen   ; /* Buffer Length */
    const uint32_t          ByteCnt     ; /* Byte Count  */
    const EApiStatus_t  StatusCode ; /* Allowed Return Value 1 */
}EApiI2CHLInterfaceValidate_t;
const EApiI2CHLInterfaceValidate_t EApiI2CHLReadValidate[]={
    {0x64, 0x00, Buffer, ARRAY_SIZE(Buffer),  10, EAPI_STATUS_SUCCESS},
    {0x64, 0x00, NULL  , ARRAY_SIZE(Buffer),  10, EAPI_STATUS_INVALID_PARAMETER},
    {0x64, 0x00, Buffer,             0x0000,  20, EAPI_STATUS_INVALID_PARAMETER},
    {0x64, 0x00, Buffer, ARRAY_SIZE(Buffer),   0, EAPI_STATUS_INVALID_PARAMETER},
    {0x64, 0x00, Buffer,             0x0010,  20, EAPI_STATUS_MORE_DATA},
    {0x64, 0x00, Buffer, ARRAY_SIZE(Buffer),  67, EAPI_STATUS_SUCCESS},
};
const EApiI2CHLInterfaceValidate_t EApiI2CHLWriteValidate[]={
    {0x64, 0x00, Buffer,            0x0000 ,  10, EAPI_STATUS_SUCCESS},
    {0x64, 0x00, NULL  ,            0x0000 ,  10, EAPI_STATUS_INVALID_PARAMETER},
    {0x64, 0x00, Buffer,            0x0000 ,   0, EAPI_STATUS_INVALID_PARAMETER},
};
typedef struct EApiI2CCapValidate_s{
    uint32_t         *pValue      ; /* Value Pointer*/
    const EApiStatus_t  StatusCode ; /* Allowed Return Value 1 */
}EApiI2CCapValidate_t;

uint32_t I2CMaxClk=0;
const EApiI2CCapValidate_t EApiI2CInterfaceValidate[]={
    {&I2CMaxClk, EAPI_STATUS_SUCCESS},
    {NULL      , EAPI_STATUS_INVALID_PARAMETER},
};

void printHex(
        __IN FILE*  OutStream,
        __IN void * pBuffer  ,
        __IN size_t ByteCount
        )
{
    for(; ByteCount --; ){
        EAPI_fprintf(OutStream, TEXT("%02")TEXT(PRIX8)TEXT(" "), *((uint8_t*)pBuffer));
        pBuffer=((uint8_t*)pBuffer)+1;
    }
}
void EApiValidateI2CApi (void)
{
    EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;

    //____________ i2c ________________________________
    printf("\n******** I2C 0x27 EApiI2CReadTransfer ********\n");
    uint8_t prBuffer2[8]= {0};

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

    printf("\n******** I2C 0x27 EApiI2CWriteTransfer - one write for 6 bytes ********\n");
    uint8_t pBuffer3[16];
    for(int j=0; j< 16; j++)
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
        printf("successful\n");
    else
        printf("It is an error\n");

    printf("\n******** I2C 0x27 EApiI2CReadTransfer to check Write ********\n");
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
        printf("\n");
    }
    else
        printf("It is an error.\n");

    printf("\n******** I2C 0x27 EApiI2CWriteTransfer - one write for each byte ********\n");
    pBuffer3[4]=0x04;
    for (int j=0; j <16 ; j++)
    {
        StatusCode=EApiI2CWriteTransfer(
                    I2CBUS,
                    0x27,
                    EAPI_I2C_ENC_STD_CMD(2),
                    &pBuffer3[j],
                    1
                    );
        if(EAPI_TEST_SUCCESS(StatusCode))
            printf("successful\n");
        else
            printf("It is an error\n");
        sleep(1);
    }
    printf("\n******** I2C 0x27 EApiI2CReadTransfer to check Write ********\n");
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
        printf("\n");
    }
    else
        printf("It is an error.\n");

    //__ eeprom __________________________________________
    printf("\n******** Eeprom 0x50   EApiI2CWriteTransfer to first 192 Bytes from eeprom.bak********\n");
    uint8_t outvalue;
    FILE *file;
    int j =0;
    file = fopen("eeprom.bak","r");
    if (file != NULL)
    {
        outvalue = fgetc(file);
        printf("It will take about 5 msec\n");
        while ( !feof(file) && (j < 192))
        {
            StatusCode=EApiI2CWriteTransfer(
                        I2CBUS,
                        0x50,
                        EAPI_I2C_ENC_EXT_CMD(j),
                        &outvalue,
                        1
                        );
            if(!EAPI_TEST_SUCCESS(StatusCode))
                // printf("successful %d\n",j);
                //else
                printf("Error %d\n",j);
            //   sleep(1);
            usleep(5000);
            j++;
            outvalue = fgetc(file);
        }
        fclose(file);
    }
    else
        printf("No eeprom.bak file is founded to read from it.\n");
    //********************************
    printf("\n******** Eeprom 0x50   EApiI2CReadTransfer first 200 Bytes ********\n");
    uint8_t prBuffer1[200];
    StatusCode=EApiI2CReadTransfer(
                I2CBUS,
                0x50,
                EAPI_I2C_ENC_EXT_CMD(0),
                prBuffer1,
                200,
                200
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        int k =0;
        for (int i =0 ; i < 200 ; i++){
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


    printf("\n******** Eeprom 0x50   EApiI2CReadTransfer second 200 Bytes ********\n");
    StatusCode=EApiI2CReadTransfer(
                I2CBUS,
                0x50,
                EAPI_I2C_ENC_EXT_CMD(200),
                prBuffer1,
                200,
                200
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        int k =0;
        for (int i =0 ; i < 200 ; i++){
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


    /* ****** EApiI2CGetBusCap simulate*********************************************** */
    printf("\n******** EApiI2CGetBusCap ********\n");
    for(unsigned i2=0;i2<ARRAY_SIZE(EApiI2CInterfaceValidate);i2++) /* Iterated thought test cases */
    {
        StatusCode=EApiI2CGetBusCap(I2CBUS, EApiI2CInterfaceValidate[i2].pValue);
        if (StatusCode == EApiI2CInterfaceValidate[i2].StatusCode)
        {
            printf("successful test");
            if (StatusCode == EAPI_STATUS_SUCCESS)
                printf(": %d",*(EApiI2CInterfaceValidate[i2].pValue));
            printf("\n");
        }
        else
            printf("fail test\n");
    }

    return;
}
/*
 * Test Storage Function
 *
 */

void EApiValidateStorageApi(void)
{
    TCHAR TmpStrBuf[1024];
    EApiStatus_t StatusCode = EAPI_STATUS_SUCCESS;
    uint32_t pStorgeSize = 0 ;
    uint32_t pBlockLen = 0;
    unsigned int size =0;

 printf("\n********  EApiValidateStorageApi ********\n");
  printf("\n");
    StatusCode=EApiStorageCap(EAPI_ID_STORAGE_STD,&pStorgeSize,&pBlockLen);
    if(EAPI_TEST_SUCCESS(StatusCode))
        printf("The User space storage is %d, Write Block alignment is %d\n", pStorgeSize, pBlockLen);
    else
        printf("Unsuccessful Storage Cap\n");


    StatusCode=EApiStorageAreaRead(
                EAPI_ID_STORAGE_STD,
                0,
                TmpStrBuf,
                ARRAY_SIZE(TmpStrBuf) , /* For Debug Purposes */
                pStorgeSize
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        EAPI_MSG_OUT(
                    TEXT("%-30s : "),"Read Standard Storage"
                    );
        printHex(stdout, TmpStrBuf, pStorgeSize);
        EAPI_MSG_OUT(TEXT("\n"));

    }
    else
    {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(TEXT("%-30s : %s\n"), "Read Standard Storage", TmpStrBuf);
    }


    strncpy(TmpStrBuf, "Write-Test1 more than capacity.", sizeof("Write-Test1 more than capacity."));
    size = sizeof("Write-Test1 more than capacity.");
    StatusCode=EApiStorageAreaWrite(
                EAPI_ID_STORAGE_STD,
                0                            ,
                TmpStrBuf                     ,
                size
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        EAPI_MSG_OUT(
                    TEXT("%-30s : "),
                    "Write1 Standard Storage"
                    );
        printHex(stdout, TmpStrBuf,size);
        EAPI_MSG_OUT(TEXT("\n"));
    }
    else
    {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
                    TEXT("%-30s :")TEXT(" %s\n")      ,
                    "Write1 Standard Storage",
                    TmpStrBuf
                    );
    }


    strncpy(TmpStrBuf, "Write-Test2 ok.", sizeof("Write-Test2 ok."));
    size = sizeof("Write-Test2 ok.");
    StatusCode=EApiStorageAreaWrite(
                EAPI_ID_STORAGE_STD,
                0                            ,
                TmpStrBuf                     ,
                size
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        EAPI_MSG_OUT(
                    TEXT("%-30s : "),
                    "Write2 Standard Storage"
                    );
        printHex(stdout, TmpStrBuf,size);
        EAPI_MSG_OUT(TEXT("\n"));
    }
    else
    {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(
                    TEXT("%-30s :")TEXT(" %s\n")      ,
                    "Write2 Standard Storage",
                    TmpStrBuf
                    );
    }

    StatusCode=EApiStorageAreaRead(
                EAPI_ID_STORAGE_STD,
                0,
                TmpStrBuf,
                ARRAY_SIZE(TmpStrBuf) , /* For Debug Purposes */
                pStorgeSize
                );
    if(EAPI_TEST_SUCCESS(StatusCode))
    {
        EAPI_MSG_OUT(
                    TEXT("%-30s : "),"Read2 Standard Storage"
                    );
        printHex(stdout, TmpStrBuf, pStorgeSize);
        EAPI_MSG_OUT(TEXT("\n"));

    }
    else
    {
        EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
        EAPI_MSG_OUT(TEXT("%-30s : %s\n"), "Read2 Standard Storage", TmpStrBuf);
    }

    return ;
}

/*
 * Test GPIO Function
 *
 */

typedef struct EApiGpioType_s{
    const EApiId_t  Id     ;
    const TCHAR *const   Desc   ;
}EApiGpioType_t;

const EApiGpioType_t EApiGpioDevices[]={
    {EAPI_ID_GPIO_BANK00   , TEXT("GPIO Bank0"      )},
    {EAPI_GPIO_GPIO_ID(0)  , TEXT("GPIO GPIO0"      )},
    {EAPI_GPIO_GPIO_ID(1)  , TEXT("GPIO GPIO1"      )},
    {EAPI_GPIO_GPIO_ID(2)  , TEXT("GPIO GPIO2"      )},
    {EAPI_GPIO_GPIO_ID(3)  , TEXT("GPIO GPIO3"      )},
    {EAPI_GPIO_GPIO_ID(4)  , TEXT("GPIO GPIO4"      )},
    {EAPI_GPIO_GPIO_ID(5)  , TEXT("GPIO GPIO5"      )},
    {EAPI_GPIO_GPIO_ID(6)  , TEXT("GPIO GPIO6"      )},
    {EAPI_GPIO_GPIO_ID(7)  , TEXT("GPIO GPIO7"      )},
    {0x00000F00            , TEXT("Unsupported"     )},
};


void EApiValidateGPIOApi(void)
{
    TCHAR TmpStrBuf[1024];
    unsigned i;
    uint32_t Direction;
    uint32_t Level;
    uint32_t Inputs;
    uint32_t Outputs;
    EApiStatus_t StatusCode;

    printf("\n********  EApiValidateGPIOApi ********\n");

    for(i=0;i<ARRAY_SIZE(EApiGpioDevices);i++){

        Direction = 0;
        Level = 0;
        Inputs = 0;
        Outputs = 0;

        /*       *((int*)NULL)=0; */
        StatusCode=EApiGPIOGetDirectionCaps(EApiGpioDevices[i].Id, &Inputs, &Outputs);
        if(!EAPI_TEST_SUCCESS(StatusCode))
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(
                        TEXT("\n%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOGetDirectionCaps"),
                        TmpStrBuf
                        );
            continue;
        }
        EAPI_MSG_OUT(
                    TEXT("\n%-15s %-25s : Inputs   =%02")TEXT(PRIX32)TEXT(" Outputs=%02")TEXT(PRIX32)TEXT("\n"),
                    EApiGpioDevices[i].Desc,
                    TEXT("EApiGPIOGetDirectionCaps"),
                    Inputs,
                    Outputs
                    );

sleep(1);
        StatusCode=EApiGPIOGetDirection(EApiGpioDevices[i].Id, Inputs|Outputs, &Direction);
        if(!EAPI_TEST_SUCCESS(StatusCode))
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(
                        TEXT("%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOGetDirection"),
                        TmpStrBuf
                        );
            continue;
        }
        EAPI_MSG_OUT(
                    TEXT("%-15s %-25s : Direction=%02")TEXT(PRIX32)TEXT("\n"),
                    EApiGpioDevices[i].Desc,
                    TEXT("EApiGPIOGetDirection"),
                    Direction
                    );

sleep(1);
        StatusCode=EApiGPIOGetLevel(EApiGpioDevices[i].Id, Inputs|Outputs, &Level);
        if(!EAPI_TEST_SUCCESS(StatusCode))
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(
                        TEXT("%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOGetLevel"),
                        TmpStrBuf
                        );
            continue;
        }
        EAPI_MSG_OUT(
                    TEXT("%-15s %-25s : Level    =%02")TEXT(PRIX32)TEXT("\n"),
                    EApiGpioDevices[i].Desc,
                    TEXT("EApiGPIOGetLevel"),
                    Level
                    );
sleep(1);
        StatusCode=EApiGPIOSetDirection(
                    EApiGpioDevices[i].Id,
                    Inputs|Outputs,
                    ~(Direction)
                    );
        if(!EAPI_TEST_SUCCESS(StatusCode))
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(
                        TEXT("%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOSetDirection"),
                        TmpStrBuf
                        );
            continue;
        }
sleep(1);
        StatusCode=EApiGPIOGetDirection(EApiGpioDevices[i].Id, Inputs|Outputs, &Direction);
        if(!EAPI_TEST_SUCCESS(StatusCode))
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(
                        TEXT("%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOGetDirection"),
                        TmpStrBuf
                        );
            continue;
        }
        EAPI_MSG_OUT(
                    TEXT("%-15s %-25s : Direction=%02")TEXT(PRIX32)TEXT("\n"),
                    EApiGpioDevices[i].Desc,
                    TEXT("EApiGPIOGetDirection"),
                    Direction
                    );

sleep(1);
        StatusCode=EApiGPIOSetLevel(EApiGpioDevices[i].Id, Outputs, ~(Level));
        if(!EAPI_TEST_SUCCESS(StatusCode))
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(
                        TEXT("%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOSetLevel"),
                        TmpStrBuf
                        );
            continue;
        }
sleep(1);
        StatusCode=EApiGPIOGetLevel(EApiGpioDevices[i].Id, Inputs|Outputs, &Level);
        if(!EAPI_TEST_SUCCESS(StatusCode))
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(
                        TEXT("%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOGetLevel"),
                        TmpStrBuf
                        );
            continue;
        }
        EAPI_MSG_OUT(
                    TEXT("%-15s %-25s : Level    =%02")TEXT(PRIX32)TEXT("\n"),
                    EApiGpioDevices[i].Desc,
                    TEXT("EApiGPIOGetLevel"),
                    Level);


    }

    //    StatusCode = EApiGPIOSetDirection(EAPI_ID_GPIO_BANK00, 0xff, 0x00);
    //    if (StatusCode != EAPI_STATUS_SUCCESS)
    //        printf("error in set direction\n");

    //    while(1)
    //    {
    //        StatusCode = EApiGPIOGetLevel(EAPI_ID_GPIO_BANK00, 0xff, &Level);
    //        if (StatusCode != EAPI_STATUS_SUCCESS)
    //            printf("error in get level-1\n");

    //       Level2 = 0;
    //       Level2 = ~(Level);

    //        StatusCode = EApiGPIOSetLevel(EAPI_ID_GPIO_BANK00, 0xff, Level2);
    //        if (StatusCode != EAPI_STATUS_SUCCESS)
    //            printf("error in set level\n");

            sleep(1);
    //    }
    return ;
}

/*
 * Test Watchdog Function
 *
 */
void sig_handler(int signum) {
    if (signum == SIGINT)
    {
        EApiWDogStop();
        exit(0);
    }
}
void EApiValidateWatchdogApi()
{
    time_t rawtime;
    struct tm *timeinfo;
    uint32_t maxDelay, maxeventTimeout, maxResetTimeout;
    unsigned int count = 0;
    int ping = 0;

    EApiStatus_t StatusCode;

    signal(SIGINT,&sig_handler);

    printf("\n********  EApiValidateWatchdogApi ********\n\n");

    EApiWDogGetCap(&maxDelay, &maxeventTimeout, &maxResetTimeout);
    printf("max delay: %d msec, maxEventTimeout: %d msec, maxResetTimeout: %d msec\n",maxDelay, maxeventTimeout, maxResetTimeout);

    StatusCode = EApiWDogStart(0,3000,5000);
    ping = ((3000 + 5000)/1000) - 2;
    if(StatusCode == EAPI_STATUS_SUCCESS )
    {
        if (watchdogLoop == 0) // forever
        {
            while(1)
            {
                time(&rawtime);
                timeinfo = localtime(&rawtime);
                printf("ping at %s",asctime(timeinfo));
                EApiWDogTrigger();
                sleep(ping);
            }
        }
        else
        {
            while(count < watchdogLoop)
            {
                time(&rawtime);
                timeinfo = localtime(&rawtime);
                printf("ping at %s",asctime(timeinfo));
                EApiWDogTrigger();
                count++;
                sleep(ping);
            }
            EApiWDogStop();
        }
    }
}

typedef struct EApiBacklightType_s{
    const EApiId_t  Id  ;
    const uint32_t enable;
    const uint32_t bright;
    const TCHAR *const   Desc;
}EApiBacklightType_t;

const EApiBacklightType_t EApiBacklights[]={
    {EAPI_ID_BACKLIGHT_1       , EAPI_BACKLIGHT_SET_ON, 0,     TEXT("EAPI_ID_BACKLIGHT_1"   )},
    {EAPI_ID_BACKLIGHT_1       , EAPI_BACKLIGHT_SET_ON, 2000,  TEXT("EAPI_ID_BACKLIGHT_1"        )},
    {EAPI_ID_BACKLIGHT_1       , EAPI_BACKLIGHT_SET_OFF, 8000, TEXT("EAPI_ID_BACKLIGHT_1"  )},
    {EAPI_ID_BACKLIGHT_1       , EAPI_BACKLIGHT_SET_OFF, 1500, TEXT("EAPI_ID_BACKLIGHT_1" )},
    {EAPI_ID_BACKLIGHT_2       , EAPI_BACKLIGHT_SET_ON, 2000,  TEXT("EAPI_ID_BACKLIGHT_2"  )},
    {EAPI_ID_BACKLIGHT_3       , EAPI_BACKLIGHT_SET_OFF, 1500, TEXT("EAPI_ID_BACKLIGHT_3" )},
};


void EApiValidateBacklightApi (void)
{
    EApiStatus_t StatusCode;
    uint32_t Value;
    unsigned i;


    TCHAR TmpStrBuf[1024];

  printf("\n********  EApiValidateBacklightApi ********\n");

    for(i=0;i<ARRAY_SIZE(EApiBacklights);i++){
        printf("\n");
        if((StatusCode=EApiVgaGetBacklightEnable(EApiBacklights[i].Id, &Value))==EAPI_STATUS_SUCCESS)
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            if (Value == EAPI_BACKLIGHT_SET_ON)
                EAPI_MSG_OUT(TEXT("%-30sGetBacklightEnable\tEnable:EAPI_BACKLIGHT_SET_ON \t%s\n"), EApiBacklights[i].Desc,TmpStrBuf);
            else
                EAPI_MSG_OUT(TEXT("%-30sGetBacklightEnable\tEnable:EAPI_BACKLIGHT_SET_OFF\t%s\n"), EApiBacklights[i].Desc,TmpStrBuf);
        }else{
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30sGetBacklightEnable\t%s\n"), EApiBacklights[i].Desc, TmpStrBuf);
        }
        if((StatusCode=EApiVgaSetBacklightEnable(EApiBacklights[i].Id, EApiBacklights[i].enable))==EAPI_STATUS_SUCCESS)
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30sSetBacklightEnable\t%s\n"), EApiBacklights[i].Desc, TmpStrBuf);
        }else{
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30sSetBacklightEnable\t%s\n"), EApiBacklights[i].Desc, TmpStrBuf);
        }
        if((StatusCode=EApiVgaGetBacklightBrightness(EApiBacklights[i].Id, &Value))==EAPI_STATUS_SUCCESS)
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30sGetBacklightBrightness\tBrightness:%d\t%s\n"), EApiBacklights[i].Desc, Value, TmpStrBuf);
        }else{
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30sGetBacklightBrightness\t%s\n"), EApiBacklights[i].Desc, TmpStrBuf);
        }
        if((StatusCode=EApiVgaSetBacklightBrightness(EApiBacklights[i].Id, EApiBacklights[i].bright))==EAPI_STATUS_SUCCESS)
        {
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30sSetBacklightBrightness\tBrightness:%d\t%s\n"), EApiBacklights[i].Desc, EApiBacklights[i].bright,TmpStrBuf);
        }else{
            EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
            EAPI_MSG_OUT(TEXT("%-30sSetBacklightBrightness\t%s\n"), EApiBacklights[i].Desc, TmpStrBuf);
        }
    }
    return ;
}

void EApiValidatePwmEApi (void)
{
    EApiStatus_t StatusCode;
uint32_t minperiod =0,maxperiod= 0,mingran=0,maxgran=0,feature=0;
uint32_t pPwmPeriod, pPwmDutyCycle, pPwmPolarity, pPwmFeatureFlags, pPwmEnable, pPwmGranularity;
EApiId_t compan;

    TCHAR TmpStrBuf[1024];

  printf("\n********  EApiValidatePwmEApi ********\n");

  feature = EAPIEX_PWM_QUERY_FLAG;
   StatusCode = EApiExPwmGetCaps(EAPIEX_ID_PWM_CHANNEL_0,&minperiod,&maxperiod,&mingran,&maxgran,&compan,&feature);
  if(!EAPI_TEST_SUCCESS(StatusCode))
  {
	  EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmGetCaps\t%s\n"), TmpStrBuf);
  }
  else
 EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetCaps\tminPeriod:%d\tmaxPeriod:%d\tminGranularity:%d\tmaxGranularity:%d\tCompanionChannel:%d\tFeatures:%d\n"),minperiod,maxperiod,mingran,maxgran,compan,feature );

   feature = EAPIEX_PWM_QUERY_FLAG;
  StatusCode = EApiExPwmGetCaps(EAPIEX_ID_PWM_CHANNEL_1,&minperiod,&maxperiod,&mingran,&maxgran,&compan,&feature);
  if(!EAPI_TEST_SUCCESS(StatusCode))
  {
	  EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmGetCaps\t%s\n"), TmpStrBuf);
  }
  else
 EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetCaps\tminPeriod:%d\tmaxPeriod:%d\tminGranularity:%d\tmaxGranularity:%d\tCompanionChannel:%d\tFeatures:%d\n"),minperiod,maxperiod,mingran,maxgran,compan,feature );

  
  StatusCode = EApiExPwmGetConfig(EAPIEX_ID_PWM_CHANNEL_0, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmGetConfig\t%s\n"), TmpStrBuf);

}
else
 EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetConfig\tPeriod:%d\tDuty-cycle:%d\tPolarity:%d\tFeature:%d\tEnable:%d\tGranularity:%d\n"),pPwmPeriod,pPwmDutyCycle,pPwmPolarity,pPwmFeatureFlags,pPwmEnable,pPwmGranularity );


 StatusCode = EApiExPwmGetConfig(EAPIEX_ID_PWM_CHANNEL_1, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmGetConfig\t%s\n"), TmpStrBuf);

}
else
 EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetConfig\tPeriod:%d\tDuty-cycle:%d\tPolarity:%d\tFeature:%d\tEnable:%d\tGranularity:%d\n"),pPwmPeriod,pPwmDutyCycle,pPwmPolarity,pPwmFeatureFlags,pPwmEnable,pPwmGranularity );

 StatusCode = EApiExPwmGetConfig(2, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("No ch2 in EApiExPwmGetConfig\t%s\n"), TmpStrBuf);

}
else
 EAPI_MSG_OUT(TEXT("EApiExPwmGetConfig\tPeriod:%d\tDuty-cycle:%d\tPolarity:%d\tFeature:%d\tEnable:%d\tGranularity:%d\n"),pPwmPeriod,pPwmDutyCycle,pPwmPolarity,pPwmFeatureFlags,pPwmEnable,pPwmGranularity );

pPwmPeriod = 160;
pPwmDutyCycle = 20;
pPwmPolarity = EAPIEX_PWM_POLARITY_INVERSED;
pPwmFeatureFlags = 0;//EAPIEX_PWM_FEATURE_CENTER_MODE;
pPwmEnable = 1;
uint32_t minstep = 4;
uint32_t maxstep = 10;
StatusCode = EApiExPwmSetConfig(EAPIEX_ID_PWM_CHANNEL_0, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&minstep,&maxstep,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmSetConfig 160,20:\t%s\n"), TmpStrBuf);
}
else
 EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmSetConfig 160,20: \tGranularity:%d\n"),pPwmGranularity );


pPwmPeriod = 1000;
pPwmDutyCycle = 250;
pPwmPolarity = EAPIEX_PWM_POLARITY_NORMAL;
pPwmFeatureFlags = 0 ;
pPwmEnable = 1;
StatusCode = EApiExPwmSetConfig(EAPIEX_ID_PWM_CHANNEL_1, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,0,0,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmSetConfig 1000,250:\t%s\n"), TmpStrBuf);
}
else
 EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmSetConfig 1000,250: \tGranularity:%d\n"),pPwmGranularity );

StatusCode = EApiExPwmGetConfig(EAPIEX_ID_PWM_CHANNEL_0, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmGetConfig\t%s\n"), TmpStrBuf);

}
else
 EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetConfig\tPeriod:%d\tDuty-cycle:%d\tPolarity:%d\tFeature:%d\tEnable:%d\tGranularity:%d\n"),pPwmPeriod,pPwmDutyCycle,pPwmPolarity,pPwmFeatureFlags,pPwmEnable,pPwmGranularity );


 StatusCode = EApiExPwmGetConfig(EAPIEX_ID_PWM_CHANNEL_1, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmGetConfig\t%s\n"), TmpStrBuf);

}
else
 EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetConfig\tPeriod:%d\tDuty-cycle:%d\tPolarity:%d\tFeature:%d\tEnable:%d\tGranularity:%d\n"),pPwmPeriod,pPwmDutyCycle,pPwmPolarity,pPwmFeatureFlags,pPwmEnable,pPwmGranularity );


StatusCode = EApiExPwmGetDuty(EAPIEX_ID_PWM_CHANNEL_0,&pPwmDutyCycle);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmGetDuty\t%s\n"), TmpStrBuf);
}
else
 EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetDuty\tDuty-Cycle:%d\n"),pPwmDutyCycle);

StatusCode = EApiExPwmGetDuty(EAPIEX_ID_PWM_CHANNEL_1,&pPwmDutyCycle);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmGetDuty\t%s\n"), TmpStrBuf);
}
else
 EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetDuty\tDuty-Cycle:%d\n"),pPwmDutyCycle);

StatusCode = EApiExPwmGetDuty(2,&pPwmDutyCycle);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("No ch2 in EApiExPwmGetDuty\t%s\n"), TmpStrBuf);
}
else
 EAPI_MSG_OUT(TEXT("EApiExPwmGetDuty\tDuty-Cycle:%d\n"),pPwmDutyCycle);


pPwmDutyCycle = 40;
StatusCode = EApiExPwmSetDuty(EAPIEX_ID_PWM_CHANNEL_0, pPwmDutyCycle);
EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
if(!EAPI_TEST_SUCCESS(StatusCode))
	EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmSetDuty 40:\t%s\n"), TmpStrBuf);
else
EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmSetDuty 40: \t%s\n"), TmpStrBuf);

StatusCode = EApiExPwmGetConfig(EAPIEX_ID_PWM_CHANNEL_0, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmGetConfig\t%s\n"), TmpStrBuf);

}
else
 EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetConfig\tPeriod:%d\tDuty-cycle:%d\tPolarity:%d\tFeature:%d\tEnable:%d\tGranularity:%d\n"),pPwmPeriod,pPwmDutyCycle,pPwmPolarity,pPwmFeatureFlags,pPwmEnable,pPwmGranularity );

pPwmDutyCycle = 230;
StatusCode = EApiExPwmSetDuty(EAPIEX_ID_PWM_CHANNEL_1, pPwmDutyCycle);
EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
if(!EAPI_TEST_SUCCESS(StatusCode))
	EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmSetDuty 230:\t%s\n"), TmpStrBuf);
else
EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmSetDuty 230: \t%s\n"), TmpStrBuf);

StatusCode = EApiExPwmGetConfig(EAPIEX_ID_PWM_CHANNEL_1, &pPwmPeriod,&pPwmDutyCycle,&pPwmPolarity,&pPwmFeatureFlags,&pPwmEnable,&pPwmGranularity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmGetConfig\t%s\n"), TmpStrBuf);

}
else
 EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetConfig\tPeriod:%d\tDuty-cycle:%d\tPolarity:%d\tFeature:%d\tEnable:%d\tGranularity:%d\n"),pPwmPeriod,pPwmDutyCycle,pPwmPolarity,pPwmFeatureFlags,pPwmEnable,pPwmGranularity );


pPwmPolarity = EAPIEX_PWM_POLARITY_NORMAL;
StatusCode = EApiExPwmSetPolarity(EAPIEX_ID_PWM_CHANNEL_0, pPwmPolarity);
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmSetPolarity normal:\t%s\n"), TmpStrBuf);

StatusCode = EApiExPwmGetPolarity(EAPIEX_ID_PWM_CHANNEL_0, &pPwmPolarity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch0:EApiExPwmGetPolarity\t%s\n"), TmpStrBuf);
}
else
EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetPolarity\t%d\n"), pPwmPolarity);


pPwmPolarity = EAPIEX_PWM_POLARITY_INVERSED; 
StatusCode = EApiExPwmSetPolarity(EAPIEX_ID_PWM_CHANNEL_1, pPwmPolarity);
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmSetPolarity inversed:\t%s\n"), TmpStrBuf);

StatusCode = EApiExPwmGetPolarity(EAPIEX_ID_PWM_CHANNEL_1, &pPwmPolarity);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
          EAPI_MSG_OUT(TEXT("Error in Ch1:EApiExPwmGetPolarity\t%s\n"), TmpStrBuf);
}
else
EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetPolarity\t%d\n"), pPwmPolarity);


pPwmEnable = 1;
StatusCode = EApiExPwmSetEnable(EAPIEX_ID_PWM_CHANNEL_0,pPwmEnable);
EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmSetEnable 1:\t%s\n"), TmpStrBuf);


StatusCode = EApiExPwmGetEnable(EAPIEX_ID_PWM_CHANNEL_0, &pPwmEnable);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetEnable\t%s\n"), TmpStrBuf);
}
else
EAPI_MSG_OUT(TEXT("Ch0:EApiExPwmGetEnable\t%d\n"),pPwmEnable );

pPwmEnable = 0;
StatusCode = EApiExPwmSetEnable(EAPIEX_ID_PWM_CHANNEL_1,pPwmEnable);
EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmSetEnable 0:\t%s\n"), TmpStrBuf);


StatusCode = EApiExPwmGetEnable(EAPIEX_ID_PWM_CHANNEL_1, &pPwmEnable);
if(!EAPI_TEST_SUCCESS(StatusCode))
{
 EApiAHCreateErrorString(StatusCode, TmpStrBuf, ARRAY_SIZE(TmpStrBuf));
EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetEnable\t%s\n"), TmpStrBuf);
}
else
EAPI_MSG_OUT(TEXT("Ch1:EApiExPwmGetEnable\t%d\n"),pPwmEnable );

    return ;
}


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
    {EApiValidateGPIOApi    , TEXT("Gpio Function"       )},
    {EApiValidateWatchdogApi    , TEXT("Watchdog Function"       )},
    {EApiValidateBacklightApi    , TEXT("Backlight Function"       )},
    {EApiValidateStorageApi , TEXT("Storage Function"    )},
    {EApiValidatePwmEApi , TEXT("PWM Function"    )},
};
/* void __cdecl main( __IN  char *const *const  argv, __IN const int argc) */
typedef enum ProgramStatusCodes_e{
    PRG_RETURN_OK             =0,
    PRG_RETURN_ERROR            ,
    PRG_RETURN_LIB_INIT_ERROR   ,
    PRG_RETURN_LIB_UNINIT_ERROR
}ProgramStatusCodes_t;

void usage(void)
{
    printf("Usage: EApiValidateAPI [-s][-v][-g][-w][-b][-u][-i I2C-BUS][-a I2C-BUS][-n run-times]\n");
    printf("[-s] to run EApiBoardGetStringA\n");
    printf("[-v] to run EApiBoardGetValue\n");
    printf("[-i I2C-BUS] to run i2c R/W of an I2C bus name(I2C-BUS)\n");
    printf("[-g] to run EApi GPIO GetLevel, SetLevel and SetDirection to output\n");
    printf("[-w] to run EApi Watchog test\n");
    printf("[-b] to run EApi Backlight test\n");
    printf("[-u] to run EApi User Storage test\n");
    printf("[-p] to run EApi PWM test\n");
    printf("[-a] to run all EAPi tests\n");
    printf("[-n] number of times running application. without set, App will run infinite\n");
    return;
}

int
__cdecl
main(int argc, char *argv[])
{

    int option = 0;
    int getstring = -1, getvalue = -1, i2c = -1, num =-1 , gpio = -1, watchdog= -1, backlight= -1, storage= -1, pwm= -1;
    int nostop = 0;
    int noOption = 0;

    //Specifying the expected options
    //The two options l and b expect numbers as argument
    while ((option = getopt(argc, argv,"svi:n:gwbua:p")) != -1) {
        noOption = 1;
        switch (option) {
        case 's' : getstring = 1;
            break;
        case 'v' : getvalue = 1;
            break;
        case 'i' : i2c = atoi(optarg);
            break;
        case 'n' : num = atoi(optarg);
            break;
        case 'g' : gpio = 1;
            break;
        case 'w' : watchdog = 1;
            break;
        case 'b' : backlight = 1;
            break;
        case 'u' : storage = 1;
            break;
        case 'p' : pwm = 1;
            break;
	case 'a' :
            getstring = 1;
            storage = 1;
            getvalue = 1;
            i2c = atoi(optarg);
            gpio = 1;
            watchdog = 1;
            backlight = 1;
            storage = 1;
	    pwm =1;
            break;
        case '?' :
        default:
            usage();
            exit(PRG_RETURN_OK);
        }
    }

    if(noOption == 0)
    {
        usage();
        exit(PRG_RETURN_OK);
    }

    LogStream=EAPI_fopen(TEXT("EApiValidateAPI.log"), TEXT("w"));
    if(LogStream==NULL)
        LogStream=stdout;

    if(!EAPI_TEST_SUCCESS(EApiLibInitialize()))
        exit(PRG_RETURN_LIB_INIT_ERROR);

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

    if (i2c != -1) // i2c bus number
        I2CBUS = i2c;

    if (num == -1)// run forever
        nostop = 1;



    while ((num > 0 && nostop ==0) || (nostop == 1))
    {
        if (getvalue == 1)
            TestFunctions[0].TestHandler();
        if (getstring == 1)
            TestFunctions[1].TestHandler();
        if (i2c != -1) // i2c bus number
            TestFunctions[2].TestHandler();
        if (gpio == 1)
            TestFunctions[3].TestHandler();
        if (watchdog == 1 )
        {
            if (nostop == 1)
                watchdogLoop = 0;
            else
                watchdogLoop = num;

            TestFunctions[4].TestHandler();
        }
        if (backlight == 1)
            TestFunctions[5].TestHandler();
        if (storage == 1)
            TestFunctions[6].TestHandler();
	if (pwm == 1)
            TestFunctions[7].TestHandler();
        if (num > 0)
            num--;
    }

    if(!EAPI_TEST_SUCCESS(EApiLibUnInitialize()))
    {
        exit(PRG_RETURN_LIB_UNINIT_ERROR);
    }
    exit(PRG_RETURN_OK);
}
