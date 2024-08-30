#include "Motorbike.h"

Motorbike::Motorbike(int id) : Vehicle(id) {}

int Motorbike::getParkingDuration() const {
    int duration = Vehicle::getParkingDuration();
    return static_cast<int>(duration * 0.85); // 15% reduction
}
