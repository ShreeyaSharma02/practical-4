#include "Bus.h"

Bus::Bus(int id) : Vehicle(id) {}

int Bus::getParkingDuration() const {
    int duration = Vehicle::getParkingDuration();
    return static_cast<int>(duration * 0.75); // 25% reduction
}
