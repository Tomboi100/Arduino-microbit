from microbit import *

steps = 0
display.show(str(steps))

if button_a.get_presses()
    while True:
        if accelerometer.was_gesture("shake"):
            steps += 1
            if steps < 10:
                display.show(str(steps))
            else:
                display.scroll(str(steps))
elif button_b.get_presses()
    with open('step.txt') as my_file:
        my_file = steps.write()
