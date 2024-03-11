#include <iostream>


class Rational {
public:
    //1
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    //2
    Rational operator+(const Rational &other) const {
        return Rational(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
    }

    //3
    Rational operator+(int number) const {
        return Rational(numerator + number * denominator, denominator);
    }


    //5
    Rational operator-(const Rational &other) const {
        return Rational(numerator * other.denominator - denominator * other.numerator, denominator * other.denominator);
    }

    //6
    Rational operator-(int number) const {
        return Rational(numerator - number * denominator, denominator);
    }

    //8
    Rational operator*(const Rational &other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    //9
    Rational operator*(int number) const {
        return Rational(numerator * number, denominator);
    }

    //11
    Rational operator/(const Rational &other) const {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    //12
    Rational operator/(int number) const {
        return Rational(numerator, denominator * number);
    }

    //14
    Rational operator+() const {
        return Rational(numerator, denominator);
    }

    //15
    Rational operator-() const {
        return Rational(-numerator, -denominator);
    }

    //18
    void operator+=(const Rational &other) {
        numerator = numerator * other.denominator + denominator * other.numerator;
        denominator = denominator * other.denominator;
    }

    //19
    void operator-=(const Rational &other) {
        numerator = numerator * other.denominator - denominator * other.numerator;
        denominator = denominator * other.denominator;
    }

    //20
    void operator*=(const Rational &other) {
        numerator = numerator * other.numerator;
        denominator = denominator * other.denominator;
    }

    //21
    void operator/=(const Rational &other) {
        numerator = numerator * other.denominator;
        denominator = denominator * other.numerator;
    }

    //22
    bool operator==(const Rational &other) {
        reduceFraction(*this);

        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational &other) {
        reduceFraction(*this);

        return !(numerator == other.numerator && denominator == other.denominator);
    }

    Rational operator++() {
        numerator += denominator;
        reduceFraction(*this);
        return *this;
    }

    Rational operator++(int) {
        return ++(*this);
    }

    Rational operator--() {
        numerator -= denominator;
        reduceFraction(*this);
        return *this;
    }

    Rational operator--(int) {
        return --(*this);
    }


    //16
    int getNumerator() const {
        return this->numerator;
    }

    //17
    int getDenominator() const {
        return this->denominator;
    }

    //extra
    friend void reduceFraction(Rational &obj) {
        int common = gcd(obj.numerator, obj.denominator);
        obj.numerator /= common;
        obj.denominator /= common;
    }

    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

private:
    int numerator;
    int denominator;
};

//4
Rational operator+(int number, const Rational &other) {
    return Rational(other.getNumerator() + number * other.getDenominator(), other.getDenominator());
}

//7
Rational operator-(int number, const Rational &other) {
    return Rational(number * other.getDenominator() - other.getNumerator(), other.getDenominator());
}

//10
Rational operator*(int number, const Rational &other) {
    return Rational(number * other.getNumerator(), other.getDenominator());
}

//13
Rational operator/(int number, const Rational &other) {
    return Rational(number * other.getDenominator(), other.getNumerator());
}
