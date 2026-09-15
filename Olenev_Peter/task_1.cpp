#include <stdio.h>
#include <random>
#include <cmath>

using RUB = unsigned long long int;
using YEARS = unsigned int;

struct Person{
    RUB cash;
    RUB salary;
    YEARS age;
    unsigned int number_of_promotions;
    unsigned int health;
    int childs;
    bool car;
    bool wife;
    bool lizard;
    bool mortage;
    bool dismission;

};

struct Person peter;

void peter_init()
{
    peter.age=21;
    peter.cash=0;
    peter.salary=40000;
    peter.health=75-21;
    peter.number_of_promotions=0;
    peter.dismission=false;
}


void peter_salary(unsigned int number_of_promotions, bool dismission)
{
    if (dismission){
        peter.salary=0;
    }
    else{
        double salary_thousands =
            (-1.0/3.0) * std::pow(number_of_promotions, 5)
          + (25.0/12.0) * std::pow(number_of_promotions, 4)
          + (25.0/6.0)  * std::pow(number_of_promotions, 3)
          - (385.0/12.0)* std::pow(number_of_promotions, 2)
          + (397.0/6.0) * number_of_promotions
          + 40.0;
        peter.salary = static_cast<RUB>(std::round(salary_thousands)) * 1000;
    }

}

int world_tick(int year, int month)
{
    if (month==12){
        ++year;
        month=1;
    }
    else{
        ++month;
    }
    return year, month;
}


bool peter_promotion_at_work() 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(5, 54*12);
    return dist(gen) == 1;
}


bool peter_dismissial_from_work()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 54*12);
    return dist(gen) == 1;
}


void simulation()
{
    int year=2027;
    int month=1;
    while(peter.health){

        peter_salary(year, month);
        //peter_rent(year, month);              // аренда квартиры (растёт каждый год)
        //peter_food(year, month);              // еда (зависит от инфляции)
        //peter_transport(year, month);         // метро/бензин
        //peter_utilities(year, month);         // свет, вода, интернет
        //peter_phone(year, month);             // мобильная связь
        //peter_clothes(year, month);           // одежда (сезонно)

        //peter_taxes(year, month);             // НДФЛ, налог на имущество
        //peter_deposit(year, month);           // банковский вклад (капает %)
        //peter_stocks(year, month);            // акции (случайные колебания)
        //peter_credit(year, month);            // кредитка, проценты

        //peter_car(year, month);               // покупка машины в рассрочку
        //peter_car_repair(year, month);        // случайные поломки
        //peter_mortgage(year, month);          // ипотека на 20 лет

        //peter_vacation(year, month);          // отпуск раз в год
        //peter_entertainment(year, month);     // спортзал
        //peter_doctor(year, month);            // случайные болезни
        //peter_health_check(year);             // ухудшение здоровья с возрастом

        //peter_inheritance(year, month);       // наследство от бабушки
        //peter_friend_loan(year, month);       // дал в долг другу
        //peter_accident(year, month);          // ДТП

        //peter_economy(year, month);           // кризис/рост
        //peter_pandemic(year, month);          // ковид-подобное событие

        //peter_save_for_goal(year, month);     // цель: квартира/машина
        //peter_pension_fund(year, month);      // пенсионные накопления
        //peter_emergency_fund(year, month);    // подушка безопасности

        world_tick(year, month);
    }
}

int main(){
    simulation();
}
