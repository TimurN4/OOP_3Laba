#include "../include/triangle.h"
#include "../include/point.h"
#include <cmath>

const double eps = 1e-6;

bool triangle::valid_triangle() const { // y = kx + b
    double k = (this->points[1]._y - this->points[0]._y) / (this->points[1]._x - this->points[0]._x);
    double b = (((this->points[1]._x - this->points[0]._x) * this->points[0]._y) - ((this->points[1]._y - this->points[0]._y) * this->points[0]._x)) / 
    (this->points[1]._x - this->points[0]._x);
    double kx_plus_b = k * this->points[2]._x + b;

    if(abs(this->points[2]._y - kx_plus_b) > eps) {
        throw std::invalid_argument("all 3 points are on the same line");
    }

    return true;
}

triangle::triangle(const point& x, const point& y, const point& z) {
    this->points[0] = x;
    this->points[1] = y;
    this->points[2] = z;
    valid_triangle();
}

triangle::triangle(const point tochki[3]) {
    for(int i = 0; i < 3; ++i) {
        this->points[i] = tochki[i];
    }
    valid_triangle();
}

triangle &triangle::operator=(const triangle &treygolnik) {
    //treygolnik.valid_triangle();
    //if(this != treygolnik) {
        for(int i = 0; i < 3; ++i) {
            this->points[i] = treygolnik.points[i];
        }
    //}
    return *this;
}

triangle &triangle::operator=(const triangle &&treygolnik) noexcept{
    for(int i = 0; i < 3; ++i) {
        this->points[i] = std::move(treygolnik.points[i]);
    }
    //this->points = treygolnik.points; whyyy
    return *this;
}

bool triangle::operator==(const figure &treygolnik) const {
    const triangle* trey = dynamic_cast<const triangle*>(&treygolnik);
    if(!trey) {
        return false;
    }
    for(int i = 0; i < 3; ++i) {
        if(this->points[i]._x != trey->points[i]._x || this->points[i]._y != trey->points[i]._y) {// whyyyyy
            return false;
        }
    }
    return true;
}

void triangle::get_points_of_figure() const {
    std::cout << *this << std::endl;
}

point triangle::get_center() const{
    double x_centre = (this->points[0]._x + this->points[1]._x + this->points[2]._x) / 3;
    double y_centre = (this->points[0]._y + this->points[1]._y + this->points[2]._y) / 3;

    return point{x_centre, y_centre};
}

triangle::operator double() const {
    double storona1 = sqrt(pow(this->points[0]._x - this->points[1]._x, 2) + pow(this->points[0]._y - this->points[1]._y, 2));
    double storona2 = sqrt(pow(this->points[1]._x - this->points[2]._x, 2) + pow(this->points[1]._y - this->points[2]._y, 2));
    double storona3 = sqrt(pow(this->points[2]._x - this->points[0]._x, 2) + pow(this->points[2]._y - this->points[0]._y, 2));
    double polyperimetr = (storona1 + storona2 + storona3) / 2;
    return sqrt(polyperimetr * (polyperimetr - storona1) * (polyperimetr - storona2) * (polyperimetr - storona3));
}

std::istream& operator>>(std::istream& is, triangle& f) {
    point coordinats[3];
    is >> coordinats[0] >> coordinats[1] >> coordinats[2];
    if(is.fail()) {
        throw std::invalid_argument("input fail");
    }
    for(int i = 0; i < 3; ++i) {
        f.points[i] = coordinats[i];
    }
    return is;

}

std::ostream& operator<<(std::ostream& os, triangle& figure) {
    os << "coordinates of triangle\n";
    for(int i = 0; i < 3; ++i) {
        os << figure.points[i];
    }
    return os;
}