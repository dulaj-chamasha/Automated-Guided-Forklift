# Automated Guided Forklift 🚜

A smart autonomous robot designed for warehouse cargo handling with line-following navigation and servo-driven lifting capabilities.  
Built on Arduino Mega platform with integrated sensors, motor drivers, and custom 3D-printed hardware for reliable pick-and-place operations.

## 🔧 System Overview

This Automated Guided Vehicle (AGV) performs three core functions:
- **🧭 Navigation:** IR sensor array tracks black lines on white surfaces
- **🎯 Object Detection:** Ultrasonic ranging sensor (2–400 cm range)  
- **🦾 Cargo Handling:** Servo motor with string-pulley lifting mechanism
- **🧠 Control System:** Arduino Mega 2560 coordinates all operations

## 📐 Hardware Components

| Component | Specification |
|-----------|---------------|
| **Microcontroller** | Arduino Mega 2560 |
| **Navigation** | 3× IR sensors (digital output) |
| **Object Detection** | HC-SR04 ultrasonic sensor |
| **Lifting System** | Servo motor (180° rotation) |
| **Motor Control** | L298N dual H-bridge driver |
| **Power Supply** | 11.1V Li-ion battery (3S, 4300mAh) + BMS |
| **Chassis** | Two-wheel drive + caster wheel |
| **Forklift Arms** | Custom 3D-printed reinforced design |
| **Track Specs** | 3cm black line on white surface |
| **Payload** | 20-40g (tested up to 100g) |

## ⚙️ Method of Operation

1. **🛤️ Path Following:** Three IR sensors detect 3cm black line and control wheel motors for precise tracking
2. **🔍 Obstacle Detection:** Ultrasonic sensor monitors path and stops forklift ~2cm before objects
3. **📦 Cargo Handling:** Servo motor lifts forks using string-pulley system to engage 5×5×5cm boxes
4. **🤖 Automation:** Arduino Mega processes all sensor data and coordinates actuator responses

### Control Algorithm
```
Line Following Logic:
- Center sensor only → Move Forward
- Left + Center → Turn Right
- Right + Center → Turn Left
- All sensors → Stop

Object Handling:
1. Detect → 2. Position → 3. Lift → 4. Transport → 5. Unload
```

## 📊 Performance Results

- **Navigation Accuracy:** ±1cm deviation from centerline with 3-sensor configuration
- **Detection Range:** Reliable obstacle detection 2-400cm
- **Lifting Capacity:** Successfully tested up to 100g (1N force) with structural analysis
- **Response Time:** 200ms from detection to action
- **Success Rate:** 50+ autonomous cycles completed with zero collisions
- **Power Efficiency:** 4-6 hours continuous operation

## 🚀 Future Enhancements

- **Advanced Control:** PID controller for smoother line tracking and reduced oscillation
- **AI Integration:** Camera modules with object recognition for intelligent cargo sorting  
- **Hybrid Systems:** Electric-hydraulic lifting for increased payload capacity
- **Safety Features:** Gyro sensors and load balancing for overturn prevention
- **Path Planning:** Multi-route navigation with decision algorithms

## 🏭 Applications

This AGV demonstrates practical use in:
- Small-scale warehouse automation
- Educational robotics platforms
- Industrial material handling proof-of-concept  
- Foundation for advanced autonomous vehicle development

## 📂 Repository Structure

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




