# Robot Drive System (ESP32)

A wireless robot drive system developed as a Year 2 Semester 1 project. 

This project focuses on hardware-level programming and wireless communication, utilizing an ESP32 microcontroller to drive robot motors via Bluetooth connection with PlayStation 4 (PS4) and PlayStation 5 (PS5) controllers.

## Features
- Wireless control using standard PS4 and PS5 controllers.
- Real-time signal processing from joystick inputs to motor outputs.
- Bluetooth MAC address pairing and connection management.
- Multi-controller support separated by specific modules.

## Repository Structure
- `/main3_ps5` - Alternative or specific control logic for the PS5 controller.
- `/mainesp32_robot_ps4` - Main firmware for ESP32 integration with a PS4 controller.
- `/mainesp32_robot_ps5` - Main firmware for ESP32 integration with a PS5 controller.

## Tech Stack & Software
- **Language:** C/C++ 
- **Microcontroller Framework:** iox esp32
- **Libraries:** PS4Controller.h, ps5Controller.h

## Hardware Components
- ESP32 Development Board
- Motor Driver ZK-BM1
- DC Motors / Mecanum Wheels 
- PS4 / PS5 DualSense Controller

## How to Setup and Run
1. Clone this repository:
   ```bash
   git clone [https://github.com/your-username/Drive-system_robot.git](https://github.com/your-username/Drive-system_robot.git)
