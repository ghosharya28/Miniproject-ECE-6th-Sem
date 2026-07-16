# Development and Experimental Applications of a Direct Digital Synthesis (DDS)-Based Signal Generation Platform

*A Low-Cost RF Signal Generator and Antenna Analyzer Using Arduino Uno and AD9850*

![GitHub](https://img.shields.io/badge/Platform-Arduino-blue)
![Python](https://img.shields.io/badge/Python-3.x-yellow)
![DDS](https://img.shields.io/badge/DDS-AD9850-green)

---

## Overview

This repository contains the complete implementation, documentation, and experimental results of a **DDS-Based Signal Generation Platform** developed using an **Arduino Uno**, **AD9850 Direct Digital Synthesis (DDS) module**, and **Python**.

The objective of this project is to develop a **low-cost, programmable RF experimentation platform** capable of generating RF signals and demonstrating practical applications in communication engineering.

The developed platform includes:

- 📡 DDS-Based RF Signal Generator
- 📶 Wire Antenna Analyzer
- ⚡ DDS-Based RF Component Analyzer for Passive RLC Components
- 📈 Python-Based Data Acquisition and Visualization
- 📖 Proposed DDS-Based BPSK/QPSK Communication System

The project was developed as a **Mini Project** for the Department of Electronics and Communication Engineering, Cooch Behar Government Engineering College (MAKAUT). :contentReference[oaicite:0]{index=0}

---

## Features

- Programmable RF signal generation using AD9850 DDS
- Frequency sweep over configurable RF ranges
- Arduino-based data acquisition
- Python GUI using Matplotlib
- Wire antenna response analysis
- Relative RF characterization of passive RLC components
- Open-source implementation using low-cost hardware
- Foundation for future DDS-based digital communication systems

---

## Repository Structure

```
## Repository Structure

```text
Miniproject-ECE-6th-Sem/
│
├── antenna_analyser/
│   ├── Arduino firmware
│   ├── Python plotting scripts
│   ├── Hardware photographs
│   ├── Experimental output graphs
│   └── README.md
│
├── rlc_rf_analyser/
│   ├── Arduino firmware
│   ├── Python analysis script
│   ├── Hardware photographs
│   ├── Experimental output graphs
│   └── README.md
│
├── signal_gen/
│   ├── Arduino firmware
│   ├── Python plotting script
│   ├── Hardware photographs
│   ├── Experimental output graphs
│   └── README.md
│
├── report/
│   ├── Mini_Project_Report.pdf
│   ├── Mini_Project_Report.docx
│   ├── Presentation.pptx
│   └── README.md
│
├── README.md
```

---

## Hardware Used

- Arduino Uno
- AD9850 DDS Module
- RF Detector Circuit
- Breadboard
- Passive RLC Components
- Wire Antenna
- USB Serial Interface

---

## Software Used

- Arduino IDE
- Python 3.x
- Matplotlib
- NumPy
- PySerial
- Microsoft Word
- Microsoft PowerPoint

---

## Applications

### 1. DDS-Based RF Signal Generator

A programmable RF signal generator capable of producing stable sinusoidal waveforms over a configurable frequency range using the AD9850 DDS module.

---

### 2. Wire Antenna Analyzer

Performs RF frequency sweeps and acquires the relative response of a wire antenna. Measurement data are visualized using Python, providing a low-cost platform for basic antenna characterization.

---

### 3. DDS-Based RF Component Analyzer

Studies the frequency-dependent RF response of passive resistors, capacitors, and inductors using a DDS-generated excitation signal and Arduino-based data acquisition.

---

### 4. Proposed DDS-Based Digital Communication

The report also presents the theoretical design of a DDS-based **BPSK/QPSK transmitter**, illustrating how the developed platform can be extended for digital communication experiments. :contentReference[oaicite:1]{index=1}

---

## Experimental Results

The repository includes:

- Hardware photographs
- Circuit diagrams
- Frequency response graphs
- Antenna response plots
- RF component analysis graphs
- Complete project report
- Project presentation

---

## Future Improvements

- SWR and Return Loss calculation
- Automatic impedance extraction
- Higher-resolution ADC
- Smith Chart visualization
- I/Q demodulation
- Portable RF measurement platform
- Software Defined Radio (SDR) integration
- Compact Vector Network Analyzer (VNA)

---

## Getting Started

### Clone the repository

```bash
git clone https://github.com/<your-username>/DDS-RF-Component-Analyzer.git
```

### Install Python dependencies

```bash
pip install pyserial matplotlib numpy
```

### Upload Arduino Firmware

Open the required Arduino sketch from the `src/` directory using the Arduino IDE and upload it to the Arduino Uno.

### Run Python Application

Navigate to the appropriate Python script and execute:

```bash
python rfanalyser.py
```

or

```bash
python plotac.py
```

depending on the application.

---

## Documentation

The complete project report and presentation are available in the **docs/** directory.

---

## Author

**Arya Ghosh**  
Department of Electronics and Communication Engineering  
Cooch Behar Government Engineering College  
Maulana Abul Kalam Azad University of Technology (MAKAUT), West Bengal

---

## Team Members

- Adripta Ghosh
- Anushka Roy
- Arijit Manna
- Arya Ghosh
- Swastik Bal
