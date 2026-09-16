#include <stdio.h>

//typedef int RUB;
using RUB = int;

struct Person {
    RUB cash;
    RUB salary;
    RUB food;
    RUB home_bills;
    RUB rent;
};

struct Person den;

void den_salary(const int year, const int month)
{
    if (month == 1) // индексация зарплаты 7% в год
    {
        den.salary = den.salary * 107 / 100;
    }

    if (year == 2030 and month == 3) // Повышение
    {
        den.salary += 30'000;
    }

    den.cash += den.salary;
}

void den_food(const int year, const int month)
{
    if (month == 1) // инфляция на еду 6% в год
    {
        den.food = den.food * 106 / 100;
    }

    den.cash -= den.food;
}

void den_home_bills(const int year, const int month)
{
    if (month == 7) // индексация тарифов 10% в год
    {
        den.home_bills = den.home_bills * 110 / 100;
    }

    den.cash -= den.home_bills;
}

void den_rent(const int year, const int month)
{
    if (month == 9) // хозяин квартиры поднимает аренду 5% в год
    {
        den.rent = den.rent * 105 / 100;
    }

    den.cash -= den.rent;
}

void simulation()
{
    int year = 2026;
    int month = 9;
    while (not ( year == 2036 and month == 9 ))
    {
        den_salary(year, month);
        den_food(year, month);
        den_home_bills(year, month);
        den_rent(year, month);

        ++month;
        if (month == 13)
        {
            ++year;
            month = 1;
        }
    }
}

void den_init()
{
    den.cash = 40'000;
    den.salary = 70'000;
    den.food = 25'000;
    den.home_bills = 5'000;
    den.rent = 40'000;
}

void den_print()
{
    printf("Den salary = %d\n", den.salary);
    printf("Den cash = %d\n", den.cash);
    printf("Den food = %d\n", den.food);
    printf("Den home bills = %d\n", den.home_bills);
    printf("Den rent = %d\n", den.rent);
}

int main()
{
    den_init();

    simulation();

    den_print();
}
