from time import sleep
import pyfirmata2

ARDUINO_PORT = 'COM5'

try:
    board = pyfirmata2.Arduino(ARDUINO_PORT)
    
    led_pin = board.digital[13]
    led_pin.mode = pyfirmata2.OUTPUT

    while True:
        led_pin.write(1)
        sleep(1)
        led_pin.write(0)
        sleep(1)

except KeyboardInterrupt:
    print("Stopping...")
    led_pin.write(0)
    board.exit()

except Exception as e:
    print(f"Exception: {e}")
    print("Make Sure Board is Connected and StandardFirmata is Uploaded!")