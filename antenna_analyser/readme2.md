# Wire Antenna Analyzer

This folder contains the complete software developed for the **DDS-Based Wire Antenna Analyzer**. The analyzer uses an **AD9850 Direct Digital Synthesis (DDS)** module to perform programmable RF frequency sweeps and measures the relative RF response of a wire antenna using an Arduino Uno. The acquired data are visualized using Python and Matplotlib in both real-time and post-processing modes.

---

## Overview

The Arduino Uno controls the AD9850 DDS module to generate RF signals over a specified frequency range. During the frequency sweep, the RF detector output is sampled through the Arduino's ADC and transmitted to a computer via serial communication.

Two Python applications are provided:

- **Live Plotting:** Displays the antenna response continuously during the frequency sweep.
- **Post-Processing Plot:** Stores the acquired data and generates a complete frequency response graph after the sweep is finished.

This implementation is intended for educational purposes and basic antenna characterization.

---

## Features

- Programmable RF frequency sweep using AD9850 DDS
- Arduino-based RF amplitude acquisition
- Real-time serial communication
- Live frequency response plotting
- Automatic plotting after sweep completion
- Supports multiple sweep ranges
- Low-cost RF measurement platform

---

## Hardware Requirements

- Arduino Uno
- AD9850 DDS Module
- RF Detector Circuit
- Wire Antenna (Device Under Test)
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
| GND | GND |
| VCC | 5V |

The RF detector output is connected to **A0**.

---

## Folder Contents

### Arduino Firmware

| File | Description |
|------|-------------|
| `antennaanalyser.ino` | Controls the AD9850 DDS, performs frequency sweep, reads ADC values, and transmits data over Serial. |

---

### Python Scripts

| File | Description |
|------|-------------|
| `plotac.py` | Displays the antenna response continuously during the frequency sweep (Live Plot). |
| `plotlf.py` | Collects the complete dataset and plots the frequency response after the sweep has finished. |

---

## Output

The analyzer produces three representative outputs.

### 1. Live Frequency Response

Displays the antenna response in real time while the frequency sweep is in progress.

```
outputs/
└── Live_Plot.png
```

---

### 2. Frequency Response (500 kHz Sweep)

Complete frequency response generated after accumulating all data for a **500 kHz sweep**.

```
outputs/
└── Sweep_500kHz.png
```

---

### 3. Frequency Response (1 MHz Sweep)

Complete frequency response generated after accumulating all data for a **1 MHz sweep**.

```
outputs/
└── Sweep_1MHz.png
```

---

## Working Principle

1. Arduino initializes the AD9850 DDS module.
2. DDS generates a sinusoidal RF signal.
3. The frequency is incremented automatically throughout the sweep.
4. The RF signal excites the wire antenna.
5. The detector circuit converts the received RF signal into a measurable DC voltage.
6. Arduino samples the voltage using its ADC.
7. ADC values are transmitted to the computer through Serial communication.
8. Python visualizes the antenna response either in real time or after the frequency sweep is complete.

---

## Applications

- Wire antenna characterization
- Educational RF laboratory experiments
- RF signal propagation studies
- Frequency response analysis
- Amateur radio experimentation
- Communication engineering projects

---

## Future Improvements

- Automatic SWR estimation
- Return Loss calculation
- VSWR visualization
- Smith Chart plotting
- Higher-resolution ADC
- Automatic calibration
- PC-based GUI with data logging
- Extension to a compact Vector Network Analyzer (VNA)

---

## Author

**Arya Ghosh**  
Department of Electronics and Communication Engineering  
Cooch Behar Government Engineering College
