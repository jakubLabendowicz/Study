#include "Developer.h"

Developer::Developer(string surname1, int age1, int experience1, int salary1)
{
    surname = surname1;
    age = age1;
    experience = experience1;
    salary = salary1;
}

Developer::~Developer()
{

}

float Developer::calculateBonus(int value)
{
    return value + 0.2 * value * (salary + experience);
}
