# DDS Signal Generator

This folder contains the Arduino firmware and Python utilities used to generate programmable RF signals using an AD9850 Direct Digital Synthesis (DDS) module and visualize the detected signal amplitude using **Matplotlib**.

Overview

The Arduino Uno controls the AD9850 DDS module to generate sinusoidal RF signals over a user-defined frequency range. During the frequency sweep, the analog signal from an RF detector circuit is sampled through the Arduino's ADC (A0) and transmitted to a computer via serial communication.

A Python script reads the serial data and plots the measured ADC amplitude against frequency using Matplotlib, allowing visualization of the RF response of passive components.

Features

- Programmable RF signal generation using AD9850 DDS
- Frequency sweep over a configurable range
- Arduino-based ADC acquisition
- Real-time serial communication
- Python-based visualization using Matplotlib
- Suitable for RF response analysis and educational experiments

Hardware Requirements

- Arduino Uno
- AD9850 DDS Module
- RF Detector Circuit
- Breadboard and jumper wires
- USB Cable

Software Requirements

- Arduino IDE
- Python 3.x
- pyserial
- matplotlib
- numpy

Install the required Python libraries:

```bash
pip install pyserial matplotlib numpy
```
Pin Connections

| AD9850 Pin | Arduino Uno |
|------------|-------------|
| W_CLK | D8 |
| FQ_UD | D9 |
| DATA | D10 |
| RESET | D11 |
| GND | GND |
| VCC | 5V |

The detector output is connected to A0.

Files

| File | Description |
|------|-------------|
| `signalgen.ino` | Arduino firmware for DDS signal generation and ADC acquisition |
| `main.py` | Python script for plotting RF amplitude versus frequency |

Output

The Python application generates a graph of **Relative RF Amplitude (ADC Counts)** versus **Frequency (MHz)**, enabling visualization of the RF response of the Device Under Test (DUT).

Applications

- RF signal generation
- Passive component characterization
- Educational RF laboratory experiments
- Frequency response analysis
- Communication engineering projects

Author

Arya Ghosh
Department of Electronics and Communication Engineering  
Cooch Behar Government Engineering College
