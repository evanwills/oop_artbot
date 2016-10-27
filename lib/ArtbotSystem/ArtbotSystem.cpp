#include "ArtbotSystem.h"

ArtbotSystem::ArtbotSystem( ArtbotUI ui , ArtbotDriver driver ) {
	ui.setDrawingModes( ArtbotController::getAvailableModes() );
}

ArtbotSystem::welcome() {
	ui.welcome();
}


/**
 * makes UI show available modes and lets user choose desired
 * mode.
 * @return TRUE if mode has been set
 * (steps 2, 3 & 4 from Flow)
 */
bool ArtbotSystem::doDrawingMode() {

}


/**
 * gets new inputs for controller
 *
 * @return TRUE if user has finalised settings
 * (step 5 from Flow)
 */
bool ArtbotSystem::doDrawingSettings() {

}

/**
 * passes values from UI to controller
 * (steps 6 & 7 from Flow)
 */
void ArtbotSystem::beginDrawing() {

}


/**
 * passes commands from controller to driver
 * (steps 8.a - 8.c from Flow)
 */
void ArtbotSystem::draw() {

}

/**
 * checks UI to see if drawing mode has been interrupted
 * @return activityMode
 *		0 = get new drawing mode
 *		1 = update drawing mode config
 *		2 = continue drawing (no interrupt),
 *
 * (step 9 from Flow)
 */
char ArtbotSystem::checkDrawInterupt() {

}
