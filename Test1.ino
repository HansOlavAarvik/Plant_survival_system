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
#include <avr/io.h>

// Global variables for duration and distance
float duration, distance;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  
  // Set PB1 (Trig) as output and PB2 (Echo) as input
  DDRB |= (1 << PB1);  // PB1 is output (Trig)
  DDRB &= ~(1 << PB2); // PB2 is input (Echo)
}

void loop() {
  // Ultrasonic sensor reading
  
  // Make sure Trig is low for 2 microseconds
  PORTB &= ~(1 << PB1);
  delayMicroseconds(2);
  
  // Send a 10-microsecond HIGH pulse to the Trig pin (PB1)
  PORTB |= (1 << PB1);
  delayMicroseconds(10);
  PORTB &= ~(1 << PB1);  // Set Trig low after pulse
  
  // Measure the duration of the pulse on Echo pin (PB2)
  duration = pulseIn(PB2, HIGH);
  
  // Calculate distance in cm
  distance = (duration * 0.0343) / 2;
  
  // Print the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait 1 second before taking another measurement
  delay(100);
}