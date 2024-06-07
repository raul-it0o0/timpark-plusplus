#include "../include/print.h"
using namespace stlUtils;

void printParkingLotList(Administrator& sessionAdmin) {

    int list_counter = 1;

    for (auto parkingLot : sessionAdmin.ownedParkingLots) {
        cout << "[" << list_counter << "] " << parkingLot.getName() << endl;
        list_counter++;
    }
    cout << endl;
}
