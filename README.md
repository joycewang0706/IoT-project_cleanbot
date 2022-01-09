# IoT-project_cleanBot

## Overview
cleanBot has two mode one is automatically clean the room with the vaccum, another mode is to clean the specific point.
clean robot usually not cleanning the most dirty spot in the room, because it was busy cleaning other place. 

#### My idea of the robot to go to the specific place
Where people are the trash will be made, so i assume people have phone with them, that the CleanBot detect the mobile hotsopt signal and approach it. Clean the spot when wifi signal is large or equal to 85%.


<img src="https://i.imgur.com/SboxFeM.png" width="40%" height ="40%">


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
<img src="https://i.imgur.com/79DiJS9.jpg" width="50%" height ="50%">
<img src="https://i.imgur.com/yR6ifUQ.jpg" width="50%" height ="50%">
<img src="https://i.imgur.com/Ph3gViL.jpg" width="40%" height ="30%">

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

### NodeMCU circuit 
<img src="https://i.imgur.com/snR8yYY.png" width="40%" height ="40%">
<img src="https://i.imgur.com/42Xp1kk.png" width="40%" height ="40%">
`A4=SDA` `A5=SCL`
NodeMCU is very fragile if voltage too high and not stable it will broke.
So i use `7805` to regulate the voltage 


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
 
 ### NodeMCU side library
 ```
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <Wire.h>
 ```
 ### NodeMCU side
 - connect the wifi
 - website
 - scan the mobile hotspot signal
 - pass the value to Arduino Uno
 
> wifi signal
>I have covert wifi strength in dBm to percentage 


 ### Difficulty in NodeMCU
 when i try to connect to the mobile hotspot signal, the nodeMCU keep disconnect it.
 I have try to use 2.4Ghz (iphone and Android) and push the reset button on the NodeMCU, still can not work. 
 And there are many people asking the same question online.
 
 ## Arduino UNO
 use Uno to control:
 - four DC motor
 
 ## Reference
 wifi_signal: https://www.intuitibits.com/2016/03/23/dbm-to-percent-conversion/
 NodeMCU: https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
 
 



