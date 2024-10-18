#include "../include/point.h"


point::point() : _x(0), _y(0) {}

point::point(double x, double y) : _x(x), _y(y) {}

std::istream& operator>>(std::istream& is, point& point) {
    std::cout << "Вводи координаты точки\n";
    is >> point._x >> point._y;
    return is;
}
std::ostream& operator<<(std::ostream& os, const point& point) {
    os << "( " << point._x << ":" << point._y << " )\n";
    return os;
}

// bool point::operator==(const point& p) {
//     return this->_x == p._x && this->_y == p._y;
// }

// bool point::operator!=(const point& p) {
//     return this->_x != p._x || this->_y != p._y;
// }