# Automated Guided Forklift System 🚜

An autonomous mobile robot for warehouse material handling with line-following navigation and cargo lifting capabilities.

## System Overview

This project implements an Automated Guided Vehicle (AGV) that performs three primary functions:
- **Navigation**: Follows predefined paths using infrared sensors
- **Detection**: Identifies cargo using ultrasonic ranging
- **Manipulation**: Lifts and transports objects using servo-controlled forks

## Technical Specifications

| Component | Specification |
|-----------|---------------|
| Microcontroller | Arduino Mega 2560 |
| Navigation Sensors | 3× IR sensors (digital output) |
| Object Detection | HC-SR04 ultrasonic sensor |
| Actuator | Servo motor (180° rotation) |
| Motor Control | L298N dual H-bridge driver |
| Power Supply | 11.1V Li-ion battery (3S, 4300mAh) |
| Track Width | 3cm black line on white surface |
| Detection Range | 2-400cm |
| Payload Capacity | 20-40g (tested up to 100g) |

## System Architecture

```
Input Layer:     IR Sensors → Line Detection
                 Ultrasonic → Object Detection

Processing:      Arduino Mega → Control Logic

Output Layer:    Motor Driver → Wheel Movement
                 Servo Motor → Fork Lifting
```

## Operation Sequence

1. **Path Following**: IR sensor array detects black line and controls wheel motors
2. **Object Detection**: Ultrasonic sensor monitors path for obstacles
3. **Positioning**: System stops 2cm from detected object
4. **Loading**: Servo motor lifts forks to engage cargo
5. **Transport**: Resume path following while carrying load
6. **Unloading**: Lower forks at destination point

## Hardware Implementation

### Chassis Design
- Two-wheel differential drive with castor wheel
- Lightweight plastic frame for optimal weight distribution
- 3D-printed lifting mechanism with reinforcement webs

### Sensor Configuration
- **IR Array**: Three sensors mounted 1.5cm apart for line tracking
- **Ultrasonic**: Front-mounted for forward object detection
- **Servo**: Top-mounted with string-pulley system for vertical lift

### Power Management
- Battery Management System (BMS) with overcharge protection
- Voltage regulation: 12V (motors), 5V (Arduino), 3.3V (sensors)
- Estimated runtime: 4-6 hours continuous operation

## Control Algorithm

### Line Following Logic
```
Sensor State → Action
Left + Center → Turn Right
Right + Center → Turn Left  
Center Only → Move Forward
All White → Stop
All Black → Stop
```

### Object Handling Protocol
```
1. Detect object (distance < threshold)
2. Approach to 2cm proximity
3. Align forks beneath object
4. Activate servo (lift sequence)
5. Resume navigation
6. Destination reached → Lower forks
```

## Performance Metrics

- **Navigation Accuracy**: ±1cm deviation from path centerline
- **Detection Reliability**: 95% success rate in object identification
- **Lifting Precision**: ±2mm vertical positioning accuracy
- **Response Time**: 200ms from detection to action
- **Power Consumption**: 1A average during operation

## Testing Results

### Validation Environment
- Test track: 3m × 2m with straight sections and 90° turns
- Standard payload: 5×5×5cm cardboard boxes (20-40g)
- Ambient conditions: Indoor lighting, room temperature

### Performance Summary
✓ Successfully completed 50+ autonomous cycles  
✓ Zero collision incidents during testing  
✓ Consistent cargo handling across all trials  
✓ Stable operation under varying load conditions

## Applications

This AGV system demonstrates practical applications in:
- Small-scale warehouse automation
- Educational robotics platforms  
- Proof-of-concept for industrial material handling
- Foundation for advanced autonomous vehicle development
## Project Structure

```
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
```


---


