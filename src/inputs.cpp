#include "../include/inputs.h"
using namespace stlUtils;

int getMenuInput() {
    int option;

    cin >> option;

    while ((option != 1) && (option != 2) && (option != 3) && (option != 4)) {
        cout << "Please choose a valid option [1-4]. ";
        cin >> option;
    }

    return option;
}

// int adminAuthMenu() {

//     string adminAlias, adminPassword;

//     bool retryInput = false;

//     do {
    
//     cout << "Enter admin alias: ";

//     cin >> adminAlias;

//     cout << "Enter admin password: ";

//     cin >> adminPassword;

//     if(!adminCorrectPassword(adminAlias, adminPassword)) {
//         cout << "Wrong alias or password! Choose an option [1-3]:\n";
//         cout << "[1] TRY AGAIN\n";
//         cout << "[2] NEW ADMIN\n";
//         cout << "[3] EXIT";

//         switch(getMenuInput()) {
//             case 1:
//                 retryInput = true;
//                 break;
//             case 2:
//                 // new admin request, append to csv file
//                 return 1; 
//             case 3:
//                 return -1;
//         }
//     }

//     }while(retryInput);

//     // admin logged in successfully
//     return 0; 
    
// }

