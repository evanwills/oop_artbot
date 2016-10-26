#include "ArtbotInputField.h"

// ==================================================================
// START: ArtbotInputField


ArtbotInputField::ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	__value = 0;
}
ArtbotInputField::ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , int minValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
}
ArtbotInputField::ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , int maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	_hasMax = true;
	__max = maxValue;
	__value = 0;
}
ArtbotInputField::ArtbotInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , int minValue , int maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
	_hasMax = true;
	__max = maxValue;
}


bool ArtbotInputField::setValue( int val ) {
	if( _hasMin == true && val < __min ) {
		return false;
	}
	if( _hasMax == true && val > __max ) {
		return false;
	}
	__value = val;
	return true;
}

int ArtbotInputField::getValue() {
	return __value;
}

//  END:  ArtbotInputField
// ==================================================================




// ==================================================================
// START: ArtbotBoolInputField

ArtbotBoolInputField::ArtbotBoolInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 0;
	_isSigned = false;
	__value = false;
}

bool ArtbotBoolInputField::setValue( bool val ) {
	return true;
}

bool ArtbotBoolInputField::getValue() {
	return __value;
}

//  END:  ArtbotBoolInputField
// ==================================================================




// ==================================================================
// START: ArtbotCharInputField


ArtbotCharInputField::ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 1;
	__value = 0;
}
ArtbotCharInputField::ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , char minValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 1;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
}
ArtbotCharInputField::ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , char maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 1;
	_hasMax = true;
	__max = maxValue;
	__value = 0;
}
ArtbotCharInputField::ArtbotCharInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , char minValue , char maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 1;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
	_hasMax = true;
	__max = maxValue;
}

bool ArtbotCharInputField::setValue( char val ) {
	if( _hasMin == true && val < __min ) {
		return false;
	}
	if( _hasMax == true && val > __max ) {
		return false;
	}
	__value = val;
	return true;
}

char ArtbotCharInputField::getValue() {
	return __value;
}

//  END:  ArtbotCharInputField
// ==================================================================




// ==================================================================
// START: ArtbotUIntInputField
ArtbotUIntInputField::ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	__value = 0;
}
ArtbotUIntInputField::ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned int minValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
}
ArtbotUIntInputField::ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , unsigned int maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	_hasMax = true;
	__max = maxValue;
	__value = 0;
}
ArtbotUIntInputField::ArtbotUIntInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned int minValue , unsigned int maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 3;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
	_hasMax = true;
	__max = maxValue;
}

bool ArtbotUIntInputField::setValue( unsigned int val ) {
	if( _hasMin == true && val < __min ) {
		return false;
	}
	if( _hasMax == true && val > __max ) {
		return false;
	}
	__value = val;
	return true;
}

unsigned int ArtbotUIntInputField::getValue() {
	return __value;
}

//  END:  ArtbotUIntInputField
// ==================================================================




// ==================================================================
// START: ArtbotLongInputField

ArtbotLongInputField::ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	__value = 0;
}
ArtbotLongInputField::ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , long minValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
}
ArtbotLongInputField::ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , long maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	_hasMax = true;
	__max = maxValue;
	__value = 0;
}
ArtbotLongInputField::ArtbotLongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , long minValue , long maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
	_hasMax = true;
	__max = maxValue;
}

bool ArtbotLongInputField::setValue( long val ) {
	if( _hasMin == true && val < __min ) {
		return false;
	}
	if( _hasMax == true && val > __max ) {
		return false;
	}
	__value = val;
	return true;
}

long ArtbotLongInputField::getValue() {
	return __value;
}

//  END:  ArtbotLongInputField
// ==================================================================




// ==================================================================
// START: ArtbotULongInputField

ArtbotULongInputField::ArtbotULongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	__value = 0;
}
ArtbotULongInputField::ArtbotULongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned long minValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
}
ArtbotULongInputField::ArtbotULongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , unsigned long maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	_hasMax = true;
	__max = maxValue;
	__value = 0;
}
ArtbotULongInputField::ArtbotULongInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , unsigned long minValue , unsigned long maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 4;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
	_hasMax = true;
	__max = maxValue;
}

bool ArtbotULongInputField::setValue( unsigned long val ) {
	if( _hasMin == true && val < __min ) {
		return false;
	}
	if( _hasMax == true && val > __max ) {
		return false;
	}
	__value = val;
	return true;
}

unsigned long ArtbotULongInputField::getValue() {
	return __value;
}

//  END:  ArtbotULongInputField
// ==================================================================




// ==================================================================
// START: ArtbotFloatInputField

ArtbotFloatInputField::ArtbotFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 5;
	__value = 0;
}
ArtbotFloatInputField::ArtbotFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , long minValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 5;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
}
ArtbotFloatInputField::ArtbotFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , long maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 5;
	_hasMax = true;
	__max = maxValue;
	__value = 0;
}
ArtbotFloatInputField::ArtbotFloatInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , long minValue , long maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 5;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
	_hasMax = true;
	__max = maxValue;
}

bool ArtbotFloatInputField::setValue( float val ) {
	if( _hasMin == true && val < __min ) {
		return false;
	}
	if( _hasMax == true && val > __max ) {
		return false;
	}
	__value = val;
	return true;
}

float ArtbotFloatInputField::getValue() {
	return __value;
}

//  END:  ArtbotULongInputField
// ==================================================================




// ==================================================================
// START: ArtbotDoubleInputField

ArtbotDoubleInputField::ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 6;
	__value = 0;
}
ArtbotDoubleInputField::ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , double minValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 6;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
}
ArtbotDoubleInputField::ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , bool minValue , double maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 6;
	_hasMax = true;
	__max = maxValue;
	__value = 0;
}
ArtbotDoubleInputField::ArtbotDoubleInputField( char fieldName[16] , char abbreviation[4] , char unitType , char componentID , char subComponentID , char fieldID , double minValue , double maxValue ) {
	_name = fieldName;
	_abbr = abbreviation;
	_unit = unitType;
	_component = componentID;
	_subComponent = subComponentID;
	_fieldID = fieldID;
	_dataType = 6;
	_hasMin = true;
	__min = minValue;
	__value = minValue;
	_hasMax = true;
	__max = maxValue;
}

bool ArtbotDoubleInputField::setValue( double val ) {
	if( _hasMin == true && val < __min ) {
		return false;
	}
	if( _hasMax == true && val > __max ) {
		return false;
	}
	__value = val;
	return true;
}

double ArtbotDoubleInputField::getValue() {
	return __value;
}

//  END:  ArtbotDoubleInputField
// ==================================================================
