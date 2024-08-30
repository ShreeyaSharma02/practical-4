#include <iostream>
#include <ctime>
#include <vector>

class Vehicle {
private:
    std::time_t timeOfEntry;
    int ID;

public:
    Vehicle(int id) : ID(id) {
        timeOfEntry = std::time(nullptr);
    }

    int getID() const {
        return ID;
    }

    virtual int getParkingDuration() const {
        return std::difftime(std::time(nullptr), timeOfEntry);
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int duration = Vehicle::getParkingDuration();
        return duration - (duration * 0.10); 
    }
};

class Bus : public Vehicle {
public:
    Bus(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int duration = Vehicle::getParkingDuration();
        return duration - (duration * 0.25); 
    }
};

class Motorbike : public Vehicle {
public:
    Motorbike(int id) : Vehicle(id) {}

    int getParkingDuration() const override {
        int duration = Vehicle::getParkingDuration();
        return duration - (duration * 0.15); 
    }
};

int main() {
    std::vector<Vehicle*> parkingLot;
    int choice;
    int id = 0;

    while (true) {
        std::cout << "Enter vehicle type (1: Car, 2: Bus, 3: Motorbike, 0: Exit): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        Vehicle* vehicle = nullptr;

        switch (choice) {
            case 1:
                vehicle = new Car(++id);
                break;
            case 2:
                vehicle = new Bus(++id);
                break;
            case 3:
                vehicle = new Motorbike(++id);
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
                continue;
        }

        parkingLot.push_back(vehicle);
    }

    for (auto vehicle : parkingLot) {
        std::cout << "Vehicle ID: " << vehicle->getID() << ", Parking Duration: " << vehicle->getParkingDuration() << " seconds" << std::endl;
        delete vehicle;
    }

    return 0;
}
