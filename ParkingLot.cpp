#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : maxCapacity(capacity) {}

ParkingLot::~ParkingLot() {
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }
}

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (vehicles.size() >= maxCapacity) {
        std::cout << "Parking lot is full!" << std::endl;
        return false;
    }
    vehicles.push_back(vehicle);
    return true;
}

bool ParkingLot::unparkVehicle(int index) {
    if (index < 0 || index >= vehicles.size()) {
        std::cout << "Invalid vehicle index!" << std::endl;
        return false;
    }
    vehicles.erase(vehicles.begin() + index);
    return true;
}

int ParkingLot::getCount() const {
    return vehicles.size();
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) {
    int count = 0;
    for (Vehicle* vehicle : vehicles) {
        if (vehicle->getParkingTime() > maxParkingDuration) {
            count++;
        }
    }
    return count;
}
