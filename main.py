import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque

# ----------------------------
# SERIAL SETTINGS
# ----------------------------
PORT = 'COM5'
BAUD = 115200

ser = serial.Serial(PORT, BAUD, timeout=1)

# ----------------------------
# GRAPH SETTINGS
# ----------------------------
plt.style.use("dark_background")

BUFFER_SIZE = 300

samples = deque(maxlen=BUFFER_SIZE)

fig, ax = plt.subplots(figsize=(10,5))

line, = ax.plot([], [], lw=2, color='cyan')

ax.set_title("Live ADC Waveform")
ax.set_xlabel("Samples")
ax.set_ylabel("ADC Value")

text = ax.text(
    0.02,
    0.95,
    "",
    transform=ax.transAxes,
    color='yellow',
    fontsize=11
)

# ----------------------------
# UPDATE FUNCTION
# ----------------------------
def update(frame):

    try:
        while ser.in_waiting:

            value = ser.readline().decode().strip()

            if value:

                adc = int(value)

                samples.append(adc)

    except Exception as e:
        print(e)

    if len(samples) > 1:

        line.set_data(range(len(samples)), samples)

        ymin = min(samples)
        ymax = max(samples)

        if ymin == ymax:
            ymin -= 10
            ymax += 10

        padding = max((ymax - ymin) * 0.15, 5)

        ax.set_ylim(ymin - padding, ymax + padding)
        ax.set_xlim(0, BUFFER_SIZE)

        text.set_text(f"Latest ADC : {samples[-1]}")

    return line, text

ani = animation.FuncAnimation(
    fig,
    update,
    interval=20,
    blit=False,
    cache_frame_data=False
)

plt.tight_layout()
plt.show()