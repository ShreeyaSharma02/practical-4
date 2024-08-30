// Vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H

#include <ctime>

class Vehicle {
private:
    int id;
    std::time_t parkingTime;

public:
    Vehicle(int id); // Constructor with integer parameter
    int getId() const;
    std::time_t getParkingTime() const;
};

#endif
