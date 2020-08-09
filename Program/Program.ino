#include "config.h"

void setup() {
  Serial.begin(9600);
  DIAM(3000);
  SERVO_RODA_KIRI.attach(PIN_RODA_KIRI);
  SERVO_RODA_KANAN.attach(PIN_RODA_KANAN);
  pinMode(KIPAS, INPUT);
  pinMode(BUZZER, OUTPUT);
  KONDISI_ROBOT = 0;
}

void loop()
{
  int SENSOR_DINDING_KIRI  = SONAR_KIRI.ping_cm();
  int SENSOR_DINDING_KANAN = SONAR_KANAN.ping_cm();
  int SENSOR_DINDING_DEPAN = SONAR_DEPAN.ping_cm();
  int BASE        = analogRead(A0);
  int LED_API1    = analogRead(A1);
  int LED_API2    = analogRead(A2);
  int LED_API3    = analogRead(A3);
  int LED_API4    = analogRead(A4);
  int LED_API5    = analogRead(A5);

  Serial.print(SENSOR_DINDING_KIRI);
  Serial.print("   SENSOR DINDING KIRI ||");
  Serial.print(SENSOR_DINDING_DEPAN);
  Serial.print("   SENSOR DINDING DEPAN  ||");
  Serial.print(SENSOR_DINDING_KANAN);
  Serial.print("   SENSOR DINDING KANAN   ||");
  Serial.print(LED_API3);
  Serial.print("   LED API3 ||   ");
  Serial.print(BASE);
  Serial.println("   Base||   ");

  if ((LED_API2 > NILAI_API  || LED_API3 > NILAI_API  || LED_API4 > NILAI_API )
      && (SENSOR_DINDING_DEPAN > Jarak_Min_Dinding && SENSOR_DINDING_DEPAN < Jarak_Max_Dinding))
  {
    digitalWrite(BUZZER, LOW);
    pinMode(KIPAS, OUTPUT);
    digitalWrite(KIPAS, LOW);
    DIAM(2000);
    Tiup(NILAI_BELOK);
    DIAM(1000);
    KONDISI_ROBOT = 1;
  }
  else {
    digitalWrite(BUZZER, LOW);
    pinMode(KIPAS, INPUT);
    digitalWrite(KIPAS, HIGH);

    if (BASE > Warna_Lintasan && KONDISI_ROBOT != 1)
    {
      MAJU();
      delay(10);
      DIAM(5000);
    }

    else if (SENSOR_DINDING_KIRI < Jarak_Avr_Dinding && SENSOR_DINDING_KIRI > Jarak_Min_Dinding)
    {
      SERONG_KANAN(); //panggil kanan
      delay(50);
    }

    else if (SENSOR_DINDING_KANAN < Jarak_Avr_Dinding && SENSOR_DINDING_KANAN > Jarak_Min_Dinding) {
      SERONG_KIRI();
      delay(50);
    }

    else if (SENSOR_DINDING_DEPAN < Jarak_Avr_Dinding && SENSOR_DINDING_DEPAN > Jarak_Min_Dinding)
    {
      if (SENSOR_DINDING_KIRI < SENSOR_DINDING_KANAN) {
        BELOK_KANAN();
        delay(NILAI_BELOK);
      }

      else if (SENSOR_DINDING_KIRI > SENSOR_DINDING_KANAN) {
        BELOK_KIRI();
        delay(NILAI_BELOK);
      }
    }

    else {
      MAJU();
      delay(100);
    }
  }
}
