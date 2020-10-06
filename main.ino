/*
 * This is a battery tester meant to tell you if a 
 * lithium-ion battery is "good" for normal use and 
 * "bad" for prolonged use. 
 * 
 * The circuit consists of a voltage divider with a 1 : 1
 * ratio of resistors connected to the A0 analog pin with 
 * the Arduino's Liquid Crystal display connected along 
 * the digital pins according to this image:
 * 
 * https://www.arduino.cc/en/uploads/Tutorial/LCD_Base_bb_Fritz.png
 * 
 * The voltage divider can be connected to a battery upwards of 10V
 * and is also connected to a common ground.
 * 
 * A few things to keep in mind:
 * 
 * - The exact % is not completely accurate for half-charged batteries. The discharge graph 
 * for VEX 3000 mAh lithium ion batteries has a small slope between 7.25 - 7 volts that 
 * accounts for 50% of the battery's discharge graph. Since the voltage of batteries *slightly*
 * vary due to temperature, a battery at half-charge can be observed fluctating on by +- 10% if it's
 * between 10 - 60%.
 * 
 * https://content.vexrobotics.com/images/800px-QBT_Volts_at_4A.png
 * 
 * - Battery voltages decrease as more current is drawn from the battery due to
 * internal resistance. This means that a reading of 80% might actually be 60% under
 * heavy conditions.
 * 
 * 
 * "What is this made for if it's inaccurate?"
 * 
 * This circuit allows you to simply stick the terminals of a battery quickly and
 * know if it's at full charge or near it. That's it!
 * 
 * "Why can't I use a multimeter?"
 * 
 * You probably could just use a multimeter, but you wouldn't be able to solve for an approximate
 * percentage instantely with that reading. 
 */

#include <LiquidCrystal.h>
#include "NineVoltTester.h"

LiquidCrystal lcd(2, 3, 9, 10, 11, 12);

const int readingPin = A0;
NineVoltTester tester;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Welcome to Diego");
  lcd.setCursor(0, 1);
  lcd.print("\'s batt tester!");
  delay(3000);
  lcd.clear();
}

void loop() {
  int rawValue = analogRead(readingPin);
  
  float incomingVoltage = (rawValue / 1024.0) * 5.0;
  float originalVoltage = incomingVoltage * 2;

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Volt:");

  lcd.setCursor(0, 1);
  lcd.print(originalVoltage);
  lcd.print("V");

  float relativePercent = NineVoltTester::CalculatePercent(originalVoltage);

  lcd.setCursor(7,0);
  lcd.print(NineVoltTester::IsGood(originalVoltage) ? "Good!" : "Bad!");

  lcd.setCursor(7, 1);
  lcd.print(relativePercent);
  lcd.print("%");

  delay(300);
}
