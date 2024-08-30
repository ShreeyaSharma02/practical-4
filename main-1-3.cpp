#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include <iostream>
#include <thread>
#include <chrono>

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

    std::cout << "Simulating delay... Please wait for 20 seconds." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(20));

    int overstayingVehicles = lot.countOverstayingVehicles(15);
    std::cout << "Number of vehicles that have overstayed: " << overstayingVehicles << std::endl;

    return 0;
}
