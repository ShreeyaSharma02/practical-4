#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"
#include <vector>

class ParkingLot {
private:
    int capacity;
    int count;
    std::vector<Vehicle*> vehicles;

public:
    ParkingLot(int maxCapacity);
    int getCount() const;
    void parkVehicle(Vehicle* vehicle);
    void unparkVehicle(int id);
    int countOverstayingVehicles(int maxParkingDuration) const;  
    ~ParkingLot();
};

#endif
