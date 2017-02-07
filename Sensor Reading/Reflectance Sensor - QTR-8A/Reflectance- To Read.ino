

//quanto menor o valor, mais luz infravermelha chega ao sensor

//=====================================================================
#define sensorLinhaDir  A10  //Portas dos sensores de refletância CENTRAIS
#define sensorLinhaEsq  A11
//======================================================================
#define sensorCantoEsq  A12 //Portas dos sensores de refletância CANTOS
#define sensorCantoDir  A9
//=======================================================================
#define sensorExEsq A8     //Portas dos sensores de refletância EXTREMOS
#define sensorExDir A13
//======================================================================
int ledPin = 13;      // select the pin for the LED

int valorLinhaEsq, valorLinhaDir, valorCantoEsq, valorCantoDir, valorExDir, valorExEsq = 0;  // variable to store the value coming from the sensor

void setup() {
    Serial.begin(9600);
}

void loop() {
  
  valorLinhaEsq = analogRead(sensorLinhaEsq);   // VALOR LIDO PELO SENSORES -CENTRAIS- GUARDADOS NAS VARIAVEIS  
  valorLinhaDir = analogRead(sensorLinhaDir);
  //========================================================================================================
  valorCantoEsq = analogRead(sensorCantoEsq);   // VALOR LIDO PELO SENSORES -CANTOS- GUARDADOS NAS VARIAVEIS  
  valorCantoDir = analogRead(sensorCantoDir);
  //==========================================================================================================
  valorExEsq = analogRead(sensorExEsq);         // VALOR LIDO PELO SENSORES -EXTREMOS- GUARDADOS NAS VARIAVEIS
  valorExDir = analogRead(sensorExDir);
  //==========================================================================================================
  
  Serial.print("Linha Esq: ");     //PRINTA OS VALORES DOS SENSORES DE REFLETÂNCIA CENTRAIS
  Serial.print(valorLinhaEsq);
  Serial.print("   Linha Dir: ");
  Serial.print(valorLinhaDir);
  //========================================================================================
  Serial.print("   Canto Esq: ");  //PRINTA OS VALORES DOS SENSORES DE REFLETÂNCIA DOS CANTOS
  Serial.print(valorCantoEsq);
  Serial.print("   Canto Dir: ");
  Serial.print(valorCantoDir);
  //========================================================================================
  Serial.print("   Extremo Dir: "); //PRINTA OS VALORES DOS SENSORES DE REFLETÂNCIA EXTREMOS 
  Serial.print(valorExDir);
  Serial.print("   Extremo Esq: ");
  Serial.println(valorExDir); 
  //==========================================================================================
  
  delay(250);
}
