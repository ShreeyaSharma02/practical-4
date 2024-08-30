#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    int numVehicles;
    std::cout << "Enter the number of vehicles: ";
    std::cin >> numVehicles;

    std::vector<Vehicle*> parkingLot;

    for (int i = 0; i < numVehicles; ++i) {
        int type, id;
        std::cout << "Enter vehicle type (1 for Car, 2 for Bus, 3 for Motorbike): ";
        std::cin >> type;
        std::cout << "Enter vehicle ID: ";
        std::cin >> id;

        switch (type) {
        case 1:
            parkingLot.push_back(new Car(id));
            break;
        case 2:
            parkingLot.push_back(new Bus(id));
            break;
        case 3:
            parkingLot.push_back(new Motorbike(id));
            break;
        default:
            std::cout << "Invalid type. Try again.\n";
            --i; 
            break;
        }
    }

    std::cout << "\nParking durations:\n";
    for (auto vehicle : parkingLot) {
        std::cout << "Vehicle ID: " << vehicle->getID() 
                  << ", Duration (seconds): " << vehicle->getParkingDuration() << "\n";
    }

    for (auto vehicle : parkingLot) {
        delete vehicle;
    }

    return 0;
}
