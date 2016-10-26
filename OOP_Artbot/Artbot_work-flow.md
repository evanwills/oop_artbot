# Artbot (programatic) work-flow

## Artbot software components in brief:
1.	__system:__ a like an OS. does very basic stuff (handles interaction between other objects)
2.	__UI:__ handles collecting user input from buttons, encoders switches etc and displaying to user what they've just input.
3.	__controller:__ does the calculations
4.	__driver:__ makes components move
5.	__input:__ (struct) metadata for each input field required by controller for a specific component (wheel & pen)


## Work-flow
1.	system instantiates UI & driver objects
2.	system gets drawing mode from user input
3.	system gets appropriate controller object from controller factory based on selected drawing mode
4.	system gets input field info from controller and hands them on to the UI
5.	UI gets user to input values for each field controller needs and shows user values they've input
6.	User initiates drawing mode
7.	system takes values from UI input and hands them on to the controller
8.	Drawing mode Loops until interupted:
	1.	controller calculates driver commands
	2.	system gets controller commands and passes them to the driver
	3.	driver makes parts move.
9.	If user interrupts drawing
	*	If user wants to update settings for current mode go back to step 5
	*	If user wants a new mode go back:
		1.	system destructs controller class
		2.	goes back to step 2

## Artbot Constants:
*	__`0`__ = `WHEELS`;
*	__`0`__ = `WHEEL_LEFT`;
*	__`1`__ = `WHEEL_RIGHT`;
*	__`0`__ = `PEN`;
*	__`0`__ = `PEN_HEIGHT`;
*	__`1`__ = `PEN_LOCATION`;
*	__`2`__ = `PEN_ANGLE`



## Artbot software components in detail

### system (class: `ArtbotSystem`)

__*(Could also be called *__`ArtbotOS`__* or *__`ArtbotBIOS`__*)*__

__*NOTE:*__ most (if not all) of `ArtbotSystem` could just be in the artbot.ino file

#### Responsible for:
*	instantiating the UI, controller and driver objects.
*	passing controller input info to UI
*	passing user inputs from UI back to controller
*	passing driver instructions from controller to driver

#### Public methods:

__*NOTE:*__ I'm least clear about how the architecture of `ArtbotSystem` should look

__`bool doMode()`__ makes UI show available modes and lets user choose desired mode (returns `true` if mode has been set) (steps 2, 3 & 4 from Flow)

__`bool doSettings()`__ gets user to configure settings for controller (returns true if user has finalised settings) (step 5 from flow)

__`void beginDrawing()`__ passes values form UI to controller (steps 6 & 7)

__`void draw()`__	passes commands from controller to driver (steps 8.1 - 8.3)

__`void checkDrawInterupt()`__ checks if drawing mode has been interupted
*	`0` = continue drawing (no interrupt),
*	`1` = update drawing mode settings
*	`2` = get new drawing mode
(step 9 from Flow)

### UI (class: `ArtbotUI`)

__*(Could also be called *__`ArtbotUserInterface`__* or *__`ArtbotView`__* or *__`ArtbotInput`__*)*__

#### Responsible for:
*	providing base UI for mode selection
*	providing UI for each input required by controller
*	providing user with visual feedback on their interactions with Artbot
*	providing user defined input values to be handed to the controller

#### Public methods:

__`void setDrawingModes( array modes )`__ takes a list of drawing modes (supplied by controller static method: `getAvailableModes()`) to tell the user the drawing modes it has a available

__`void renderModeSelector()`__ shows user list of available drawing modes. reads physical component(s) and converts the user input into a value to be passed back to the system

__`char getDrawingMode()`__ returns the index of the drawing mode to be used. (to be passed to the controller factory) returns -1 if no mode selected.

__`void setInputField( InputField field )`__ takes an input field struct from a controller and includes it in the UI

__`void renderInputFields()`__ shows the user the fields needed for the controller. reads physical components and converts their inputs into values to be passed back to the controler. shows user the values it's read from the physical components

__`array getInputValue( char component, char subComponent, char field )`__ returns the user defined value for a particular field

__`void setPresets( array presets )`__ Add preset values for the current Drawing mode

__`bool startDrawing()`__ switch to drawing mode if true

__`Void purgeInputFields()`__ delete all input fields from previous controller (free up memory)


### Controller (class: `ArtbotController`)
__*(could also be called *__`ArtbotAlgorithm`__* or *__`ArtbotDrawingMode`__*)*__
#### Responsible for:
*	providing appropriate controller object (factory pattern)
*	holding a static array of controller class names to be used by the UI
*	holding a static array of `inputField` structs used to define values needed by the controller
*	providing info on required inputs (to be handed to UI)
*	taking UI supplied user input values
*	calculating values to be turned into commands for driver
*	providing commands to be handed to driver

Students can extend this class and only change the `calculate()` method to give very different styles of drawings.

#### Public methods:
__`static ArtbotController factory( unsigned char drawingMode )`__ factory method for getting appropriate drawing mode controller

__`static array getAvailableModes()`__ returns an array of available drawing modes. (To be used by the UI when getting the user to select drawing mode.)

__`char getFieldCount( [char component [,char subComponent]] )`__ returns the number of items in a group
*	If no parameters are supplied, then it returns the number of primary components (1 at this point but could be 2 or more).
*	If component is supplied then it returns the number of sub components (for wheels it would be 2)
*	If sub-component is also supplied then it returns the number of fields for that sub component

__`InputField getInputField( char component, char subComponent, char field )`__ returns the input field metadata object for use by UI

__`void setInputValues( char component, char subComponent, char field, `__*mixed*__` inputValue )`__ takes user defined value for a specific controller field (to be used for calculating driver commands)

*`mixed`* __`array getInputValue( char component, char subComponent, char field )`__ Gets current user defined value for particular field being used for calculating driver commands

__`array getPresetValues()`__ Gets an array of developer defined preset configuration values for that drawing mode

__`void calculate()`__ contains the algorythm for generating the commands for the driver

__`int getDriverValue( char component, char subComponent, char field )`__ returns a particular value to be passed to the driver

The idea with the controller is that each time a new child controller class is defined, the developer also defines all the fields that  controller needs using an array of `InputFields` with all the metadata required for that field. These `InputFields` can then be handed to the UI. The UI then does what it needs with the metatdata to allow it (the UI) to get the user to input and let the user see that input.

### driver (class: `ArtbotDriver`)
__*(If controller has different name, it could be called *__`ArtbotDrawingMode`__*)*__
#### Responsible for:
*	receiving commands from controller
*	making components move according to recieved commands.

#### Public methods:
__`void setWheelAction( char wheel, int distance, int speed, unsigned int acceleration, unsigned int deceleration )`__ sets parameters for each wheel (wheel: `1` = left wheel & `2` = right wheel)

__`void setPenAction( int depth, int position )`__ sets paramters for pen

__`void drive()`__ makes all the components move as directed.

__`void stop()`__ makes all the components stop moving.

__`bool travelCompleted()`__ whether or not the driver has finished the last command (or set of commmands)

__`int edgeReached()`__ whether or not the artbot has gone beyond the bounds of the drawing surface.

__`int getMaxWheelSpeed()`__ gets the maximum speed wheels can move at.



### input (struct: `InputMetadata`)

__*(Could also be called *__`FieldMetadata`__*)*__
#### Responsible for:
*	Holds all metadata for each field required by controller

#### Public methods:



#### Properties:

__`string name[16]`:__ Name of field to be shown to user (e.g. "distance" or "speed")

__`char component`:__
The  ID/index of the component this field is for
*	`0` = `WHEELS`
*	`1` = `PEN`

__`char subComponent`:__ The  ID/index of the sub-component this field is for

e.g. for Wheels:
*	`0` = `LEFT`
*	`1` = `RIGHT`
*	`2` = `LEFT_AND_RIGHT`

e.g. for Pen:
*	`0` = `HEIGHT`
*	`1` = `LOCATION`
*	`2` = `ANGLE`

__`char fieldID`:__ The ID/index of this particular field e.g for both wheels:
*	`0` = `SPEED`
*	`1` = `DISTANCE`

__`char dataType:`__ Type of value the field holds
*	__`0`__ = bool (`AB_BOOL`)
*	__`1`__ = char (`AB_CHAR`)
*	__`2`__ = short int (`AB_SHORT_INT`)
*	__`3`__ = int (`AB_INT`)
*	__`4`__ = long (`AB_LONG`)
*	__`5`__ = float (`AB_FLOAT`)
*	__`6`__ = double (`AB_DOUBLE`)

__`bool isSigned:`__ Whether or not the value should be signed.

__`bool hasMin:`__ Whether or not this field has a minimum

__`bool hasMax:`__ Whether or not this field has a maximum

__`int min:`__ Minimum value the controller will accept.

__`int max:`__ Maximum value the controller will accept.

__*NOTE:*__ Different versions of InputMetadata are required for each data type
