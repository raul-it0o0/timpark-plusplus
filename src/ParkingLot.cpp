#include "../include/ParkingLot.h"
using namespace stlUtils;

ParkingLot::ParkingLot(const string& name,
                       const int& capacity,
                       const int& occupation,
                       const float&costPerDay) {

    this->name = name;
    this->capacity = capacity;
    this->occupation = occupation;
    this->costPerDay = costPerDay;

    this->totalEarnings = 0;
    this->earningsOfDay = 0;
    this->incomingCarsOfDay = 0;
    this->outgoingCarsOfDay = 0;

}

void ParkingLot::printDailyReport() {

    cout << "[_____ " << this->name << " _____]" << endl;

    // Today's earnings
    cout << "- Today's earnings: " << this->earningsOfDay << " RON" << endl;

    // New cars today
    cout << "- " << this->incomingCarsOfDay << " new cars came in today." << endl;

    // Cars that left today
    cout << "- " << this->outgoingCarsOfDay << " cars have left the parking lot today." << endl;

    // Total earnings for past 14 days (value resets every 14 days)
    cout << "- Total earnings for the past ";

    if((DayCounter == 1) || (DayCounter%14 == 1))
        cout << " day: ";
    else if (DayCounter <= 14)
        cout << DayCounter << "days: ";
    else
        cout << DayCounter - 14 << "days: ";

    cout << this->totalEarnings << " RON" << endl;

    cout << endl;

}

double ParkingLot::getTodayEarnings() {
    return this->earningsOfDay;
}
double ParkingLot::getTotalEarnings() {
    return this->totalEarnings;
}

void ParkingLot::resetDailyStats() {

    this->earningsOfDay = 0;
    this->incomingCarsOfDay = 0;
    this->outgoingCarsOfDay = 0;

    if (DayCounter % 14 == 0)
        this->totalEarnings = 0;
}

void ParkingLot::addEarnings() {
    // Calculate earnings from non-new cars and add to total
    this->earningsOfDay += (this->occupation - this->outgoingCarsOfDay)*this->costPerDay;
    this->totalEarnings += earningsOfDay;
}

string ParkingLot::getName() {
    return this->name;
} // not needed i think

void ParkingLot::addCar() {

    cout << flush;
    system("CLS");

    if(this->occupation == this->capacity) {
        cout << "ERROR: Cannot add car; Parking lot is full\n";
        return;
    }

    this->occupation++;
    cout << "Car added.\n";

    if (this->occupation == this->capacity)
        cout << "NOTICE: Parking lot is now at full capacity." << endl;

    // New cars pay the first day
    this->earningsOfDay += costPerDay;

    // file update
}

void ParkingLot::removeCar() {

    cout << flush;
    system("CLS");

    if(this->occupation == 0) {
        cout << "ERROR: Parking lot is empty; cannot remove car";
        return;
    }

    this->occupation--;
    cout << "Removed car\n";

    if (this->occupation == 0)
        cout << "NOTICE: Parking lot is now empty." << endl;

    // file update
}

void ParkingLot::modifyFees() {

    float newCost;

    cout << flush;
    system("CLS");

    cout << "Enter new parking cost per day: ";
    cin >> newCost;

    while (newCost <= 0) {
        cout << "Parking cannot be free or < 0!" << endl;
        cout << "Enter new parking cost per day: ";
        cin >> newCost;
    }

    this->costPerDay = newCost;
    cout << "Changed parking cost.\n";

    // file update
}

void ParkingLot::modifyCapacity(int newCapacity) {
    if (newCapacity < this->occupation) {
        cout << "ERROR: Parking lot occupation greater than capacity." << endl;
        return;
    }

    if (newCapacity == this->occupation) {
        cout << "NOTICE: Parking lot is now at full capacity." << endl;
    }

    this->capacity = newCapacity;
}