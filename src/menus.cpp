#include "../include/menus.h"
#include "../include/print.h"
using namespace stlUtils;

int mainMenu() {

    cout << flush;
    system("CLS");
    cout << "Welcome to TimPark++\n";
    cout << "Choose an option below [1-3]: \n";
    cout << "[1] ADMIN LOGIN\n";
    cout << "[2] NEW ADMIN\n";  
    cout << "[3] EXIT\n";
    cout << endl;

    int option;
    cin >> option;
//  not sure about the condition for the exception if this is implemented using unsigned char.

    while((option != 1) && (option != 2) && (option != 3))  {
        cout << "Please choose a valid option [1-3]. ";
        cin >> option;
    }

    return option;

}

int adminAuthMenu(string& adminAlias, string& adminPassword) {

    bool retryInput = false;

    do {
    
    cout << "Enter admin alias: ";

    cin >> adminAlias;

    cout << "Enter admin password: ";

    cin >> adminPassword;

    if(!adminCorrectPassword(adminAlias, adminPassword)) {
        cout << "Wrong alias or password! Choose an option [1-4]:\n";
        cout << "[1] TRY AGAIN\n";
        cout << "[2] NEW ADMIN\n";
        cout << "[3] BACK TO MAIN MENU\n";
        cout << "[4] EXIT\n";
        cout << endl;

        switch(getMenuInput()) {
            case 1:
                retryInput = true;
                break;
            case 2:
                // new admin request, append to csv file
                return 1; 
            case 3:
                return -1;
            case 4:
                return -2;
        }
    }

    }while(retryInput);

    // admin logged in successfully
    return 0; 
    
}

int getNewAdminCredentials(string& alias, string& password) {

    string temp;
    bool passwordValidated = false;

    cout << "Enter admin alias: ";

//     while(aliasTaken())

    cin >> alias;

    do {

        cout << "Enter admin password: ";

        cin >> password;

        cout << "Confirm password (retype): ";

        cin >> temp;

        // maybe add option to go back to main menu

        if (password == temp)
            passwordValidated = true;

    } while(!passwordValidated);

    return 0;

}

int adminPanel(const string& alias, const string& password) {

    Administrator sessionAdmin(alias, password);
    string temp; // not useful for anything, only used for cin
    bool reprintMenu = true;
    bool validatedInput = true;

    do {
        cout<<flush;
        system("CLS");

        cout << "Logged in as: " << alias << endl;
        cout << "Choose an option below [1-6]: \n\n";

        cout << "[1] MANAGE PARKING LOT(S)\n";
        cout << "[2] DECLARE NEW DAY\n";
        cout << "[3] CREATE NEW PARKING LOT\n\n";

        cout << "[4] CHANGE PASSWORD\n";

        cout << "[5] BACK TO MAIN MENU (LOGOUT)\n";
        cout << "[6] EXIT\n\n";

        int option;
        cin >> option;

        do {
            switch(option) {
                case 1:
                    if(sessionAdmin.ownedParkingLots.empty()) {
                        cout << "You have no parking lots to manage.\n";
                        cout << "Type any character to continue. ";
                        cin >> temp;
                        reprintMenu = true;
                    }
                    else {
                        parkingLotPanel(sessionAdmin);
                        reprintMenu = true;
                    }
                    break;

                case 2:
                    sessionAdmin.nextDay();
                    cout << "Type any character to continue. ";
                    cin >> temp;
                    reprintMenu = true;
                    break;

                case 3:
                    sessionAdmin.addNewParkingLotPanel();
                    cout << "Type any character to continue. ";
                    cin >> temp;
                    reprintMenu = true;
                    break;

                case 4:
                    sessionAdmin.changePassword();
                    cout << "Type any character to continue. ";
                    cin >> temp;
                    reprintMenu = true;
                    break;

                case 5:
                    return -1;

                case 6:
                    return -2;

                default:
                    validatedInput = false;
                    cout << "Please choose a valid option [1-5]. ";
                    cin >> option;
                    break;
            }
        }while(!validatedInput);
    }while(reprintMenu);

    return 0;

}

void parkingLotPanel(Administrator& sessionAdmin) {

    bool reprintMenu = false;

    do {
        cout << flush;
        system("CLS");

        cout << "Choose an option below [1-" << sessionAdmin.ownedParkingLots.size() + 2 << "]: \n\n";

        printParkingLotList(sessionAdmin);

        cout << "[" << sessionAdmin.ownedParkingLots.size() + 1 << "] ADD NEW PARKING LOT\n";

        cout << "[" << sessionAdmin.ownedParkingLots.size() + 2 << "] BACK TO ADMIN PANEL\n\n";

        string input;
        cin >> input;
        int option = stoi(input);
        bool validatedInput = true;

        do {
            if (option == sessionAdmin.ownedParkingLots.size() + 1) {
                sessionAdmin.addNewParkingLotPanel();
                reprintMenu = true;
            }

            else if (option == sessionAdmin.ownedParkingLots.size() + 2)
                return;

            else if ((1 <= option) && (option <= sessionAdmin.ownedParkingLots.size())) {
                sessionAdmin.manageParkingLotMenu(sessionAdmin.ownedParkingLots[option - 1]);
                reprintMenu = true;
            }

            else {
                validatedInput = false;
                cout << "Please choose a valid option [1-" << sessionAdmin.ownedParkingLots.size() + 3
                     << "]. ";
                cin >> input;
                option = stoi(input);
            }
        } while(!validatedInput);
    } while(reprintMenu);



}
