#include <iostream>


class Rational {
public:
    //1
    Rational(int num = 0, int denom = 1) : nummm(num), dennnn(denom) {}

    //2
    Rational operator+(const Rational &other) const {
        return Rational(nummm * other.dennnn + dennnn * other.nummm, dennnn * other.dennnn);
    }

    //3
    Rational operator+(int number) const {
        return Rational(nummm + number * dennnn, dennnn);
    }


    //5
    Rational operator-(const Rational &other) const {
        return Rational(nummm * other.dennnn - dennnn * other.nummm, dennnn * other.dennnn);
    }

    //6
    Rational operator-(int number) const {
        return Rational(nummm - number * dennnn, dennnn);
    }

    //8
    Rational operator*(const Rational &other) const {
        return Rational(nummm * other.nummm, dennnn * other.dennnn);
    }

    //9
    Rational operator*(int number) const {
        return Rational(nummm * number, dennnn);
    }

    //11
    Rational operator/(const Rational &other) const {
        return Rational(nummm * other.dennnn, dennnn * other.nummm);
    }

    //12
    Rational operator/(int number) const {
        return Rational(nummm, dennnn * number);
    }

    //14
    Rational operator+() const {
        return Rational(nummm, dennnn);
    }

    //15
    Rational operator-() const {
        return Rational(-nummm, -dennnn);
    }

    //18
    void operator+=(const Rational &other) {
        nummm = nummm * other.dennnn + dennnn * other.nummm;
        dennnn = dennnn * other.dennnn;
    }

    //19
    void operator-=(const Rational &other) {
        nummm = nummm * other.dennnn - dennnn * other.nummm;
        dennnn = dennnn * other.dennnn;
    }

    //20
    void operator*=(const Rational &other) {
        nummm = nummm * other.nummm;
        dennnn = dennnn * other.dennnn;
    }

    //21
    void operator/=(const Rational &other) {
        nummm = nummm * other.dennnn;
        dennnn = dennnn * other.nummm;
    }

    //22
    bool operator==(const Rational &other) {
        reduceFraction(*this);

        return nummm == other.nummm && dennnn == other.dennnn;
    }

    bool operator!=(const Rational &other) {
        reduceFraction(*this);

        return !(nummm == other.nummm && dennnn == other.dennnn);
    }

    Rational operator++() {
        nummm += dennnn;
        reduceFraction(*this);
        return *this;
    }

    Rational operator++(int) {
        return ++(*this);
    }

    Rational operator--() {
        nummm -= dennnn;
        reduceFraction(*this);
        return *this;
    }

    Rational operator--(int) {
        return --(*this);
    }


    //16
    int numerator() const {
        return this->nummm;
    }

    //17
    int denominator() const {
        return this->dennnn;
    }

    //extra
    friend void reduceFraction(Rational &obj) {
        int common = gcd(obj.nummm, obj.dennnn);
        obj.nummm /= common;
        obj.dennnn /= common;
    }

    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

private:
    int nummm;
    int dennnn;
};

//4
Rational operator+(int number, const Rational &other) {
    return Rational(other.numerator() + number * other.denominator(), other.denominator());
}

//7
Rational operator-(int number, const Rational &other) {
    return Rational(number * other.denominator() - other.numerator(), other.denominator());
}

//10
Rational operator*(int number, const Rational &other) {
    return Rational(number * other.numerator(), other.denominator());
}

//13
Rational operator/(int number, const Rational &other) {
    return Rational(number * other.denominator(), other.numerator());
}
