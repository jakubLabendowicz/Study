#ifndef TEAMLEADER_H
#define TEAMLEADER_H
#include "Employee.h"

class TeamLeader : public Employee
{
    public:
        TeamLeader();
        TeamLeader(string surname1, int age1, int experience1, int salary1);
        virtual ~TeamLeader();
        virtual float calculateBonus(int value) override;
        virtual void show() override;

    protected:

    private:
};

#endif // TEAMLEADER_H
