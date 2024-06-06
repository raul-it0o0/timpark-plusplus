#pragma once
#include "main.h"
using namespace stlUtils;

class ParkingLot {
    public:
        string name; // not sure if these 3 should be made private
        unsigned int capacity;
        unsigned int occupation;
        ParkingLot(string name, int capacity, int occupation);
        void modifyCapacity();
        void addCar();
        void removeCar();
        void modifyFees();

    private:
        unsigned long int earnings;
        unsigned long int earningSum; // reset every 14 days
        float costPerDay;
};