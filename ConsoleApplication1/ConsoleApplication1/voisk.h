#pragma once
#include <iostream>
#include <vector>
#include "structs.h"
#include <random>
#include <ctime>
#include <mutex>
using namespace std;


class Voisk {
private:
    mutable mutex m;
    mutable mutex m1;
    vector <Gun> guns;
    vector <Soldier> army;
public:
    
    Voisk(int size);
    void sort(bool por);
    void sortGuns(bool por);
    void print();
    void sumMass();
    void war(Voisk& v2);
    unique_lock<mutex> getLock();
};
