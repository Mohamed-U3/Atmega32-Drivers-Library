#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"


u8 KPD_U8getPressedKey(void)
{

	u8 loacal_u8PressedKey =  KPD_NO_PRESSED_KEY  , local_u8ColmnIDX , local_u8RowIDX , Local_u8PinState ;
    static u8 Local_u8KPDARR[COLUMN_NUM][ROW_NUM]= KPD_ARR_VAL;
    static u8 local_u8KPDColmnArr[COLUMN_NUM]={KPD_COLMN0_PIN,KPD_COLMN1_PIN,KPD_COLMN2_PIN,KPD_COLMN3_PIN};
    static u8 local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

    for (local_u8ColmnIDX=0 ; local_u8ColmnIDX< COLUMN_NUM ;local_u8ColmnIDX++)
    {
    	 /* ACctivate current colume */

    	DIO_u8SetPinValue(KPD_port ,local_u8KPDColmnArr[local_u8ColmnIDX],DIO_u8PIN_LOW);
    	for (local_u8RowIDX =0 ; local_u8RowIDX< ROW_NUM ; local_u8RowIDX ++ )
    	{
    		/* READ THE CURENT ROW*/
    		DIO_u8GetPinValue( KPD_port ,local_u8KPDRowArr[local_u8RowIDX], &Local_u8PinState );

    		/* CHECK IF SWITCH IS PRESSED*/

    		if (DIO_u8PIN_LOW == Local_u8PinState )
    		{

    			loacal_u8PressedKey = Local_u8KPDARR[local_u8RowIDX][local_u8ColmnIDX];

    			/* polling (busy waiting ) until the key is released */

    			while (DIO_u8PIN_LOW == Local_u8PinState)
    			{

    				DIO_u8GetPinValue( KPD_port ,local_u8KPDRowArr[local_u8RowIDX], &Local_u8PinState );
    			}

    			return loacal_u8PressedKey ;


    		}
    		/*Deactivate the current column*/

    	}
    	DIO_u8SetPinValue(KPD_port ,local_u8KPDColmnArr[local_u8ColmnIDX],DIO_u8PIN_HIGH);

    }

    //return Local_u8KPDARR[2][1];
    return loacal_u8PressedKey ;
}
