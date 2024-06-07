#pragma once
#include "main.h"
using namespace stlUtils;

class ParkingLot {
    private:
        string name;
        unsigned int capacity;
        unsigned int occupation;
        float costPerDay;
        
        double totalEarnings; // reset every 14 days
        double earningsOfDay;
        unsigned int incomingCarsOfDay;
        unsigned int outgoingCarsOfDay;
//        NO PAYING ON LAST DAY OF PARKING!

    public:
        ParkingLot(const string& name,
                   const int& capacity,
                   const int& occupation,
                   const float& costPerDay);
        string getName();

        void modifyCapacity(int newCapacity);
        void addCar();
        void removeCar();
        void modifyFees();

        double getTodayEarnings();
        double getTotalEarnings();

        void printDailyReport();
        void addEarnings();
        void resetDailyStats();
};