

class BatteryTester {
public:
  BatteryTester(float lowerBound, float upperBound) {
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
  }

  float getPercent(float voltage) {
    return ((voltage - lowerBound) / (upperBound - lowerBound)) * 100.0f;
  };
  
  bool isCharged(float voltage) {
    return getPercent(voltage) > 95.0;
  };

private:
  float lowerBound = 0.0f;
  float upperBound = 1.0f;
};
