/*******************************************************************************
  SQI Peripheral Library Template Implementation

  File Name:
    sqi_CommandStatus_Default.h

  Summary:
    SQI PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CommandStatus
    and its Variant : Default
    For following APIs :
        PLIB_SQI_CommandStatusGet
        PLIB_SQI_ExistsCommandStatus

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _SQI_COMMANDSTATUS_DEFAULT_H
#define _SQI_COMMANDSTATUS_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _SQI_COMMAND_STATUS_VREG(index)

  MASKs:
    _SQI_COMMAND_STATUS_MASK(index)

  POSs:
    _SQI_COMMAND_STATUS_POS(index)

  LENs:
    _SQI_COMMAND_STATUS_LEN(index)

*/


//******************************************************************************
/* Function :  SQI_CommandStatusGet_Default

  Summary:
    Implements Default variant of PLIB_SQI_CommandStatusGet

  Description:
    This template implements the Default variant of the PLIB_SQI_CommandStatusGet function.
*/

PLIB_TEMPLATE uint8_t SQI_CommandStatusGet_Default( SQI_MODULE_ID index )
{
    return (uint8_t) _SFR_FIELD_READ (_SQI_COMMAND_STATUS_VREG(index),
					  				  _SQI_COMMAND_STATUS_MASK(index),
					  				  _SQI_COMMAND_STATUS_POS(index));
}


//******************************************************************************
/* Function :  SQI_ExistsCommandStatus_Default

  Summary:
    Implements Default variant of PLIB_SQI_ExistsCommandStatus

  Description:
    This template implements the Default variant of the PLIB_SQI_ExistsCommandStatus function.
*/

#define PLIB_SQI_ExistsCommandStatus PLIB_SQI_ExistsCommandStatus
PLIB_TEMPLATE bool SQI_ExistsCommandStatus_Default( SQI_MODULE_ID index )
{
    return true;
}


#endif /*_SQI_COMMANDSTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

