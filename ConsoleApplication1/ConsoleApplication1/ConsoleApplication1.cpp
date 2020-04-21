// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "voisk.h"
#include <thread>
using namespace std;
void command(Voisk& v, bool por)
{
    v.print();
    v.sort(por);
    //v.print();
}
void command2(Voisk& v, bool por)
{
    v.print();

    v.sortGuns(por);
    //v.print();
}
void war(Voisk& v1, Voisk& v2)
{
    if (&v1 < &v2) {
        unique_lock<mutex> lock1(v1.getLock());
        unique_lock<mutex> lock2(v2.getLock());
        v1.war(v2);
        lock2.unlock();
        lock1.unlock();
    }
    else {
        unique_lock<mutex> lock1(v2.getLock());
        unique_lock<mutex> lock2(v1.getLock());
        v1.war(v2);
        lock2.unlock();
        lock1.unlock();
    }

}
int main()
{
    Voisk test(8);
    Voisk test1(8);

    thread g1(war, ref(test), ref(test1));
    thread g2(war, ref(test1), ref(test));
    g1.join();
    g2.join();
    std::cout << "\n\n\n\n";
    test.print();
    std::cout <<"Hello World!\n";
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
