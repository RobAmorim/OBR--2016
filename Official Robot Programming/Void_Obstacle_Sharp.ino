

/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Obstacle) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */


void RightObstacle()

  {

 //Divert from all sizes of obstacles 

 Robot.stop(500);  //Stop when found the obstacle 
  TurnRight();
//====================================================================================

ReadSharp();
while(Distance_Sharp_Left > 250) //while robot is nearby of obstacle. Go forward! 
  { 
     ReadSharp();
     Robot.forward(); 
     ReadSharp();
  }
      Robot.stop(2000);
 //======================================================================================= 
      Robot.forwardCM(5); 
      Robot.stop(1000);
//===============================================================================================
 TurnLeft();
//===================================================================================================
ReadSharp();
while(Distance_Sharp_Left < 250) //while robot is nearby of obstacle. Go forward! 
  {
     ReadSharp();
     Robot.forward();
     ReadSharp(); 
   }
    Robot.stop(1000); 
//=================================================================================================
 ReadSharp();
 while(Distance_Sharp_Left > 250) //while robot is nearby of obstacle. Go forward!
 {
      ReadSharp();
      Robot.forward(); 
      ReadSharp();
 }

    Robot.stop(1000); 
//==================================================================================================
    Robot.forwardCM(7);
    Robot.stop(1000); 
//===========================================================================================================
    TurnLeft();;
//================================================================================================================
ReadReflectance(); 
while((valueRightLine < cutoffValue)&&(valueLeftLine < cutoffValue))//while reflectance sensor is in white. Go forward! 
   {
      ReadReflectance(); 
      Robot.forward(); 
      ReadReflectance(); 
   }
      Robot.stop(600);
//==================================================================================================================
      Robot.forwardCM(3);
      Robot.stop();
//==================================================================================================================  
ReadReflectance(); 
while((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue))//while reflectance sensor is in white. Turn Right! 
   {
        ReadReflectance(); 
        Robot.right();
        ReadReflectance(); 
  }
        
  }


 void LeftObstacle()

  {

 //Divert from all sizes of obstacles 

 Robot.stop(500);  //Stop when found the obstacle 
  TurnLeft();
//====================================================================================

  ReadSharp();
while(Distance_Sharp_Right > 250)//while robot is nearby of obstacle. Go forward! 
  { 
     ReadSharp();
     Robot.forward(); 
     ReadSharp();
  }
      Robot.stop(2000);
 //======================================================================================= 
     Robot.forwardCM(5); 
      Robot.stop(1000);
//===============================================================================================
 TurnRight();
//===================================================================================================
 ReadSharp();
while(Distance_Sharp_Right < 250)    //while robot is nearby of obstacle. Go forward!
  {
     ReadSharp();
     Robot.forward();
     ReadSharp(); 
   }
    Robot.stop(1000); 
//=================================================================================================
  ReadSharp();
 while(Distance_Sharp_Right > 250)   //while robot is nearby of obstacle. Go forward!

 {
      ReadSharp();
      Robot.forward(); 
      ReadSharp();
 }

    Robot.stop(1000); 
//==================================================================================================
    Robot.forwardCM(7);
    Robot.stop(1000); 
//===========================================================================================================
   TurnRight();
//================================================================================================================
   ReadReflectance(); 
while((valueRightLine < cutoffValue)&&(valueLeftLine < cutoffValue))//while reflectance sensor is in white. Turn Right! 
   {
      ReadReflectance(); 
      Robot.forward(); 
      ReadReflectance(); 
   }
      Robot.stop(600);
//==================================================================================================================
      Robot.forwardCM(3);
      Robot.stop();
//==================================================================================================================  
    ReadReflectance(); 
while((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)) //while reflectance sensor is in white. Turn Left!  
   {
        ReadReflectance(); 
        Robot.left();
        ReadReflectance(); 
  }
        
  }

