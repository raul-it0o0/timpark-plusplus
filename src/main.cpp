#include "../include/main.h"
#include "../include/menus.h"
using namespace stlUtils;

int main() {

    int menu_chooser = -1;
    // 0 - main menu
    // 1 - admin menu
    // 2 - create new admin menu
    do {
        switch (mainMenu()) {
        case 1:
            // user has selected ADMIN LOGIN
            // need admin auth success flag
            cout<<flush;
            system("CLS");
            switch(adminAuthMenu()) {
                case 0:
                    // user granted access to ADMIN PANEL
                    menu_chooser = 1;
                    break;
                case 1:
                    // user has selected NEW ADMIN ACCOUNT
                    menu_chooser = 2;
                case -1:
                    // user has selected BACK TO MAIN MENU
                    menu_chooser = 0;
                default:
                    // user has selected EXIT
                    break;
            }
            break;

        case 2:
            // user has selected USER LOGIN
            cout<<flush;
            system("CLS");
            cout<<"user auth menu not available"<<endl;
            // userAuthMenu();
            break;

        default:
            // user has selected EXIT
            return 0;
        }

        switch(menu_chooser) {
            case 1:
                cout<<flush;
                system("CLS");
                cout<<"admin panel"<<flush;
                cin>>menu_chooser;
                // adminPanel();
                break;
            case 2:
                cout<<flush;
                system("CLS");
                cout<<"createNewAdmin";
                // createNewAdmin();
                // adminPanel();
            default:
                break;
        }

    }while(menu_chooser == 0);

    return 0;
}
