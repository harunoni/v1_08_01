/*******************************************************************************
  PMP Peripheral Library Template Implementation

  File Name:
    pmp_WriteChipSelectEnable_Basic.h

  Summary:
    PMP PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : WriteChipSelectEnable
    and its Variant : Basic
    For following APIs :
        PLIB_PMP_ExistsWriteChipSelectEnable
        PLIB_PMP_WriteChipSelectXEnable
        PLIB_PMP_WriteChipSelectXDisable

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

#ifndef _PMP_WRITECHIPSELECTENABLE_BASIC_H
#define _PMP_WRITECHIPSELECTENABLE_BASIC_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _PMP_DUAL_WRITE_CS_ENABLE_VREG(index)

  MASKs: 
    _PMP_DUAL_WRITE_CS_ENABLE_MASK(index)

  POSs: 
    _PMP_DUAL_WRITE_CS_ENABLE_POS(index)

  LENs: 
    _PMP_DUAL_WRITE_CS_ENABLE_LEN(index)

*/


//******************************************************************************
/* Function :  PMP_ExistsWriteChipSelectEnable_Basic

  Summary:
    Implements Basic variant of PLIB_PMP_ExistsWriteChipSelectEnable

  Description:
    This template implements the Basic variant of the PLIB_PMP_ExistsWriteChipSelectEnable function.
*/

#define PLIB_PMP_ExistsWriteChipSelectEnable PLIB_PMP_ExistsWriteChipSelectEnable
PLIB_TEMPLATE bool PMP_ExistsWriteChipSelectEnable_Basic( PMP_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  PMP_WriteChipSelectXEnable_Basic

  Summary:
    Implements Basic variant of PLIB_PMP_WriteChipSelectXEnable 

  Description:
    This template implements the Basic variant of the PLIB_PMP_WriteChipSelectXEnable function.
*/

PLIB_TEMPLATE void PMP_WriteChipSelectXEnable_Basic( PMP_MODULE_ID index , PMP_CHIP_SELECT chipSelect )
{
    _SFR_FIELD_WRITE(
                        _PMP_DUAL_WRITE_CS_ENABLE_VREG(index),
                        _PMP_DUAL_WRITE_CS_ENABLE_MASK(index),
                        ( (_PMP_DUAL_WRITE_CS_ENABLE_POS(index)) + (chipSelect) ),
                        1
    );
}


//******************************************************************************
/* Function :  PMP_WriteChipSelectXDisable_Basic

  Summary:
    Implements Basic variant of PLIB_PMP_WriteChipSelectXDisable 

  Description:
    This template implements the Basic variant of the PLIB_PMP_WriteChipSelectXDisable function.
*/

PLIB_TEMPLATE void PMP_WriteChipSelectXDisable_Basic( PMP_MODULE_ID index , PMP_CHIP_SELECT chipSelect )
{
    _SFR_FIELD_CLEAR(
                        _PMP_DUAL_WRITE_CS_ENABLE_VREG(index),
                        _PMP_DUAL_WRITE_CS_ENABLE_MASK(index),
                        ( (_PMP_DUAL_WRITE_CS_ENABLE_POS(index)) + (chipSelect) ),
                        1
    );
}


#endif /*_PMP_WRITECHIPSELECTENABLE_BASIC_H*/

/******************************************************************************
 End of File
*/

