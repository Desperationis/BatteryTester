# BatteryTester
![Setup](IMG_20210221_201524.jpg)
This is a simple voltmeter meant to tell if a battery is charged or not and its very approximate % via an Arduino Uno. The main.ino file contains a class named `BatteryTester` that accepts two parameters in its constructor: the lower and upper bound. The lower bound is the minimum possible usable voltage the battery can have, and the upper bound is what is considered to be 100% as the unloaded voltage. By default, this program measures the % of a 3000 mah NiMH 7.2 VEX battery, though it can be configured to accept any type of battery (less than 10 volts) through modifying main.ino. 

As for rechargable batteries, make sure to leave the battery out for 12 hours after charging ***or*** apply a load to it to get rid of [surface charge](https://mechanics.stackexchange.com/questions/44197/what-is-surface-charge-and-how-does-it-affect-battery-testing). Without this step, the battery has an elevated voltage (from clinging on to slightly more electrons than usual from its charger) that may give a false reading. By applying a load for a short period of time, you drain the excess electrons, or by leaving it out for awhile, you're allowing the battery to suck up and distribute the excess electrons throughout itself. 

The wiring for this is as follows:

![Circuit Diagram](circuit.png)
... where the battery to the far left can be replaced with any battery less than 10 V. 
