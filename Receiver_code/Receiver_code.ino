#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define CE and CSN pins for ESP8266 (NodeMCU)
#define CE_PIN D2  // GPIO4
#define CSN_PIN D1 // GPIO5

RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  delay(1000); // Wait for serial

  if (!radio.begin()) {
    Serial.println("NRF24L01 not found!");
    while (1); // Stop here if NRF not working
  }

  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);   // Reduce power for stability
  radio.setDataRate(RF24_1MBPS);   // Optional: Set data rate
  radio.startListening();

  Serial.println("ESP8266 NRF24 Receiver Ready");
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print("Received: ");
    Serial.println(text);
  }
}
