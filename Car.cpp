#include "Car.h"

Car::Car(int id) : Vehicle(id) {}

int Car::getParkingDuration() const {
    int duration = Vehicle::getParkingDuration();
    return static_cast<int>(duration * 0.9); // 10% reduction
}
