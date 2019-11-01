 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Mostafa Maged
 ******************************************************************************/

#include "Port.h"
#include "Dio_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC Port_ConfigChannel * Port_PortChannels = NULL_PTR;
STATIC uint8 Dio_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
		/*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Dio_Status       = PORT_INITIALIZED;
		Port_PortChannels = ConfigPtr->Channels; /* address of the first Channels structure --> Channels[0] */
		int counter;

		/* point to the required DDR Register */
		Port_PortType * DDR_Ptr = NULL_PTR;
		Port_PortType * PORT_Ptr = NULL_PTR;

		for(counter = 0; counter < PORT_CONFIGURED_CHANNLES; counter++)
		{
			switch(Port_PortChannels[counter].port)
			{
				case  PORTA_ID: DDR_Ptr = &DDRA_REG;
								PORT_Ptr = &PORTA_REG;
						 break;
				case  PORTB_ID: DDR_Ptr = &DDRB_REG;
								PORT_Ptr = &PORTB_REG;
						 break;
				case  PORTC_ID: DDR_Ptr = &DDRC_REG;
								PORT_Ptr = &PORTC_REG;
						 break;
				case  PORTD_ID: DDR_Ptr = &DDRD_REG;
								PORT_Ptr = &PORTD_REG;
						 break;
			}
			if(Port_PortChannels[counter].direction == PORT_PIN_OUT)
			{
				SET_BIT(*DDR_Ptr,Port_PortChannels[counter].pin_num); // set the corresponding bit in the DDR register to configure it as output pin
				CLEAR_BIT(*PORT_Ptr, Port_PortChannels[counter].pin_num); // clear the corresponding bit as initial value
			}
			else if(Port_PortChannels[counter].direction == PORT_PIN_IN)
			{
				CLEAR_BIT(*DDR_Ptr,Port_PortChannels[counter].pin_num); // clear the corresponding bit in the DDR register to configure it as input pin
			}
		}
	}
}

void Port_RefreshPortDirection(void)
{

}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
	Port_PortType * DDR_Ptr = NULL_PTR;
	/* point to the required DDR Register */
	switch(Port_PortChannels[Pin].port)
	{
		case  PORTA_ID: DDR_Ptr = &DDRA_REG;
				 break;
		case  PORTB_ID: DDR_Ptr = &DDRB_REG;
				 break;
		case  PORTC_ID: DDR_Ptr = &DDRC_REG;
				 break;
		case  PORTD_ID: DDR_Ptr = &DDRD_REG;
				 break;
	}
	if(Port_PortChannels[Pin].direction == PORT_PIN_OUT)
	{
		SET_BIT(*DDR_Ptr,Port_PortChannels[Pin].pin_num); // set the corresponding bit in the DDR register to configure it as output pin
	}
	else if(Port_PortChannels[Pin].direction == PORT_PIN_IN)
	{
		CLEAR_BIT(*DDR_Ptr,Port_PortChannels[Pin].pin_num); // clear the corresponding bit in the DDR register to configure it as input pin
	}				
}
#endif

#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/*Sets the port pin mode*/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{

}
