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

#include <ArtbotSystem.h>     // does all the basic setting up of Artbot stuff
#include <ArtbotUI.h>         // handles showing the user stuff on the screen and getting user input
#include <ArtbotDrawingMode.h> // does all the calcuations also has info on what user inputs are required
#include <ArtbotDriver.h>     // makes the moving components move
#include <ArtbotInputMetadata.h> // metadata objects containing info about each input required by the controller



void setup() {
}

void loop() {
}
