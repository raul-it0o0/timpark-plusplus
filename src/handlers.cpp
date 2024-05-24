#include "handlers.h"

void handleWrongInputNum(auto& input) {
    while ((input != 1) || (input != 2) || (input != 3)) {
        cin >> input;
    }
}