

/*----------------------------------------------------------------------------
 * Oficial championsship Programing ( function -> void LED RGB) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

void LedBlue() //Light up - LED RGB BLUE 

{
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);

  
  
  }

void LedRed() //Light up - LED RGB Red 

{
  
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, LOW); 
  
  
  }

void LedGreen() //Light up - LED RGB Green 

{
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, HIGH);
   
  }

void LedYellow() //Light up - LED RGB Yellow

{
  
   digitalWrite(Led1, LOW);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  
  }
