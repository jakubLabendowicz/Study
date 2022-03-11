#ifndef DEVELOPER_H
#define DEVELOPER_H
#include "Employee.h"


class Developer : public Employee
{
    public:
        Developer();
        Developer(string surname1, int age1, int experience1, int salary1);
        virtual ~Developer();
        virtual float calculateBonus(int value) override;

    protected:

    private:
};

#endif // DEVELOPER_H
