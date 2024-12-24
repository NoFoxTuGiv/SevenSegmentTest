/********************************************************************************
 * File: SevenSegmentButton.ino
 * Author: [Your Name or Team Name]
 * Created: [Date]
 *
 * Description:
 * This Arduino sketch demonstrates how to control a 7-segment display
 * using digital pins (a through g). A push button wired to pin 9 increments 
 * the displayed digit (0–9). Each digit is lit by energizing the appropriate 
 * segments on the display through dedicated functions (zero() through nine()).
 *
 * Hardware Setup:
 * - 7-segment display pins (a, b, c, d, e, f, g) connected to Arduino digital
 *   pins 2, 3, 4, 5, 6, 7, and 8, respectively.
 * - Push button connected to pin 9 (with one side to GND if using INPUT_PULLUP).
 * - Each segment pin may require a current-limiting resistor (depending on the 
 *   display type).
 *
 * Usage:
 * 1. Upload this sketch to your Arduino.
 * 2. On each button press, the displayed digit increments by one (0 -> 1 -> 2 
 *    -> ... -> 9 -> back to 0).
 * 3. Adjust or remove the delay() if you want a faster response or want to fine-
 *    tune button debouncing (hardware debouncing may also be used).
 ********************************************************************************/

#include "Arduino.h"

const byte a = 2, b = 3, c = 4, d = 5, e = 6, f = 7, g = 8, btnPin = 9;
byte btnState = 0, lastBtnState = HIGH, display = 0;

void setup() {
  for (int pin = a; pin <= g; pin++) {
    pinMode(pin, OUTPUT);
  }
  pinMode(btnPin, INPUT_PULLUP);
  
  // Optional: If you need serial output for debugging,
  // uncomment the line below.
  // Serial.begin(9600);
}

void loop() {
  btnState = digitalRead(btnPin);

  // Check for a LOW signal (button press) transitioning from not-pressed (HIGH)
  if (btnState == LOW && lastBtnState == HIGH) {
    display = (display + 1) % 10;
    
    // Uncomment if you want to view the current digit on serial monitor
    // Serial.println(display);

    switch (display) {
      case 0: zero();   break;
      case 1: one();    break;
      case 2: two();    break;
      case 3: three();  break;
      case 4: four();   break;
      case 5: five();   break;
      case 6: six();    break;
      case 7: seven();  break;
      case 8: eight();  break;
      case 9: nine();   break;
    }
  }

  // Update the previous button state for the next loop
  lastBtnState = btnState;

  // Small delay for debouncing
  delay(50);
}

// ---------------------------------------------------------------------------
// Digit Functions for Lighting the 7-Segment Display
// ---------------------------------------------------------------------------
void zero() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void one() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void two() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void three() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void four() {
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void five() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void six() {
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void seven() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void eight() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void nine() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}