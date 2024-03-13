#include <iostream>
#include <utility>
#include <vector>

class Shape
{
public:
    Shape(double = 0, double = 0);
    virtual double getArea() = 0;// каждый доверний класс обязан реализовать иначе CE

    //virtual функцию можно переопределить в дочернем классе
    // override (в дочернем) -- явно указываем что будем перезаписывать
    virtual void print() const;
    std::pair<double, double> getCoords() const;

private:
    std::pair<double, double> coord;
};

void Shape::print() const
{
    std::cout << "this is shape:  " << coord.first << '\t' << coord.second << '\n';
}

class Square : public Shape
{
private:
    double side;

public:
    Square(std::pair<double, double>, double);
    void print() const override;
    double getArea() override;
};

Shape::Shape(double x, double y)
{
    this->coord = std::make_pair(x, y);
}

double Square::getArea()
{
    return side * side;
}

std::pair<double, double> Shape::getCoords() const
{
    return this->coord;
}

Square::Square(std::pair<double, double> coords, double side) : Shape(coords.first, coords.second)
{
    // часть конструктора реализуется по наследованию
    this->side = side;
}

void Square::print() const
{
    std::cout << "this is square:  " << this->getCoords().first << '\t' << this->getCoords().second << '\n';
}
int main()
{
    // Shape s{1, 1}; // не можем создать тк не реализована getArea()

    Square sq{{2, 2}, 2};
    // s.print();
    // sq.print();

    // std::unique_ptr<Shape> = std::make_unique(Square {{2, 2}, 2});
    Shape* sqPtr = new Square{{2, 2}, 3};

    // Shape* sPtr = new Shape{2, 3};

    sqPtr->print();
    // sPtr->print();

    // std::vector<Shape*> vecOfShapes{sqPtr, sPtr};

    // for (int i = 0; i < 2; i++)
    // {
    //     vecOfShapes[i]->print();
    // }


    // // нужно чтобы не делать delete, он сделает это сам когда выйдет из зоны видимости
    // std::unique_ptr<int> a = std::make_unique<int>(5);
    // std::unique_ptr<int> a2;
    // // a2 = a; // так не можем

    // std::shared_ptr<int> b = std::make_shared<int>(6);
    // std::shared_ptr<int> b2;
    // b2 = b;
}