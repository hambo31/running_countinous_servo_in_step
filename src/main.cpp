#include <Arduino.h>
#include <Servo.h>

Servo servoX;

// Tentukan pin servo
int X = 9;

// Arah servo
int up = 70;  // Kanan
int dw = 110; // Kiri
int st = 90;  // Stop

void move_to_step(int valX)
{

  // If the val is plus, turn to right
  if (valX > 0)
  {
    Serial.println(valX);
    for (int y = 1; y <= valX; y++)
    {
      for (int x = 0; x <= 1; x++)
      {
        servoX.write(up);
        delayMicroseconds(8500);
        servoX.write(st);
      }
    }
  }

  // If the val is minus, turn to left
  if (valX < 0)
  {
    for (int y = valX; y <= 0; y++)
    {
      for (int x = 0; x <= 1; x++)
      {
        servoX.write(dw);
        delayMicroseconds(8500);
        servoX.write(st);
      }
    }
  }
}

void setup()
{
  Serial.begin(9600);

  servoX.attach(X);
}

void loop()
{

  while (Serial.available() > 0)
  {
    int val = Serial.parseInt();
    // Serial.println(val);
    move_to_step(val);
  }
}