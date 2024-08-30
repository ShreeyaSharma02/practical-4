// Vehicle.cpp
#include "Vehicle.h"

Vehicle::Vehicle(int id) : id(id), parkingTime(std::time(nullptr)) {}

int Vehicle::getId() const {
    return id;
}

std::time_t Vehicle::getParkingTime() const {
    return parkingTime;
}
