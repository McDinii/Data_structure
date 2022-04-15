#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>

using namespace std;

namespace Struct {
    struct job
    {
        string name;
        string lastName;
        string jobName;
        string phone;
        float salary;
        int id;
    };
}