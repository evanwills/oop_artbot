/*
 * ArtbotInputField is used by ArtbotController to tell the UI what
 * it needs the user to input and for the UI to store the user's
 * input to be used by the controller
 *
 * Created by Evan Wills 2016-10-16
 * Released under GPL2 Licence
 */

#ifndef ArtbotInputField_h
#define ArtbotInputField_h

#include <Arduino.h>
#include <stdlib.h>

class ArtbotInputField {
	public:
		ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldIndex );
		ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldIndex , int minValue );
		ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldIndex , bool minValue , int maxValue );
		ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldIndex , int minValue , int maxValue );
		char name();
		char abbr();
		char unit();
		char component();
		char subComponent();
		char fieldID();
		char dataType();
		bool isSigned();
		bool hasMin();
		bool hasMax();
		int getMin();
		int getMax();
		/**
		 * returns TRUE if the supplied value was acceptable and
		 * thus set
		 */
		bool setValue( int val );
		int getValue();
	protected:
		char _name[16];
		char _abbr[4];
		// 0 = unspecified; 1 = mm; 2 = seconds; 3 = revolutions
		char _unit;
		// 0 = wheels; 1 = pen
		char _component;
		// for wheels: 0 = left; 1 = right; 2 = both left & right;
		// for pen: 0 = height; 1 = position; 2 = angle;
		char _subComponent;
		char _fieldID; // 0 wheel, 5 pen height, 6 pen position;
		char _dataType; // is set within the constructor;
		bool _isSigned = false;
		bool _hasMin = false;
		bool _hasMax = false;
		/**
		 * Tests whether value supplied to setValue()
		 */
		bool _inputIsWithinLimits();
	private:
		int __min;
		int __max;
		int __value;
};

class ArtbotBoolInputField : public ArtbotInputField {
	public:
		ArtbotBoolInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID );

		bool getMin();
	  	bool getMax();
  		bool setValue( bool val );
  		bool getValue();
	private:
		bool __value;
};

class ArtbotCharInputField : public  ArtbotInputField {
	public:
		ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID );
		ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , char minValue );
		ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , char maxValue );
		ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , char minValue , char maxValue );

  		char getMin();
  	  	char getMax();
 		bool setValue( char val );
  		char getValue();
	private:
		char __min;
		char __max;
		char __value;
};

class ArtbotUIntInputField : public  ArtbotInputField {
	public:
		ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID );
		ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned int minValue );
		ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , unsigned int maxValue );
		ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned int minValue , unsigned int maxValue );
		unsigned int getMin();
		unsigned int getMax();
  		bool setValue( unsigned int val );
  		unsigned int getValue();
	private:
		unsigned int __min;
		unsigned int __max;
		unsigned int __value;
};

class ArtbotLongInputField : public  ArtbotInputField {
	public:
		ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID );
		ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , long minValue );
		ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , long maxValue );
		ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , long minValue , long maxValue );
		long getMin();
		long getMax();
  		bool setValue( long val );
  		long getValue();
	private:
	long __min;
	long __max;
	long __value;
};

class ArtbotULongInputField : public  ArtbotInputField {
	public:
		ArtbotULongInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ); // no min and no min
		ArtbotULongInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned long minValue ); // only min set
		ArtbotULongInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , unsigned long maxValue ); // only max set
		ArtbotULongInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned long minValue , unsigned long maxValue ); // has both min and max set
		unsigned long getMin();
		unsigned long getMax();
  		bool setValue( unsigned long val );
  		unsigned long getValue();
	private:
		unsigned long __min;
		unsigned long __max;
		unsigned long __value;
};

class ArtbotFloatInputField : public  ArtbotInputField {
	public:
		ArtbotFloatInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID );
		ArtbotFloatInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , float minValue );
		ArtbotFloatInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , float maxValue );
		ArtbotFloatInputField(	char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , float minValue , float maxValue );
		float getMin();
		float getMax();
  		bool setValue( float val );
  		float getValue();
	private:
		float __min;
		float __max;
		float __value;
};

// class ArtbotUFloatInputField : public  ArtbotInputField {
//	public:
//	 	ArtbotUFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID );
//	 	ArtbotUFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned float minValue );
//	 	ArtbotUFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
//		 		 				char componentID , char subComponentID , char fieldID ,
// 								bool minValue , unsigned float maxValue );
//	 	ArtbotUFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
//		 		 				char componentID , char subComponentID , char fieldID ,
//		 						unsigned float minValue , unsigned float maxValue );
//		unsigned float getMin();
//		unsigned float getMax();
//  	bool setValue( unsigned float val );
//  	unsigned float getValue();
//	private:
//		unsigned float __min;
//		unsigned float __max;
//		unsigned float __value;
// };

class ArtbotDoubleInputField : public  ArtbotInputField {
	public:
		ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
								char componentID , char subComponentID , char fieldID );
		ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
								char componentID , char subComponentID , char fieldID ,
								double minValue );
		ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
								char componentID , char subComponentID , char fieldID ,
								bool minValue , double maxValue );
		ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
								char componentID , char subComponentID , char fieldID ,
								double minValue , double maxValue );
		double getMin();
		double getMax();
  		bool setValue( double val );
  		double getValue();
	private:
		double __min;
		double __max;
		double __value;
};

// class ArtbotUDoubleInputField : public  ArtbotInputField {
//	public:
//	 	ArtbotUDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
//		 		 				 char componentID , char subComponentID , char fieldID );
//	 	ArtbotUDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
//		 		 				 char componentID , char subComponentID , char fieldID ,
// 								 unsigned double minValue );
//	 	ArtbotUDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
//		 		 				 char componentID , char subComponentID , char fieldID ,
// 								 bool double minValue , unsigned double maxValue );
//	 	ArtbotUDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType ,
//		 		 				 char componentID , char subComponentID , char fieldID ,
//		 						 unsigned double minValue , unsigned double maxValue );
//		unsigned double getMin();
//		unsigned double getMax();
//  	bool setValue( unsigned double val );
//  	unsigned double getValue();
//	private:
//		unsigned double __min;
//		unsigned double __max;
//		unsigned double __value;
// };

#endif
