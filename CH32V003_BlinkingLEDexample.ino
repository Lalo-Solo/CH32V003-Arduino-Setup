/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Description:  Example of the classic blinking LED sketch to run on the CH32V003 MCU
Prerequisites: Need to install support for WCH CH32V003 boards from:
              https://github.com/openwch/board_manager_files/raw/main/package_ch32v_index.json
By:           @Lalo_Solo
              https://github.com/Lalo-Solo
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#define LED_PIN D13          // PD3, Pin 20

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}