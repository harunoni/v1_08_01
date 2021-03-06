/*******************************************************************************
  USART Peripheral Library Template Implementation

  File Name:
    usart_EnableControl_Default.h

  Summary:
    USART PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EnableControl
    and its Variant : Default
    For following APIs :
        PLIB_USART_ExistsEnable
        PLIB_USART_Disable
        PLIB_USART_Enable
        PLIB_USART_BaudSetAndEnable

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

#ifndef _USART_ENABLECONTROL_DEFAULT_H
#define _USART_ENABLECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USART_ENABLE_CONTROL_VREG(index)

  MASKs: 
    _USART_ENABLE_CONTROL_MASK(index)

  POSs: 
    _USART_ENABLE_CONTROL_POS(index)

  LENs: 
    _USART_ENABLE_CONTROL_LEN(index)

*/


//******************************************************************************
/* Function :  USART_ExistsEnable_Default

  Summary:
    Implements Default variant of PLIB_USART_ExistsEnable

  Description:
    This template implements the Default variant of the PLIB_USART_ExistsEnable function.
*/

#define PLIB_USART_ExistsEnable PLIB_USART_ExistsEnable
PLIB_TEMPLATE bool USART_ExistsEnable_Default( USART_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  USART_Disable_Default

  Summary:
    Implements Default variant of PLIB_USART_Disable 

  Description:
    This template implements the Default variant of the PLIB_USART_Disable function.
*/

PLIB_TEMPLATE void USART_Disable_Default( USART_MODULE_ID index )
{
    _SFR_BIT_CLEAR(_USART_ENABLE_CONTROL_VREG(index),
                 _USART_ENABLE_CONTROL_POS(index) );
}


//******************************************************************************
/* Function :  USART_Enable_Default

  Summary:
    Implements Default variant of PLIB_USART_Enable 

  Description:
    This template implements the Default variant of the PLIB_USART_Enable function.
*/

PLIB_TEMPLATE void USART_Enable_Default( USART_MODULE_ID index )
{
    _SFR_BIT_SET(_USART_ENABLE_CONTROL_VREG(index),
                 _USART_ENABLE_CONTROL_POS(index) );
}

//******************************************************************************
/* Function :  USART_BaudSetAndEnable_Default

  Summary:
    Implements Default variant of PLIB_USART_BaudSetAndEnable 

  Description:
    This template implements the Default variant of the PLIB_USART_BaudSetAndEnable function.
*/

PLIB_TEMPLATE void USART_BaudSetAndEnable_Default( USART_MODULE_ID index, uint32_t systemClock, uint32_t baud  )
{
    int32_t brgValueLow = 0;
    int32_t brgValueHigh = 0;
    SFR_TYPE * umode = _USART_ENABLE_CONTROL_VREG(index);
    SFR_TYPE * usta = _USART_RECEIVER_IDLE_VREG(index);
    SFR_TYPE * ubaud = _USART_BAUD_RATE_VREG(index);

    /* Enable transmit and receive */
    *usta |= 0x1400;

    /* Find the BRG Value */
    brgValueLow  = (((systemClock / baud) >> 4) - 1);
    brgValueHigh = (((systemClock / baud) >> 2) - 1);

    /* Check if the baud value can be set with high baud settings */
    if ((brgValueHigh >= 0) && (brgValueHigh <= UINT16_MAX))
    {
	/* Set BRGH */
        *umode |= 0x0008;
        *ubaud = brgValueHigh;
    }
    else
    {
	/* Clear BRGH */
        *umode &= ~0x0008;
        *ubaud = brgValueLow;
    }

    /* Enable the UART */
    *umode |= 0x8000;
}

#endif /*_USART_ENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

