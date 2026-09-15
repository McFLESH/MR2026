#include <iostream>
#include <stdio.h>

using RUB=unsigned long long int;

struct Person{
    RUB cash;
    RUB salary;
};

struct Person alice;


void alice_init()
{
    alice.cash=20000;
    alice.salary=80000;
}


void alice_print()
{
    printf("Alice cash=%llu\n",alice.cash);
}


void alice_salary(const int year, const int month)
{
    if (year==2026 and month==12){    //promotion
        alice.salary=120000;
    }
}


void simulation()
{
    int year=2026;
    int month=9;
    while(not(year==2027 and month==9)){

        alice_salary(year, month);
        //alice_car();
        //alice_mortage();
        //alice_cat();
        //alice_rent();


        alice.cash+=alice.salary;
        month++;
        if (month==13){
            ++year;
            month=1;
        }
    }
}

int main(){
    simulation();
    alice_print();
}
