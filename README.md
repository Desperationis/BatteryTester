# BatteryTester
![Setup](IMG_20210221_201524.jpg)
This is a simple voltmeter meant to tell if a battery is charged or not and its very approximate % via an Arduino Uno. The main.ino file contains a class named `BatteryTester` that accepts two parameters in its constructor: the lower and upper bound. The lower bound is the minimum possible usabe voltage the battery can have, and the upper bound is what is considered to be 100% as the unloaded voltage. By default, this program measures the % of a 3000 mah NiMH 7.2 VEX battery, though it can be configured to accept any type of battery (less than 10 volts) through modifying main.ino. 

The wiring for this is as follows:

![Circuit Diagram](circuit.png)
... where the battery to the far left can be replaced with any battery less than 10 V. 
