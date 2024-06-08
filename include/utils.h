#pragma once
#include "main.h"
#include "Administrator.h"
#include <fstream>
using namespace stlUtils;

bool foundInSequence(const int value, int referenceArray[], int size);

string encrypt(string& message, const string& key);

string decrypt(string& encrypted, const string& key);

bool adminCorrectPassword(const string& adminAlias, const string& adminPassword);

bool aliasTaken(const string& alias);