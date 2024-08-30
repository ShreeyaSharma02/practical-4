#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int maxCapacity) : maxCapacity(maxCapacity) {}

ParkingLot::~ParkingLot() {
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }
}

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (vehicles.size() >= maxCapacity) {
        std::cout << "The lot is full" << std::endl;
        return false;
    }
    vehicles.push_back(vehicle);
    return true;
}

bool ParkingLot::unparkVehicle(int id) {
    for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            vehicles.erase(it);
            return true;
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
    return false;
}

int ParkingLot::getCount() const {
    return vehicles.size();
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int count = 0;
    time_t currentTime = std::time(0);

    for (const Vehicle* vehicle : vehicles) {
        if (difftime(currentTime, vehicle->getParkingTime()) > maxParkingDuration) {
            count++;
        }
    }

    return count;
}
