# Simon-Says-Game-2
# Task 1b – Simon Says Game using ESP32

---

##  Objective

To familiarize myself with the ESP32 by designing and implementing a simple Simon Says game using LEDs and pushbuttons. This task helps me understand digital input and output operations while applying basic programming logic to create an interactive system.

---

## Description

In this task, I will create a Simon Says game using an ESP32, 4 LEDs, and 4 pushbuttons.

The game works as follows:

- The ESP32 generates a random LED sequence.
- LEDs blink one by one to display the sequence.
- I must press the corresponding buttons in the same order.
- If the input is correct, the level increases.
- If I press a wrong button, all LEDs flash to indicate failure.
- The game restarts automatically.

This task helps in understanding:
- GPIO input (reading buttons)
- GPIO output (controlling LEDs)
- Random number generation
- Basic program logic and condition checking

---

#  Components Required

- ESP32 Development Board  
- 4 LEDs  
- 4 Pushbuttons  
- 4 × 220Ω resistors  
- Breadboard  
- Jumper wires  

---

#  Connections

## LED Connections

Each LED must be connected with a **220Ω resistor** to limit current.

| LED   | ESP32 GPIO | Connection Description |
|-------|------------|------------------------|
| LED 1 | GPIO 2     | GPIO → 220Ω → LED (+) |
| LED 2 | GPIO 4     | GPIO → 220Ω → LED (+) |
| LED 3 | GPIO 5     | GPIO → 220Ω → LED (+) |
| LED 4 | GPIO 18    | GPIO → 220Ω → LED (+) |

- LED negative (short leg) → GND  
- All GND connections must be common  

---

## Pushbutton Connections (Using INPUT_PULLUP)

Buttons are connected using the internal pull-up resistor.

| Button   | ESP32 GPIO | Other Side |
|----------|------------|------------|
| Button 1 | GPIO 12    | GND        |
| Button 2 | GPIO 13    | GND        |
| Button 3 | GPIO 14    | GND        |
| Button 4 | GPIO 27    | GND        |

- One terminal of button → GPIO  
- Other terminal → GND  

Logic used in code:

- Not Pressed → HIGH  
- Pressed → LOW  
