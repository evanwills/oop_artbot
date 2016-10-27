#include <Arduino.h>


// Include libraries for drawing to the OLED screen
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

// Include libraries for the stepper motors
#include <AccelStepper.h>
#include <AFMotor.h>


#include <TimedButton.h>      // allows for using buttons in a time sensitive way
#include <RotaryEncoder.h>    // makes getting the output of a rotary encoder easier.

// #include <ArtbotSystem.h>     // does all the basic setting up of Artbot stuff
#include <ArtbotUI.h>         // handles showing the user stuff on the screen and getting user input
#include <ArtbotDrawingMode.h> // does all the calcuations also has info on what user inputs are required
#include <ArtbotDriver.h>     // makes the moving components move
#include <ArtbotInputMetadata.h> // metadata objects containing info about each input required by the controller


ArtbotUI ui = new ArtbotUI();

ArtbotDriver driver = new ArtbotDriver( 2048, 79, 400, 100 );

ArtbotController controller;

// ArtbotSystem system = new ArtbotSystem( ui , driver );

void setup() {
	ui.setDrawingModes( ArtbotController::getAvailableModes() );
	ui.welcome();
}

void loop() {
	char mode = ui.checkDrawInterupt();

	if( mode == 0 ) {
		driver.stop();
		if( ui.renderModeSelector() == true ) {
			controller = ArtbotController::factory( ui.getDrawingMode() );
		}
	} else if (mode == 1) {
		driver.stop();
		if( ui.renderInputFields() == true ) {
			controller.setInputValues();
		}
	} else {
		if( dirver.travelCompleted(WHEEL_LEFT) == true ) {
			controller.calculate( WHEELS , WHEEL_LEFT );
			driver.setWheelAction(
				WHEEL_LEFT,
				controller.getDriverValue( WHEELS , WHEEL_LEFT , WHEEL_DISTANCE ),
				controller.getDriverValue( WHEELS , WHEEL_LEFT , WHEEL_SPEED),
				controller.getDriverValue( WHEELS , WHEEL_LEFT , WHEEL_ACCELLERATION)
			);
		}

		if( dirver.travelCompleted(WHEEL_RIGHT) == true ) {
			controller.calculate( WHEELS , WHEEL_RIGHT);
			driver.setWheelAction(
				WHEEL_RIGHT,
				controller.getDriverValue( WHEELS , WHEEL_RIGHT , WHEEL_DISTANCE),
				controller.getDriverValue( WHEELS , WHEEL_RIGHT , WHEEL_SPEED),
				controller.getDriverValue( WHEELS , WHEEL_RIGHT , WHEEL_ACCELLERATION)
			);
		}

//		Not yet implemented!
//		if( dirver.travelCompleted( PEN , PEN_HEIGHT) == true ) {
//			controller.calculate( PEN , PEN_HEIGHT );
//			driver.setPenAction(
// 				controller.getDriverValue( PEN , PEN_HEIGHT),
// 				controller.getDriverValue( PEN , PEN_POSITION),
// 				controller.getDriverValue( PEN , PEN_ANGLE)
//			);
//		}


		driver.draw();
	}
}
