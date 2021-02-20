#define RECU 2
#define ENVOI 4
#define VITESSE 340.0 //m.s-1

void envoi();
int reception();
void distance(int duree);

void envoi(){
// envoi un signal haut pendant 10us
Serial.println("debut envoi");
digitalWrite(ENVOI, LOW);
digitalWrite(ENVOI, HIGH);
Serial.println("high");
delayMicroseconds(10);
digitalWrite(ENVOI, LOW);
}
int reception(){
  //scrutation de la sortie de echo(RECU)
  int t0=0;
  Serial.println("read");
  while(!digitalRead(RECU));
  Serial.println("read 2");
  t0=micros();
  while(digitalRead(RECU));
  return micros()-t0;  
}

void distance(int duree){
   float distance=(VITESSE*duree/1000000.0)*100;
   Serial.print("La distance est: ");
   Serial.print(distance);
   Serial.println(" cm");
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RECU,INPUT);
  pinMode(ENVOI, OUTPUT);
  digitalWrite(ENVOI, LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Debut test Ultrasonic sensor");
  envoi();
  distance(reception());
    delay(500);
}
