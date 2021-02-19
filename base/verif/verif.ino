void config2();
void envoi_commande();
void rep_capteur();

void config2(){
  Serial.print("Bon\r\n");
}

int check_d2(){
   int response=-1;
  response=digitalRead(2);
  return response;
}


void envoi_commande(){
  pinMode(2,OUTPUT);
  pinMode (2,HIGH);
  delay(10);
  pinMode(2,LOW);
  delay(18);
  pinMode (2,HIGH);
  delayMicroseconds(30);
  pinMode(2,INPUT);
}

void rep_capteur(){
  while(!digitalRead(2));
  Serial.print("Ca marche\n");
}
void setup() {
  // put your setup code here, to run once:  
Serial.begin(9600);
pinMode(2,INPUT_PULLUP);
}

void loop() {
   config2();
   envoi_commande();
   rep_capteur();
   
   //delay(1000);
  // put your main code here, to run repeatedly:

}
