// Programa : Detector de cores usando modulo TCS230  
// Alteracoes e comentarios : Arduino e Cia  
//  
// Baseado no programa original de Martin Mason  
   
//Pinos de conexao do modulo TCS230 DIREITO 
#define Dir_s0  37
#define Dir_s1  39  
#define Dir_s2  41
#define Dir_s3  43  
#define Dir_out 27
//Pinos de conexao do modulo TCS230 ESQUERDO 
#define Esq_s0  36
#define Esq_s1  38  
#define Esq_s2  40
#define Esq_s3  42 
#define Esq_out 26
//Variaveis que armazenam o valor das cores  

int Dir_green = 0;  
int Esq_green = 0;  

void color(); 

    
void setup()  


{  
  
  pinMode(Dir_s0, OUTPUT);  //PINOS DO SENSOR DE COR DA DIREITA
  pinMode(Dir_s1, OUTPUT);  
  pinMode(Dir_s2, OUTPUT);  
  pinMode(Dir_s3, OUTPUT);  
  pinMode(Dir_out, INPUT);  
//================================================================
  pinMode(Esq_s0, OUTPUT);  //PINOS DO SENSOR DE COR DA ESQUERDA  
  pinMode(Esq_s1, OUTPUT);  
  pinMode(Esq_s2, OUTPUT);  
  pinMode(Esq_s3, OUTPUT);  
  pinMode(Esq_out, INPUT);  
 
  Serial.begin(9600);  
  //============================================================================   
  digitalWrite(Dir_s0, HIGH);  //CONDIÇÃO DE FREQUÊNCIA DO SENSOR DE COR DIREITO
  digitalWrite(Dir_s1, LOW);
  //============================================================================
  digitalWrite(Esq_s0, HIGH);  //CONDIÇÃO DE FREQUÊNCIA DO SENSOR DE COR ESQUERDO
  digitalWrite(Esq_s1, LOW);

  
}  
    
void loop() 
{  
  color(); //Chama a rotina que le as cores  
  
  //Mostra no serial monitor os valores detectados  
 //=================================================================================
  Serial.print(" Verde Dir : ");  //PRINTA O VALOR LIDO PELO SENSOR DE COR DIREITO
  Serial.print(Dir_green, DEC);  
 //================================================================================ 
  Serial.print(" ======  Verde Esq: ");   //PRINTA O VALOR LIDO PELO SENSOR DE COR ESQUERDO 
  Serial.println(Esq_green, DEC);  
  //=================================================================================
  
  delay(200); 
 }  
    
void color()  
{  
  //Rotina que le o valor das cores  
  
 digitalWrite(Dir_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO DIREITO
 digitalWrite(Dir_s3, HIGH);   
//===============================
 digitalWrite(Esq_s2, HIGH);  // CONDIÇÃO QUE ACIONA OS FOTOTRANSISTORS PARA VERDE DO ESQUERDO
 digitalWrite(Esq_s3, HIGH);
   
 //count OUT, pGreen, GREEN  
 
  Dir_green = pulseIn(Dir_out, digitalRead(Dir_out) == HIGH ? LOW : HIGH); 
  Esq_green = pulseIn(Esq_out, digitalRead(Esq_out) == HIGH ? LOW : HIGH);   
}

