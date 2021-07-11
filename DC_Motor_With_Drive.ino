int Mot1Plus=3;
int Mot1Minus=6;
int Mot2Plus=9;
int Mot2Minus=11;
int EnableA=5;
int EnableB=10;
int s1;
int s2;

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
  s1=analogRead(A0);
  s1= map(s1,0,1023,0,180);
  if (s2>0){
  digitalWrite(Mot1Plus,LOW);
  analogWrite(Mot1Minus,LOW);
  digitalWrite(Mot2Plus,LOW);
  analogWrite(Mot2Minus,LOW);
  Serial.println(s1);
  }
  else {
    digitalWrite(Mot1Plus,LOW);
  analogWrite(Mot1Minus,s1);
  digitalWrite(Mot2Plus,LOW);
  analogWrite(Mot2Minus,s1);
  Serial.println(s1);
  }
    
  s2=analogRead(A1);
  s2= map(s2,0,1023,0,180);
  if (s1>0){
  digitalWrite(Mot1Plus,LOW);
  analogWrite(Mot1Minus,LOW);
  digitalWrite(Mot2Plus,LOW);
  analogWrite(Mot2Minus,LOW);
  Serial.println(s2);
  }
  else {
    digitalWrite(Mot1Plus,s2);
  analogWrite(Mot1Minus,LOW);
  digitalWrite(Mot2Plus,s2);
  analogWrite(Mot2Minus,LOW);
  Serial.println(s2);
  }
  



}
