
/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Turn Right and Left with gyro) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

void TurnRight() //Turn robot for right with gyro sensor 
{
     Robot.speed(230, 230);
   resetGyro();
  
while(TotalDegrees > ninetyDegreeRight) //Turn right 
  {  
     AGRead();
     TotalDegrees += GDegreesZ;
     Robot.right();     
  }
    Robot.stop();
    resetGyro();
}

void TurnLeft() //Turn robot for right with gyro sensor 

{
      Robot.speed(230, 230);
      resetGyro();
 while(TotalDegrees < ninetyDegreeLeft)  //Turn Left 
   {
      AGRead();
      TotalDegrees += GDegreesZ;
      Robot.left();
   }
    Robot.stop(); 
    resetGyro();
}
//=========================================================================================

void TurnLeftAdjust() //Adjust of curve in room 3 

{
      Robot.speed(230, 230);
      resetGyro();
 while(TotalDegrees < adjustLeft)  //turn left 
   {
      AGRead();
      TotalDegrees += GDegreesZ;
      Robot.left();
   }
    Robot.stop(); 
    resetGyro();
}

void TurnTriRight() //Right curve in room 3 
{
     Robot.speed(230, 230);
   resetGyro();
  
while(TotalDegrees > TriRight) // turn right 
  {  
     AGRead();
     TotalDegrees += GDegreesZ;
     Robot.right();     
  }
    Robot.stop();
    resetGyro();
}

void TurnTriLeft() //Left curve in room 3  

{
      Robot.speed(230, 230);
      resetGyro();
 while(TotalDegrees < TriLeft)  //turn left 
   {
      AGRead();
      TotalDegrees += GDegreesZ;
      Robot.left();
   }
    Robot.stop(); 
    resetGyro();
}
//=========================================================================================
