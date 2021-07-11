# Control the spped and direction of DC Motors for Robot Wheels
## Introduction 
In order converting the electrical energy to mechanical energy, the electric motor is used. In general, the electric motor has many types and one of these types is DC Motor.
DC motor can be rotating either clockwise or anti-clockwise depending on the application of it .Therefore, it needs to be controlled, and in our project, we have used L293D H-bride driver that connected with arduino UNO kit to achieve that, using TinkerCAD simulation website.

## Components
*	Arduino UNO
*	x2 DC Motor
*	9V Battery with Charging
*	Potentiometer
*	L293D driver

## L293D
L293D H-bridge is the driver that used to control two DC Motors, either the speed or the direc  that has 16 pins distributed as:
*	4 pins for input from the arduino, 2 of these for one DC motor and 2 for another DC motor.
*	4 pins for output to the DC motor, 2 of these for one DC motor and 2 for another DC motor.
*	2 pins for enable and disable for 2 DC Motor respectively.
*	Pin for 5V supply voltage that connected to the 5V of arduino.
*	Pin for supply voltage that connected to the 9V Battery.
*	4 pins for ground.

Using TinkerCAD website, theses pins connected with arduino and battery as it shown here (https://www.tinkercad.com/things/eMLA91PguFE-dc-motor-for-robot-wheels/editel)
In this project we have used it to control both speed and direction by changing the value of the resistance of potentiometer .


## Potentiometer
The potentiomener can change the resistance by rotating it from 0 to 180 degrees to obtain different values of it.

In this project, we have programmed the potentiometer to change the direction by changing the angle of the potentiometer rotating, whereas from 0-80 degrees in a certain direction and from 90-180 in the opposite direction.

## Battery
To choose the suitable battery, we should know two important values, which are voltage and current.
The battery voltage can be determined by take the highest voltage that included in the circuit, so the voltage of the battery is 9V
As for the current , we cannot determined and the reason referred to the value of torque which is unknown, because the value of torque depends on the load, and we don’t have it.

to build the charging circuit, we need to regulate the voltage to obtain the voltage of battery which is 9V.Unfortunatly, TinkerCAD can not do it,so we use the proteus to build and sketch the charging circuit which is in the fingure

![Charging Circuit](https://user-images.githubusercontent.com/85504873/125182513-4aae6380-e217-11eb-9a51-e11aef9c0d62.png)

## Arduino Code
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

s= map(s,0,1023,0,180);
 

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
