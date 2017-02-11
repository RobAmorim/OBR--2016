

/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Claw SERVO) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */
 
void ClawDown() //Claw - Down 

{
  motor1.write(140);  //Open the claw 
  motor2.write(50); 
  
delay(2000);

CentralMotor.write(180);
delay(2000);


}

void ClawClimb()  //Claw - Up

{

Robot.forward(3000);
Robot.stop(500);

 motor1.write(60);
motor2.write(130); 

delay(2000);


CentralMotor.write(0);
delay(2000);


}

