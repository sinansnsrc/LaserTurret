/*#plug joystick x into A0, y into A1, button into D2
#plug laser + into D7
#rest of it is straightforward
#should work*/

#include <Servo.h>

const int buttonPin = 2;
const int laserPin = 7;
const int xPin = A0;
const int yPin = A1;

int xPos = 0;
int yPos = 0;

int currentXPosition = 90;
int currentYPosition = 90;

Servo servoX;
Servo servoY;

bool button = false;

void setup() {
  // put your setup code here, to run once:
  servoX.attach(10);
  servoY.attach(9);

  servoX.write(90);
  servoY.write(90);
  
  pinMode(buttonPin, INPUT);
  pinMode(laserPin, OUTPUT);
  digitalWrite(buttonPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin) == 0) { 
    button = !button; 
    if(button) { digitalWrite(laserPin, HIGH); }
    else { digitalWrite(laserPin, LOW); }
    delay(250);
  }
  
  
  xPos = analogRead(xPin);
  yPos = analogRead(yPin);

  if (xPos < 300){
    if(!(currentXPosition <= 10)){
      currentXPosition -= 20;
      servoX.write(180 - currentXPosition); 
    }
  }
  else if(xPos > 700){
    if(!(currentXPosition >= 170)){
      currentXPosition += 20;
      servoX.write(180 - currentXPosition);
    }
  }

  if (yPos < 300){
    if(!(currentYPosition <= 10)){
      currentYPosition -= 20;
      servoY.write(180 - currentYPosition); 
    }
  }
  else if(yPos > 700){
    if(!(currentYPosition >= 170)){
      currentYPosition += 20;
      servoY.write(180 - currentYPosition);
    }
  }

  delay(100);
}
