#include "../include/main.h"
#include "../include/menus.h"
using namespace stlUtils;

unsigned int DayCounter = 1;
// first day = 1

int main() {

    string alias, password;
    int menu_chooser = -1;
    // 0 - main menu
    // 1 - admin menu
    // 2 - create new admin menu
    do {
        switch(mainMenu()) {
        case 1:
            // user has selected ADMIN LOGIN
            // need admin auth success flag
            cout<<flush;
            system("CLS");
            switch(adminAuthMenu(alias, password)) {
                case 0:
                    // user granted access to ADMIN PANEL
                    menu_chooser = 1;
                    break;
                case 1:
                    // user has selected NEW ADMIN ACCOUNT
                    menu_chooser = 2;
                    break;
                case -1:
                    // user has selected BACK TO MAIN MENU
                    menu_chooser = 0;
                    break;
                default:
                    // user has selected EXIT
                    break;
            }
            break;

        case 2:
            // user has selected NEW ADMIN
            cout<<flush;
            system("CLS");
            switch(getNewAdminCredentials(alias, password)) {
                case 0:
                    menu_chooser = 1;
                    break;
                case -1:
                    // user has selected BACK TO MAIN MENU
                    menu_chooser = 0;
                    break;
                case -2:
                    // user has selected EXIT
                    return 0;
            }
            break;

        default:
            // user has selected EXIT
            return 0;
        }

        switch(menu_chooser) {
            case 1:
                // user granted access to ADMIN PANEL
                switch(adminPanel(alias, password)) {
                    case -1:
                        menu_chooser = 0;
                        break;
                    default:
                        return 0;
                }
                break;
            case 2:
                // user has selected NEW ADMIN
                cout<<flush;
                system("CLS");
                switch(getNewAdminCredentials(alias, password)) {
                    case 0:
                        menu_chooser = 1;
                        break;
                    case -1:
                        // user has selected BACK TO MAIN MENU
                        menu_chooser = 0;
                        break;
                    case -2:
                        // user has selected EXIT
                        return 0;
                }
                break;
            default:
                break;
        }

    }while(menu_chooser == 0);

    return 0;
}
