#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"
#include <vector>

class ParkingLot {
private:
    int maxCapacity;
    std::vector<Vehicle*> vehicles;

public:
    ParkingLot(int maxCapacity);
    ~ParkingLot();
    bool parkVehicle(Vehicle* vehicle);
    bool unparkVehicle(int id);
    int getCount() const;
    int countOverstayingVehicles(int maxParkingDuration) const;
};

#endif
