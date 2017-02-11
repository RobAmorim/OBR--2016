
/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Crossroad) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

void Crossroad()

{
  
//===============================================================================================================
                                    // ALL SENSOR IS IN BLACK  
//===============================================================================================================                                       

if((valueLeftLine > cutoffValue)&&(valueRightLine > cutoffValue)&&(valueLeftCorner > cutoffValue)  // All sensor is in black 
  &&(valueRightCorner > cutoffValue)&&(valueLeftEx > cutoffValue)&&(valueRightEx > cutoffValue)) 

{

   Color();
//==================================================================  
  if((greenRight  < cutoff_Green)&&(greenLeft > cutoff_Green))  //Checking color sensor right 
{
  LedGreen();
  Robot.forwardCM(A, 180, 180);
  Robot.stop(200); 
  Robot.speed(210, 210);
  Turn_Left_Crossroad();
}
//=====================================================================
  if((greenRight  > cutoff_Green)&&(greenLeft < cutoff_Green)) //Checking color sensor left
{
{
 LedGreen();
 Robot.forwardCM(A, 180, 180);
 Robot.stop(200); 
 Robot.speed(210, 210); 
 Turn_Right_Crossroad(); 
}
//=======================================================================
 else
{
    Robot.forwardCM(2);
    ReadReflectance();
} // else

}// If

//===============================================================================================================
                                       // 90º Curve - Right 
//===============================================================================================================  
  if((valueLeftLine > cutoffValue)&&(valueRightLine > cutoffValue)&&(valueLeftCorner > cutoffValue)&&   // 90º Curve - Right 
  (valueRightCorner < cutoffValue)&&(valueLeftEx > cutoffValue)&&(valueRightEx <  cutoffValue))
  
  {
     LedRed();
     delay(200);
     ColorRight(); 
//================================================================================================================
  if(greenRight  > cutoff_Green)        //if here have green 
{
    LedGreen();
    Robot.forwardCM(A, 180, 180);
    Robot.stop(200); 
    Robot.speed(210, 210);
    Turn_Right_Crossroad();
}

//================================================================================================================
 else {  //if here doesn't have green 

  Robot.forwardCM(A, 180, 180);
  Robot.stop(200); 
   ReadReflectance();
   Robot.speed(210, 210);

   
   if((valueLeftLine < cutoffValue)&&(valueRightLine  < cutoffValue))  //All withe in front - (90º Curve) 

  {
    Turn_Right_Crossroad();
  }
//==============================================================================================================

}
  }
//===============================================================================================================
                                       // 90º Curve - Left
//===============================================================================================================  
 if((valueLeftLine > cutoffValue)&&(valueRightLine > cutoffValue)&&(valueLeftCorner < cutoffValue)  // Curva 90º para Esquerda
 &&(valueRightCorner > cutoffValue) && (valueLeftEx < cutoffValue)&&(valueRightEx > cutoffValue))

{
    LedRed();
    ColorLeft(); 
//==================================================================================
  if(greenLeft > cutoff_Green)   //if here have green 
{
    LedGreen(); 
    Robot.forwardCM(A, 180, 180);
    Robot.stop(200); 
    Turn_Left_Crossroad();
}
//========================================================================================
else { // if here doesn't have green 

  Robot.forwardCM(A, 180, 180);
  Robot.stop(200); 
  ReadReflectance();
  Robot.speed(210, 210);


 if((valueLeftLine < cutoffValue)&&(valueRightLine < cutoffValue))  //All withe in front - (90º Curve) 


  {
    Turn_Left_Crossroad();
  }
//===========================================================================================================

      }
         }
//====================================================================================================

}
  

