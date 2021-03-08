# BatteryTester
![Setup](IMG_20210221_201524.jpg)
This is a simple voltmeter meant to tell if a battery is charged or not and its approximate % via an Arduino Uno. The main.ino file contains a class named `BatteryTester` that has a abstract function, `getPercent(voltage)`, where you fill in the formula for any battery's discharge curve such that you can get an approximate %. An example for a 3000 mAh 7.2 Vex Batery is shown.

As for any type of battery, make sure to apply a load to the battery momentarily to get rid of [surface charge](https://mechanics.stackexchange.com/questions/44197/what-is-surface-charge-and-how-does-it-affect-battery-testing). Without this step, the battery has an elevated voltage (from having time to fully soak and spread out electrons throughout itself) that may give a false reading. By applying a load for a short period of time, you drain the excess electrons.

The wiring for this is as follows:

![Circuit Diagram](circuit.png)
... where the battery to the far left can be replaced with any battery less than 10 V. 
