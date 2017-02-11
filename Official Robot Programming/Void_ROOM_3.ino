
/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void room_3) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

void room_3()
{

//==================================================================================================
                                      //Adjust the robot on the east wall of room 3 
//================================================================================================== 
  ReadSharp();
  while(Distance_Sharp_Right > 70) 
{
    ReadSharp();
    Robot.left();
     ReadSharp();
}
  Robot.stop(3000);
  TurnLeftAdjust();
  Robot.stop(1000);
  Robot.backward(2000);
  Robot.stop(3000);
//==================================================================================================
                                    //Leading the robot for west wall of room 3 
//================================================================================================== 

   Robot.forwardCM(20); 
   Robot.stop(500); 
    TurnRight(); 
   Robot.stop(500);
   Robot.forwardCM(60); 
   Robot.stop(500);
    TurnRight(); 
   Robot.stop(500);
   Robot.forward(2000);
   Robot.stop(500);
   Robot.backward(7500);

//====================================================================================================
                                       //Detect rescue area 
//================================================================================================== 

  ReadSharps();

if((sharpRightValue <= 60)&&(sharpLeftValue > 45)) //Triangle Right 
{
  LedBlue(); 

  for(int i = 0; i<= 5; i++)
  {
  Tri_Right_room3();
  }
}

else if((sharpRightValue > 60)&&(sharpLeftValue <= 45))  //Triangle Left
{
  LedRed();
   for(int i =0; i<= 5; i++)
  {
  Tri_Left_room3();
  }
}

else if((sharpRightValue > 60)&&(sharpLeftValue > 45)) //Triangle Diagonal
{
  LedGreen();
   for(int i =0; i<= 5; i++)
  {
  Tri_Diagonal_room3();
  }
}
   
}

//===================================================================================================
                                          //Rescue area is in right triangle 
//=====================================================================================================

void Tri_Right_room3()

{
   Robot.forwardCM(65);
   Robot.stop(500);



  sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 

 while((sharpRightValue > 60)&&(sharpLeftValue > 45))

 {
  Robot.forward();
   sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 }

  while((sharpRightValue < 60)&&(sharpLeftValue > 45))

 {
   TurnRight();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(60);
   TurnRight();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriLeft();
  Robot.speed(180,180);
  Robot.forward(3000); 
  Robot.stop(500);

  ClawDown();
  


CentralMotor.write(0);
delay(2000);

Robot.backwardCM(50);

TurnTriLeft();
TurnTriLeft();

Robot.backward(4000);

Robot.stop(1000);

//=============================================================================================================================================
 Robot.forwardCM(65);
 Robot.stop(500);

 sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 

 while((sharpRightValue > 60)&&(sharpLeftValue > 45))

 {
  Robot.forward();
 sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 }

  while((sharpRightValue < 60)&&(sharpLeftValue > 45))

 {
   TurnRight();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(60);
  TurnRight();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriLeft();
    Robot.speed(180,180);
  Robot.forward(3000); 
  Robot.stop(500);

  ClawDown();
  


CentralMotor.write(0);
delay(2000);

Robot.backwardCM(50);

TurnTriLeft();
TurnTriLeft();

Robot.backward(4000);

Robot.stop(1000);

  
 }

  while((sharpRightValue > 60)&&(sharpLeftValue < 45))

 {
   TurnLeft();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(70);
  TurnLeft();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriLeft();
  Robot.speed(180,180);
  Robot.forward(3000);
  Robot.stop(500);

  ClawDown();

CentralMotor.write(0);
delay(2000);

Robot.backwardCM(50);

TurnTriLeft();
TurnTriLeft();

Robot.backward(4000);

Robot.stop(1000);
   
 }

  
 }

  while((sharpRightValue > 60)&&(sharpLeftValue < 45))

 {
  TurnLeft();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(70);
  TurnLeft();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriLeft();
  Robot.speed(180,180);
  Robot.forward(3000);
  Robot.stop(500);

  ClawDown();

CentralMotor.write(0);
delay(2000);

Robot.backwardCM(50);
   
TurnTriLeft();
TurnTriLeft();

Robot.backward(4000);

Robot.stop(1000);

 Robot.forwardCM(65);
   Robot.stop(500);



sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 

 while((sharpRightValue > 60)&&(sharpLeftValue > 45))

 {
  Robot.forward();
  
   sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 }

  while((sharpRightValue < 60)&&(sharpLeftValue > 45))

 {
   TurnRight();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(60);
   TurnRight();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriLeft();
    Robot.speed(180,180);
  Robot.forward(3000); 
  Robot.stop(500);

  ClawDown();
  


CentralMotor.write(0);
delay(2000);

Robot.backwardCM(50);

TurnTriLeft();
TurnTriLeft();

Robot.backward(4000);

Robot.stop(1000);

  
 }

  while((sharpRightValue > 60)&&(sharpLeftValue < 45))

 {
  TurnLeft();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(70);
  TurnLeft();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
 TurnTriLeft();
  Robot.speed(180,180);
  Robot.forward(3000);
  Robot.stop(500);

  ClawDown();

CentralMotor.write(0);
delay(2000);

Robot.backwardCM(50);

TurnTriLeft();
TurnTriLeft();

Robot.backward(4000);

Robot.stop(1000);
   
 }
   
 }

 //================================================================================
}

//===================================================================================================
                                        //Rescue area is in left triangle 
//=====================================================================================================

void Tri_Left_room3()

{
   Robot.forwardCM(65);
   Robot.stop(500);



  sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 

 while((sharpRightValue > 60)&&(sharpLeftValue > 45))

 {
  Robot.forward();
  
  sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 }

  while((sharpRightValue < 60)&&(sharpLeftValue > 45))

 {
   TurnRight();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(60);
   TurnRight();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriRight();
    Robot.speed(180,180);
  Robot.forward(3000); 
  Robot.stop(500);

  ClawDown();
  


CentralMotor.write(0);
delay(2000);

delay(2000);

Robot.backwardCM(50);

TurnTriRight();
TurnTriRight();

Robot.backward(4000);

Robot.stop(1000);

Tri_Left_room3();
  
 }

 

  while((sharpRightValue > 60)&&(sharpLeftValue < 45))

 {
  TurnLeft();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(70);
  TurnLeft();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriRight();
  Robot.speed(180,180);
  Robot.forward(3000);
  Robot.stop(500);

  ClawDown();

CentralMotor.write(0);
delay(2000);

Robot.backwardCM(50);

TurnTriLeft();
TurnTriLeft();

Robot.backward(4000);

Robot.stop(1000);

Tri_Left_room3();
   
 }

//=============================================================================
  
//==============================================================================
}

//===================================================================================================
                                 //Rescue area is in diagonal triangle 
//=====================================================================================================

void Tri_Diagonal_room3()

{
      Robot.stop(500);

    sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 

 while((sharpRightValue > 60)&&(sharpLeftValue > 45))

 {
  Robot.forward();
   
  sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
 }

  while((sharpRightValue < 60)&&(sharpLeftValue > 45))

 {
   TurnRight();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(60);
  Robot.stop(500);
  TurnLeft();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriLeft();
    Robot.speed(180,180);
  Robot.stop(3000); 
  Robot.stop(500);

 ClawDown();
  


CentralMotor.write(0);
delay(2000);

Robot.backward(500);

  
 }

  while((sharpRightValue > 60)&&(sharpLeftValue < 45))

 {
  TurnLeft();
  delay(2000);
  ClawDown();
  ClawClimb();

  delay(2000);

  Robot.backwardCM(70);
  TurnRight();
  Robot.stop(500);
  Robot.forward(4500);
  Robot.backwardCM(60);

  Robot.stop(500);
  TurnTriLeft();
  Robot.speed(180,180);
  Robot.forward(3000);
  Robot.stop(500);

  ClawDown();

CentralMotor.write(0);
delay(2000);

Robot.backwardCM(30);

TurnTriLeft();

Robot.forward(3000);

Robot.stop(1000);
 }
 }






