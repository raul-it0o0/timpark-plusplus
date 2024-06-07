#pragma once
#include "../include/main.h"
#include "../include/utils.h"
#include "inputs.h"
#include "Administrator.h"

int mainMenu();

int adminAuthMenu(string& adminAlias, string& adminPassword);

int getNewAdminCredentials(string& alias, string& password);

int adminPanel(const string& alias, const string& password);

void parkingLotPanel(Administrator& sessionAdmin);