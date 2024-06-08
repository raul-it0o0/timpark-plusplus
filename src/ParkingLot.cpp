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

    cout << "[_____ " << this->name << " _____] " << " [__ " << ((float)this->occupation / this->capacity)
    *100 << "% OCCUPIED (" << this->occupation << "/" << this->capacity <<")__]" << endl;

    // Today's earnings
    cout << "- Today's earnings: " << this->earningsOfDay << " RON" << endl;

    // New cars today
    cout << "- " << this->incomingCarsOfDay << " new cars came in today." << endl;

    // Cars that left today
    cout << "- " << this->outgoingCarsOfDay << " cars have left the parking lot today." << endl;

    // Total earnings for past 14 days (value resets every 14 days)
    cout << "- Total earnings for the past ";

    if((DayCounter == 1) || (DayCounter%14 == 1))
        cout << "day: ";
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

unsigned int ParkingLot::getOccupation() {
    return this->occupation;
}

unsigned int ParkingLot::getCapacity() {
    return this->capacity;
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
    this->earningsOfDay += (float)(this->occupation - this->incomingCarsOfDay)*(this->costPerDay);
    this->totalEarnings += earningsOfDay;
}

string ParkingLot::getName() {
    return this->name;
}

void ParkingLot::addCar(const Administrator& admin) {

    cout << flush;
    system("CLS");

    if(this->occupation == this->capacity) {
        cout << "ERROR: Cannot add car; Parking lot is full.\n\n";
        return;
    }

    this->occupation++;
    this->incomingCarsOfDay++;
    cout << "Car added.\n";

    if (this->occupation == this->capacity)
        cout << "NOTICE: Parking lot is now at full capacity.\n";

    cout << endl;

    // New cars pay the first day
    this->earningsOfDay += costPerDay;

    // File update
    // store all entries in adminSession data file, except for (this) parking lot
    string adminFilePath{"../../data/admins/" + admin.getAlias() + ".csv"}, temp;
    ifstream fin(adminFilePath);

    // get header row
    string headerRow;
    getline(fin, headerRow);

    vector<string> names;
    vector<int> occupations, capacities;
    vector<float> costs;

    while(getline(fin, temp,',')) {
        if (temp != this->name) {
            names.push_back(temp);
            getline(fin, temp, ',');
            capacities.push_back(std::stoi(temp));
            getline(fin, temp, ',');
            occupations.push_back(std::stoi(temp));
            getline(fin, temp);
            costs.push_back(stof(temp));
        }
        else
            getline(fin, temp);
        // ignore entry of (this) parking lot in csv
    }

    fin.close();

    // overwrite the file
    ofstream fout(adminFilePath);

    // write header row
    fout << headerRow << endl;

    // write every entry except parkingLot entry
    auto namesIter = names.begin();
    auto capIter = capacities.begin();
    auto occIter = occupations.begin();
    auto costsIter = costs.begin();

    while(namesIter != names.end()) {
        fout << *namesIter << "," << *capIter << "," << *occIter << "," << *costsIter << endl;
        namesIter++;
        capIter++;
        occIter++;
        costsIter++;
    }

    // now append the parkingLot entry along with the new occupation
    fout << this->name << "," << this->capacity << "," << this->occupation << "," << this->costPerDay << endl;

    fout.close();

}

void ParkingLot::removeCar(const Administrator& admin) {

    cout << flush;
    system("CLS");

    if(this->occupation == 0) {
        cout << "ERROR: Parking lot is empty; cannot remove car.\n\n";
        return;
    }

    this->occupation--;
    this->outgoingCarsOfDay++;
    cout << "Removed car\n";

    if (this->occupation == 0)
        cout << "NOTICE: Parking lot is now empty.\n";

    cout << endl;

    // File update
    // store all entries in adminSession data file, except for (this) parking lot
    string adminFilePath{"../../data/admins/" + admin.getAlias() + ".csv"}, temp;
    ifstream fin(adminFilePath);

    // get header row
    string headerRow;
    getline(fin, headerRow);

    vector<string> names;
    vector<int> occupations, capacities;
    vector<float> costs;

    while(getline(fin, temp,',')) {
        if (temp != this->name) {
            names.push_back(temp);
            getline(fin, temp, ',');
            capacities.push_back(std::stoi(temp));
            getline(fin, temp, ',');
            occupations.push_back(std::stoi(temp));
            getline(fin, temp);
            costs.push_back(stof(temp));
        }
        else
            getline(fin, temp);
        // ignore entry of (this) parking lot in csv
    }

    fin.close();

    // overwrite the file
    ofstream fout(adminFilePath);

    // write header row
    fout << headerRow << endl;

    // write every entry except parkingLot entry
    auto namesIter = names.begin();
    auto capIter = capacities.begin();
    auto occIter = occupations.begin();
    auto costsIter = costs.begin();

    while(namesIter != names.end()) {
        fout << *namesIter << "," << *capIter << "," << *occIter << "," << *costsIter << endl;
        namesIter++;
        capIter++;
        occIter++;
        costsIter++;
    }

    // now append the parkingLot entry along with the new occupation
    fout << this->name << "," << this->capacity << "," << this->occupation << "," << this->costPerDay << endl;

    fout.close();
}

void ParkingLot::modifyFees(const Administrator& admin) {

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
    cout << "\n\nChanged parking cost.\n\n";

    // File update
    // store all entries in adminSession data file, except for (this) parking lot
    string adminFilePath{"../../data/admins/" + admin.getAlias() + ".csv"}, temp;
    ifstream fin(adminFilePath);

    // get header row
    string headerRow;
    getline(fin, headerRow);

    vector<string> names;
    vector<int> occupations, capacities;
    vector<float> costs;

    while(getline(fin, temp,',')) {
        if (temp != this->name) {
            names.push_back(temp);
            getline(fin, temp, ',');
            capacities.push_back(std::stoi(temp));
            getline(fin, temp, ',');
            occupations.push_back(std::stoi(temp));
            getline(fin, temp);
            costs.push_back(stof(temp));
        }
        else
            getline(fin, temp);
        // ignore entry of (this) parking lot in csv
    }

    fin.close();

    // overwrite the file
    ofstream fout(adminFilePath);

    // write header row
    fout << headerRow << endl;

    // write every entry except parkingLot entry
    auto namesIter = names.begin();
    auto capIter = capacities.begin();
    auto occIter = occupations.begin();
    auto costsIter = costs.begin();

    while(namesIter != names.end()) {
        fout << *namesIter << "," << *capIter << "," << *occIter << "," << *costsIter << endl;
        namesIter++;
        capIter++;
        occIter++;
        costsIter++;
    }

    // now append the parkingLot entry along with the new cost
    fout << this->name << "," << this->capacity << "," << this->occupation << "," << this->costPerDay << endl;

    fout.close();
}

void ParkingLot::modifyCapacity(const Administrator& admin) {

    int newCapacity;

    cout << flush;
    system("CLS");

    cout << "Enter new capacity: ";
    cin >> newCapacity;

    if (newCapacity < this->occupation) {
        cout << "ERROR: Parking lot occupation greater than capacity." << endl;
        return;
    }

    if (newCapacity == this->occupation) {
        cout << "NOTICE: Parking lot is now at full capacity." << endl;
    }

    this->capacity = newCapacity;

    // File update
    // store all entries in adminSession data file, except for (this) parking lot
    string adminFilePath{"../../data/admins/" + admin.getAlias() + ".csv"}, temp;
    ifstream fin(adminFilePath);

    // get header row
    string headerRow;
    getline(fin, headerRow);

    vector<string> names;
    vector<int> occupations, capacities;
    vector<float> costs;

    while(getline(fin, temp,',')) {
        if (temp != this->name) {
            names.push_back(temp);
            getline(fin, temp, ',');
            capacities.push_back(std::stoi(temp));
            getline(fin, temp, ',');
            occupations.push_back(std::stoi(temp));
            getline(fin, temp);
            costs.push_back(stof(temp));
        }
        else
            getline(fin, temp);
        // ignore entry of (this) parking lot in csv
    }

    fin.close();

    // overwrite the file
    ofstream fout(adminFilePath);

    // write header row
    fout << headerRow << endl;

    // write every entry except parkingLot entry
    auto namesIter = names.begin();
    auto capIter = capacities.begin();
    auto occIter = occupations.begin();
    auto costsIter = costs.begin();

    while(namesIter != names.end()) {
        fout << *namesIter << "," << *capIter << "," << *occIter << "," << *costsIter << endl;
        namesIter++;
        capIter++;
        occIter++;
        costsIter++;
    }

    // now append the parkingLot entry along with the new capacity
    fout << this->name << "," << this->capacity << "," << this->occupation << "," << this->costPerDay << endl;

    fout.close();

    cout << "\nUpdated parking lot capacity.\n\n";
}