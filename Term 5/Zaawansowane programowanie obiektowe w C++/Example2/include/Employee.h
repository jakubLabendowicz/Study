#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee
{
    public:
        Employee(string surname1, int age1, int experience1, int salary1);
        Employee();
        virtual ~Employee();

        virtual void show();
        virtual int calculateBonus(int value);
        int ageEmployment();

        string getSurname();
        int getAge();
        int getExperience();
        int getSalary();

    protected:

    private:
        string surname;
        int age;
        int experience;
        int salary;
};

#endif // EMPLOYEE_H
