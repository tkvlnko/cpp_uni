#include <iostream>
#include <cmath>

class Complex {
    private:
        double re;
        double im;

    public:
        Complex (double, double=0); //чтобы не прописывать  Default constructor, неявно преобразует остальное в Complex
        Complex operator+ (const Complex&);
        Complex operator- (const Complex&);
        Complex operator* (const Complex&);
        Complex operator/ (const Complex&);

        bool operator== (const Complex&);
        bool operator!= (const Complex&);

        Complex operator+ ();
        Complex operator- ();

        double abs();
        double Re();
        double Im();

    friend std::ostream& operator<< (std::ostream& ss, const Complex& comp);

};

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

std::ostream& operator<<(std::ostream& ss, const Complex& comp){
    if (comp.im == 0) {
        ss << comp.re; 
    } else if (comp.im < 0) {
        ss << comp.re << comp.im << "i";
    } else {
        ss << comp.re << "+" << comp.im << "i";
    }
    return ss;
}

Complex Complex::operator+(const Complex& other) {
    return Complex {re + other.re, im + other.im};
}

Complex Complex::operator-(const Complex& other) {
    return Complex {re - other.re, im - other.im};
}

Complex Complex::operator*(const Complex& other) {
    return Complex {re * other.re - im * other.im, re * other.im + im * other.re};
}

Complex Complex::operator/(const Complex& other) {
    return Complex {(re * other.re + im * other.im)/(std::pow(other.re, 2) + std::pow(other.im, 2)), 
    (im * other.re - re * other.im)/(std::pow(other.re, 2) + std::pow(other.im, 2))};
}

bool Complex::operator==(const Complex& other) {
    return (re == other.re && im == other.im);
}
bool Complex::operator!=(const Complex& other) {
    return (re != other.re || im != other.im);
}

double Complex::abs() 
{
    return std::pow(std::pow(re, 2) + std::pow(im, 2), 0.5);
}

Complex Complex::operator+() 
{
    return Complex {+re, +im};
}

Complex Complex::operator-() {
    return Complex {-re, -im};
}

double Complex::Re() {
    return this->re;
}

double Complex::Im() {
    return this->im;
}

int main() {
    Complex comp1 {1, 1};
    Complex comp2 {2};
    std::cout << comp1.Im();
}