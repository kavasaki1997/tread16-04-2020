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

    vector <Soldier> army;
public:
    Voisk(int size);
    void sort(bool por);
    void print();
    void sumMass();

};
