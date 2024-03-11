#include <cmath>
#include <iostream>

class Complex
{
private:
    double re;
    double im;

public:
    Complex(double, double = 0);//чтобы не прописывать  Default constructor, неявно преобразует остальное в Complex
    Complex operator+(const Complex&) const;
    Complex operator+(double) const;

    Complex operator-(const Complex&) const;
    Complex operator-(double) const;

    Complex operator*(const Complex&) const;
    Complex operator*(double) const;

    Complex operator/(const Complex&) const;

    bool operator==(const Complex&) const;
    bool operator!=(const Complex&) const;

    Complex operator+();
    Complex operator-();

    double Re() const;
    double Im() const;

    friend std::ostream& operator<<(std::ostream& ss, const Complex& comp);
};

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

std::ostream& operator<<(std::ostream& ss, const Complex& comp)
{
    if (comp.im == 0)
    {
        ss << comp.re;
    }
    else if (comp.im < 0)
    {
        ss << comp.re << comp.im << "i";
    }
    else
    {
        ss << comp.re << "+" << comp.im << "i";
    }
    return ss;
}

Complex Complex::operator+(const Complex& other) const
{
    return Complex{re + other.re, im + other.im};
}

Complex Complex::operator+(double right) const
{
    return *this + Complex{right};
};

Complex operator+(double left, const Complex& right)
{
    return right + left;
}

Complex Complex::operator-(const Complex& other) const
{
    return Complex{re - other.re, im - other.im};
}

Complex Complex::operator-(double right) const
{
    return *this - Complex{right};
};

Complex operator-(double left, const Complex& right)
{
    return -(right - left);
}

Complex Complex::operator*(const Complex& other) const
{
    return Complex{re * other.re - im * other.im, re * other.im + im * other.re};
}

Complex Complex::operator*(double right) const
{
    return (*this) * Complex{right};
}

Complex operator*(double left, const Complex& other)
{
    return other * left;
}

Complex Complex::operator/(const Complex& other) const
{
    return Complex{(re * other.re + im * other.im) / (std::pow(other.re, 2) + std::pow(other.im, 2)),
                   (im * other.re - re * other.im) / (std::pow(other.re, 2) + std::pow(other.im, 2))};
}

bool Complex::operator==(const Complex& other) const
{
    return (re == other.re && im == other.im);
}
bool Complex::operator!=(const Complex& other) const
{
    return (re != other.re || im != other.im);
}

double abs(const Complex& comp)
{
    return std::pow(std::pow(comp.Re(), 2) + std::pow(comp.Im(), 2), 0.5);
}

Complex Complex::operator+()
{
    return Complex{+re, +im};
}

Complex Complex::operator-()
{
    return Complex{-re, -im};
}

double Complex::Re() const
{
    return this->re;
}

double Complex::Im() const
{
    return this->im;
}

int main()
{
    Complex comp1{1, 1};
    Complex comp2{2, 2};
    // std::cout << comp2.abs();
}