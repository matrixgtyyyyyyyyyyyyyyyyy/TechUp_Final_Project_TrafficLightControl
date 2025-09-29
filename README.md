# TechUp_Final_Project_TrafficLightControl# TechUp Final Project: Traffic Light Control System

## Objective
Simulate a traffic light with pedestrian crossing using Arduino.

## Components Used
- Arduino Uno
- 3 LEDs (Red, Yellow, Green)
- Push Button (internal pull-up)
- 16x2 I2C LCD (Adafruit)
- Resistors, Breadboard, Wires

## Block Diagram
See `Diagrams/BlockDiagram.png`

## Circuit Diagram
See `Simulation/Tinkercad_Circuit.png`

## Arduino Code
See `Code/TrafficLight_Control.ino`

## Workflow
Step-by-step logic:
1. Default: RED → GREEN → YELLOW cycle.
2. Button press sets pedestrian request.
3. After current cycle, system enters PEDESTRIAN state.
4. LCD shows "WALK" while RED LED is ON.
5. After walk time, return to default cycle.

## Simulation Results
See `Simulation/SimulationResults.png`

## Reflection / Challenges
- Tinkercad does not support I2C LCD libraries.
- Learned non-blocking `millis()` state machine implementation.
