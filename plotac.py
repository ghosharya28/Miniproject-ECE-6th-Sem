import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM5', 115200, timeout=1)

freqs = []
values = []

print("Reading... Ctrl+C to stop")

try:
    while True:
        line = ser.readline().decode(errors='ignore').strip()
        if ',' in line:
            f, v = line.split(',')
            freqs.append(float(f))
            values.append(int(v))

except KeyboardInterrupt:
    pass

# Normalize
values = [v / max(values) for v in values]

plt.plot(freqs, values)
plt.xlabel("Frequency (Hz)")
plt.ylabel("Reflection")
plt.title("Antenna Response")
plt.grid()
plt.show()