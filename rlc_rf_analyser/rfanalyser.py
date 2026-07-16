import serial
import matplotlib.pyplot as plt

COM_PORT = "COM5"      # Change this
BAUD = 115200

ser = serial.Serial(COM_PORT, BAUD, timeout=1)

frequency = []
rf = []

print("Receiving Data...\nPress Ctrl+C to stop")

try:

    while True:

        line = ser.readline().decode().strip()

        if "," in line:

            f, a = line.split(",")

            frequency.append(float(f)/1e6)
            rf.append(int(a))

            print(f"{float(f)/1e6:.3f} MHz    {a}")

except KeyboardInterrupt:

    pass

ser.close()

plt.figure(figsize=(10,5))

plt.plot(frequency, rf)

plt.title("Relative RF Amplitude vs Frequency")

plt.xlabel("Frequency (MHz)")

plt.ylabel("Relative RF Amplitude (ADC Counts)")

plt.grid(True)

plt.show()