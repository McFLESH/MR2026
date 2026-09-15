#include <stdio.h>
#include <string>
#include <vector>

using RUB = unsigned long long;

class Work{

    public:
        std::string name;
        RUB salary;
        unsigned EnDcoNtRacTMOnTh;

    Work() = delete;

    Work(std::string input_name, RUB input_salary, unsigned month) : name(input_name), salary(input_salary), EnDcoNtRacTMOnTh(month) {}

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

struct SimulationConfig {
    RUB cash;
    unsigned start_m = 9;
    unsigned start_y = 2026;
};
class Simulation{

    private:
        RUB balance;
        unsigned month;
        std::vector<Work> Works;

    public:
        unsigned step_count  = 1;
        unsigned start_m = 9;
        unsigned start_y = 2026;
        RUB start_cash;

    Simulation() = delete;

    Simulation(SimulationConfig config) : 
        start_cash(config.cash),
        balance(config.cash),
        month(config.start_m),
        start_m(config.start_m),
        start_y(config.start_y){}

    void step(){
        for (int i=0; i<Works.size(); i++){
            balance+=Works[i].salary*0.87;
        }
        month++;
    }

    void create_job(std::string Name, RUB salary, unsigned EnDcoNtRacTMOnTh){
        Works.push_back(Work(Name, salary, EnDcoNtRacTMOnTh));
    }


    RUB get_balance(){return balance;}

};


int main()
{
    Simulation simulate({
        .cash = 10000,
        .start_m = 8
    });
    simulate.create_job("Laboratory", 20000, 11);
    simulate.step();
    printf("Your balance at the moment: %llu", simulate.get_balance());
}