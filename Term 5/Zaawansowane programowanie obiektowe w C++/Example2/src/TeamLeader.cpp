#include "TeamLeader.h"

TeamLeader::TeamLeader(string surname1, int age1, int experience1, int salary1)
{
    surname = surname1;
    age = age1;
    experience = experience1;
    salary = salary1;
}

TeamLeader::~TeamLeader()
{
    //dtor
}

float TeamLeader::calculateBonus(int value)
{
    return value * (1 + salary + experience);
}

string TeamLeader::show()
{
    cout << "Nazwisko: " << surname << endl;
    cout << "Wiek: " << age << endl;
    cout << "Sta¿ pracy: " << experience << endl;
    cout << "Wyp³ata: " << salary << endl;
    cout << "Jestem TeamLeader z " << experience << " letnim doœwiadczeniem" << endl;
}
