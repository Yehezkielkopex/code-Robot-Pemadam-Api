void MAJU()
{
  SERVO_RODA_KIRI.write(LAJU_RODA);
  SERVO_RODA_KANAN.write(-LAJU_RODA);
}

void Mundur()
{
  SERVO_RODA_KIRI.write(-LAJU_RODA);
  SERVO_RODA_KANAN.write(LAJU_RODA);
}

void BELOK_KIRI()
{
  SERVO_RODA_KIRI.write(-LAJU_RODA);   
  SERVO_RODA_KANAN.write(-LAJU_RODA); 
}

void BELOK_KANAN()
{
  SERVO_RODA_KIRI.write(LAJU_RODA);   
  SERVO_RODA_KANAN.write(LAJU_RODA);       
}

void SERONG_KANAN()
{
  SERVO_RODA_KIRI.write(LAJU_RODA);     
  SERVO_RODA_KANAN.write(NILAI_BERHENTI_KANAN); 
}

void SERONG_KIRI()
{
  SERVO_RODA_KIRI.write(NILAI_BERHENTI_KIRI); 
  SERVO_RODA_KANAN.write(-LAJU_RODA);         
}

void DIAM(int x) 
{
  SERVO_RODA_KIRI.write(NILAI_BERHENTI_KIRI);
  SERVO_RODA_KANAN.write(NILAI_BERHENTI_KANAN);  
  delay(x);
}

void Tiup(int x) 
{  
  BELOK_KANAN();
  delay(x / 4);
  DIAM(x);
  BELOK_KIRI();
  delay(x / 2);
  DIAM(x);
  BELOK_KANAN();
  delay(x / 2);
  DIAM(x);
  BELOK_KIRI();
  delay(x / 4);
  DIAM(x);
}
