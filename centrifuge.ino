#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

/* Declarations */

LiquidCrystal_I2C screen(0x3F, 16, 2);
Servo servo;

#define buttonPin 6
#define potentiometerPin A2
#define infraRedPin 3

#define greetingState 0
#define selectDurationState 1
#define selectRpmState 2
#define startSpinningState 3
#define spinningState 4
#define stopSpinningState 5

byte state = 0;
byte buttonState = 0;
bool wasButtonStateHigh = false;
bool changeToNextState = false;

int potentiometerValue = 0;
int setDuration = 0;
int previousSetDuration = 0;
int setRpm = 0;
int previousSetRpm = 0;

int currentRpm = 0;
int infraRedState = 0;
int infraRedPreviousState = 0;

int servoValue = 0;
int servoFactor = 1; // the increment or decrement factor of the servo in the spinning state
int rpmPrecision = 100; //the precision of the rpm + / - ;

int servoMinim = 59;
int servoMaxim = 180;

uint32_t startSpinningTime = 0;

unsigned long previousRevolutionTime;
unsigned long oneRevolutionDuration;
unsigned long screenRefreshTime;

unsigned long speedAdjustTime;

/* Initial setup of the board */

void setup()
{
  Wire.begin();

  screen.init();
  screen.backlight(); //turn on the backlight of the lcd screen

  Serial.begin(9600);

  servo.attach(9);//atach servo
  servo.write(0);//arm servo
  
  pinMode(buttonPin, INPUT);
}

/* The main loop logic */

void loop()
{
  buttonLogic();

  changeStateLogic();

  switch (state)
  {
    case greetingState:
      resetValues();
      greeting();
      break;
    case selectDurationState:
      selectDuration();
      break;
    case selectRpmState:
      selectRpm();
      break;
    case startSpinningState:
      startSpinning();
      break;
    case spinningState:
      spinning();
      break;
    case stopSpinningState:
      stopSpinning();
      break;
  }
}
