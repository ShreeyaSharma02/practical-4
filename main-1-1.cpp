#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include <iostream>

int main() {
    ParkingLot lot(10);
    int id = 0;

    for (int i = 0; i < 10; ++i) {
        if (i < 5) {
            lot.parkVehicle(new Car(++id));
        } else if (i < 8) {
            lot.parkVehicle(new Bus(++id));
        } else {
            lot.parkVehicle(new Motorbike(++id));
        }
    }

    std::cout << "Total number of vehicles in the parking lot: " << lot.getCount() << std::endl;

    std::cout << "Enter vehicle ID to unpark: ";
    int unparkId;
    std::cin >> unparkId;
    lot.unparkVehicle(unparkId);

    std::cout << "Total number of vehicles in the parking lot after unparking: " << lot.getCount() << std::endl;

    return 0;
}
