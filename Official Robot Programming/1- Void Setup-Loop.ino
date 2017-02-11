
/*----------------------------------------------------------------------------
 * Oficial championsship Programming (Settings, function -> void setup and loop) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

//=================================================
         
                  //LIBRARIES 

#include <ControlMotorsRobot.h> //Control of motors with enconder and walking with centimeter 

#include <Thread.h>  //Function Tread 
           
#include <ArduinoSensors.h> //Functions of sensors 

#include <sensors/PingUltrasonic.h> //Functions of the ultrasonic Sensor  

#include <SharpIR.h> //Functions of the ultrasonic Sensor 
 
#include <Wire.h> //Control of the Gyro Sensor 

#include <Servo.h> //Control of the motor servo (claw) 

//===============================================

             // MOTORS SETTING

  #define A  2.5 // Constant of control for walking with centimeter 

  Motors Robot;  //ROBOT INSTANCE
//==================================================

          // MOTORS CLAW SETTING --MICROSERVO

Servo motor1; //Motor CLAW-RIGHT
Servo motor2; //Motor CLAW-LEFT
Servo CentralMotor; //Central Motor 

//==================================================

             //ULTRASSONIC SENSOR SETTING


int Front_echoPin   = 24;   //Pin -> Connections  (Echo and Trigger) 
int Front_triggerPin  = 25;

float distanceFront = 0; // variable to store the value coming from the sensor 
 
PingUltrasonic myUltrasonicFront(Front_triggerPin, Front_echoPin);

//===============================================================

         //SETTING SHARP SENSOR CRUD/RAW
                  
#define SharpRight A9  //Pins -> Connections of Sharp Sensor 
#define SharpLeft A8

 
 int Distance_Sharp_Left = 0; // variable to store the value coming from the left sensor 
 int Distance_Sharp_Right =0; // variable to store the value coming from the right sensor 

 //============================================================

        // SETTING SHARPS SENSOR FILTER

#define irR A9 //Pins -> Connections of Sharp Sensor 
#define irL A8 
#define model 1080

SharpIR sharpRightSensor(irR, 25, 93, model);   // Default Settings 
SharpIR sharpLeftSensor(irL, 25, 93, model);  

unsigned int sharpRightValue = 0; // variable to store the value coming from the right sensor 
unsigned int sharpLeftValue = 0;  // variable to store the value coming from the left sensor

 //===============================================================================  

          //SETTING REFLECTANCE SENSOR 
                      
#define sensorRighLine A12     //Pins -> Connections of Reflectance Sensor 
#define sensorLeftLine A13
#define sensorLeftCorner A14
#define sensorRightCorner A11
#define sensorRightEx A10
#define sensorLeftEx A15

int cutoffValue = 200; //Cuttoff value of reflective sensor 
int valueLeftLine,valueRightLine,valueLeftCorner,valueRightCorner,valueRightEx,valueLeftEx = 0;  // variable to store the value coming from the sensor

//===============================================================================

                    //SETTING GIROSCÓPIO 

const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
int GDegreesX, GDegreesY, GDegreesZ, DegreesY, ACDegreesX, ACDegreesY, ACDegreesZ;
const int minAC = -16800;
const int maxAC = 16800;
int TotalDegrees = 0;

#define ninetyDegreeRight -12950*2 // Default Settings for turn with gyro sensor 
#define ninetyDegreeLeft  10950*2 
#define TriRight -15950 
#define TriLeft  13950
#define adjustLeft  4050 

  //=================================================================================

                             //SETTING COLOR SENSOR 

#define Right_s0 37  //Pins -> Connections of color right sensor 
#define Right_s1 39  
#define Right_s2 41  
#define Right_s3 43
#define Right_out 27 
 
#define Left_s0 36  //Pins -> Connections of color left sensor 
#define Left_s1 38
#define Left_s2 40  
#define Left_s3 42
#define Left_out 26  
 
int greenRight = 0;  // variable to store the value coming from the right sensor 
int greenLeft = 0;   // variable to store the value coming from the left sensor 

int cutoff_Green = 30;  //Cuttoff value of color sensor 
//===============================================================================

                                  //SETTING LED RGB

#define Led1 48 // Pin -> Connections of LED'S 
#define Led2 49
#define Led3 50
//=========================================================================================
                                     // VOID SETUP
//=========================================================================================
void setup() {

   Serial.begin(9600);
//==============================================
                //Settings of Gyro sensor 
                
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
//=======================================================
                //Settings of Color Sensor 

  pinMode(Right_s1, OUTPUT);  //Color sensor Right
  pinMode(Right_s2, OUTPUT);  
  pinMode(Right_s3, OUTPUT);  
  pinMode(Right_out, INPUT);  
  digitalWrite(Right_s0, HIGH); 
  digitalWrite(Right_s1, LOW);  

  pinMode(Left_s1, OUTPUT);  //Color Sensor Left
  pinMode(Left_s2, OUTPUT);  
  pinMode(Left_s3, OUTPUT);  
  pinMode(Left_out, INPUT);  
  digitalWrite(Left_s0, HIGH);  
  digitalWrite(Left_s1, LOW);  
//=====================================================
                      //LED RGB

 pinMode(Led1, OUTPUT); 
 pinMode(Led2, OUTPUT);
 pinMode(Led3, OUTPUT);
//=====================================================
                 //SERVO SETTING
                 
  motor1.attach(23);
  motor2.attach(22);
  CentralMotor.attach(52);
  CentralMotor.write(0);
//=====================================================
}

//=========================================================================================
                                     // VOID LOOP
//=========================================================================================

void loop() 
{
  
  LedBlue();
  ReadReflectance();
  ReadSharp();
  ReadUltra();
  
Robot.speed(220, 220);  

//================================================================================================
                            //Sensor sharp is checking if the robot is in ramp 
//===============================================================================================
if((Distance_Sharp_Left > 250)&&(Distance_Sharp_Right > 250)) // Portal Checking 

{
  LedYellow();
  Robot.forwardCM(5, 200, 200);
  Robot.stop(500);
  ReadSharp();

  if((Distance_Sharp_Left > 250)&&(Distance_Sharp_Right > 250)) //Ramp checking 
{
  while((Distance_Sharp_Left > 250)&&(Distance_Sharp_Right > 250))

  {
  ReadReflectance();
  ReadSharp();
  Ramp();
  ReadReflectance();
  ReadSharp();
  }

  Robot.stop(500);
  ReadSharp();
  
 if((Distance_Sharp_Left > 250)&&(Distance_Sharp_Right > 250)) //Checking if is false reading 
{
  ReadSharp();
  
  while((Distance_Sharp_Left > 250)&&(Distance_Sharp_Right > 250))

  {
  ReadReflectance();
  ReadSharp();
  Ramp();
  ReadReflectance();
  ReadSharp();
  }
}
  Robot.stop(1500);   //Enter in room 3 
  Robot.forwardCM(25);
  Robot.stop(500); 
  room_3();      //Enter in room 3 
}
}

//==================================================================================================
else{                                      //Checking if have obstacle 
//=================================================================================================== 
 if(distanceFront < 15)
 {
   distanceFront = myUltrasonicFront.readDistance();
   if(distanceFront < 15)
 {
   distanceFront = myUltrasonicFront.readDistance();
   if(distanceFront < 15)
 {
  LedRed();
  Robot.stop(1000);
  RightObstacle();
 }
 }
  }
//======================================================================================================================
     else {                                     //Basic - Line following 
//======================================================================================================================
  ReadReflectance();
 if((valueLeftLine > cutoffValue)&&(valueRightLine > cutoffValue)) //Central Sensors is in black
  {
   Robot.forward();     
  }
  
 if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // ALL sensors is in White 
  (valueRightCorner < cutoffValue)&&(valueLeftEx < cutoffValue)&&(valueRightEx < cutoffValue))
  {
    Robot.forward();   
  }
 
 if((valueLeftLine < cutoffValue)&&(valueRightLine > cutoffValue)) // Central sensor left is in whith and central sensor right is in black 
 {
  Robot.left(); 
  }
  
 if((valueLeftLine > cutoffValue)&&(valueRightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
  Robot.right(); 
  }
//============================================================================================================================
                                         //Corner and Extreme - Line following 
//=======================================================================================================================
    if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner > cutoffValue)&&  //All sensors is in whith and the sensor of left corner is in black 
  (valueRightCorner < cutoffValue )&&(valueLeftEx < cutoffValue )&&(valueRightEx < cutoffValue ))
  {
  Robot.right(); 
  }
    if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of left extreme is in black
  (valueRightCorner < cutoffValue)&&(valueLeftEx > cutoffValue)&&(valueRightEx < cutoffValue))
  {
   Robot.right(); 
  }
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (valueRightCorner < cutoffValue)&&(valueLeftEx > cutoffValue)&&(valueRightEx < cutoffValue))         // left corner  is in black
  {
   Robot.right(); 
  }
  
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (valueRightCorner > cutoffValue)&&(valueLeftEx < cutoffValue)&&(valueRightEx < cutoffValue))
  {
    Robot.left();
  }
  
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (valueRightCorner < cutoffValue)&&(valueLeftEx < cutoffValue)&&(valueRightEx > cutoffValue))
  {
    Robot.left();
  }
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (valueRightCorner > cutoffValue)&&(valueLeftEx < cutoffValue)&&(valueRightEx > cutoffValue))         // right corner  is in black
  {
    Robot.left();  
  }
//=================================================================================================================================
                                               //CROSSROAD 
//=================================================================================================================================
   if((valueLeftLine > cutoffValue)&&(valueRightLine > cutoffValue)&&(valueLeftCorner > cutoffValue)  //All sensors is in black 
  &&(valueRightCorner > cutoffValue)&&(valueLeftEx > cutoffValue)&&(valueRightEx > cutoffValue)) 
  {
    LedRed();
    Robot.backward(100, 100, 100); //Parar robô
    Robot.stop(1000);
    ReadReflectance();
    Robot.speed(210, 210); 
    Crossroad();
  } 
  
  if((valueLeftLine > cutoffValue)&&(valueRightLine > cutoffValue)&&(valueLeftCorner > cutoffValue)&&  // 90º Curver - Direita 
  (valueRightCorner < cutoffValue)&&(valueLeftEx > cutoffValue)&&(valueRightEx <  cutoffValue))
  
  {
     LedRed();
    Robot.backward(100, 100, 100); 
    Robot.stop(1000);
    ReadReflectance();
    Robot.speed(210, 210); 
    Crossroad();
  }
  
  if((valueLeftLine > cutoffValue)&&(valueRightLine > cutoffValue)&&(valueLeftCorner < cutoffValue)  // 90º Curver - Esquerda
 &&(valueRightCorner > cutoffValue) && (valueLeftEx < cutoffValue)&&(valueRightEx > cutoffValue))
  
  {
   LedRed();
    Robot.backward(100, 100, 100); 
    Robot.stop(1000);
    ReadReflectance();
    Robot.speed(210, 210); 
    Crossroad();
  }
//=======================================================================================================================

  }// second else
  
    }// first else
     
         }// Loop
