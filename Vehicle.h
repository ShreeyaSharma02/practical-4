#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <ctime>

class Vehicle {
protected:
    int id;
    std::string type;
    time_t parkingTime;

public:
    Vehicle(int id, const std::string& type);
    int getId() const;
    std::string getType() const;
    time_t getParkingTime() const;
};

#endif
