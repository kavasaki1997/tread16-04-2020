#include "voisk.h"
#include <windows.h>
Voisk::Voisk(int size) 
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        Soldier soldier;

        soldier.mass = 50 + rand() % 90;
        soldier.height = 160 + rand() % 190;
        soldier.power = rand() % 8 + 3;
        army.push_back(soldier);

    }
}

void Voisk::sort(bool por) {
    std::lock_guard<std::mutex> lock(m);
    for (int i = 0; i < army.size() - 1; i++) {
        for (int j = 0; j < army.size() - i - 1; j++) {
            if (por) {
                Sleep(200);
                if (army[j].height > army[j + 1].height) {
                    swap(army[j], army[j + 1]);
                }
            }
            else
            {
                Sleep(200);
                if (army[j].height < army[j + 1].height) {
                    swap(army[j], army[j + 1]);
                }
            }
            
        }
    }
   
}
void Voisk::sortGuns(bool por)
{
    
    std::lock_guard<std::mutex> lock(m1);
    for (int i = 0; i < guns.size() - 1; i++) {
        for (int j = 0; j < guns.size() - i - 1; j++) {
            if (por) {
                Sleep(200);
                if (guns[j].mass > guns[j + 1].mass) {
                    swap(guns[j], guns[j + 1]);
                }
            }
            else
            {
                Sleep(200);
                if (guns[j].mass < guns[j + 1].mass) {
                    swap(guns[j], guns[j + 1]);
                }
            }

        }
    }
}
void Voisk::print() {
    for (int i = 0; i < army.size(); ++i) {
        cout << "Soldier " << i + 1 << ": h = " << army[i].height << " mass =" << army[i].mass  << "\n";
    }
}
void Voisk::sumMass() {
    int sumMass = 0;

    for (int i = 0; i < army.size(); ++i) {
        sumMass += army[i].mass;
    }

    cout << "Summ mass: " << sumMass;
}

void Voisk::war(Voisk& v2)
{
    for (size_t i = 0; i < army.size(); i++)
    {
        if (army[i].power < v2.army[i].power)
        {
            army[i].health -= v2.army[i].power - army[i].power;
        }
        if (army[i].power <= 0)
        {
            army.erase(army.begin() + i);
            i--;
        }
    }

    
}
std::unique_lock<std::mutex> Voisk::getLock()
{
    unique_lock<mutex> lock(m);
    return lock; 
}
