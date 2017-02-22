
/*----------------------------------------------------------------------------
 * Color Sensor - TCS3200 - Reading 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-08 (July 2016) $
 * ---------------------------------------------------------------------------
 */

//=================================================
                       
#define Pin_s0 22    //Connections Pins of color sensor  TCS230 
#define Pin_s1 23  
#define Pin_s2 24  
#define Pin_s3 25  
#define Pin_out A14 

 
int green = 0;  // variable to store the value coming from the right sensor 

    
void setup()  


{  
  
  pinMode(Pino_s0, OUTPUT);  //Pin setting - color sensor 
  pinMode(Pino_s1, OUTPUT);  
  pinMode(Pino_s2, OUTPUT);  
  pinMode(Pino_s3, OUTPUT);  
  pinMode(Pino_out, INPUT);  

  Serial.begin(9600);  
  //============================================================================   
  digitalWrite(Pino_s0, HIGH);  //Frequency Setting - color sensor 
  digitalWrite(Pino_s1, LOW);
  //============================================================================
 

  
}  
    
void loop() 
{  
  color(); //Reading color sensor 
  
  //To show values readed of color sensor 
 //=================================================================================
  Serial.print(" Value Color : ");  //Print values readed of color sensor 
  Serial.println(green, DEC);  
 //================================================================================ 
 
  
  delay(200); 
 }  
    
void color()  
{  
  //Routine that read color sensor  
  
 digitalWrite(Pino_s2, Right);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO DIREITO
 digitalWrite(Pino_s3, Right);   
//===============================

 //count OUT, pGreen, GREEN  
 
 green = pulseIn(Pino_out, digitalRead(Pino_out) == HIGH ? LOW : HIGH); 
   
}

