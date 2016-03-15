#include <iostream>
#include <lsm9ds0.h>
using namespace std;


using namespace upm;


LSM9DS0 motionSensor;

struct Vector {
	float x;
	float y;
	float z;
};


int main() {
  /* Setup your example here, code that should run once
   */

	motionSensor.init();

  /* Code in this loop will run repeatedly
   */
  for (;;) {
	  Vector magReading, accelReading, gyroReading;

	  motionSensor.update();
	  motionSensor.getMagnetometer(&magReading.x, &magReading.y, &magReading.z);
	  motionSensor.getAccelerometer(&accelReading.x, &accelReading.y, &accelReading.z);
	  motionSensor.getGyroscope(&gyroReading.x, &gyroReading.y, &gyroReading.z);
  }

  return 0;
}
