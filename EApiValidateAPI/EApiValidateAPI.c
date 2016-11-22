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

#define END_OF_LIST_MARK ((uint32_t)-1)
typedef void EApiValidateTestFunction(void);
#define DESTRUCTIVE_ALLOWED 1
unsigned int I2CBUS;
unsigned int simulI2C = 0;

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
EApiValidateTestFunction EApiValidateGPIOApi   ;



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


    /* ****** READWRITERAW simulate*********************************************** */
    if (simulI2C == 1)
    {
        strcpy(testw," Hello from Data modul. This is a simulation test for eAPI library");
        testw[0]=0x00;
        printf("\n******** Simulate 0x64  EApiI2CWriteReadRaw ********\n");
        for(unsigned i2=0;i2<ARRAY_SIZE(EApiI2CLLValidate);i2++) /* Iterated thought test cases */
        {
            StatusCode=EApiI2CWriteReadRaw(
                        I2CBUS                               ,
                        EAPI_I2C_ENC_STD_CMD(EApiI2CLLValidate[i2].Address)   ,
                        EApiI2CLLValidate[i2].WBufPtr   ,
                        EApiI2CLLValidate[i2].WByteCnt  ,
                        EApiI2CLLValidate[i2].RBufPtr   ,
                        EApiI2CLLValidate[i2].RBufPtrLen,
                        EApiI2CLLValidate[i2].RByteCnt
                        );
            if (StatusCode == EApiI2CLLValidate[i2].StatusCode)
            {
                printf("successful test");
                if(EApiI2CLLValidate[i2].RBufPtr != NULL && (StatusCode == EAPI_STATUS_SUCCESS || StatusCode == EAPI_STATUS_MORE_DATA ))
                {
                    printf(": read result >  %s",(uint8_t*)EApiI2CLLValidate[i2].RBufPtr);
                }
                printf("\n");

            }
            else
                printf("fail test\n");
        }
        /* ****** EApiI2CReadTransfer simulate*********************************************** */
        printf("\n******** Simulate 0x64  EApiI2CReadTransfer ********\n");

        for(unsigned i2=0;i2<ARRAY_SIZE(EApiI2CHLReadValidate);i2++) /* Iterated thought test cases */
        {
            memset(Buffer, 0x00, ARRAY_SIZE(Buffer));
            StatusCode=EApiI2CReadTransfer(
                        I2CBUS                                   ,
                        EAPI_I2C_ENC_STD_CMD(EApiI2CHLReadValidate[i2].Address)   ,
                        EApiI2CHLReadValidate[i2].Offset    ,
                        EApiI2CHLReadValidate[i2].BufPtr    ,
                        EApiI2CHLReadValidate[i2].BufPtrLen ,
                        EApiI2CHLReadValidate[i2].ByteCnt
                        );
            if (StatusCode == EApiI2CHLReadValidate[i2].StatusCode)
            {
                printf("successful test");
                if(EApiI2CHLReadValidate[i2].BufPtr != NULL && (StatusCode == EAPI_STATUS_SUCCESS || StatusCode == EAPI_STATUS_MORE_DATA ))
                {
                    printf(": read result >  %s",(uint8_t*)EApiI2CHLReadValidate[i2].BufPtr);
                }
                printf("\n");

            }
            else
                printf("fail test\n");
        }
        /* ****** EApiI2CWriteTransfer simulate*********************************************** */
        printf("\n******** Simulate 0x64 EApiI2CWriteTransfer ********\n");
        memset(Buffer, 0x00, ARRAY_SIZE(Buffer));
        for(unsigned i2=0;i2<ARRAY_SIZE(EApiI2CHLWriteValidate);i2++) /* Iterated thought test cases */
        {
            StatusCode=EApiI2CWriteTransfer(
                        I2CBUS                                   ,
                        EApiI2CHLWriteValidate[i2].Address  ,
                        EApiI2CHLWriteValidate[i2].Offset   ,
                        EApiI2CHLWriteValidate[i2].BufPtr   ,
                        EApiI2CHLWriteValidate[i2].ByteCnt
                        );
            if (StatusCode == EApiI2CHLWriteValidate[i2].StatusCode)
                printf("successful test\n");
            else
                printf("fail test\n");
        }
    }
    /* ****** EApiI2CGetBusCap simulate*********************************************** */
    printf("\n******** Simulate 0x64 EApiI2CGetBusCap ********\n");
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
                        TEXT("\n\n%-15s %-25s : %s\n"),
                        EApiGpioDevices[i].Desc,
                        TEXT("EApiGPIOGetDirectionCaps"),
                        TmpStrBuf
                        );
            continue;
        }
        EAPI_MSG_OUT(
                    TEXT("\n\n%-15s %-25s : Inputs   =%02")TEXT(PRIX32)TEXT(" Outputs=%02")TEXT(PRIX32)TEXT("\n"),
                    EApiGpioDevices[i].Desc,
                    TEXT("EApiGPIOGetDirectionCaps"),
                    Inputs,
                    Outputs
                    );


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

    //        sleep(1);
    //    }
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
    //{EApiValidateStorageApi , TEXT("Storage Function"    )},
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
main(int argc, char *argv[])
{

    int option = 0;
    int getstring = -1, getvalue = -1, i2c = -1, num =-1 , gpio = -1;
    int nostop = 0;
    int noOption = 0;

    int count =0;
    time_t rawtime;
    struct tm *timeinfo;


    //    EApiWDogStart(5000,5000,10000);
    //    while(count < 2)
    //    {
    //        EApiWDogTrigger();
    //        time(&rawtime);
    //        timeinfo = localtime(&rawtime);
    //        printf("%s\n",asctime(timeinfo));
    //        count++;
    //        sleep(16);
    //    }
    //    EApiWDogStop();





    //Specifying the expected options
    //The two options l and b expect numbers as argument
    while ((option = getopt(argc, argv,"svi:n:mg")) != -1) {
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
        case 'm' : simulI2C = 1;
            break;
        case 'g' : gpio = 1;
            break;
        case '?' :
        default: printf("Usage: EApiValidateAPI [-s] [-v] [-i I2C-BUS] [-n run-times]\n");
            printf("[-s] to run EApiBoardGetStringA\n");
            printf("[-v] to run EApiBoardGetValue\n");
            printf("[-i I2C-BUS] to run i2c R/W of an I2C bus name(I2C-BUS)\n");
            printf("[-g] to run EApi GPIO GetLevel, SetLevel and SetDirection to output\n");
            printf("[-n] number of times running application. without set, App will run infinite\n");
            exit(PRG_RETURN_OK);
        }
    }

    if(noOption == 0)
    {
        printf("Usage: EApiValidateAPI [-s] [-v] [-i I2C-BUS] [-n run-times]\n");
        printf("[-s] to run EApiBoardGetStringA\n");
        printf("[-v] to run EApiBoardGetValue\n");
        printf("[-i I2C-BUS] to run i2c R/W of an I2C bus name(I2C-BUS)\n");
        printf("[-g] to run EApi GPIO GetLevel, SetLevel and SetDirection to output\n");
        printf("[-n] number of times running application. without set, App will run infinite\n");
        exit(PRG_RETURN_OK);
    }

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

        if (num > 0)
            num--;
    }

    if(!EAPI_TEST_SUCCESS(EApiLibUnInitialize()))
    {
        exit(PRG_RETURN_LIB_UNINIT_ERROR);
    }
    exit(PRG_RETURN_OK);
}
