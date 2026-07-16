import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM5', 115200, timeout=1)

freqs = []
values = []

plt.ion()

fig, ax = plt.subplots()
line, = ax.plot([], [])

ax.set_xlabel("Frequency")
ax.set_ylabel("Reflection")
ax.set_title("Antenna Response")

while True:
    line_raw = ser.readline().decode(errors='ignore').strip()

    if ',' in line_raw:
        f, v = line_raw.split(',')

        freqs.append(float(f))
        values.append(int(v))

        line.set_xdata(freqs)
        line.set_ydata(values)

        ax.relim()
        ax.autoscale_view()

        plt.draw()
        plt.pause(0.01)