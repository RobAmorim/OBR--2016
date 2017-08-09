
/*----------------------------------------------------------------------------
 * COlor Sensor -TCS3200 - TO READ 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-08 (July 2016) $
 * ---------------------------------------------------------------------------
 */

//=================================================
   
                                  
#define Right_s0  37    //Connection Pins Color sensor - Right  
#define Right_s1  39  
#define Right_s2  41
#define Right_s3  43  
#define Right_out 27

#define Esq_s0  36    //Connection Pins Color sensor - Left
#define Esq_s1  38  
#define Esq_s2  40
#define Esq_s3  42 
#define Esq_out 26


int Right_green = 0;    // variable to store the value coming from the right sensor 
int Left_green = 0;   // variable to store the value coming from the right sensor 

void color(); 

    
void setup()  


{  
  
  pinMode(Right_s0, OUTPUT);  //Setting Pins Color sensor - Right
  pinMode(Right_s1, OUTPUT);  
  pinMode(Right_s2, OUTPUT);  
  pinMode(Right_s3, OUTPUT);  
  pinMode(Right_out, INPUT);  
//================================================================
  pinMode(Left_s0, OUTPUT);  //Setting Pins Color sensor - Left 
  pinMode(Left_s1, OUTPUT);  
  pinMode(Left_s2, OUTPUT);  
  pinMode(Left_s3, OUTPUT);  
  pinMode(Left_out, INPUT);  
 
  Serial.begin(9600);  
  //============================================================================   
  digitalWrite(Right_s0, HIGH);  //Setting frequency color sensor - Right 
  digitalWrite(Right_s1, LOW);
  //============================================================================
  digitalWrite(Left_s0, HIGH); //Setting frequency color sensor - Left 
  digitalWrite(Left_s1, LOW);

  
}  
    
void loop() 
{  
  color(); //Routine that read color sensor  
  
  //to Show  values of color sensor readed 
 //=================================================================================
  Serial.print(" Verde Dir : ");  //Print of values readed - Color Sensor Right 
  Serial.print(Right_green, DEC);  
 //================================================================================ 
  Serial.print(" ======  Verde Esq: ");   //Print of values readed - Color Sensor Left  
  Serial.println(Left_green, DEC);  
  //=================================================================================
  
  delay(200); 
 }  
    
void color()  
{  
  //Routine that read color sensor  
  
 digitalWrite(Right_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO DIREITO
 digitalWrite(Right_s3, HIGH);   
//===============================
 digitalWrite(Left_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO ESQUERDO
 digitalWrite(Left_s3, HIGH);
   
 //count OUT, pGreen, GREEN  
 
  Right_green = pulseIn(Right_out, digitalRead(Right_out) == HIGH ? LOW : HIGH, 5000); 
  Left_green = pulseIn(Left_out, digitalRead(Left_out) == HIGH ? LOW : HIGH, 5000);   
}

