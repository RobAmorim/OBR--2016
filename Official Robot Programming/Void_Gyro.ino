

/*----------------------------------------------------------------------------
 * Oficial championsship Programing (function -> settings Gyro) 
 * ---------------------------------------------------------------------------
 * $Author Roboson Vincius Amorim Silva
 * $Date 2016-07 (July 2015) $
 * ---------------------------------------------------------------------------
 */

void AGRead() { //Read of Gyro sensor 
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX=Wire.read()<<8 |Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  Degrees();
}

void Degrees() { //Map raw values of gyro sensor 
  ACDegreesX = map(AcX, minAC, maxAC, -90, 90);
  ACDegreesY = map(AcY, minAC, maxAC, -90 , 90);
  ACDegreesZ = map(AcZ, minAC, maxAC, -90 , 90);
  GDegreesX = map(GyX, minAC, maxAC, -90, 90);
  GDegreesY = map(GyY, minAC, maxAC, -90, 90);
  GDegreesZ = map(GyZ, minAC, maxAC, -90, 90);
}

void resetGyro() //Reset gyro sensor 
{
  Wire.write(0);
  TotalDegrees = 0;
  GDegreesZ = 0; 
} 
