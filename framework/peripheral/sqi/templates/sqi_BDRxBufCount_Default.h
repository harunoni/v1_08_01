/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_BDRxBufCount_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BDRxBufCount
    and its Variant : Default
    For following APIs :
        PLIB_SQI_DMABDReceiveBufferCountGet
        PLIB_SQI_ExistsBDRxBufCount

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

//DOM-IGNORE-END

#ifndef _SQI_BDRXBUFCOUNT_DEFAULT_H
#define _SQI_BDRXBUFCOUNT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _SQI_RECEIVE_BUF_COUNT_VREG(index)

  MASKs:
    _SQI_RECEIVE_BUF_COUNT_MASK(index)

  POSs:
    _SQI_RECEIVE_BUF_COUNT_POS(index)

  LENs:
    _SQI_RECEIVE_BUF_COUNT_LEN(index)

*/


//******************************************************************************
/* Function :  SQI_DMABDReceiveBufferCountGet_Default

  Summary:
    Implements Default variant of PLIB_SQI_DMABDReceiveBufferCountGet

  Description:
    This template implements the Default variant of the PLIB_SQI_DMABDReceiveBufferCountGet function.
*/

PLIB_TEMPLATE uint8_t SQI_DMABDReceiveBufferCountGet_Default( SQI_MODULE_ID index )
{
	return (uint8_t) _SFR_FIELD_READ (_SQI_RECEIVE_BUF_COUNT_VREG(index),
									  _SQI_RECEIVE_BUF_COUNT_MASK(index),
									  _SQI_RECEIVE_BUF_COUNT_POS(index));
}


//******************************************************************************
/* Function :  SQI_ExistsBDRxBufCount_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsBDRxBufCount

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsBDRxBufCount function.
*/

#define PLIB_SQI_ExistsBDRxBufCount PLIB_SQI_ExistsBDRxBufCount
PLIB_TEMPLATE bool SQI_ExistsBDRxBufCount_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_BDRXBUFCOUNT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

