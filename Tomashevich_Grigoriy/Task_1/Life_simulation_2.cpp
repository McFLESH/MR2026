#include <stdio.h>

using RUB = unsigned long long int;

struct Person {
    RUB cash;
    RUB salary;
    bool car;       //наличие машины
    bool flat;      // наличие квартиры
    RUB mortgadge;  // ипотека
};

struct Person bob;

void bob_salary(const int year, const int month) 
{
    short int multiplicator;

    multiplicator = 1 + (year - 2026)/100;

    if (year == 2027 && month == 1) {  // and --> &&
        bob.salary = 100'000*multiplicator; // Переход со стажировки на полноправную должность
    }

    if (year == 2029 && month == 5) {  
        bob.salary = 140'000*multiplicator; // Смена места работы, та же должность
    }

    if (year == 2030 && month == 1) {  
        bob.salary = 180'000*multiplicator; // Повышение
    }

    if (year == 2030 && month == 12) {  
        bob.salary = 150'000*multiplicator; //  Смена места работы, понижение
    }

    if (year == 2032 && month == 11) {  
        bob.salary = 200'000*multiplicator; //  Повышение
    }

    bob.cash += bob.salary;
}

void bob_car(const int year, const int month) 
{
    if (year >= 2030 || (year == 2030 && month >= 6) && bob.cash >= 500'000 && bob.salary >= 100'000 && bob.car == false) {
        bob.car = true;
        bob.cash -= 300'000;
    }

    if (bob.car == true) {
        bob.cash -= 50'000;  //затраты на авто: страховка, топливо, штраф и ТО    
    }

    if (bob.cash <= 50'000 && bob.salary <= 100'000 && bob.car == true) {
        bob.car = false;
        bob.cash += 200'000;
    }
}

void bob_food(const int year) 
{
    double inflation = 1.0;

    for (int y = 2026; y < year; ++y) {
        inflation *= 1.07; 
    }

    bob.cash -= (RUB) (7000*inflation);
}

void bob_rent(const int year, const int month) 
{   
    long int rent = 0;

    if (bob.flat == true) {
        rent = 0;
        return;
    }

    if (year < 2027 || (year == 2027 && month <= 8)) {
        rent = 0;
    }
    else if (year < 2028 || (year == 2028 && month <= 6)) {
        rent = 20'000;
    }
    else if (year < 2030 || (year == 2030 && month <= 4) || bob.flat == false) {
        rent = 40'000;
    }
    else {
        rent = 0;
    }
    
    bob.cash -= rent;
}

void bob_home_bills(const int year, const int month)  
{
    long int bills = 0;
    
    if (year > 2033 || (year == 2033 && month >= 3) ) {
        bills = 25'000;
    }
    else if (year > 2030 || (year == 2030 && month >= 4) ) {
        bills = 20'000;
    }
    else if (year > 2028 || (year == 2028 && month >= 6) ) {
        bills = 10'000;
    }
    else {
        bills = 5'000;
    }

    bob.cash -= bills;
}

void bob_mortgadge(const int year, const int month) 
{
    long int mortgadge = 0;

    if (year >= 2033 && month >= 3 && bob.flat == false) {
        
        bob.flat = true;
        bob.mortgadge = 15'000'000;

    }

    if (bob.mortgadge > 0 && year < 2052) {

        mortgadge = 70'000;

        if (month == 1) {
        mortgadge *= 2;
        }

        if (bob.mortgadge < mortgadge) {
            mortgadge = bob.mortgadge;
        }

    }

    bob.cash -= mortgadge;
    bob.mortgadge -= mortgadge;
          
}

void simulation() 
{
    int year = 2026;
    int month = 9;

    while ( !  (year == 2027 && month == 3) ) {  // and --> &&   not --> !

        bob_salary(year, month);
        
        bob_car(year, month);
        bob_mortgadge(year, month);
        bob_rent(year, month);
        bob_home_bills(year, month);
        bob_food(year);
        //bob_dog(year, month);
        //food_bank_income(year, month);
        


        ++month;
        if (month == 13) {
            ++year;
            month = 1;
        }

    }

}


void bob_init() 
{
    bob.cash = 20'000;
    bob.salary = 80'000;
    bob.car = false;       //наличие машины
    bob.flat = false;      // наличие квартиры
    bob.mortgadge = 0;

}

void bob_print() 
{
    printf("Bob cash = %llu\n", bob.cash);
}


int main () 
{
    bob_init();

    simulation();

    bob_print();

    return 0;
}