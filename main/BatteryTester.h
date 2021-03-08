

class BatteryTester {
public:
  BatteryTester() = default;

  virtual float getPercent(float voltage) = 0;

  virtual bool isFull(float voltage) {
    return getPercent(voltage) > .90; // Arbitrary
  };

  virtual float getLowerBound() {
    return 0.0f;
  }

  virtual float getUpperBound() {
    return 10.0f;
  }
};
