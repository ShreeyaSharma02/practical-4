#include <iostream>
#include <ctime>
#include <vector>
#include <thread> 
#include <chrono> 

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
                return;
            }
        }
        std::cout << "Vehicle not in the lot." << std::endl;
    }

    int countOverstayingVehicles(int maxParkingDuration) {
        int overstayingCount = 0;
        for (int i = 0; i < count; ++i) {
            if (vehicles[i]->getParkingDuration() > maxParkingDuration) {
                overstayingCount++;
            }
        }
        return overstayingCount;
    }
};

int main() {
    ParkingLot lot(10);
    int choice, id = 0;

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
