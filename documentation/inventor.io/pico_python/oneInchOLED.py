#this is the setup script for using
#the .9" display on Pico
#At the moment, I'm looking for a use for these (I have three and their around $1)
#this isn't my code. Tinker Tech Trove wrote this in his YouTube video: https://www.youtube.com/watch?v=YSqGV6NGWYM

from machine import Pin, I2C
from ssd1306 import SSD1306_I2C

w = 128
h = 32

i2c = I2C(0, scl=Pin(17), sda=Pin(16), freq=200000)
addr = i2c.scan()[0]
oled = SSD1306_I2C(w, h, i2c, addr)

oled.fill(0)
oled.text("Start", 5, 5)
oled.text("IR send", 5, 15)
oled.show
