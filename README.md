# IoT-project_cleanBot

## Overview
cleanBot has two mode one is automatically clean the room with the vaccum, another mode is to clean the specific point.
clean robot usually not cleanning the most dirty spot in the room, because it was busy cleaning other place. 

#### My idea of the robot to go to the specific place
Where people are the trash will be made, so i assume people have phone with them, that the CleanBot detect the mobile hotsopt signal and approach it. Clean the spot when wifi signal is large or equal to 85%.


!([Imgur](https://i.imgur.com/WLry6g6.png?2) )


## Components
### Hardware
- arduino uno *1
- L293d motor shield *1
- nodeMCU *1
- servo mtor *1
- DC motor *4
- 7805 regulater *1
- pin header
- 12V battery package
- mini vaccum*1
- car shield

### Software
- Arduino IDE

## Circuit Diagram
![](https://i.imgur.com/5rGqtyh.png)

## CleanBot look

## Before Getting start
`vscode` can compile the arduino and more easy to debug, code hinting, auto compile and IntelliSense.

vscode compile arduino:
- install extention `arduino`
- go to command panel to `Arduino: Initialize`
- generate files `arduino.json` `c_cppproperties.json` `my_setch.ino`
- in `c_cppproperties.json` have to inclue Path of the library you want to use

## The mistake I have made
while i have reference many documents and try to bring it together to make my own robot ,although i have study about the compoenets  can it be connect to each other ,but still have lots of issue when i try to connect them.

#### L293d motor shield (notice!!)
Because the motor shield has no `pin header` on the digital pin, analog pin, power and GND pin. So i have to `welding pin header` by my self! (make sure you buy the L293d motor shield with pin header on it) 

> `jumper`
when you plugin the USB and with the external power you have to remove it from the L293d motor shield so you can test your motor.

If you unplung the USB and connect with the external power you have to plugin the 

#### Arduino wifi module (notice!)
i should buy the arduino UNO that has wifi (esp8266) on it, or the smaller chip of esp8266 module (it will simply gives UNO the wifi function)

## Arduino Uno connect to NodeMCU
### NodeMCU I2C with Arduino IDE

I used NodeMCU as 
- webserver
- detect the mobile hotspot
- sending data to Uno

> I2C 
is a serial bus interface connection protocol (two-wire interface). 
- SDA (serial data):wire is used for data exchange between master and slave devices.
- SCL (serial clock):is used for the synchronous clock in between master and slave devices.
 works in two modes:
 `Master Device : NodeMCU`
 `Slave Device : Arduino UNO`
 
 



