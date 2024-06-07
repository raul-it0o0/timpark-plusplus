#pragma once
#include "main.h"
#include "ParkingLot.h"
#include <filesystem>
#include <format>
#include <fstream>
using namespace stlUtils;


class Administrator {
    private:
        string alias;
        string password;
        double totalEarnings;
        double todayEarnings;

    public:
        vector<ParkingLot> ownedParkingLots;
        Administrator(const string& alias, const string& password);
        void changePassword();
        void manageParkingLotMenu(ParkingLot& parkingLot);
        void addParkingLot(const string& name,
                           const int& capacity,
                           const int& occupation,
                           const float&costPerDay);
        void deleteParkingLot(ParkingLot& parkingLotToDelete);
        void nextDay();

        bool nameTaken(const string& name);

        void printGeneralStats();
        void addEarnings();
        void resetDailyStats();

        void addNewParkingLotPanel();
        void manageParkingLotMenu();

};