/*
  Physical Pixel

  An example of using the Arduino board to receive data from the computer. In
  this case, the Arduino boards turns on an LED when it receives the character
  'H', and turns off the LED when it receives the character 'L'.

  The data can be sent from the Arduino Serial Monitor, or another program like
  Processing (see code below), Flash (via a serial-net proxy), PD, or Max/MSP.

  The circuit:
  - LED connected from digital pin 13 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/PhysicalPixel
*/

const int buzzer = 9; //buzzer to arduino pin 9
const int ledPin1 = 12; // the pin that the yellow LED is attached to
const int ledPin2 = 11; // the pin that the red LED is attached to
int incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      tone(buzzer, 1000); // Send 1KHz sound signal...
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin1, LOW);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      noTone(buzzer);     // Stop sound...
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
    }
    //     if it's an K (ASCII 76) turn off the LED:
    if (incomingByte == 'K') {
      noTone(buzzer);     // Stop sound...
//      digitalWrite(ledPin2, LOW);
//      digitalWrite(ledPin1, LOW);
    }
  }
}
