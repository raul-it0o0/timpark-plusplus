#include "../include/Administrator.h"
using namespace stlUtils;
namespace fs = std::filesystem;

Administrator::Administrator(const string& alias, const string& password) {

    this->alias = alias;
    this->password = password;
    this->totalEarnings = 0;
    this->todayEarnings = 0;

    // go through file
    // Determine if admin is new or not; if he/she has a parking lot data file
    bool newAdmin = true;
    fs::path currentPath = "../../data/admins";
    string adminFileName = string{alias + ".csv"};

    for (const auto& adminFile : fs::recursive_directory_iterator(currentPath))
        if (adminFile.path().filename() == adminFileName) {
            newAdmin = false;
            break;
        }

    string adminFilePath = currentPath.generic_string() + "/" + adminFileName;

    if (newAdmin) {
        ofstream fout(adminFilePath);
        // create data file

        // write header row
        fout << "ParkingLotName,Capacity,Occupation,CostPerDay" << endl;

        fout.close();
    }

    else {
        // parse data file and create parking lot objects
        ifstream fin(adminFilePath);

        string temp, name;
        int capacity, occupation;
        float costPerDay;


        // ignore header row
        getline(fin, temp);
        getline(fin, temp);

        while(!fin.eof()) {
            getline(fin, temp, ',');
            name = temp;

            getline(fin, temp, ',');
            capacity = stoi(temp);

            getline(fin, temp, ',');
            occupation = stoi(temp);

            // finally, read until newline \n
            getline(fin, temp);
            costPerDay = stof(temp);

            this->addParkingLot(name, capacity, occupation, costPerDay);
            // create object and pushback
        }

        fin.close();

    }

}

void Administrator::addParkingLot(const string &name,
                                  const int &capacity,
                                  const int &occupation,
                                  const float &costPerDay) {

    ParkingLot newParkingLot{name, capacity, occupation, costPerDay};
    this->ownedParkingLots.push_back(newParkingLot);

    // File update

}

void Administrator::nextDay() {

    cout << flush;
    system("CLS");
    // Print today's report for each parking lot object
    if (this->ownedParkingLots.empty()) {
        cout << "No parking lots to generate reports for.\n";
        this->printGeneralStats();
        this->resetDailyStats();
        DayCounter++;
        return;
    }

    cout << "Reports for the " << this->ownedParkingLots.size() << " owned parking lots:\n\n";
    for (auto& parkingLot : this->ownedParkingLots) {
        parkingLot.addEarnings();
        parkingLot.printDailyReport();
    }
    cout << endl;

    this->addEarnings();
    this->printGeneralStats();

    cout << endl;

    for (auto& parkingLot : this->ownedParkingLots)
        parkingLot.resetDailyStats();

    this->resetDailyStats();

    DayCounter++;
}

void Administrator::deleteParkingLot(ParkingLot& parkingLotToDelete) {

    cout << flush;
    system("CLS");

    // find index of parking lot in vector
    int i;

    for (i = 0; i < this->ownedParkingLots.size(); i++)
        if (this->ownedParkingLots[i].getName() == parkingLotToDelete.getName())
            break;

    // erase (remove) parking lot object from vector
    this->ownedParkingLots.erase(this->ownedParkingLots.begin()+i);

    cout << "Deleted parking lot.\n";

    // File update (using i?)
}

void Administrator::printGeneralStats() {
    cout << "General day report:\n";
    cout << "- Total earnings today: " << this->totalEarnings << endl;
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

void Administrator::addEarnings() {

    for (auto& parkingLot : this->ownedParkingLots)
        this->todayEarnings += parkingLot.getTodayEarnings();

    this->totalEarnings += this->todayEarnings;

}

void Administrator::resetDailyStats() {

    this->todayEarnings = 0;

    if (DayCounter % 14 == 0)
        this->totalEarnings = 0;

}

void Administrator::addNewParkingLotPanel() {

    cout << flush;
    system("CLS");

    char answer;
    string name;
    int capacity, occupation;
    float costPerDay;

    cout << "Enter new parking lot name: ";
    cin >> name;

    while(this->nameTaken(name)) {
        cout << "This parking lot name is taken.\n";
        cout << "Enter another name: ";
        cin >> name;
    }

    cout << "Enter parking lot capacity: ";
    cin >> capacity;

    while(capacity <= 0) {
        cout << "Parking lot must have capacity for at least one car.\n";
        cout << "Enter parking lot capacity: ";
        cin >> capacity;
    }

    cout << "Are there cars in the parking lot? [Y/N]: ";
    cin >> answer;

    if (answer == 'Y') {
        cout << "Enter the number of cars in the parking lot: ";
        cin >> occupation;

        while(occupation <= 0) {
            cout << "Enter a number > 0 ." << endl;
            cout << "Enter the number of cars in the parking lot: ";
            cin >> occupation;
        }
    }
    else {
        occupation = 0;
    }

    cout << "Enter the parking cost per day: ";
    cin >> costPerDay;

    while(costPerDay <= 0) {
        cout << "Parking cannot be free or < 0!" << endl;
        cout << "Enter the parking cost per day: ";
        cin >> costPerDay;
    }

    this->addParkingLot(name, capacity, occupation, costPerDay);

    cout << "Added parking lot.\n";

}

bool Administrator::nameTaken(const string &name) {
    for (auto parkingLot : this->ownedParkingLots)
        if (parkingLot.getName() == name)
            return true;

    return false;
}

void Administrator::manageParkingLotMenu(ParkingLot &parkingLot) {

    bool reprintMenu = false;

    do {
        cout << flush;
        system("CLS");

        cout << "Parking lot: " << parkingLot.getName() << endl << endl;
        cout << "Choose an option below [1-5]:\n\n";

        cout << "[1] ADD CAR\n";
        cout << "[2] REMOVE CAR\n";
        cout << "[3] CHANGE PARKING COST\n\n";

        cout << "[4] DELETE THIS PARKING LOT\n";
        cout << "[5] BACK TO MAIN MENU\n\n";

        string input;
        cin >> input;
        int option = stoi(input);
        bool validatedInput = true;

        do {
            switch (option) {
                case 1:
                    parkingLot.addCar();
                    cout << " Type any character to continue. ";
                    cin >> input;
                    reprintMenu = true;
                    break;
                case 2:
                    parkingLot.removeCar();
                    cout << " Type any character to continue. ";
                    cin >> input;
                    reprintMenu = true;
                    break;
                case 3:
                    parkingLot.modifyFees();
                    cout << " Type any character to continue. ";
                    cin >> input;
                    reprintMenu = true;
                    break;
                case 4:
                    this->deleteParkingLot(parkingLot);
                    cout << " Type any character to continue. ";
                    cin >> input;
                    return;
                case 5:
                    return;
                default:
                    validatedInput = false;
                    cout << "Please choose a valid option [1-5]. ";
                    cin >> input;
                    option = stoi(input);
                    break;
            }
        }while(!validatedInput);
    }while(reprintMenu);

}

void Administrator::changePassword() {
    cout << flush;
    system("CLS");

    string newPassword, temp;
    bool passwordValidated = true;

    do {

        cout << "Enter admin password: ";

        cin >> newPassword;

        cout << "Confirm password (retype): ";

        cin >> temp;

        // maybe add option to go back to main menu

        if (newPassword != temp) {
            cout << "The two passwords must match. Try again\n";
            passwordValidated = false;
        }
        else
            passwordValidated = true;

    } while(!passwordValidated);

    cout << "Password changed.\n";

}

