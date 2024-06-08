#pragma once
#include "main.h"
#include "Administrator.h"
using namespace stlUtils;

class Administrator;

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

    public:
        ParkingLot(const string& name,
                   const int& capacity,
                   const int& occupation,
                   const float& costPerDay);
        string getName();

        void modifyCapacity(const Administrator& admin);
        void addCar(const Administrator& admin);
        void removeCar(const Administrator& admin);
        void modifyFees(const Administrator& admin);

        double getTodayEarnings();
        double getTotalEarnings();
        unsigned int getCapacity();
        unsigned int getOccupation();

        void printDailyReport();
        void addEarnings();
        void resetDailyStats();
};