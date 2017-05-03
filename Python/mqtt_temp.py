#!/usr/bin/python

# Install via 'sudo pip install paho-mqtt'
import paho.mqtt.client as mqtt

# This is installed by default on Raspbian
from gpiozero import LED

def on_connect(client, userdata, flags, rc):
    client.subscribe("iotChallenge/temp")

def on_message(client, userdata, msg):
        print(msg.topic + " " + str(msg.payload))
        if float(msg.payload) >= 29.0:
            my_led.on()
        else:
            my_led.off()

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect("192.168.178.21", 1883, 60)

my_led = LED(4)

client.loop_forever()
