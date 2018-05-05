#include "../include/weather_station.h"
#include <iostream>
#include <string.h>
namespace csce240 {
const int DATA_LENGTH = 4;
const int TYPE_OFFSET = 5;
const int TYPE_LENGTH = 3;
int HUM_IDX = 0;
int PRS_IDX = 0;
int TMP_IDX = 0;
int IndexOfSensor(std::string sensor);
WeatherStation::WeatherStation() {
	SensorNet::PowerOn();
	HUM_IDX = IndexOfSensor("HUM");
	PRS_IDX = IndexOfSensor("PRS");
	TMP_IDX = IndexOfSensor("TMP");
}
WeatherStation::~WeatherStation() {
	SensorNet::PowerOff();
}

double WeatherStation::GetHumidity() const {
	int size = 0;

	char *data = new char[0]();

	SensorNet::ReadSensor(HUM_IDX, &size, data);
	char type[DATA_LENGTH + 1];
	memcpy(type, data, DATA_LENGTH);

	delete data;

	type[4] = '\0';
	int result = atoi(type);
	return result / 100.0;
}
double WeatherStation::GetPressure() const {
	int size = 0;

	char *data = new char[0]();

	SensorNet::ReadSensor(PRS_IDX, &size, data);
	char type[DATA_LENGTH + 2];

	memcpy(type, data, DATA_LENGTH / 2);
	memcpy(type + 3, data + 2, DATA_LENGTH);
	type[2] = '.';

	delete data;

	//type[4] = '\0';

	double dec = std::stod(type);
	return dec;
}
double WeatherStation::GetTemperature() const {

	int size = 0;

	char *data = new char[0]();

	SensorNet::ReadSensor(TMP_IDX, &size, data);
	char type[DATA_LENGTH + 2];

	memcpy(type, data, DATA_LENGTH / 2);
	memcpy(type + 3, data + 2, DATA_LENGTH);
	type[2] = '.';
	delete data;

	double dec = std::stod(type);
	return dec;
}
int IndexOfSensor(std::string sensor) {
	for (int i = 0; i < 3; i++) {
		int size = 0;

		char *data = new char[0]();

		SensorNet::ReadSensor(i, &size, data);
		char type[TYPE_LENGTH + 1];
		memcpy(type, data + TYPE_OFFSET, TYPE_LENGTH);

		delete data;

		type[3] = '\0';
		std::string t(type);
		if (sensor == t) {
			return i;
		}

	}

	return -1;

}
}

