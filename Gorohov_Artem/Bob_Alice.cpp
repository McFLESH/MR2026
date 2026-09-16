#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


using RUB = unsigned long long int;
using Percent = double;


struct Work
{
    RUB salary_month;
    double promotion_factor;      // Коэффициент повышения зарплаты
    RUB bonus;                    // Годовая премия
    string position;
    int experience_years;
    bool has_remote;              // Есть ли удаленная работа
    int vacation_days_used;       
    int vacation_days_total;     
    RUB education_allowance_year; // Годовой бюджет на обучение (от компании)
    RUB transport_compensation_month; // Компенсация проезда
    RUB phone_compensation_month;      // Компенсация связи
    RUB stock_options;            // Количество опционов на акции
    RUB stock_price;              // Цена одной акции
};

struct Tbank
{
    RUB balance;                  // Текущий счет (дебетовая карта)
    RUB deposit;                  // Накопления на депозите
    Percent deposit_rate;         // Процент по депозиту (% годовых)
    RUB credit_card_debt;         // Задолженность по кредитке
    RUB credit_card_limit;        
    Percent credit_rate;          
    RUB investment;               // Инвестиции (акции, фонды)
    RUB crypto;                   // Криптовалюта
    RUB gold;                    
    RUB bonds;                    
    RUB pension;                  // Накопительная пенсия (НПФ)
    RUB life_insurance;           // Страховка жизни (инвестиционная)
    RUB debit_card_cashback;      // Ежемесячный кэшбэк
};

struct Car
{
    RUB value;                   // Рыночная стоимость автомобиля
    RUB gas_month;
    RUB maintenance_month;
    RUB insurance_year;
    RUB parking_month;
    RUB tax_year;                
    RUB fine_avg;                // Средний штраф (случайные нарушения)
    int age_months;              // Возраст авто в месяцах
    bool need_repair;           
    RUB repair_cost;             // Стоимость ремонта при необходимости
    RUB washing_month;
    RUB tires_year;              // Годовая замена шин (сезонная)
    RUB diagnostics_year;        // Техосмотр/диагностика в год
    RUB tolls_month;             
    RUB rental_income;           // Доход от аренды авто (каршеринг)
    bool has_rental;             
    RUB loan;                    
    RUB loan_month;              // Ежемесячный платеж по кредиту
};

struct Cat
{
    string name;
    string color;
    int age;
    RUB food_month;
    RUB vet_month;
    RUB toys_month;
    RUB insurance_month;         // Страховка для кота
    bool sick;                   // Болеет ли кот в текущем месяце
    int sick_days;               
    RUB grooming_month;          // Стрижка, вычесывание
    RUB treats_month;            // Лакомства для кота
    RUB bedding_year;            // Годовая стоимость лежанок/подстилок
    RUB carrier_one_time;        // Разовая покупка переноски
    bool carrier_bought;         // Куплена ли уже переноска
};

struct Property
{
    RUB rent_month;
    RUB utilities_month;          // Коммунальные услуги (ЖКХ)
    RUB internet_month;
    RUB phone_month;
    RUB insurance_year;           // Страховка квартиры/дома
    bool has_mortgage;            // Есть ли ипотека
    RUB mortgage_month;           // Ежемесячный платеж по ипотеке
    RUB mortgage_debt;            // Остаток долга по ипотеке
    RUB property_tax_year;        // Налог на недвижимость в год
    RUB renovation_year;          
    RUB furniture_year;           
    RUB appliances_year;          
    bool owns_apartment;          // В собственности ли квартира
    RUB apartment_value;          // Рыночная стоимость квартиры
};

struct FoodExpenses
{
    RUB groceries;                 // Продукты в магазине
    RUB eating_out;                
    RUB fast_food;                 // Фастфуд
    RUB delivery;                  
    RUB coffee;                    // Кофе с собой
    RUB sweets;                    // Сладости
    RUB fruits;
    RUB vegetables;
    RUB meat;
    RUB fish;
    RUB dairy;                     // Молочные продукты
    RUB bread;
    RUB alcohol;
    RUB water;                      
    RUB juices;
    RUB snacks;                     // Снеки (чипсы, орехи)
    RUB frozen;                     
    RUB canned;                     
    RUB spices;                     
    RUB baby_food;                  
};

struct HealthExpenses
{
    RUB medicine;                   // Лекарства (регулярные)
    RUB pharmacy;                   // Аптека (разовые покупки)
    RUB dentist;                    
    RUB therapist;                  
    RUB cardiologist;               
    RUB psychologist;               
    RUB massage;                    
    RUB fitness;                   
    RUB beauty;                     
    RUB barber;                      
    RUB cosmetics;                   
    RUB perfume;                     
    RUB ophthalmologist;             
    RUB surgeon;                     
    RUB hospital;                    
    RUB physiotherapy;               
    RUB vitamins;                    // Витамины
    RUB dietary_supplements;         // БАДы
    RUB medical_tests;               // Анализы
    RUB ambulance;                   // Скорая помощь (платная)
};

struct ClothingExpenses
{
    RUB clothes;                     
    RUB shoes;                       
    RUB accessories;                  // Аксессуары (ремни, очки)
    RUB dry_clean;                    // Химчистка
    RUB repair;                       // Ремонт одежды/обуви
    RUB sportswear;                   
    RUB underwear;                    
    RUB socks;                        
    RUB hats;                         
    RUB gloves;                      
    RUB bags;                         
    RUB jewelry;                      // Украшения (бижутерия)
    RUB watches;                      
};

struct TransportExpenses
{
    RUB public_transport;             // Общественный транспорт
    RUB taxi;                         // Такси (общее)
    RUB taxi_work;                     // Такси на работу
    RUB taxi_weekend;                
    RUB train;                         
    RUB plane;                         
    RUB bus;                          
    RUB subway;                      
    RUB bicycle;                       
    RUB scooter;                       // Самокат (обслуживание)
    RUB rideshare;                     // Попутчики (BlaBlaCar)
    RUB car_sharing;                   // Каршеринг
};

struct EntertainmentExpenses
{
    RUB travel;                       
    RUB hotel;                          
    RUB hostel;                         
    RUB camping;                        
    RUB museum;
    RUB theater;
    RUB concert;
    RUB cinema;
    RUB hobbies;                        
    RUB subscriptions;                  // Подписки (общие)
    RUB sport;                          // Спортивные события (билеты)
    RUB souvenirs;                      // Сувениры
    RUB photos;                          // Фотоуслуги
    RUB books;
    RUB music;                          
    RUB games;                           
    RUB streaming;                       // Стриминговые сервисы
    RUB nightclub;                        
    RUB bar;                              
    RUB karaoke;
    RUB bowling;
    RUB billiard;
    RUB quests;                            // Квест-комнаты
    RUB amusement_park;                    // Парк аттракционов
    RUB zoo;
    RUB aquarium;
};

struct MiscExpenses
{
    RUB education;                         
    RUB charity;                            // Благотворительность
    RUB lottery;                           
    RUB gambling;                           // Азартные игры (казино)
    RUB fines;                               // Штрафы (не авто)
    RUB taxes;                               // Дополнительные налоги
    RUB lawyer;                              // Юрист
    RUB notary;                              // Нотариус
    RUB bank_fee;                            // Комиссия банка (обслуживание)
    RUB atm_fee;                             // Комиссия за снятие наличных
    RUB postal;                             
    RUB furniture;                          
    RUB electronics;                         
    RUB home_appliances;                     
    RUB kitchen;                             // Кухонная утварь
    RUB bed_linen;                          
    RUB towels;                               
    RUB gifts;                                
    RUB flowers;                              
    RUB greeting_cards;                       // Открытки
    RUB pet_sitting;                          // Присмотр за животными
    RUB house_cleaning;                       // Клининг
    RUB pest_control;                         // Дератизация/дезинсекция
    RUB moving;                                // Переезд (грузчики)
    RUB storage;                               // Аренда склада/кладовки
    RUB subscriptions_other;                   // Прочие подписки
    RUB software;                              // ПО (лицензии)
    RUB cloud_storage;                         // Облачное хранилище
    RUB domain_hosting;                        // Домен и хостинг
    RUB dating_sites;                          // Сайты знакомств
};



struct Person
{
    string name;
    int age;
    bool married;
    bool has_children;
    RUB children_expenses_month;               
    int children_count;
    vector<string> children_names;
    bool has_pet_dog;
    RUB dog_expenses_month;
    Work work;
    Tbank bank;
    Car car;
    Cat cat;
    Property property;
    FoodExpenses food;
    HealthExpenses health;
    ClothingExpenses clothing;
    TransportExpenses transport;
    EntertainmentExpenses entertainment;
    MiscExpenses misc;
    RUB deposit_month;                           // Плановая сумма пополнения депозита
    RUB emergency_fund;                          // Подушка безопасности
    int birthday_month;                         
    int wedding_anniversary_month;               
    int child_birth_month;                        
    bool expecting_child;                        
    RUB maternity_payment;                        // Декретные выплаты
    RUB freelance_income_month;                   // Средний доход с фриланса
    RUB rental_income_month;                       
    RUB dividend_income_year;                      
    RUB student_loan;                              
    RUB student_loan_month;                        // Ежемесячный платеж по студенческому
    RUB personal_loan;                             // Остаток по личному кредиту
    RUB personal_loan_month;                       // Ежемесячный платеж по личному
    vector<RUB> balance_history;                   // История баланса по месяцам
    vector<RUB> deposit_history;                   // История депозита по месяцам
    vector<RUB> networth_history;                  // История чистой стоимости
};

struct Person Alice;
struct Person Bob;


double random_inflation(double min_percent, double max_percent)
{
    return min_percent + (double)rand() / RAND_MAX * (max_percent - min_percent);
}

RUB apply_monthly_inflation(RUB amount, double inflation_percent)
{
    return amount * (1 + inflation_percent / 100 / 12);
}

RUB apply_yearly_inflation(RUB amount, double inflation_percent)
{
    return amount * (1 + inflation_percent / 100);
}

bool random_event(double prob)
{
    return (rand() / (double)RAND_MAX) < prob;
}


void alice_salary(const int month, const int year)
{
   
    if (month == 1)
    {
        if (year >= 2026 && year <= 2035)
        {

            double index = 1.0;
            if (year == 2026) index = 1.03;     
            else if (year == 2027) index = 1.05;  
            else if (year == 2028) index = 1.04; 
            else if (year == 2029) index = 1.06; 
            else if (year == 2030) index = 1.05;  
            else if (year == 2031) index = 1.04; 
            else if (year == 2032) index = 1.04;  
            else if (year == 2033) index = 1.03;  
            else if (year == 2034) index = 1.03;  
            else if (year == 2035) index = 1.02;
            
            Alice.work.salary_month = (RUB)(Alice.work.salary_month * index);
        }
    }
    
    if (year >= 2026 && year <= 2035)
    {
        if (month == 6)
        {
            double bonus_percent = 0.5;
            if (year == 2026) bonus_percent = 0.5;
            else if (year == 2027) bonus_percent = 0.5;
            else if (year == 2028) bonus_percent = 0.6;
            else if (year == 2029) bonus_percent = 0.7;
            else if (year >= 2030) bonus_percent = 0.6;
            
            Alice.bank.balance += (RUB)(Alice.work.salary_month * bonus_percent);
        }
        
        if (month == 12)
        {
            double bonus_percent = 0.3;
            if (year == 2026) bonus_percent = 0.3;
            else if (year == 2027) bonus_percent = 0.4;
            else if (year == 2028) bonus_percent = 0.4;
            else if (year == 2029) bonus_percent = 0.5;
            else if (year >= 2030) bonus_percent = 0.35; 
            
            Alice.bank.balance += (RUB)(Alice.work.salary_month * bonus_percent);
        }
    }
    Alice.bank.balance += Alice.work.salary_month;
}

void bob_salary(const int month, const int year)
{
    if (month == 1)
    {
        if (year >= 2026 && year <= 2035)
        {
    
            double index = 1.0;
            if (year == 2026) index = 1.02;    
            else if (year == 2027) index = 1.03; 
            else if (year == 2028) index = 1.02;
            else if (year == 2029) index = 1.04; 
            else if (year == 2030) index = 1.03;  
            else if (year == 2031) index = 1.02; 
            else if (year == 2032) index = 1.02;  
            else if (year == 2033) index = 1.02;  
            else if (year == 2034) index = 1.01;  
            else if (year == 2035) index = 1.01;  
            
            Bob.work.salary_month = (RUB)(Bob.work.salary_month * index);
        }
    }
    
    if (year >= 2026 && year <= 2035)
    {
   
        if (month == 3)
        {
            double bonus_percent = 0.0;
            if (year == 2026) bonus_percent = 0.0;      
            else if (year == 2027) bonus_percent = 0.2;  
            else if (year == 2028) bonus_percent = 0.25; 
            else if (year == 2029) bonus_percent = 0.3;  
            else if (year >= 2030) bonus_percent = 0.25; 
            
            Bob.bank.balance += (RUB)(Bob.work.salary_month * bonus_percent);
        }
        
        
        if (month == 9)
        {
            double bonus_percent = 0.0;
            if (year == 2026) bonus_percent = 0.0;     
            else if (year == 2027) bonus_percent = 0.3;  
            else if (year == 2028) bonus_percent = 0.35; 
            else if (year == 2029) bonus_percent = 0.4;  
            else if (year >= 2030) bonus_percent = 0.3;  
            
            Bob.bank.balance += (RUB)(Bob.work.salary_month * bonus_percent);
        }
    }
    Bob.bank.balance += Bob.work.salary_month;
}


void alice_additional_income(int month, int year)
{
    if (random_event(0.3))
    {
        Alice.bank.balance += Alice.freelance_income_month;
    }
    if (Alice.car.has_rental && random_event(0.5))
    {
        Alice.bank.balance += Alice.car.rental_income;
    }
    if (Alice.property.owns_apartment && random_event(0.1))
    {
        Alice.bank.balance += Alice.rental_income_month;
    }
    if (month == 9 && year == 2027)
    {
        Alice.bank.balance += Alice.dividend_income_year;
    }
    if (month == 9 && year == 2028)
    {
        Alice.bank.balance += Alice.dividend_income_year * 1.02;
    }
    if (month == 9 && year == 2029)
    {
        Alice.bank.balance += Alice.dividend_income_year * 1.04;
    }
}


void bob_additional_income(int month, int year)
{
    if (random_event(0.2))
    {
        Bob.bank.balance += Bob.freelance_income_month;
    }
    if (Bob.car.has_rental && random_event(0.3))
    {
        Bob.bank.balance += Bob.car.rental_income;
    }
    if (month == 11 && year == 2027)
    {
        Bob.bank.balance += Bob.dividend_income_year;
    }
    if (month == 11 && year == 2028)
    {
        Bob.bank.balance += Bob.dividend_income_year * 1.01;
    }
}



void alice_deposit()
{

}


void bob_deposit()
{

}


void alice_loan_payments()
{

}


void bob_loan_payments()
{

}


void alice_property(int month)
{

}


void bob_property(int month)
{

}


void alice_food()
{
    
}


void bob_food()
{
    
}




















void simulation_alice()
{
    int year = 2026;
    int month = 9;
    while (not (year == 2027 and month ==9)) {
        alice_salary(month, year);
        alice_additional_income(month, year);
        alice_deposit();
        alice_loan_payments();
        alice_property(month);
        alice_food();
        alice_cat(month);
        alice_dog();
        alice_car(month);
        alice_transport();
        alice_monthly_events();
        alice_clothing();
        alice_misc();
        alice_personal_events(month, year);
        alice_record_history(month, year);

        ++month;
        if (month == 13)
        {
            ++year;
            month = 1;
        }
    }
}


void simulation_bob()
{
    int year = 2026;
    int month = 9;
    while (not (year == 2027 and month ==9)) {
        bob_salary(month, year);
        bob_additional_income(month, year);
        bob_deposit();
        bob_loan_payments();
        bob_property(month);
        bob_food();
        bob_cat();
        bob_car(month);
        bob_transport();
        bob_monthly_events();
        bob_clothing();
        bob_misc();
        bob_personal_events(month, year);
        bob_record_history(month, year);
        ++month;
        if (month == 13)
        {
            month = 1;
            ++year;
        }
    }
}


void alice_init()
{
    Alice.name = "Alice Djokovitch";
    Alice.age = 28;
    Alice.married = false;
    Alice.has_children = false;
    Alice.children_expenses_month = 0;
    Alice.children_count = 0;
    Alice.has_pet_dog = true;
    Alice.dog_expenses_month = 3000;
    Alice.birthday_month = 4;
    Alice.wedding_anniversary_month = 2;
    Alice.child_birth_month = 0;
    Alice.expecting_child = false;
    Alice.maternity_payment = 0;
    Alice.freelance_income_month = 5000;
    Alice.rental_income_month = 0;
    Alice.dividend_income_year = 2000;
    Alice.student_loan = 0;
    Alice.student_loan_month = 0;
    Alice.car.loan = 0;
    Alice.car.loan_month = 0;
    Alice.personal_loan = 0;
    Alice.personal_loan_month = 0;

    Alice.work.salary_month = 180'000;
    Alice.work.promotion_factor = 1.2;
    Alice.work.position = "Manager";
    Alice.work.experience_years = 5;
    Alice.work.has_remote = true;
    Alice.work.vacation_days_used = 0;
    Alice.work.vacation_days_total = 28;
    Alice.work.education_allowance_year = 50'000;
    Alice.work.transport_compensation_month = 3000;
    Alice.work.phone_compensation_month = 1000;
    Alice.work.stock_options = 100;
    Alice.work.stock_price = 500;

    Alice.bank.balance = 60'000;
    Alice.bank.deposit = 0;
    Alice.bank.deposit_rate = 14.0;
    Alice.bank.credit_card_debt = 0;
    Alice.bank.credit_card_limit = 300'000;
    Alice.bank.credit_rate = 25.0;
    Alice.bank.investment = 0;
    Alice.bank.crypto = 0;
    Alice.bank.gold = 0;
    Alice.bank.bonds = 0;
    Alice.bank.pension = 20000;
    Alice.bank.life_insurance = 0;
    Alice.bank.debit_card_cashback = 500;

    Alice.car.value = 2'400'000;
    Alice.car.gas_month = 5000;
    Alice.car.maintenance_month = 3000;
    Alice.car.insurance_year = 96000;
    Alice.car.parking_month = 2000;
    Alice.car.tax_year = 15000;
    Alice.car.fine_avg = 500;
    Alice.car.age_months = 24;
    Alice.car.need_repair = false;
    Alice.car.washing_month = 1000;
    Alice.car.tires_year = 8000;
    Alice.car.diagnostics_year = 3000;
    Alice.car.tolls_month = 500;
    Alice.car.rental_income = 0;
    Alice.car.has_rental = false;

    Alice.cat.name = "Turbo";
    Alice.cat.color = "grey-braun-red";
    Alice.cat.age = 3;
    Alice.cat.food_month = 6000;
    Alice.cat.vet_month = 3000;
    Alice.cat.toys_month = 1000;
    Alice.cat.insurance_month = 2000;
    Alice.cat.sick = false;
    Alice.cat.grooming_month = 500;
    Alice.cat.treats_month = 300;
    Alice.cat.bedding_year = 2000;
    Alice.cat.carrier_one_time = 2500;
    Alice.cat.carrier_bought = false;

    Alice.property.rent_month = 40'000;
    Alice.property.utilities_month = 7000;
    Alice.property.internet_month = 1000;
    Alice.property.phone_month = 500;
    Alice.property.insurance_year = 12000;
    Alice.property.has_mortgage = false;
    Alice.property.mortgage_month = 0;
    Alice.property.mortgage_debt = 0;
    Alice.property.property_tax_year = 0;
    Alice.property.renovation_year = 0;
    Alice.property.furniture_year = 0;
    Alice.property.appliances_year = 0;
    Alice.property.owns_apartment = false;
    Alice.property.apartment_value = 0;

    Alice.food.groceries = 15000;
    Alice.food.eating_out = 5000;
    Alice.food.fast_food = 1500;
    Alice.food.delivery = 1000;
    Alice.food.coffee = 300;
    Alice.food.sweets = 500;
    Alice.food.fruits = 1000;
    Alice.food.vegetables = 800;
    Alice.food.meat = 2000;
    Alice.food.fish = 1500;
    Alice.food.dairy = 700;
    Alice.food.bread = 300;
    Alice.food.alcohol = 2000;
    Alice.food.water = 500;
    Alice.food.juices = 300;
    Alice.food.snacks = 400;
    Alice.food.frozen = 600;
    Alice.food.canned = 200;
    Alice.food.spices = 100;
    Alice.food.baby_food = 0;

    Alice.health.medicine = 5000;
    Alice.health.pharmacy = 1000;
    Alice.health.dentist = 5000;
    Alice.health.therapist = 1500;
    Alice.health.cardiologist = 2500;
    Alice.health.psychologist = 3000;
    Alice.health.massage = 2500;
    Alice.health.fitness = 5000;
    Alice.health.beauty = 3000;
    Alice.health.barber = 0;
    Alice.health.cosmetics = 2000;
    Alice.health.perfume = 3000;
    Alice.health.ophthalmologist = 2000;
    Alice.health.surgeon = 5000;
    Alice.health.hospital = 10'000;
    Alice.health.physiotherapy = 1500;
    Alice.health.vitamins = 1000;
    Alice.health.dietary_supplements = 500;
    Alice.health.medical_tests = 800;
    Alice.health.ambulance = 2000;

    Alice.clothing.clothes = 15000;
    Alice.clothing.shoes = 5000;
    Alice.clothing.accessories = 2000;
    Alice.clothing.dry_clean = 1000;
    Alice.clothing.repair = 500;
    Alice.clothing.sportswear = 2000;
    Alice.clothing.underwear = 1000;
    Alice.clothing.socks = 300;
    Alice.clothing.hats = 500;
    Alice.clothing.gloves = 300;
    Alice.clothing.bags = 2000;
    Alice.clothing.jewelry = 1000;
    Alice.clothing.watches = 1500;

    Alice.transport.public_transport = 3000;
    Alice.transport.taxi = 1000;
    Alice.transport.taxi_work = 1500;
    Alice.transport.taxi_weekend = 1000;
    Alice.transport.train = 3000;
    Alice.transport.plane = 20'000;
    Alice.transport.bus = 1000;
    Alice.transport.subway = 500;
    Alice.transport.bicycle = 200;
    Alice.transport.scooter = 300;
    Alice.transport.rideshare = 400;
    Alice.transport.car_sharing = 600;

    Alice.entertainment.travel = 80'000;
    Alice.entertainment.hotel = 5000;
    Alice.entertainment.hostel = 1500;
    Alice.entertainment.camping = 1000;
    Alice.entertainment.museum = 500;
    Alice.entertainment.theater = 1500;
    Alice.entertainment.concert = 2000;
    Alice.entertainment.cinema = 1000;
    Alice.entertainment.hobbies = 3000;
    Alice.entertainment.subscriptions = 2000;
    Alice.entertainment.sport = 4000;
    Alice.entertainment.souvenirs = 3000;
    Alice.entertainment.photos = 1000;
    Alice.entertainment.books = 1500;
    Alice.entertainment.music = 500;
    Alice.entertainment.games = 1000;
    Alice.entertainment.streaming = 800;
    Alice.entertainment.nightclub = 1500;
    Alice.entertainment.bar = 1000;
    Alice.entertainment.karaoke = 800;
    Alice.entertainment.bowling = 600;
    Alice.entertainment.billiard = 500;
    Alice.entertainment.quests = 1000;
    Alice.entertainment.amusement_park = 2000;
    Alice.entertainment.zoo = 400;
    Alice.entertainment.aquarium = 600;

    Alice.misc.education = 20'000;
    Alice.misc.charity = 3000;
    Alice.misc.lottery = 200;
    Alice.misc.gambling = 0;
    Alice.misc.fines = 1000;
    Alice.misc.taxes = 5000;
    Alice.misc.lawyer = 5000;
    Alice.misc.notary = 2000;
    Alice.misc.bank_fee = 300;
    Alice.misc.atm_fee = 200;
    Alice.misc.postal = 300;
    Alice.misc.furniture = 20'000;
    Alice.misc.electronics = 30'000;
    Alice.misc.home_appliances = 15000;
    Alice.misc.kitchen = 3000;
    Alice.misc.bed_linen = 2000;
    Alice.misc.towels = 1000;
    Alice.misc.gifts = 2000;
    Alice.misc.flowers = 500;
    Alice.misc.greeting_cards = 100;
    Alice.misc.pet_sitting = 500;
    Alice.misc.house_cleaning = 1500;
    Alice.misc.pest_control = 200;
    Alice.misc.moving = 5000;
    Alice.misc.storage = 1000;
    Alice.misc.subscriptions_other = 300;
    Alice.misc.software = 500;
    Alice.misc.cloud_storage = 200;
    Alice.misc.domain_hosting = 100;
    Alice.misc.dating_sites = 300;

    Alice.deposit_month = 40'000;
    Alice.emergency_fund = 50'000;
}


void bob_init()
{
    Bob.name = "Bob Bauer";
    Bob.age = 32;
    Bob.married = false;
    Bob.has_children = false;
    Bob.children_expenses_month = 0;
    Bob.children_count = 0;
    Bob.has_pet_dog = false;
    Bob.dog_expenses_month = 0;
    Bob.birthday_month = 10;
    Bob.wedding_anniversary_month = 0;
    Bob.child_birth_month = 0;
    Bob.expecting_child = false;
    Bob.maternity_payment = 0;
    Bob.freelance_income_month = 2000;
    Bob.rental_income_month = 0;
    Bob.dividend_income_year = 1000;
    Bob.student_loan = 200'000;
    Bob.student_loan_month = 5000;
    Bob.car.loan = 300'000;
    Bob.car.loan_month = 10000;
    Bob.personal_loan = 0;
    Bob.personal_loan_month = 0;

    Bob.work.salary_month = 150'000;
    Bob.work.promotion_factor = 1.15;
    Bob.work.position = "Mecatronic";
    Bob.work.experience_years = 7;
    Bob.work.has_remote = true;
    Bob.work.vacation_days_used = 0;
    Bob.work.vacation_days_total = 28;
    Bob.work.education_allowance_year = 30000;
    Bob.work.transport_compensation_month = 2000;
    Bob.work.phone_compensation_month = 500;
    Bob.work.stock_options = 50;
    Bob.work.stock_price = 400;

    Bob.bank.balance = 45000;
    Bob.bank.deposit = 10000;
    Bob.bank.deposit_rate = 13.0;
    Bob.bank.credit_card_debt = 15000;
    Bob.bank.credit_card_limit = 200000;
    Bob.bank.credit_rate = 27.0;
    Bob.bank.investment = 20000;
    Bob.bank.crypto = 5000;
    Bob.bank.gold = 0;
    Bob.bank.bonds = 0;
    Bob.bank.pension = 10000;
    Bob.bank.life_insurance = 0;
    Bob.bank.debit_card_cashback = 200;

    Bob.car.value = 1800000;
    Bob.car.gas_month = 4000;
    Bob.car.maintenance_month = 2000;
    Bob.car.insurance_year = 72000;
    Bob.car.parking_month = 1000;
    Bob.car.tax_year = 10000;
    Bob.car.fine_avg = 300;
    Bob.car.age_months = 36;
    Bob.car.need_repair = false;
    Bob.car.washing_month = 500;
    Bob.car.tires_year = 6000;
    Bob.car.diagnostics_year = 2000;
    Bob.car.tolls_month = 200;
    Bob.car.rental_income = 0;
    Bob.car.has_rental = false;

    Bob.cat.name = "Bulka";
    Bob.cat.color = "orange";
    Bob.cat.age = 5;
    Bob.cat.food_month = 4000;
    Bob.cat.vet_month = 2000;
    Bob.cat.toys_month = 500;
    Bob.cat.insurance_month = 1000;
    Bob.cat.sick = false;
    Bob.cat.grooming_month = 0;
    Bob.cat.treats_month = 200;
    Bob.cat.bedding_year = 1000;
    Bob.cat.carrier_one_time = 0;
    Bob.cat.carrier_bought = true;

    Bob.property.rent_month = 30'000;
    Bob.property.utilities_month = 5000;
    Bob.property.internet_month = 800;
    Bob.property.phone_month = 400;
    Bob.property.insurance_year = 9600;
    Bob.property.has_mortgage = true;
    Bob.property.mortgage_month = 25000;
    Bob.property.mortgage_debt = 1'500'000;
    Bob.property.property_tax_year = 12000;
    Bob.property.renovation_year = 0;
    Bob.property.furniture_year = 0;
    Bob.property.appliances_year = 0;
    Bob.property.owns_apartment = true;
    Bob.property.apartment_value = 5'000'000;

    Bob.food.groceries = 12000;
    Bob.food.eating_out = 3000;
    Bob.food.fast_food = 800;
    Bob.food.delivery = 500;
    Bob.food.coffee = 150;
    Bob.food.sweets = 200;
    Bob.food.fruits = 500;
    Bob.food.vegetables = 400;
    Bob.food.meat = 1000;
    Bob.food.fish = 800;
    Bob.food.dairy = 400;
    Bob.food.bread = 150;
    Bob.food.alcohol = 1500;
    Bob.food.water = 300;
    Bob.food.juices = 150;
    Bob.food.snacks = 200;
    Bob.food.frozen = 300;
    Bob.food.canned = 100;
    Bob.food.spices = 50;

    Bob.health.medicine = 3000;
    Bob.health.pharmacy = 500;
    Bob.health.dentist = 3000;
    Bob.health.therapist = 1000;
    Bob.health.cardiologist = 1500;
    Bob.health.psychologist = 0;
    Bob.health.massage = 0;
    Bob.health.fitness = 2000;
    Bob.health.beauty = 0;
    Bob.health.barber = 1000;
    Bob.health.cosmetics = 0;
    Bob.health.perfume = 0;
    Bob.health.ophthalmologist = 1000;
    Bob.health.surgeon = 0;
    Bob.health.hospital = 0;
    Bob.health.physiotherapy = 0;
    Bob.health.vitamins = 500;
    Bob.health.dietary_supplements = 200;
    Bob.health.medical_tests = 300;
    Bob.health.ambulance = 0;

    Bob.clothing.clothes = 10000;
    Bob.clothing.shoes = 3000;
    Bob.clothing.accessories = 1000;
    Bob.clothing.dry_clean = 500;
    Bob.clothing.repair = 300;
    Bob.clothing.sportswear = 1000;
    Bob.clothing.underwear = 500;
    Bob.clothing.socks = 200;
    Bob.clothing.hats = 300;
    Bob.clothing.gloves = 200;
    Bob.clothing.bags = 0;
    Bob.clothing.jewelry = 0;
    Bob.clothing.watches = 0;

    Bob.transport.public_transport = 2500;
    Bob.transport.taxi = 500;
    Bob.transport.taxi_work = 500;
    Bob.transport.taxi_weekend = 300;
    Bob.transport.train = 2000;
    Bob.transport.plane = 15000;
    Bob.transport.bus = 500;
    Bob.transport.subway = 300;
    Bob.transport.bicycle = 0;
    Bob.transport.scooter = 0;
    Bob.transport.rideshare = 0;
    Bob.transport.car_sharing = 0;

    Bob.entertainment.travel = 50'000;
    Bob.entertainment.hotel = 3000;
    Bob.entertainment.hostel = 1000;
    Bob.entertainment.camping = 600;
    Bob.entertainment.museum = 300;
    Bob.entertainment.theater = 800;
    Bob.entertainment.concert = 1200;
    Bob.entertainment.cinema = 500;
    Bob.entertainment.hobbies = 2000;
    Bob.entertainment.subscriptions = 1500;
    Bob.entertainment.sport = 2000;
    Bob.entertainment.souvenirs = 1500;
    Bob.entertainment.photos = 500;
    Bob.entertainment.books = 800;
    Bob.entertainment.music = 200;
    Bob.entertainment.games = 300;
    Bob.entertainment.streaming = 600;
    Bob.entertainment.nightclub = 0;
    Bob.entertainment.bar = 500;
    Bob.entertainment.karaoke = 0;
    Bob.entertainment.bowling = 0;
    Bob.entertainment.billiard = 0;
    Bob.entertainment.quests = 0;
    Bob.entertainment.amusement_park = 0;
    Bob.entertainment.zoo = 0;
    Bob.entertainment.aquarium = 0;

    Bob.misc.education = 10'000;
    Bob.misc.charity = 1000;
    Bob.misc.lottery = 100;
    Bob.misc.gambling = 500;
    Bob.misc.fines = 500;
    Bob.misc.taxes = 2000;
    Bob.misc.lawyer = 2000;
    Bob.misc.notary = 1000;
    Bob.misc.bank_fee = 200;
    Bob.misc.atm_fee = 150;
    Bob.misc.postal = 200;
    Bob.misc.furniture = 10'000;
    Bob.misc.electronics = 15000;
    Bob.misc.home_appliances = 8000;
    Bob.misc.kitchen = 1500;
    Bob.misc.bed_linen = 1000;
    Bob.misc.towels = 500;
    Bob.misc.gifts = 1000;
    Bob.misc.flowers = 200;
    Bob.misc.greeting_cards = 50;
    Bob.misc.pet_sitting = 0;
    Bob.misc.house_cleaning = 500;
    Bob.misc.pest_control = 0;
    Bob.misc.moving = 0;
    Bob.misc.storage = 0;
    Bob.misc.subscriptions_other = 200;
    Bob.misc.software = 300;
    Bob.misc.cloud_storage = 100;
    Bob.misc.domain_hosting = 50;
    Bob.misc.dating_sites = 0;

    Bob.deposit_month = 30'000;
    Bob.emergency_fund = 20'000;
}





void print_results(const Person &p)
{
    
}





int main()
{
    alice_init();
    bob_init();
    
    simulation_alice();
    simulation_bob();

    print_results(Alice);
    print_results(Bob);
}
