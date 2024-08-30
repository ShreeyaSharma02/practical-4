#include "Vehicle.h"

Vehicle::Vehicle(int id, const std::string& type) : id(id), type(type) {
    parkingTime = std::time(0);
}

int Vehicle::getId() const {
    return id;
}

std::string Vehicle::getType() const {
    return type;
}

time_t Vehicle::getParkingTime() const {
    return parkingTime;
}
