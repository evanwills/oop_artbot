/*
 * ArtbotDriver manages making all the physical, moving components of
 * the Artbot move
 *
 * Created by Evan Wills 2016-10-16
 * Released under GPL2 Licence
 */


#ifndef ArtbotDriver_h
#define ArtbotDriver_h

#include <Arduino.h>
#include <stdlib.h>

#include <AFMotor.h>
#include <AccelStepper.h>


class ArtbotDriver {
	public:
		ArtbotDriver( int stepsPerRevolution , float wheelDiameter );
		ArtbotDriver( int stepsPerRevolution , float wheelDiameter , int maxSpeed  );
		ArtbotDriver( int stepsPerRevolution , float wheelDiameter , int maxSpeed , int maxAccelleration );
		ArtbotDriver( int stepsPerRevolution , float wheelDiameter , int maxSpeed , int maxAccelleration , bool reverseWheelSide );

		/**
		 * sets parameters for each wheel (wheel: 0 = WHEEL_LEFT & 1 = WHEEL_RIGHT)
		 */
		void setWheelAction( char wheel, int distance, int speed, unsigned int acceleration, unsigned int deceleration );

		/**
		 * sets parameters for pen
		 */
		void setPenAction( int depth, int position, int angle );

		/**
		 * makes all the components move as directed.
		 * (to be run after setWheelAction() & setPenAction())
		 */
		void draw();

		/**
		 * makes all the components stop moving.
		 */
		void stop();

		/**
		 * whether or not the driver has finished the last command (or set of commands) for a particular component.
		 */
		bool travelCompleted( char component );

		/**
		 * whether or not the artbot has gone beyond the bounds of the drawing surface.
		 */
		int edgeReached();

		/**
		 *
		 */
		void forwardStepLeft();

		/**
		 *
		 */
		void backwardStepLeft();

		/**
		 * wrappers for the second motor!
		 */
		void forwardStepRight();

		/**
		 *
		 */
		void backwardStepRight();

	protected:
		float stepFactor;
		AF_Stepper leftMotor;
		AF_Stepper rightMotor;
		AccelStepper leftAccelMotor;
		AccelStepper rightAccelMotor;


};

#endif
