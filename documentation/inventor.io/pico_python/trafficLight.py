import machine
import time

red_pin = machine.Pin(0, machine.Pin.OUT)
yellow_pin = machine.Pin(1, machinePin.OUT)
green_pin = machine.Pin(2, machine.Pin.OUT)

def traffic_light():
    red_pin.on()
    time.sleep(2)
    red_pin.off()
    green_pin.on()
    time.sleep(2)
    green.pin.off()
    yellow_pin.on()
    time.sleep(1)
    yellow_pin.on()
    
#call traffic light func
traffic_light();
