#include <avr/io.h>
// #include <avr/io.h>
// //Pot reads in range [0,633]
// float duration, distance;
// void setup() { 
//   Serial.begin(9600);
//   DDRC = 0xFE; // A0 input 
//   // echo PB2, Trig PB1
//   DDRB |= (1 << PB1);
//   DDRB &= ~(1 << PB2); 
// }

// void loop() {
//   float duration, distance;
//   // pot
//   int sensorValue = analogRead(A0);
//   //Serial.println("pot: ");
//   //Serial.println(sensorValue);

//   //ultraonic
//   PORTB &= ~(1 << PB1);
//   delay(2);
//   PORTB |= (1 << PB1);
//   delay(10);
//   PORTB &= ~(1 << PB1);
//   duration = pulseIn(PB2, HIGH);
//   distance = (duration*.0343)/2;
//   Serial.print("Distance: ");
//   Serial.print(distance);
//   Serial.println(" cm");
//   //ultrasonic


//   delay(1000);
// }


// Global variables for duration and distance
float duration, distance, duration_two;
int trig = 3;
int echo = 2;
int out  = 0;
void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  
  // Set PB1 (Trig) as output and PB2 (Echo) as input
  DDRD |= (1 << trig);  // PB1 is output (Trig)
  DDRD &= ~(1 << echo); // PB2 is input (Echo)
  DDRB &= ~(1 << out);
}

void loop() {
  // Ultrasonic sensor reading
  
  // Make sure Trig is low for 2 microseconds
  PORTB &= ~(1 << trig);
  delayMicroseconds(2);
  
  // Send a 10-microsecond HIGH pulse to the Trig pin (trig)
  PORTB |= (1 << trig);
  delayMicroseconds(10);
  PORTB &= ~(1 << trig);  // Set Trig low after pulse
  
  // Measure the duration of the pulse on Echo pin (PB2)
  //duration = pulseIn(echo, HIGH);
  duration_two = pulseIn(out, HIGH);
  // Calculate distance in cm
  distance = duration * 0.0343 / 2;
  
  // Print the distance
  
  Serial.print("duration: ");
  Serial.print(duration_two);
  Serial.println(" ms");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // Wait 1 second before taking another measurement
  delay(500);
}