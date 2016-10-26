/**
 * ArtbotController.h - provides everything for the user interface of Artbot
 *
 * It is intended that this should make it easy to allow different
 * drawing modes with different input to work with a standard UI
 *
 * Created by Evan Wills 2016-10-16
 * Released under GPL2 Licence
 */

#ifndef ArtbotController_h
#define ArtbotController_h


#include <Arduino.h>
#include <stdlib.h>
#include <ArtbotInputMetadata.h>

class ArtbotController {

	public:
		/**
		 *
		 returns an ArtbotController object to be used by the system to calculate commands for the motors and servos.
		 */
		static ArtBotController factory( char drawingMode );
		/**
		 * Returns an array of available drawing modes
		 * (To be used by the UI when getting the user to select drawing mode.)
		 */
		static array getAvailableModes();

		/**
 		 * returns the number of items in a group.
 		 *	+	If no parameters are supplied, then it returns the number
 		 *		of primary components (1 (wheels) at this point but could
		 *		be 2 (wheels & pen) or more).
 		 *
		 *	+	If component is supplied then it returns the number of sub
 		 *		components (for wheels it would be 2)
 		 *
		 *	+	If component AND sub-component is also supplied then it
		 *		returns the number of fields for that sub component
		 */
		char getFieldCount( char component );

		/**
		 * returns the user input field metadata object for use by UI
		 */
	 	* ArtbotInputField getInputField( char component );

		/**
		 * Because ArtbotInputFields are passed as pointers, UI should set
		 * the value as part of it's operation. Thus, when UI has completed
		 * all fields should have their appropriate values
		 * This method just goes through each field and gets the value out
		 * for later use.
		 */
	 	void setInputValues();

		/**
		 * Gets current user defined values being used for calculating
		 * driver commands.
		 */
	 	mixed getInputValues( char component, char subComponent, char field );

		/**
		 * Gets an array of developer defined preset configuration values
		 * for that drawing mode
		 */
	 	array getPresetValues();

		/**
		 * contains the algorithm for generating the commands for the driver
		 */
	 	void calculate();

		/**
		 * returns a particular value to be passed back to the driver
		 */
	 	int getDriverValue( char component, char subComponent, char field );

};
#endif
