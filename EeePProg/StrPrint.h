/*
 *<KHeader>
 *+=========================================================================
 *I  Project Name: Kontron Secure Bios
 *+=========================================================================
 *I  $HeadURL: http://svn.code.sf.net/p/eapidk/code/trunk/apps/EeePProg/StrPrint.h $
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
 *I  ID                   : $Id: StrPrint.h 75 2010-06-28 23:50:38Z dethrophes $
 *I
 *+=========================================================================
 *</KHeader>
 */
#ifndef __STRPRINT_H__
#define __STRPRINT_H__

#ifdef __cplusplus
extern "C" {
#endif


EApiStatus_t
PrintStringBlockA(
    FILE       *OutStream     ,
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    const char *cszPreamble   ,
    signed int  siLen         ,
    const char *cszPostamble
    );

EApiStatus_t
PrintStringBlock(
    FILE       *OutStream     ,
    const char *cszStr        ,
    size_t      stMaxBlockLen ,
    const char *cszPreamble   ,
    signed int  siLen         ,
    const char *cszPostamble
    );


#ifdef __cplusplus
}
#endif
#endif /* __STRPRINT_H__ */

