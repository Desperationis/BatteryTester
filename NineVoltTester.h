/**
 * Takes in the voltage of a 9V battery and compares it to a known function
 * of its discharge curve.
 */
class NineVoltTester {
public:
  NineVoltTester() = default;

  static float CalculatePercent(float voltage) {
    //return (voltage - 5.4) / (9.6 - 5.4) * 100;
    return -((voltage + 1.5) / 7.143f) + (8.714 / 7.142);
  };
  
  static bool IsGood(float voltage) {
    return CalculatePercent(voltage) > 90.0;
  };
};
