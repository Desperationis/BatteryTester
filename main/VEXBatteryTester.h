#include "BatteryTester.h"

class VEXBatteryTester : public BatteryTester {
public:
    VEXBatteryTester() = default;

    float getPercent(float voltage) override {
      // Get an aproximate % based on a known discharge curve. The formula used below
      // is from polynomial regression.

      voltage = voltage * 1000; // Formula only accepts millivolts

      long double x0 = 26570343.396815643;
      long double x1 = 9934.2416505093006;
      long double x2 = 1.2385048871889726;
      long double x3 = .000051484120651006659;

      return (31551.8 - (x0 - (x1*voltage) + (x2*pow(voltage,2)) - (x3*pow(voltage,3)))) / 31551.8;
    };

    float getLowerBound() override {
      return 7.2f;
    }

    float getUpperBound() override {
      return 8.2f;
    }
};
