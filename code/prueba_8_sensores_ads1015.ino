#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1015 ads1;
Adafruit_ADS1015 ads2;

const int PIN_SDA = 8;
const int PIN_SCL = 9;
int16_t sensor[8];

void setup() {
  Serial.begin(115200);
  delay(1000);
  Wire.begin(PIN_SDA, PIN_SCL);

  if (!ads1.begin(0x48)) {
    Serial.println("ERROR: ADS1015 #1 (0x48) no encontrado.");
    while (1) delay(100);
  }
  if (!ads2.begin(0x49)) {
    Serial.println("ERROR: ADS1015 #2 (0x49) no encontrado.");
    while (1) delay(100);
  }

  ads1.setGain(GAIN_ONE);
  ads2.setGain(GAIN_ONE);
  ads1.setDataRate(RATE_ADS1015_3300SPS);
  ads2.setDataRate(RATE_ADS1015_3300SPS);

  Serial.println("S1\tS2\tS3\tS4\tS5\tS6\tS7\tS8");
}

void loop() {
  sensor[0] = ads1.readADC_SingleEnded(0);
  sensor[1] = ads1.readADC_SingleEnded(1);
  sensor[2] = ads1.readADC_SingleEnded(2);
  sensor[3] = ads1.readADC_SingleEnded(3);
  sensor[4] = ads2.readADC_SingleEnded(0);
  sensor[5] = ads2.readADC_SingleEnded(1);
  sensor[6] = ads2.readADC_SingleEnded(2);
  sensor[7] = ads2.readADC_SingleEnded(3);

  for (int i=0;i<8;i++) {
    Serial.print(sensor[i]);
    if (i<7) Serial.print('\t');
  }
  Serial.println();
  delay(50);
}
