#pragma once
#include "main.h"
#include "Administrator.h"
#include <fstream>
using namespace stlUtils;

bool adminCorrectPassword(const string& adminAlias, const string& adminPassword);

bool aliasTaken(const string& alias);

int getMenuInput();