#include <iostream>
#include <ostream>
#include <lsm9ds0.h>
#include <time.h>

using namespace std;


using namespace upm;


LSM9DS0 motionSensor;

struct Vector {
	float x;
	float y;
	float z;
};

struct MotionReading
{
	Vector accelReading;
	Vector gyroReading;
	Vector magReading;
	float temperature;
	tm time;
};

inline std::ostream& operator<< (std::ostream& stream,  const MotionReading& m) {

	stream << "{ "
			<< "   mag:  { x:" << m.magReading.x   << ", y:" << m.magReading.y   << ", z:" << m.magReading.z  << "},"
			<< "   gyro: { x:" << m.gyroReading.x  << ", y:" << m.gyroReading.y  << ", z:" << m.gyroReading.z << "},"
			<< "   accel:{ x:" << m.accelReading.x << ", y:" << m.accelReading.y << ", z:" << m.gyroReading.z << "},"
			<< "   temp:" <<  m.temperature
			<< "   time:" << time
			<< "}";
	return stream;
}


int main() {
  /* Setup your example here, code that should run once
   */

	MotionReading reading;
	motionSensor.init();

  /* Code in this loop will run repeatedly
   */
  for (;;) {


	  motionSensor.update();
	  motionSensor.getMagnetometer(&reading.magReading.x, &reading.magReading.y, &reading.magReading.z);
	  motionSensor.getAccelerometer(&reading.accelReading.x, &reading.accelReading.y, &reading.accelReading.z);
	  motionSensor.getGyroscope(&reading.gyroReading.x, &reading.gyroReading.y, &reading.gyroReading.z);
	  reading.temperature = motionSensor.getTemperature();
	  time_t currentTime;
	  time(&currentTime);
	  reading.time = localtime(&currentTime);

	  cout << reading << endl;
  }

  return 0;
}
