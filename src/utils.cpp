#include "../include/utils.h"
using namespace stlUtils;

bool adminCorrectPassword(const string& adminAlias, const string& adminPassword) {

    fstream fin;
    // note: this is the path to the data file, relative to THE EXECUTABLE
    fin.open("../../data/auth/logins.csv");

    if(!fin.is_open()) {
        cout << "FileNotOpenError";
        return false;
    }

    string temp;

    // ignore header row on logins.csv
    getline(fin, temp);

    while(getline(fin, temp, ',')) {

        if (temp == adminAlias) {
            // adminAlias match found
            getline(fin, temp);
            if (temp == adminPassword)
                return true;
        }

        getline(fin, temp); // change line
    }

    return false;

}