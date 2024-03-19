/* Вам надо написать класс Date для хранения даты григорианского календаря. Используйте три переменных типа int для хранения дня, месяца и года.
В вашем классе должен быть следующий публичный интерфейс:

Конструктор, принимающий на вход три числа: день, месяц и год.
В случае некорректной даты должна создаваться дата 1 января 1970 года.

Константные функции GetDay, GetMonth и GetYear.
Бинарные операторы + и -, где вторым аргументом является целое число — количество дней.
Эти операторы должны вернуть новую дату, отстоящую от заданной на указанное число дней.
Бинарный оператор -, вычисляющий разность между двумя датами и возвращающий int – количество дней.
*/

#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> months{
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31}};

class Date
{
private:
    int day, month, year;

public:
    Date(int, int, int);
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;

    Date operator+(int);
    Date operator-(int);
    Date operator-(const Date&);
};

bool isLeap(int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

bool isCorrectDate(int day, int month, int year)
{
    if (year < 1970 || year > 2099 || month > 12 || day > 31 || day < 1)
    {
        return false;
    }
    else if (isLeap(year) && month == 2)
    {
        return day <= 29;
    }
    else if (!(isLeap(year)) && month == 2)
    {
        return day <= 28;
    }
    else if (day > months[month])
    {
        return false;
    }
    else
    {
        return true;
    }
};


Date::Date(int day, int month, int year)
{

    if (isCorrectDate(day, month, year))
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    else
    {
        this->day = 1;
        this->month = 1;
        this->year = 1970;
    }
}

int Date::GetDay() const
{
    return this->day;
}

int Date::GetMonth() const
{
    return this->month;
}

int Date::GetYear() const
{
    return this->year;
}

// 3 days
// 12.04.2024

Date Date::operator+(int days)
{
    while (days > 0)
    {
        if (this->month == 2)
        {
            if (isLeap(this->year))
            {
                months[2] = 29;
            }
            else
            {
                months[2] = 28;
            }
        }
        // std::cout << days;
        if (months[this->month] < days)
        {
            days -= months[this->month];
            if (this->month == 12)
            {
                this->year += 1;
                this->month = 1;
            }
            else
            {
                this->month += 1;
            }
        }
        else
        {
            if (this->day + days > months[this->month])
            {
                this->day = days - months[this->month] + this->day;
                if (this->month == 12)
                {
                    this->year += 1;
                    this->month = 1;
                }
                else
                {
                    this->month += 1;
                }
                break;
            }
            else
            {
                this->day += days;
                break;
            }
        }
    }
    return *this;
}

int main()
{
    Date data{12, 4, 2024};
    Date data2 = data + 1000;
    std::cout << data2.GetDay() << '\t' << data2.GetMonth() << '\t' << data2.GetYear();
}