#include<iostream>
#include <chrono>
#include <random>
using namespace std;
template <typename T>
class card {
private:
    T crd;
public:
    card() {}
    card(T crd1) { crd = crd1; }
    T getcrd() { return crd; }
};
class Base {
    int amount;
    string type;
public:
    Base(int amount, string type) {
        this->amount = amount;
        this->type = type;
    }
    int getAm() { return amount; }
    string getT() { return type; }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int>dis(0, 5);
    Base base[] = { Base(dis(rng),"студенческая"),
                   Base(dis(rng),"студенческая"),
                   Base(dis(rng),"пенсионная"),
                   Base(dis(rng),"инвалидная"),
                   Base(dis(rng),"пенсионная")
    };
    card<int>iOb[5];

    for (int i = 0; i < 5; i++)
        iOb[i] = base[i].getAm();

    int c = 0;
    for (int i = 0; i < 5; i++) {

        if (iOb[i].getcrd() == 0)
            c++;
    }
    cout << "Количество карт без поездок= " << c << endl;
    card<string>strOb[5];
    for (int i = 0; i < 5; i++)
        strOb[i] = base[i].getT();
    int count = 0;
    int t;
    cout << "Введите искомый тип карты:\n1)студенчекая\n2)пенсионная\n3)инвалидная\n:" << endl;
    cin >> t;
    switch (t)
    {
    case(1): {for (int i = 0; i < 5; i++)
    {
        if (strOb[i].getcrd() == "студенческая")
            count++;
    }
           break; }
    case(2): {for (int i = 0; i < 5; i++)
    {
        if (strOb[i].getcrd() == "пенсионная")
            count++;
    }
           break; }
    case(3): {for (int i = 0; i < 5; i++)
    {
        if (strOb[i].getcrd() == "инвалидная")
            count++;
    }
           break; }

    }

    cout << "Количество карт избранного типа = " << count << endl;

    return 0;
}
