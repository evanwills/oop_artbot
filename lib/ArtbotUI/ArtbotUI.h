/**
 * ArtbotUI.h - provides everything for the user interface of Artbot
 *
 * It is intended that this should make it easy to allow different
 * drawing modes with different input to work with a standard UI
 *
 * Created by Evan Wills 2016-10-16
 * Released under GPL2 Licence
 */


#ifndef ArtbotUI_h
#define ArtbotUI_h


#include <Arduino.h>
#include <stdlib.h>
#include <TimedButton.h>
#include <RotaryEncoder.h>
#include <ArtbotInputField.h>



class ArtbotUI {
	public:
		ArtbotUI();

		/**
		 * Shows welcome screen when artbot is first started.
		 */
		 void welcome();

		/**
		 * takes a list of drawing modes (supplied by controller static method:
		 * getAvailableModes()) to tell the user the drawing modes it has a
		 * available
		 */
		void setDrawingModes( array modes );

		/**
		 * shows user list of available drawing modes. reads physical
		 * component(s) and converts the user input into an integer to be
		 * passed back to the system
		 */
		void renderModeSelector();

		/**
		 * returns the index of the drawing mode to be used.
		 * returns -1 if no mode selected.
		 *
		 * (to be passed to the controller factory)
		 */
		char getDrawingMode();

		/**
		 * takes an input field struct from a controller and includes it in
		 * the UI
		 */
		void setInputField( ArtbotInputField * field );

		/**
		 * shows the user the fields needed for the controller. reads
		 * physical components and converts their inputs into values to be
		 * passed back to the controller. Shows user the values it's read
		 * from the physical components
		 */
		void renderInputFields();

		/**
		 * Add preset values for the current Drawing mode
		 */
		void setPresets( array presets );

		/**
		 * switch to drawing mode if true
		 */
		bool startDrawing();

		/**
		 * delete all input fields from previous controller
		 * (free up memory)
		 */
		void purgeInputFields();

		/**
		 * checks to see if drawing mode has been interrupted
		 * @return activityMode
		 *		0 = get new drawing mode
		 *		1 = update drawing mode config
		 *		2 = continue drawing (no interrupt),
		 *
		 * (step 9 from Flow)
		 */
		bool checkDrawInterupt();

	protected:
		Adafruit_SSD1306 screen;
		char activityMode = 0;
};

#endif
