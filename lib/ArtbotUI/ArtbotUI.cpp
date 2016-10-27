#include "ArtbotUI.h"

ArtbotUI::ArtbotUI() {
	screen =  = OLEDScreen(4); //OLED_RESET

  // Initialise the OLED display
  // Note: it is necessary to change a value in the Adafruit_SSD1306 library to set the screen size to 128x64
  screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  screen.clearDisplay();
}

ArtbotUI::welcome() {
  // Set some default values for writing to the OLED screen
  screen.setTextColor(WHITE);

  // Write "ARTBOT" in big
  screen.setTextSize(3);
  screen.setCursor(20, 10); // this moves our cursor right back to the top left pixel.. we should talk about this.
  screen.print("PABLO"); //this copies some text to the screens memory

  // Write "Hello" in small
  screen.setTextSize(2);
  screen.setCursor(20, 45);
  screen.print("Hello :)"); //this copies some text to the screens memory
  screen.display();
}


void ArtbotUI::setDrawingModes( array modes ) {

}

void ArtbotUI::renderModeSelector(){

}

char ArtbotUI::getDrawingMode() {

}

void ArtbotUI::setInputField( ArtbotInputField * field ) {

}

void ArtbotUI::renderInputFields() {

}

void ArtbotUI::setPresets( array presets ) {

}

bool ArtbotUI::startDrawing() {

}

void ArtbotUI::purgeInputFields() {

}

char ArtbotUI::checkDrawInterupt() {

}
