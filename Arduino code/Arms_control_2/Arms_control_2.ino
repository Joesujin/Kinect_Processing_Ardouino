#include <VarSpeedServo.h>

//#include<Servo.h>
VarSpeedServo servoX;
VarSpeedServo servoY;
int state;
int posX = 0;
int posY = 0;


void setup() {
  // put your setup code here, to run once:

  servoX.attach(9);
  servoY.attach(10);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)
  {
    state = Serial.read();
    if (state == '1')
    {
      digitalWrite(13, HIGH);
      posX = 110;
      
    }
    if (state == '0')
    {
      digitalWrite(13, LOW);
      posX = 0;
    }

    if (state == '3')
    {
      digitalWrite(13, HIGH);
      posY = 160;
      
    }
    if (state == '2')
    {
      digitalWrite(13, LOW);
      posY = 0;
    }

    servoX.write(posX,25);
    servoY.write(posY,25);
    



  }
}
