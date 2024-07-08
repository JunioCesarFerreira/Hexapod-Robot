# Hexapod-Robot

🌍 *[Português](README.md) ∙ [English](README_en.md)*

## Description
This repository contains some data from a hexapod robot project that I've been implementing for some time. The original project was started in 2016, when I designed and prepared the mechanical structure. Back then, my intention was to use the PIC18F4550 MCU as a controller. In the current version developed in 2023, I am using the ESP32-S2. This is an uncompleted version. I intend to keep adding more details to the project (electronic circuit and layouts), as well as continue to evolve the current code on ESP32-S2.

## Technology and Components
- **Current Microcontroller**: ESP32-S2, chosen for its superior performance and IoT features.
- **PlatformIO with VS Code**: The firmware project was implemented using the Arduino framework on PlatformIO in VS Code.

## Repository Structure
- `HexapodRobot`: The main project directory, containing source code, libraries, and tests for the ESP32-S2.
- `MechanicProject`: Robot mechanical drawings and models, including CAD files compatible with software like SolidWorks.

## Installation and Setup
To contribute or test the project, follow these steps:
1. Install PlatformIO IDE or integrate it with Visual Studio Code.
2. Clone the repository and navigate to the `HexapodRobot` directory.
3. Follow the instructions in `platformio.ini` to set up your development environment.

## Usage
Instructions for assembling the robot and programming it with the provided code:
1. Assemble the hexapod robot hardware as per the designs in `MechanicProject`.
2. Load the code from the `HexapodRobot` directory onto the ESP32-S2.
3. Follow the detailed instructions in the code for robot control and operations.

## Contributing
Your contributions are vital for the ongoing development of the project. To contribute:
1. Fork the repository.
2. Create a branch for your feature.
3. Submit a detailed pull request.

## License
This project is distributed under the MIT License. See the [LICENSE](LICENSE) file for more details.