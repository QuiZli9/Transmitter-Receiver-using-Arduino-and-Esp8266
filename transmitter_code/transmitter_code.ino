#define echoPin 2 
#define trigPin 3

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);  // CE, CSN
const byte address[6] = "00001";

long duration; 
int distance; 

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 

  // Start radio
  if (!radio.begin()) {
    Serial.println("NRF24L01 not found or not responding");
    while (1);  // Halt
  }

  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  Serial.println("Setup complete. Starting distance measurement...");
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH, 30000);  // Timeout at 30ms (5 meters)

  // Calculate distance
  distance = duration * 0.034 / 2;

  // Print measured distance
  if (duration == 0) {
    Serial.println("No object detected or sensor error");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Send message if close
    if (distance < 20) {
      const char text[] = "Human Detected";
      bool success = radio.write(&text, sizeof(text));
      if (success) {
        Serial.println("Message sent: Human Detected");
      } else {
        Serial.println("Failed to send message");
      }
      delay(10000);  // Cooldown before next send
    }
  }

  delay(500);
}
