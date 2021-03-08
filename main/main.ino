/*
 * Essentially, this is voltmeter that measures voltages against a known *
 * discharge curve to find a rough estimate of a battery's remaining battery *
 * life.
 *
 * The circuit consists of a voltage divider with a 1 : 1 ratio of
 * resistors, with the output connected to the A0 analog pin of the Arduino. Due
 * to this, the maximum battery voltage this can measure is 10V, though higher
 * voltages are possible (at the cost of precision) if you tweak the ratio. The
 * LCD is connected to the arduino as shown in circuit.png.
 */

#include <LiquidCrystal.h>
#include "VEXBatteryTester.h"

LiquidCrystal lcd (2, 3, 9, 10, 11, 12);

void setup() {
  // This is the startup screen
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Welcome to Diego");
  lcd.setCursor(0, 1);
  lcd.print("\'s batt tester!");
  delay(3000);
  lcd.clear();
}

void loop() {
  const int readingPin = A0;
  BatteryTester* batteryTester = new VEXBatteryTester();
  int rawValue = analogRead(readingPin);

  // Turn the digital reading back into its analog component by doubling it.
  float incomingVoltage = (rawValue / 1024.0) * 5.0;
  float originalVoltage = incomingVoltage * 2;

  lcd.clear();
  lcd.setCursor(0, 1);

  // Voltages below this threshold aren't useful
  if(originalVoltage < batteryTester->getLowerBound()) {
    lcd.print("???");
    lcd.print("V");

    lcd.setCursor(0,0);
    lcd.print("INPUT BATTERY");

    lcd.setCursor(7, 1);
    lcd.print("???");
    lcd.print("%");
  }
  else {
    lcd.print(originalVoltage);
    lcd.print("V");

    float relativePercent = batteryTester->getPercent(originalVoltage) * 100;

    lcd.setCursor(0,0);
    lcd.print(batteryTester->isFull(originalVoltage) ? "Full!" : "Needs Juice");

    lcd.setCursor(7, 1);
    if(originalVoltage > batteryTester->getUpperBound()){
      lcd.print("100");
    }
    else {
      lcd.print(relativePercent);
    }
    lcd.print("%");
  }

  delay(300);
}
