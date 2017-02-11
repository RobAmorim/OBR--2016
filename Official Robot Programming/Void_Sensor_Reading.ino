
/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> void Read Sensors) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

void ReadReflectance()  //Reading reflectance sensors 

{
  valueLeftLine = analogRead(sensorLeftLine);    
  valueRightLine = analogRead(sensorRighLine);
  valueLeftCorner = analogRead(sensorLeftCorner);
  valueRightCorner = analogRead(sensorRightCorner);
  valueRightEx = analogRead(sensorRightEx);
  valueLeftEx = analogRead(sensorLeftEx); 
  
  
  }

  void ReadSharp()  //Reading sharp sensor
  
  {
     
    Distance_Sharp_Right = analogRead(SharpRight);
    Distance_Sharp_Left = analogRead (SharpLeft);
    
    }
    

  void ReadSharps() //Reading sharp sensors
  
  {
  sharpLeftValue = sharpLeftSensor.distance();
  sharpRightValue = sharpRightSensor.distance();
}

 void ColorRight()  //Reading color sensor right 
{  
 
 
  //count OUT, pGreen, GREEN 

    digitalWrite(Right_s2, HIGH);
    digitalWrite(Right_s3, HIGH);
  greenRight = pulseIn(Right_out, digitalRead(Right_out) == HIGH ? LOW : HIGH);  
}

void ReadUltra() //Reading ultrasonic sensor

{
    distanceFront = myUltrasonicFront.readDistance();
  }
  
void ColorLeft()  //Reading color sensor left
{ 

  //count OUT, pGreen, GREEN  

     digitalWrite(Left_s2, HIGH);
     digitalWrite(Left_s3, HIGH);
   greenLeft = pulseIn(Left_out, digitalRead(Left_out) == HIGH ? LOW : HIGH);  
}

void Color() //Reading color sensor right and left 

{
  
     digitalWrite(Right_s2, HIGH);
     digitalWrite(Right_s3, HIGH);
     digitalWrite(Left_s2, HIGH);
     digitalWrite(Left_s3, HIGH);
     
   greenRight = pulseIn(Right_out, digitalRead(Right_out) == HIGH ? LOW : HIGH);
   greenLeft = pulseIn(Left_out, digitalRead(Left_out) == HIGH ? LOW : HIGH);  
  
  }




