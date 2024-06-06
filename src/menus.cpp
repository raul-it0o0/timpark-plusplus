#include "../include/menus.h"
// #include "../include/handlers.h"
using namespace stlUtils;

int mainMenu() {

    cout << flush;
    system("CLS");
    cout << "Welcome to TimPark++\n";
    cout << "Choose an option below [1-3]: \n";
    cout << "[1] ADMIN LOGIN\n";
    cout << "[2] USER LOGIN\n"; // not implemented :)
    cout << "[3] EXIT\n";
    cout << endl;

    int option;
    cin >> option;
//  not sure about the condition for the exception if this is implemented using unsigned char.

    while(option != 1 && option != 2 && option != 3) {
        cout << "Please choose a valid option [1-3]. ";
        cin >> option;
    }

    return option;

}

int adminAuthMenu() {

    string adminAlias, adminPassword;

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

// void adminAuthMenuOLD(int& returnFlag) {



//     string adminAlias;
//     char continuationInput = "";

//     switch(getAdminInput()) {
//         case 0:
//             returnFlag = 0; // success in admin auth, go to main and then go to admin panel (menu)
//         case 1:
//             returnFlag = 1; // user requested new admin account
//         case -1:
//             returnFlag = -1; // user requested exit
//     }
//     // function that receives input, throws and catches exceptions
//     // catcher:
//     // - try again
//     // - create new account
//     // - exit program
//     // "if you forgot password, contact technical support"
//     // and returns a flag that indicates success or user wish to exit

//     while (true) {
//         try
//         {
//             cin >> adminAlias;
//             if (!foundAdminAliasMatch(adminAlias))
//                 throw string{"AdminAliasNotFoundError"};
            
//         }
//         catch(const string& errorName)
//         {
//             std::cerr << e.what() << '\n';
//         }
        
//     }

//     cout << "Enter admin alias: ";

//     cin >> adminAlias;

//     while ((!adminAliasMatchFound(adminAlias)) && (continuationInput == 'Y')) {
//         cout << "No such admin alias found. Type Y to try again. ";
//         cin >> continuationInput;
//     }

//     if (!adminAliasMatchFound(adminAlias)) {
        
//         cout << "No such admin alias found. Type Y to try again. ";  

//         cin >> continuationInput;

        
//     }

//     try {
//         cin >> adminAlias;

//         if(!adminAliasMatchFound(adminAlias))
//             throw 2;
//     }

//     catch (int errorNum) {
//         handleError(errorNum, adminAlias);
//     }

//     cout << ""

// //    findPassMatch(passInput)
// // returns flag, which redirects to menu function
