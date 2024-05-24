#include "menus.h"
#include "handlers.h"

unsigned char mainMenu() {
    cout << "Welcome to Timpark++" << endl;
    cout << "Choose an option below [1-3]: " << endl;
    cout << endl;
    cout << "[1] USER LOGIN" << endl;
    cout << "[2] ADMIN LOGIN" << endl;
    cout << "[3] EXIT" << endl;

    unsigned int input;
//  not sure about the condition for the exception if this is implemented using unsigned char.

    try {
        cin >> input;

        if ((input != 1) || (input != 2) || (input != 3))
            throw std::runtime_error("Wrong input.");
    }

    catch (exception err) {
        if () { handleWrongInputNum(input); }
    }

}
