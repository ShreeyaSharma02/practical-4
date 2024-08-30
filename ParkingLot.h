#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include <vector>
#include "Vehicle.h"

class ParkingLot {
private:
    std::vector<Vehicle*> vehicles;
    int maxCapacity;

public:
    ParkingLot(int capacity);
    ~ParkingLot();
    bool parkVehicle(Vehicle* vehicle);
    bool unparkVehicle(int index);
    int getCount() const;
    int countOverstayingVehicles(int maxParkingDuration);  // Add this line
};

#endif
