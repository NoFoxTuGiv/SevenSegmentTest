# SevenSegmentButton

This is a simple Arduino project which demonstrates how to control a 7-segment display using a single push button. Each press of the button increments the displayed digit from `0` through `9`, then wraps back to `0`.

You can find the tinkercad for this project [HERE](https://www.tinkercad.com/things/bkXb4d2VuoZ-seven-segment-counter).

---

## Table of Contents
1. [Overview](#overview)
2. [Hardware Requirements](#hardware-requirements)
3. [Circuit Diagram](#circuit-diagram)
4. [Wiring](#wiring)
5. [Software Setup](#software-setup)
6. [Usage Instructions](#usage-instructions)
7. [Code Explanation](#code-explanation)
8. [Troubleshooting](#troubleshooting)
9. [License](#license)

---

## Overview

- **Project Goal**: Show how to easily control a 7-segment display using Arduino’s digital pins and a single push button for incrementing digits.
- **Main Features**:
  - Simple button debouncing via a short delay.
  - Incrementing digits from `0` to `9` on every button press.
  - Separate functions for each digit, which makes it clear how each segment is lit.

---

## Hardware Requirements

- **Arduino** (Uno, Nano, Mega, etc.)
- **7-Segment Display** (common anode or common cathode; this example uses common anode, but can be adapted)
- **Push Button**
- **Current-Limiting Resistors** (if your 7-segment display requires them; value typically 220–330 Ω, depending on LED specs)
- **Breadboard & Jumper Wires** (for prototyping)

---

## Wiring

1. **Segments**  
   - Arduino digital pin **2** to segment **a**  
   - Arduino digital pin **3** to segment **b**  
   - Arduino digital pin **4** to segment **c**  
   - Arduino digital pin **5** to segment **d**  
   - Arduino digital pin **6** to segment **e**  
   - Arduino digital pin **7** to segment **f**  
   - Arduino digital pin **8** to segment **g**

2. **Push Button**  
   - One side to Arduino pin **9**  
   - Other side to **GND**  
   - Pin 9 set as `INPUT_PULLUP` in the code, so it reads `HIGH` when **not pressed** and `LOW` when pressed.

3. **Resistors**  
   - Depending on your 7-segment display, you may place resistors on each segment line or on the common anode side. Make sure you’re following the datasheet for your specific display to avoid damaging your LEDs.

---

## Software Setup

1. **Download or Clone** this repository.
2. Open the `SevenSegmentButton.ino` in the [Arduino IDE](https://www.arduino.cc/en/software), [VS Code](https://code.visualstudio.com/) with [PlatformIO](https://platformio.org/), or your preferred environment.
3. Select the appropriate **Board** (e.g., Arduino Uno) and **Port** in the IDE.
4. Click **Upload** to flash the code onto your Arduino.

---

## Usage Instructions

1. **Power on your Arduino** with the circuit connected.  
2. **Observe the 7-Segment Display** which should initially show `0` (if wired correctly).
3. **Press the Button**: Each press increments the digit (`1`, `2`, `3`, etc.).  
4. **Digit Wrap**: Once `9` is reached, the next press shows `0` again.

If you have the Serial Monitor enabled (`Serial.begin(9600)`), you can uncomment the line that prints out the digit to see debug info in the console.

---

## Code Explanation

- **Global Variables**:
  - `a, b, c, d, e, f, g`: Arduino pins connected to the 7-segment display segments.
  - `btnPin`: The pin for the push button input.
  - `display`: Tracks the current digit to display.
  - `btnState` and `lastBtnState`: Used to detect changes in button press.

- **`setup()`**:
  1. **Pin Modes**: Sets segment pins as `OUTPUT` and the button pin as `INPUT_PULLUP`.
  2. **Optional Serial**: Can be enabled for debugging or printing the current digit.

- **`loop()`**:
  1. Reads the button state.
  2. Detects a **transition** from HIGH to LOW to avoid incrementing multiple times if the button is held down.
  3. Increments the `display` variable and calls the corresponding digit function (e.g., `zero()`, `one()`, etc.).
  4. Includes a short `delay(50)` for simple debouncing.

- **Digit Functions** (`zero()`, `one()`, etc.):
  - Each function uses `digitalWrite()` to set the appropriate segments `HIGH` or `LOW`.  

---

## Troubleshooting

- **All segments remain off**: Check your wiring, especially common anode/cathode orientation and whether each segment pin is connected correctly.
- **Segments always on**: Invert the logic (switch `HIGH`/`LOW`) if you’re using a common anode display that expects a different polarity.
- **Button isn’t incrementing**: Ensure the button is wired to the correct pin (pin 9), and it’s set as `INPUT_PULLUP`. Verify you have the other side to GND.
- **Random increments**: The code uses a simple `delay(50)` for debouncing. If noise persists, consider hardware debouncing or a more sophisticated software approach.

---

## License

MIT license

---

**Happy Building!**
