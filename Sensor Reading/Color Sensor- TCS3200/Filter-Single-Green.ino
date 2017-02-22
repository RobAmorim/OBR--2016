
#include <LinkedList.h>
#include <Gaussian.h>
#include <GaussianAverage.h>

GaussianAverage myMovingAverage(10); //My movieng average 
  

#define Pin_s1 23   //Conection Pins of color sensor 
#define Pin_s2 24  
#define Pin_s3 25  
#define Pin_out A14 

 
int green = 0;  // variable to store the value coming from the color sensor 

    
void setup()  


{  
  
  pinMode(Pin_s0, OUTPUT);  //pins Setting of color sensor 
  pinMode(Pin_s1, OUTPUT);  
  pinMode(Pin_s2, OUTPUT);  
  pinMode(Pin_s3, OUTPUT);  
  pinMode(Pin_out, INPUT);  

  Serial.begin(9600);  
  //============================================================================   
  digitalWrite(Pin_s0, HIGH);  // frequency Setting of color sensor 
  digitalWrite(Pin_s1, LOW);
  //============================================================================
 

  
}  
    
void loop() 
{  
  color(); //Reading Color Sensors  
  
  //to Show values readed 
 //=================================================================================
  Serial.print(" Valor Cor Normal : ");  //Print values of color sensor 
  Serial.print(green, DEC);  
 //================================================================================ 
 Serial.print('\t'); 
 //=====================================================================================
  Serial.print(" Valor Cor Filtrada : ");  //Print values of color sensor - Movieng averange 
  Serial.println(myMovingAverage.mean, DEC); 

 //==============================================================================================
  
  delay(200); 
 }  
    
void color()  
{  
  //Reading color sensors 
 digitalWrite(Pino_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO DIREITO
 digitalWrite(Pino_s3, HIGH);   
//===============================

 //count OUT, pGreen, GREEN  
 
  green = pulseIn(Pino_out, digitalRead(Pino_out) == HIGH ? LOW : HIGH); 

  myMovingAverage += green;

  myMovingAverage.process();
   
}

