#include <iostream>
#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot parkingLot(10);

    for (int i = 0; i < 10; ++i) {
        int type, id;
        std::cout << "Enter vehicle type (1 for Car, 2 for Bus, 3 for Motorbike): ";
        std::cin >> type;
        std::cout << "Enter vehicle ID: ";
        std::cin >> id;

        Vehicle* vehicle = nullptr;
        switch (type) {
            case 1:
                vehicle = new Car(id);
                break;
            case 2:
                vehicle = new Bus(id);
                break;
            case 3:
                vehicle = new Motorbike(id);
                break;
            default:
                std::cout << "Invalid type. Try again.\n";
                --i; 
                continue;
        }
        parkingLot.parkVehicle(vehicle);
    }

    int idToUnpark;
    std::cout << "Enter the ID of the vehicle you want to unpark: ";
    std::cin >> idToUnpark;

    parkingLot.unparkVehicle(idToUnpark);

    return 0;
}
