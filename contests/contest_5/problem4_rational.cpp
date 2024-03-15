#include <iostream>
#include <numeric>

class Rational
{
private:
    int num;
    int den;

public:
    Rational(int = 0, int = 1);
    Rational operator+(const Rational&);
    Rational operator+=(const Rational&);
    Rational operator-=(const Rational&);
    Rational operator*=(const Rational&);
    Rational operator/=(const Rational&);

    Rational& operator++();
    Rational& operator--();
    Rational operator++(int);
    Rational operator--(int);

    Rational operator-(const Rational&);
    Rational operator*(const Rational&);
    Rational operator/(const Rational&);

    bool operator==(const Rational&);
    bool operator!=(const Rational&);

    Rational operator+();
    Rational operator-();


    friend void normalize(Rational& other)
    {
        int gcd1 = Rational::gcd(other.num, other.den);
        other.num = other.num / gcd1;
        other.den = other.den / gcd1;
        if (other.den < 0)
        {
            other.den = -other.den;
            other.num = -other.num;
        }
    }
    double numerator() const;
    double denominator() const;

    friend std::ostream& operator<<(std::ostream& ss, const Rational& comp);
    static int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};


Rational::Rational(int num, int den)
{
    this->num = num;
    this->den = den;
    normalize(*this);
}

double Rational::numerator() const
{

    return num;
}

double Rational::denominator() const
{

    return den;
}

//unary -
Rational Rational::operator-()
{
    return {-num, den};
}

//unary +
Rational Rational::operator+()
{
    return {num, den};
}


Rational Rational::operator+(const Rational& other)
{
    int comDen = std::lcm(den, other.den);
    return {((num * comDen / den) + (other.num * comDen / other.den)), comDen};
}

Rational Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

// int + rational
Rational operator+(int num, Rational& rational)
{
    return rational + num;
}


Rational Rational::operator-(const Rational& other)
{
    int comDen = std::lcm(den, other.den);
    return {((num * comDen / den) - (other.num * comDen / other.den)), comDen};
}

Rational Rational::operator-=(const Rational& other)
{
    *this = *this - other;
    return *this;
}

// int - rational
Rational operator-(int num, Rational& rational)
{
    return (-(rational - num));
}


Rational Rational::operator*(const Rational& other)
{
    return {num * other.num, den * other.den};
}

Rational Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    return *this;
}

// int * rational
Rational operator*(int i, Rational& other)
{
    return (other * i);
}


Rational Rational::operator/(const Rational& other)
{
    return {num * other.den, den * other.num};
}

Rational Rational::operator/=(const Rational& other)
{
    *this = *this / other;
    return *this;
}

// int / rational
Rational operator/(int i, Rational& other)
{
    return (Rational{i, 1} / other);
}


bool Rational::operator==(const Rational& other)
{
    return ((num == other.num) && (den == other.den));
}
bool Rational::operator!=(const Rational& other)
{
    return !((num == other.num) && (den == other.den));
}

Rational& Rational::operator++()
{
    *this += 1;
    return *this;
}

Rational Rational::operator++(int)
{
    Rational r = *this;
    // *this = *this + 1;
    ++(*this);
    return r;
}

Rational& Rational::operator--()
{
    *this = *this - 1;

    return *this;
}

Rational Rational::operator--(int)
{
    Rational r = *this;
    // *this = *this - 1;
    --(*this);

    return r;
}

std::ostream& operator<<(std::ostream& ss, const Rational& r)
{
    if (r.num == 0)
    {
        ss << 0;
    }
    else
    {
        ss << r.num << "/" << r.den;
    }
    return ss;
}