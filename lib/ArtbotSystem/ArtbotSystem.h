/*
 * ArtbotSystem.h
 * the super controller for the artbot.
 *
 * manages:
 *		+	objects for the physical components of the Artbot.
 *			+	buttons
 *			+	rotary encoders
 *			+	physical switches
 *			+	motors
 *		+	generates the objects that manage actually doing the drawing
 *			-	driver
 *			-	controller
 *			-	user interface
 *		+	passing data from the UI to the controller to the driver
 *		+	passing data from the driver back to the controller
 *		+	has its own UI to handle switching between drawing modes
 *
 * Created by Evan Wills 2016-10-16
 * Released under GPL2 Licence
 */



#ifndef ArtbotSystem_h
#define ArtbotSystem_h


#include <Arduino.h>
#include <stdlib.h>
#include <TimedButton.h>
#include <RotaryEncoder.h>
#include <ArtbotUI.h>
#include <ArtbotController.h>
#include <ArtbotDriver.h>

class ArtbotSystem {
	public:
		ArtbotSystem( ArtbotUI ui , ArtbotDriver driver );

		/**
		 * welcome() a pass-through method for the UI
		 */
		void welcome();

		/**
		 * makes UI show available modes and lets user choose desired
		 * mode.
		 * @return TRUE if mode has been set
		 * (steps 2, 3 & 4 from Flow)
		 */
		bool doDrawingMode();


		/**
		 * gets new inputs for controller
		 *
		 * @return TRUE if user has finalised settings
		 * (step 5 from Flow)
		 */
		bool doDrawingSettings();

		/**
		 * passes values from UI to controller
		 * (steps 6 & 7 from Flow)
		 */
		void beginDrawing();


		/**
		 * passes commands from controller to driver
		 * (steps 8.a - 8.c from Flow)
		 */
		void draw();

		/**
		 * checks UI to see if drawing mode has been interrupted
		 * @return activityMode
		 *		0 = get new drawing mode
		 *		1 = update drawing mode config
		 *		2 = continue drawing (no interrupt),
		 *
		 * (step 9 from Flow)
		 */
		char checkDrawInterupt();


	private:
		ArtbotUI _ui;
		ArtbotController controller;
		ArtbotDriver _driver;
		char activityMode = 0;
};

#endif;
