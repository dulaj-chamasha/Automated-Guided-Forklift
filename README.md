# Automated Guided Forklift 🚜

A smart forklift robot designed for **autonomous cargo handling**.  
It follows a predefined line, detects obstacles, and performs pick-and-place operations using a servo-driven forklift mechanism.  
The system is built on an **Arduino Mega** platform with integrated sensors, motor drivers, and custom 3D-printed hardware.

---

## 🔧 System Overview
- **Navigation:** IR sensor array for black line tracking  
- **Object Detection:** Ultrasonic sensor (2–400 cm)  
- **Forklift Mechanism:** Servo motor with string-pulley lift system  
- **Control Unit:** Arduino Mega 2560 + L298N Motor Driver  
- **Power:** 11.1V Li-ion battery pack with BMS  

---

## 📐 Hardware Components
- Arduino Mega 2560  
- 3 × IR Sensors  
- HC-SR04 Ultrasonic Sensor  
- Servo Motor (lifting forks)  
- L298N Motor Driver  
- 11.1V 3S Li-ion Battery Pack + BMS  
- Two-wheel chassis + caster  
- 3D printed forklift arms  

---

## ⚙️ Method of Operation
1. **Line Following:** IR sensors track a 3 cm black line on white surface  
2. **Obstacle Handling:** Ultrasonic sensor stops forklift ~2 cm before object  
3. **Cargo Handling:** Servo motor lifts and unloads cargo (5×5×5 cm box, 20–40 g)  
4. **Automation:** Arduino coordinates all sensors and actuators  

---

## 📊 Results
- Stable line following with **3-sensor configuration**  
- Cargo lifting tested up to **100 g (1N force)**  
- Reliable obstacle detection within **short-range accuracy**  

---

## 🚀 Future Enhancements
- PID control for smoother line tracking  
- AI-based object recognition with camera modules  
- Hybrid electric-hydraulic lifting system  
- Safety features for load balance and overturn prevention  

---

## 📂 Repository Structure
---
automated-guided-forklift/
├── docs/
│   └── Final_Report.pdf     # Complete technical documentation
├── src/
│   └── arduino/             # Microcontroller source code
├── hardware/
│   ├── cad_files/           # 3D models (.stl format)
│   └── schematics/          # Circuit diagrams
└── media/
    └── images/              # System photographs
---
