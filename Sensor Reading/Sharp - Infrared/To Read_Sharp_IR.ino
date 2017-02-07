
// CONFIGURAÇÕES SHARPS
#include <SharpIR.h>
#define irD A9
#define irE A8
#define model 1080
SharpIR sharpDirSensor(irD, 25, 93, model);
SharpIR sharpEsqSensor(irE, 25, 93, model);
unsigned int sharpDirValue = 0;
unsigned int sharpEsqValue = 0;

void LeituraSharps();

void setup() {
 Serial.begin(9600);

}

void loop() {

LeituraSharps; 

Serial.print("Distância Dir:");
Serial.print(sharpDirValue);


Serial.print("Distância Esq:");
Serial.println(sharpEsqValue);

delay(400); 


}

void LeituraSharps() {
  sharpEsqValue = sharpEsqSensor.distance();
  sharpDirValue = sharpDirSensor.distance();
}
