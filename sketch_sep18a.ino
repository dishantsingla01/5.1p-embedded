import RPi.GPIO as GPIO
import tkinter as tk

# Setup GPIO pins for LED control
GPIO.setmode(GPIO.BCM)  # Use Broadcom pin numbering
LED_PINS = {'red': 17, 'green': 27, 'blue': 22}

# Set up each pin as an output and initialize to low (off)
for pin in LED_PINS.values():
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.LOW)

# Define functions to control the LEDs
def turn_on_led(color):
    # Turn off all LEDs first
    for pin in LED_PINS.values():
        GPIO.output(pin, GPIO.LOW)
    # Turn on the selected LED
    GPIO.output(LED_PINS[color], GPIO.HIGH)

# Function to close the GUI and clean up GPIO
def close():
    GPIO.cleanup()
    window.quit()

# Create the GUI window
window = tk.Tk()
window.title("LED Control")

# Variable to track the selected LED color
selected_led = tk.StringVar(value='red')

# Create radio buttons for each LED
tk.Radiobutton(window, text="Red LED", variable=selected_led, value='red', command=lambda: turn_on_led('red')).pack(anchor=tk.W)
tk.Radiobutton(window, text="Green LED", variable=selected_led, value='green', command=lambda: turn_on_led('green')).pack(anchor=tk.W)
tk.Radiobutton(window, text="Blue LED", variable=selected_led, value='blue', command=lambda: turn_on_led('blue')).pack(anchor=tk.W)

# Create an exit button
tk.Button(window, text="Exit", command=close).pack()

# Run the Tkinter event loop
window.mainloop()