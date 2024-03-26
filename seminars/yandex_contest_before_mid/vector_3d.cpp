#include <iostream>

class Vector3D
{
public:
    // double
    Vector3D(double = 0.0, double = 0.0, double = 0.0);

private:
    double _x;
    double _y;
    double _z;
};

Vector3D::Vector3D(double _x, double _y, double _z)
{
    this->_x = _x;
    this->_y = _y;
    this->_z = _z;
}
