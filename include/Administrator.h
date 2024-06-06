#pragma  once
#include "main.h"
#include "ParkingLot.h"
#include <fstream>
using namespace stlUtils;


class Administrator {
    private:
        string password;
        vector<ParkingLot> ownedParkingLots;
    public:
        Administrator(const string& password);
        void changePassword();
        void addParkingLot();
        void deleteParkingLot(ParkingLot parkingLotToDelete);
        void nextDay();
        void viewAllEarnings();
        void viewEarnings(ParkingLot parkingLot);
};