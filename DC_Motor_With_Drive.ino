int Mot1Plus=3;
int Mot1Minus=6;
int Mot2Plus=9;
int Mot2Minus=11;
int EnableA=5;
int EnableB=10;
int s;

void setup() {
 pinMode(Mot1Plus,OUTPUT);
 pinMode(Mot1Minus,OUTPUT);
 pinMode(Mot2Plus,OUTPUT);
 pinMode(Mot2Minus,OUTPUT);
 pinMode(EnableA,OUTPUT);
 pinMode(EnableB,OUTPUT);
 Serial.begin(9600);


}

void loop() {
  digitalWrite(EnableA,HIGH);
  digitalWrite(EnableB,HIGH);
  s=analogRead(A0);
  if (s>=512){
  digitalWrite(Mot1Plus,LOW);
  analogWrite(Mot1Minus,s);
  digitalWrite(Mot2Plus,LOW);
  analogWrite(Mot2Minus,s);
  Serial.println(s);
  }
  else if (s<512){
  digitalWrite(Mot1Plus,s);
  analogWrite(Mot1Minus,LOW);
  digitalWrite(Mot2Plus,s);
  analogWrite(Mot2Minus,LOW);
  Serial.println(s);

}

}
