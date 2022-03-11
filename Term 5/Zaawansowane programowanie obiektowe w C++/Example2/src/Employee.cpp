#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string surname1, int age1, int experience1, int salary1)
{
    surname = surname1;
    age = age1;
    experience = experience1;
    salary = salary1;
}

Employee::~Employee()
{
    //dtor
}

void Employee::show()
{
    cout << "Nazwisko: " << surname << endl;
    cout << "Wiek: " << age << endl;
    cout << "Sta¿ pracy: " << experience << endl;
    cout << "Wyp³ata: " << salary << endl;
}

int Employee::ageEmployment()
{
    return (age - experience);
}

string Employee::getSurname()
{
    return surname;
}

int Employee::getAge()
{
    return age;
}

int Employee::getExperience()
{
    return experience;
}

int Employee::getSalary()
{
    return salary;
}
