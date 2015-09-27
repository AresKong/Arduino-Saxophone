#include "pitches.h"
const int trigPin = 11;
const int echoPin = 12;
const int speakerPin = 13;
float distance;
int flag;
const int note[2][7] = 
  { {NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4},
    {NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5} };

void setup()
{
  for(int i = 4; i < 11; i++) {
    pinMode(i, INPUT);
  }
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  for(int i = 4; i < 11; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds (2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    distance = pulseIn(echoPin, HIGH)/58.00;
    if(distance > 10)
      flag = 0; 
    else
      flag = 1;
    noTone(speakerPin);
    int j = i-4;
    while(digitalRead(i)) {
      tone(speakerPin, note[flag][j]);
    }
    noTone(speakerPin);
  }
}
￼