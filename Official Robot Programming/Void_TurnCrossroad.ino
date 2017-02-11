
/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> Turn Crossroad) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

  void Turn_Right_Crossroad() //Turn robot for right in crossroad 

  {
    
    TurnRight();
    Robot.stop(300);
    ReadReflectance();
    Robot.speed(180, 180);
    Robot.backwardCM(4);
     ReadReflectance();
    
    //if((valueLeftLine > cutoffValue)||(valueLineRight > cutoffValue)||(valueLeftCorner > cutoffValue)||(valueRightCorner > cutoffValue)) 
 //{
   
   Robot.stop(1000);
   while(valueLeftEx < cutoffValue) //Reflectance sensor 
 {
     ReadReflectance();
     Robot.backward();
      ReadReflectance();
 }

     Robot.stop();
     Robot.forwardCM(4); 
     Robot.stop();
     
     Robot.speed(210, 210);
      ReadReflectance();
     
 // }

/*else {
  
  if((valueLeftLine < cutoffValue)&&(valueLineRight < cutoffValue)&&(valueLeftCorner < cutoffValue)&&  // Todos no Branco 
  (valueRightCorner < cutoffValue))
  
{
     Robot.forward();
 }
 
}*/

}
      

//====================================================================================
  

//=============================================================================

  void Turn_Left_Crossroad() //Turn robot for left in crossroad 

  {

      TurnLeft();
      Robot.stop(300);
       ReadReflectance();
      Robot.speed(180, 180);
       Robot.backwardCM(4);
       ReadReflectance();
//=======================================================================================================================

  
//if((valueLeftLine > cutoffValue)||(valueLineRight > cutoffValue)||(valueLeftCorner > cutoffValue)||(valueRightCorner > cutoffValue))   //UM DOS SENSORES CENTRAIS NO PRETO (INDCA UMA LINHA EM FRENTE)

    //{
       Robot.stop(1000);
 while(valueRightEx  < cutoffValue) //Reflectance sensor  

   {
      ReadReflectance();
     Robot.backward();
      ReadReflectance();
   }
       Robot.stop();
       Robot.forwardCM(4); 
       Robot.stop();
       Robot.speed(210, 210);
        ReadReflectance();
       
//}

/*else
{
if((valueLeftLine < cutoffValue)&&(valueLineRight < cutoffValue)&&(valueLeftCorner < cutoffValue)&&(valueRightCorner < cutoffValue))
{
     Robot.forward();
 }
   }
 */
    }

