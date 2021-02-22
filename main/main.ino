/*
 * This is a voltmeter meant to tell you if ANY  battery is charged; It does
 * this by measuring the unloaded voltage of it and finding it's % by a
 *  * designated lower and upper bound. The % is not super accurate as it does
 * not * account for the flatline most batteries have when they are at ~90-30%.
 * Due to this, batteries are only considered "charged" if they're above 95%.
 *
 * The circuit consists of a voltage divider with a 1 : 1 ratio of
 * resistors, with the output connected to the A0 analog pin of the Arduino.
 * Due to this, the maximum battery voltage this can measure is 10V.
 * The LCD is connected to the arduino as shown in circuit.png.
 */

#include <LiquidCrystal.h>
#include "BatteryTester.h"

LiquidCrystal lcd(2, 3, 9, 10, 11, 12);
const int readingPin = A0;

// Battery tester for a VEX battery. 5V is the absolute lowest voltage it
// can go, while 8.3 V is the highest it can go unloaded.
BatteryTester VEXtester(5.0f, 8.3f);

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

  // Turn the digital reading back into its analog component by doubling it.
  float incomingVoltage = (rawValue / 1024.0) * 5.0;
  float originalVoltage = incomingVoltage * 2;

  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print(originalVoltage);
  lcd.print("V");

  float relativePercent = VEXtester.getPercent(originalVoltage);

  lcd.setCursor(0,0);
  lcd.print(VEXtester.isCharged(originalVoltage) ? "Charged!" : "NotCharged");

  lcd.setCursor(7, 1);
  lcd.print(relativePercent);
  lcd.print("%");

  delay(300);
}
