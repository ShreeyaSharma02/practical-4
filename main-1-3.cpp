#include <iostream>
#include <thread>
#include <chrono>
#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot parkingLot(10); // Parking lot with a capacity of 10 vehicles

    // Park 5 Car objects
    for (int i = 0; i < 5; ++i) {
        parkingLot.parkVehicle(new Car(i + 1));
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate time passing
    }

    // Park 3 Bus objects
    for (int i = 5; i < 8; ++i) {
        parkingLot.parkVehicle(new Bus(i + 1));
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate time passing
    }

    // Park 2 Motorbike objects
    for (int i = 8; i < 10; ++i) {
        parkingLot.parkVehicle(new Motorbike(i + 1));
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate time passing
    }

    // Now let's count the number of overstaying vehicles
    int overstayingVehicles = parkingLot.countOverstayingVehicles(15); // Check for 15 seconds
    std::cout << "Number of vehicles that have overstayed: " << overstayingVehicles << std::endl;

    return 0;
}
