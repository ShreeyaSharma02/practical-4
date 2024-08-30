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

class ParkingLot {
private:
    Vehicle** vehicles;
    int capacity;
    int count;

public:
    ParkingLot(int cap) : capacity(cap), count(0) {
        vehicles = new Vehicle*[capacity];
        for (int i = 0; i < capacity; ++i) {
            vehicles[i] = nullptr;
        }
    }

    ~ParkingLot() {
        for (int i = 0; i < capacity; ++i) {
            if (vehicles[i] != nullptr) {
                delete vehicles[i];
            }
        }
        delete[] vehicles;
    }

    int getCount() const {
        return count;
    }

    void parkVehicle(Vehicle* v) {
        if (count < capacity) {
            vehicles[count++] = v;
            std::cout << "Vehicle parked." << std::endl;
        } else {
            std::cout << "The lot is full." << std::endl;
            delete v;
        }
    }

    void unparkVehicle(int id) {
        for (int i = 0; i < count; ++i) {
            if (vehicles[i] && vehicles[i]->getID() == id) {
                delete vehicles[i];
                vehicles[i] = vehicles[--count];
                vehicles[count] = nullptr;
                std::cout << "Vehicle removed from the lot." << std::endl;
                return;
            }
        }
        std::cout << "Vehicle not in the lot." << std::endl;
    }
};

int main() {
    ParkingLot lot(10);  
    int choice, id = 0;

    while (true) {
        std::cout << "Enter vehicle type to park (1: Car, 2: Bus, 3: Motorbike, 0: Exit): ";
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

        lot.parkVehicle(vehicle);
    }

    while (true) {
        std::cout << "Enter vehicle ID to unpark (0 to exit): ";
        std::cin >> id;

        if (id == 0) {
            break;
        }

        lot.unparkVehicle(id);
    }

    return 0;
}
