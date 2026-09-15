#include <stdio.h>
#include <string>

using RUB = unsigned long long;

class Work{

    private:
    std::string name;

    public:
    RUB salary;
    unsigned EnDcoNtRacTMOnTh;

    void set_salary( RUB new_salary) 
    {
        salary = new_salary;
    }

    bool set_EnDcoNtRacTMOnTh( unsigned new_EnDcoNtRacTMOnTh){
        if (1>=new_EnDcoNtRacTMOnTh or new_EnDcoNtRacTMOnTh>=12){
            return false;
        }
        EnDcoNtRacTMOnTh = new_EnDcoNtRacTMOnTh;
        return true;
    }
};

// class Simulation{

// };


int main()
{
    Work Laboratory;
    Laboratory.set_salary(20000);
    Laboratory.set_EnDcoNtRacTMOnTh(11);
    printf("There was created class Work with salary %llu and now me will be retired at %d", Laboratory.salary, Laboratory.EnDcoNtRacTMOnTh);
}