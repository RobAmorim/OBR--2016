/*----------------------------------------------------------------------------
 * Color Sensor - TCS3200 - FILTER COLOR GREEN 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-08 (July 2016) $
 * ---------------------------------------------------------------------------
 */
//=================================================


#include <LinkedList.h>
#include <Gaussian.h>
#include <GaussianAverage.h>

GaussianAverage Right_MyMovingAverage(10); //Moving average 
GaussianAverage Left_MyMovingAverage(10); //Moving average   
   

#define Right_s0  22  //Pins -> Connections of color right sensor
#define Right_s1  23  
#define Right_s2 24  
#define Right_s3  25  
#define Right_out  A14

#define Esq_s0  26  //Pins -> Connections of color left sensor 
#define Esq_s1  27  
#define Esq_s2 28
#define Esq_s3  29 
#define Esq_out  A15

int Right_green = 0;  // variable to store the value coming from the RIGHT sensor
int Left_green = 0;  // variable to store the value coming from the left sensor

    
void setup()  


{  
  
  pinMode(Right_s0, OUTPUT);  //Pins -> setting of color right sensor 
  pinMode(Right_s1, OUTPUT);  
  pinMode(Right_s2, OUTPUT);  
  pinMode(Right_s3, OUTPUT);  
  pinMode(Right_out, INPUT);  
//================================================================
  pinMode(Left_s0, OUTPUT);  //Pins -> setting of color left sensor   
  pinMode(Left_s1, OUTPUT);  
  pinMode(Left_s2, OUTPUT);  
  pinMode(Left_s3, OUTPUT);  
  pinMode(Left_out, INPUT);  
 
  Serial.begin(9600);  
  //============================================================================   
  digitalWrite(Right_s0, HIGH);  //sensor frequency - Right 
  digitalWrite(Right_s1, LOW);
  //============================================================================
  digitalWrite(Left_s0, HIGH);   //sensor frequency - Left  
  digitalWrite(Left_s1, LOW);

  
}  
    
void loop() 
{  
  color(); //Reading Color Sensor 
  
  //Serial print Values 
 //=================================================================================
  Serial.print(" Verde Dir Normal : ");  //Print of values - Color Sensor -Right 
  Serial.print(Right_green, DEC);  
 //===========================================================================================
 Serial.print('\t');
 //==========================================================================================
  Serial.print(" Verde Dir Filtrado: ");  //Print of values - Color Sensor -Right- Moving average 
 Serial.print(Right_MyMovingAverage.mean, DEC);
  //===========================================================================================
  Serial.print('\t');
  //===========================================================================================
  Serial.print("  Verde Esq Normal: ");    //Print of values - Color Sensor - Left
  Serial.println(Left_green, DEC);  
  //=================================================================================
  Serial.print(" Verde Esq Filtrado: "); //Print of values - Color Sensor -  Left - Moving average 
  Serial.print(Left_MyMovingAverage.mean, DEC);
  
  delay(200); 
 }  
    
void color()  
{  
  //Reading Color Sensors 
  
 digitalWrite(Right_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO DIREITO
 digitalWrite(Right_s3, HIGH);   
//===============================
 digitalWrite(Left_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO ESQUERDO
 digitalWrite(Left_s3, HIGH);
   
 //count OUT, pGreen, GREEN  
 
  Right_green = pulseIn(Right_out, digitalRead(Right_out) == HIGH ? LOW : HIGH); 
  Left_green = pulseIn(Left_out, digitalRead(Left_out) == HIGH ? LOW : HIGH);  

  Right_MyMovingAverage +=  Right_green;
  Left_MyMovingAverage += Left_green;
  
  Right_MyMovingAverage.process();
  Left_MyMovingAverage.process();
}

