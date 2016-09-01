/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: EApiDK Embedded Application Development Kit
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/Smbios.h $
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
 *I  File Name            : Smbios.h
 *I  File Location        : apps\EeePProg
 *I  Last committed       : $Revision: 60 $
 *I  Last changed by      : $Author: dethrophes $
 *I  Last changed date    : $Date: 2010-02-28 21:53:20 +0100 (Sun, 28 Feb 2010) $
 *I  ID                   : $Id: Smbios.h 60 2010-02-28 20:53:20Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __SMBIOS_H__
#define __SMBIOS_H__

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(push, 1)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */


/*
 *      DMI/SMBIOS Common Header Format
 *
 *  see http://www.dmtf.org/standards/published_documents/DSP0134_2.6.1.pdf
 */

typedef struct SmbiosHdr_s{
    SMBIOS_BlockId_t Type       ; /* 0x00 Structure Type        */
    uint8_t          Length     ; /* 0x01 Specifies the length of
                                   * the formatted area of the 
                                   * structure, starting at the 
                                   * Type field. The length of the 
                                   * structure’s string-set is not
                                   * included. 
                                   */
    SmbiosHandle_t   Handle     ; /* 0x02 Specifies the structure’s 
                                   * handle, a unique 16-bit number 
                                   * in the range 0 to 0FEFFh 
                                   */
}SmbiosHdr_t;
/*
 *      Bios Information
 *
 *  see http://www.dmtf.org/standards/published_documents/DSP0134_2.6.1.pdf
 *  Type 1 Block
 */
typedef struct BiosInfo_s{
    SmbiosHdr_t SMBHdr; /* 0x00 Smbios Dynamic Block Header */
    uint8_t Vendor         ; /* 0x04 Number of ASCIIZ String */
    uint8_t BiosVersion    ; /* 0x05 Number of ASCIIZ String */
    uint16_t BiosStartSeg   ; /* 0x06 Segment location of BIOS starting address, e.g.0E800h. Note: The size of the runtime BIOS image can be computed by subtracting the Starting Address Segment from 10000h and multiplying the result by 16. */
    uint8_t BiosRelDate    ; /* 0x08 String number of the BIOS release date. The date string, if supplied, is in either mm/dd/yy or mm/dd/yyyy format. If the year portion of the string is two digits, the year is assumed to be 19yy. */
    uint8_t BiosRomSize    ; /* 0x09 Size (n) where 64K * (n+1) is the size of the physical 0Ah device containing the BIOS, in bytes   */
    uint32_t BiosChar[2]   ; /* 0x0A Defines which functions the BIOS supports.  PCI, PCMCIA, Flash, etc.    */
    uint16_t BiosEChar     ; /* 0x12 Number of ASCIIZ String */
    uint8_t BiosMajorRel   ; /* 0x14 Identifies the major release of the System BIOS; */
    uint8_t BiosMinorRel   ; /* 0x15 Identifies the minor release of the System BIOS; */
    uint8_t ECNMajorRel    ; /* 0x16 Identifies the major release of the Embedded Controller */
    uint8_t ECNMinorRel    ; /* 0x17 Identifies the minor release of the Embedded Controller */
}BiosInfo_t;

/*
 *      System Information
 *
 *  see http://www.dmtf.org/standards/published_documents/DSP0134_2.6.1.pdf
 *  Type 1 Block
 */
typedef struct SystemInfo_s{
    SmbiosHdr_t SMBHdr; /* 0x00 Smbios Dynamic Block Header */
    uint8_t Manufacturer   ; /* 0x04 Number of ASCIIZ String */
    uint8_t ProductName    ; /* 0x05 Number of ASCIIZ String */
    uint8_t Version        ; /* 0x06 Number of ASCIIZ String */
    uint8_t SerialNumber   ; /* 0x07 Number of ASCIIZ String */
    EeePGUID_t UUID        ; /* 0x08 Universal Unique ID number. */
    uint8_t Reserved0      ; /* 0x19 Reserved Set to Zero    */
    uint8_t SKU_Number     ; /* 0x1A Number of ASCIIZ String */
    uint8_t Family         ; /* 0x1B Number of ASCIIZ String */
}SystemInfo_t;

/*
 *     Base Board (or Module) Information
 *
 *  see http://www.dmtf.org/standards/published_documents/DSP0134_2.6.1.pdf
 *  Type 2 Block
 */
typedef struct ModuleInfo_s{
    SmbiosHdr_t SMBHdr; /* 0x00 Smbios Dynamic Block Header */
    uint8_t Manufacturer   ; /* 0x06 Number of ASCIIZ String */
    uint8_t Product        ; /* 0x07 Number of ASCIIZ String */
    uint8_t Version        ; /* 0x08 Number of ASCIIZ String */
    uint8_t SerialNumber   ; /* 0x09 Number of ASCIIZ String */
    uint8_t AssetTag       ; /* 0x0A Number of ASCIIZ String */
    uint8_t FeatureFlag    ; /* 0x0B A collection of 
                              *      flags that identify 
                              *      features of this 
                              *      baseboard.
                              *      +=======+=========================+
                              *      | Bits  | Descriptions            |
                              *      +=======+=========================+
                              *      | 0     | Is Motherboard          |
                              *      +-------+-------------------------+
                              *      | 1     | Requires Daughter Board |
                              *      +-------+-------------------------+
                              *      | 2     | Removable               |
                              *      +-------+-------------------------+
                              *      | 3     | Replaceable             |
                              *      +-------+-------------------------+
                              *      | 4     | Hot Swap Capable        |
                              *      +-------+-------------------------+
                              *      | 5 - 7 | Reserved                |
                              *      +=======+=========================+
                              */
#       define SMBIOS_IS_Motherboard  EEEP_UINT8_C(1 << 0)
#       define SMBIOS_REQ_DAUGHTER    EEEP_UINT8_C(1 << 1)
#       define SMBIOS_REMOVABLE       EEEP_UINT8_C(1 << 2)
#       define SMBIOS_REPLACEABLE     EEEP_UINT8_C(1 << 3)
#       define SMBIOS_HOT_SWAP_CAP    EEEP_UINT8_C(1 << 4)
    uint8_t Location       ; /* 0x0C Number of ASCIIZ String */
    SmbiosHandle_t LocHdl  ; /* 0x0D Chassis Handle */
    SMBIOS_BoardTypes_t BoardType ; /* 0x0F SMBIOS_BoardTypes_t */
    uint8_t ContainedHndls ; /* 0x0C Number Of Contained 
                              *      Object Handles That 
                              *      Follow
                              */
    SmbiosHandle_t Handles[1] ; /* 0x10 Handles */
}ModuleInfo_t;



/*
 *      Chassis Information
 *
 *  see http://www.dmtf.org/standards/published_documents/DSP0134_2.6.1.pdf
 *  Type 3 Block
 */

typedef struct ChassisInfo_s{
    SmbiosHdr_t SMBHdr; /* 0x00 Smbios Dynamic Block Header */
    uint8_t Manufacturer   ; /* 0x06 Number of ASCIIZ String */
    ChassisTypes_t Type    ; /* 0x07 ENUM */
    uint8_t Version        ; /* 0x08 Number of ASCIIZ String */
    uint8_t SerialNumber   ; /* 0x09 Number of ASCIIZ String */
    uint8_t AssetTagNumber ; /* 0x0A Number of ASCIIZ String */
    uint8_t Reserved0[4]   ; /* 0x0B Reserved */
    EeePuint32u_t OEM      ; /* 0x0F Contains OEM- or BIOS 
                              * vendor-specific information 
                              */
    uint8_t Height         ; /* 0x13 The height of the  
                              * enclosure, in 'U's.  
                              */
    uint8_t NumPowerCords  ; /* 0x14 Identifies the number   
                              * of power cords associated with  
                              * the enclosure or chassis. 
                              */
    uint8_t CElementCnt    ; /* 0x15 Contained Element Count */   
    uint8_t CElementSize   ; /* 0x16 Contained Element Size  */   
    CCElement_t CElement[1]; /* 0x17 Contained Element(s) */   
}ChassisInfo_t;


#define SMBIOS_MIN_BLOCK_LENGTH (sizeof(SmbiosHdr_t)+2)

#pragma pack(pop)   /* restore original alignment from stack */

#ifdef __cplusplus
}
#endif
#endif /* __SMBIOS_H__ */
