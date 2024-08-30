#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int maxCapacity) : capacity(maxCapacity), count(0) {
    vehicles.reserve(maxCapacity);
}

int ParkingLot::getCount() const {
    return count;
}

void ParkingLot::parkVehicle(Vehicle* vehicle) {
    if (count < capacity) {
        vehicles.push_back(vehicle);
        count++;
    } else {
        std::cout << "The lot is full" << std::endl; 
    }
}

void ParkingLot::unparkVehicle(int id) {
    for (size_t i = 0; i < vehicles.size(); ++i) {
        if (vehicles[i]->getID() == id) {
            vehicles.erase(vehicles.begin() + i);
            count--;
            return;
        }
    }
    std::cout << "Vehicle not in the lot" << std::endl;
}

int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
    int overstayingCount = 0;
    for (const auto& vehicle : vehicles) {
        if (vehicle->getParkingDuration() > maxParkingDuration) {
            overstayingCount++;
        }
    }
    return overstayingCount;
}

ParkingLot::~ParkingLot() {
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }
}
