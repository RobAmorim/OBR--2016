
/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Ramp) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

void Ramp()

{

Robot.speed(240, 240);
//======================================================================================================================
                                                 //Basic - Line Following 
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
  Robot.left(150, 150); 
  }
  
 if((valueLeftLine > cutoffValue)&&(valueRightLine < cutoffValue)) // Central sensor left is in black and central sensor right is in white
  {
  Robot.right(150, 150); 
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
   Robot.right(150); 
  }
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner > cutoffValue)&&  // All sensors is in whith and the sensor of left extreme and 
  (valueRightCorner < cutoffValue)&&(valueLeftEx > cutoffValue)&&(valueRightEx < cutoffValue))         // left corner  is in black
  {
   Robot.right(150); 
  }
  
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  //All sensors is in whith and the sensor of right corner is in black 
  (valueRightCorner > cutoffValue)&&(valueLeftEx < cutoffValue)&&(valueRightEx < cutoffValue))
  {
    Robot.left(150);
  }
  
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme is in black
  (valueRightCorner < cutoffValue)&&(valueLeftEx < cutoffValue)&&(valueRightEx > cutoffValue))
  {
    Robot.left(150);
  }
  if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // All sensors is in whith and the sensor of right extreme and 
  (valueRightCorner > cutoffValue)&&(valueLeftEx < cutoffValue)&&(valueRightEx > cutoffValue))         // right corner  is in black
  {
    Robot.left(150);  
  }
//=================================================================================================================================


}
