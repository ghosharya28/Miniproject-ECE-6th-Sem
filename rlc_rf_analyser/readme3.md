# DDS-Based RF Component Analyzer (RLC)

This folder contains the software, experimental results, and hardware implementation of a **DDS-Based RF Component Analyzer** developed using an **AD9850 DDS module**, **Arduino Uno**, and **Python**. The analyzer is designed to study the relative RF response of passive **Resistors (R), Inductors (L), and Capacitors (C)** over a programmable frequency range.

---

## Overview

The analyzer generates stable sinusoidal RF signals using the AD9850 DDS module and excites the Device Under Test (DUT). The resulting RF response is detected using an RF detector circuit and sampled by the Arduino Uno through its analog-to-digital converter (ADC).

The acquired data are transmitted to a computer via serial communication, where a Python application processes and plots the **Relative RF Amplitude vs Frequency** using Matplotlib.

This project serves as a low-cost educational platform for studying the RF characteristics of passive RLC components.

---

## Features

- DDS-based programmable RF signal generation
- Frequency sweep using AD9850 DDS
- Arduino-based RF amplitude acquisition
- Relative RF response measurement of passive RLC components
- Real-time serial communication
- Frequency response visualization using Python and Matplotlib
- Low-cost implementation suitable for laboratory demonstrations

---

## Hardware Requirements

- Arduino Uno
- AD9850 DDS Module
- RF Detector Circuit
- Passive RLC Components (Resistors, Capacitors, Inductors)
- Breadboard and Jumper Wires
- USB Cable

---

## Software Requirements

- Arduino IDE
- Python 3.x
- PySerial
- Matplotlib
- NumPy

Install the required Python libraries:

```bash
pip install pyserial matplotlib numpy
```

---

## Pin Connections

| AD9850 Pin | Arduino Uno |
|------------|-------------|
| W_CLK | D8 |
| FQ_UD | D9 |
| DATA | D10 |
| RESET | D11 |
| VCC | 5V |
| GND | GND |

The detector output is connected to **A0** of the Arduino Uno.

---

## Folder Contents

### Arduino Firmware

| File | Description |
|------|-------------|
| `rlcanalyser.ino` | Controls the AD9850 DDS module, performs programmable RF frequency sweeps, acquires ADC data from the detector circuit, and transmits measurements over Serial. |

---

### Python Script

| File | Description |
|------|-------------|
| `rfanalyser.py` | Reads serial data from the Arduino and plots the relative RF amplitude versus frequency using Matplotlib. |

---

## Experimental Results

The analyzer was tested with different passive components to observe their relative RF response.

### 1. Frequency Response of a 220 Ω Resistor

```
results/
└── Resistor_220_Ohm.png
```

This graph illustrates the relative RF amplitude obtained during a frequency sweep with a **220 Ω resistor** connected as the Device Under Test (DUT).

---

### 2. Frequency Response of a 0.1 µF Capacitor

```
results/
└── Capacitor_0.1uF.png
```

This graph shows the relative RF response of a **0.1 µF capacitor**, demonstrating its frequency-dependent behaviour under RF excitation.

---

## Hardware

Photographs of the experimental setup are provided in the **hardware/** directory.

```
hardware/
├── Complete_Hardware.jpg
├── Circuit_Setup.jpg
└── AD9850_Arduino_Setup.jpg
```

---

## Working Principle

1. Arduino initializes the AD9850 DDS module.
2. The DDS generates a sinusoidal RF signal over a programmable frequency range.
3. The RF signal excites the passive RLC component (DUT).
4. The RF detector converts the response into a measurable DC voltage.
5. Arduino samples the detector output using its ADC.
6. Measurement data are transmitted to the computer through Serial communication.
7. Python processes and plots the **Relative RF Amplitude vs Frequency**.

---

## Applications

- RF component characterization
- Educational RF laboratory experiments
- Passive component frequency-response analysis
- Communication engineering laboratories
- RF circuit experimentation
- Undergraduate electronics projects

---

## Future Improvements

- Higher-resolution external ADC
- Phase-sensitive detection
- Impedance calculation from voltage and current measurements
- Automatic component identification
- Open-Short-Load (OSL) calibration
- Smith Chart visualization
- Extension to a compact RF Impedance Analyzer or Vector Network Analyzer (VNA)

---

## Author

**Arya Ghosh**  
Department of Electronics and Communication Engineering  
Cooch Behar Government Engineering College
