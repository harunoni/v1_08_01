/*******************************************************************************
  Board Support Package Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    bsp_sys_init.c

  Summary:
    Board Support Package implementation for PIC32MZ Embedded Connectivity (EC)
    Starter Kit in combination with Multimedia Expansion Board II.

  Description:
    This file contains routines that implement the board support package for
    PIC32MZ Embedded Connectivity (EC) Starter Kit in combination with
    Multimedia Expansion Board II.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "bsp_config.h"
#include "peripheral/ebi/plib_ebi.h"

// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function: 
    void BSP_Initialize(void)

  Summary:
    Performs the necessary actions to initialize a board
  
  Description:
    This function initializes the LED, Switch and other ports on the board.
    This function must be called by the user before using any APIs present in
    this BSP.  

  Remarks:
    Refer to bsp_config.h for usage information.
*/

void BSP_Initialize(void )
{
 
   
    /* Set the Initial state of LEDs */
    PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, BSP_LED_1 );
    PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, BSP_LED_2 );
    PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, BSP_LED_3 );
    PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, BSP_LED_D6 );
    PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, BSP_LED_D7 );

 
    /* Set the Initial state of BT Pin */
    PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_2);

    /* Required for camera */

    PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_J, PORTS_BIT_POS_7);

 
    PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_J, PORTS_BIT_POS_12);

 
    PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_J, PORTS_BIT_POS_10);
  
 

    PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_K, PORTS_BIT_POS_5);

    /* Needed for USB VBUS Switch */
 
    PLIB_PORTS_PinClear ( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5 );
	
	/* BT Pin */
    PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, PORTS_BIT_POS_3 );

}

// *****************************************************************************
/* Function: 
    void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state);

  Summary:
    Controls the state of the LED.
  
  Description:
    This function allows the application to specify the state of the LED.

  Remarks:
    Refer to bsp_config.h for usage information.
*/

void BSP_LEDStateSet(BSP_LED led, BSP_LED_STATE state)
{
    /* Set the state of the LED */
    PLIB_PORTS_PinWrite (PORTS_ID_0 , PORT_CHANNEL_H , led, state );
}

// *****************************************************************************
/* Function: 
    void BSP_LEDToggle(BSP_LED led);

  Summary:
    Toggles the state of the LED between BSP_LED_STATE_ON and BSP_LED_STATE_OFF.
  
  Description:
    This function toggles the state of the LED between BSP_LED_STATE_ON and
    BSP_LED_STATE_OFF.

  Remarks:
    Refer to bsp_config.h for usage information.
*/    

void BSP_LEDToggle(BSP_LED led)
{
    PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_H, led );
}

// *****************************************************************************
/* Function: 
    BSP_LED_STATE BSP_LEDStateGet(BSP_LED led);

  Summary:
    Returns the present state of the LED.
  
  Description:
    This function returns the present state of the LED.

  Remarks:
    Refer to bsp_config.h for usage information.
*/    

BSP_LED_STATE BSP_LEDStateGet (BSP_LED led)
{
    /* Get LED Status */
    return PLIB_PORTS_PinGetLatched (PORTS_ID_0, PORT_CHANNEL_H, led);
}

// *****************************************************************************
/* Function: 
    void BSP_LEDOn(BSP_LED led);

  Summary:
    Switches ON the specified LED.
  
  Description:
    This function switches ON the specified LED.

  Remarks:
    Refer to bsp_config.h for usage information.
*/

void BSP_LEDOn(BSP_LED led)
{
    PLIB_PORTS_PinSet( PORTS_ID_0, PORT_CHANNEL_H, led );
}

// *****************************************************************************
/* Function: 
    void BSP_LEDOff(BSP_LED led);

  Summary:
    Switches Off the specified LED.
  
  Description:
    This function switches Off the specified LED.

  Remarks:
    Refer to bsp_config.h for usage information.
*/

void BSP_LEDOff(BSP_LED led)
{
    PLIB_PORTS_PinClear( PORTS_ID_0, PORT_CHANNEL_H, led );
}

// *****************************************************************************
/* Function: 
    void BSP_SwitchStateGet(BSP_SWITCH switch);

  Summary:
    Returns the present state (pressed or not pressed) of the specified switch.
  
  Description:
    This function returns the present state (pressed or not pressed) of the
    specified switch.

  Remarks:
    Refer to bsp_config.h for usage information.
*/

BSP_SWITCH_STATE BSP_SwitchStateGet( BSP_SWITCH bspSwitch )
{
    PORTS_CHANNEL bspPort;

    if(bspSwitch == BSP_SWITCH_S1)
    {
        bspPort = PORT_CHANNEL_A;
    }
    else
    {
        bspPort = PORT_CHANNEL_B;
    }

    return ( PLIB_PORTS_PinGet(PORTS_ID_0, bspPort, bspSwitch) );
}

// *****************************************************************************
/* Function: 
    void BSP_USBVBUSSwitchStateSet(BSP_USB_VBUS_SWITCH_STATE state);

  Summary:
    This function enables or disables the USB VBUS switch on the board.
  
  Description:
    This function enables or disables the VBUS switch on the board.

  Remarks:
    Refer to bsp_config.h for usage information.
*/

void BSP_USBVBUSSwitchStateSet(BSP_USB_VBUS_SWITCH_STATE state)
{
    /* Enable the VBUS switch */

    PLIB_PORTS_PinWrite( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5, state );
}

// *****************************************************************************
/* Function:
    void BSP_BluetoothPinStateSet(BSP_BT_STATE state);

  Summary:
    Sets to low/high the pin to the Bluetooth module.

  Description:
    Sets to low/high the pin to the Bluetooth module.

  Remarks:
    None.
*/
void BSP_BluetoothPinStateSet(BSP_BT_STATE state)
{
    PLIB_PORTS_PinWrite (PORTS_ID_0 , PORT_CHANNEL_B , PORTS_BIT_POS_2, state );
}

// *****************************************************************************
/* Function: 
    bool BSP_USBVBUSPowerEnable(uint8_t port, bool enable)

  Summary:
    This function controls the USB VBUS supply.
  
  Description:
    This function controls the USB VBUS supply.

  Remarks:
    None.
*/

void BSP_USBVBUSPowerEnable(uint8_t port, bool enable)
{
    /* Enable the VBUS switch */

    PLIB_PORTS_PinWrite( PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_5, enable );
}

// *****************************************************************************
/* Function: 
    bool BSP_USBVBUSOverCurrentDetect(uint8_t port)

  Summary:
    Returns true if the over current is detected on the VBUS supply.
  
  Description:
    This function returns true if over current is detected on the VBUS supply.

  Remarks:
    None.
*/

bool BSP_USBVBUSSwitchOverCurrentDetect(uint8_t port)
{
    return(false);
}
/*******************************************************************************
 End of File
*/
