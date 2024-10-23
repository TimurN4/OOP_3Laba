#include "../include/square.h"
#include "../include/point.h"
#include <cmath>

const double eps = 1e-6;

static double distance(const point& p1, const point& p2) {
    return std::sqrt((p1._x - p2._x) * (p1._x - p2._x) + (p1._y - p2._y) * (p1._y - p2._y));
}

bool square::valid_square() const { 
    double storona1 = distance(this->points[0], this->points[1]);
    double storona2 = distance(this->points[1], this->points[2]);
    double storona3 = distance(this->points[2], this->points[3]);
    double storona4 = distance(this->points[3], this->points[0]);
    double diagonal1 = distance(this->points[0], this->points[2]);
    double diagonal2 = distance(this->points[1], this->points[3]);

    if(storona1 == storona2 && storona2 == storona3 && storona3 == storona4 && storona1 == storona4 && diagonal1 == diagonal2) {
        return true;
    }
    else {
        throw std::invalid_argument("not square");
    }

    return true;
}

square::square(const point& x, const point& y, const point& z, const point& h) {
    this->points[0] = x;
    this->points[1] = y;
    this->points[2] = z;
    this->points[3] = h;
    valid_square();
}

square::square(const point tochki[4]) {
    for(int i = 0; i < 3; ++i) {
        this->points[i] = tochki[i];
    }
    valid_square();
}

square &square::operator=(const square &kvadrat) {
    //kvadrat.valid_square();
    //if(this != kvadrat) {
        for(int i = 0; i < 4; ++i) {
            this->points[i] = kvadrat.points[i];
        }
    //}
    return *this;
}

square &square::operator=(const square &&kvadrat) noexcept {
    for(int i = 0; i < 4; ++i) {
        this->points[i] = std::move(kvadrat.points[i]);
    }
    //this->points = kvadrat.points; whyyy
    return *this;
}

bool square::operator==(const figure &kvadrat) const {
    const square* trey = dynamic_cast<const square*>(&kvadrat);
    if(!trey) {
        return false;
    }
    for(int i = 0; i < 4; ++i) {
        if(this->points[i]._x != trey->points[i]._x || this->points[i]._y != trey->points[i]._y) {// whyyyyy
            return false;
        }
    }
    return true;
}

void square::get_points_of_figure() const {
    std::cout << *this << std::endl;
}

point square::get_center() const{
    double x_centre = (this->points[0]._x + this->points[2]._x) / 2;
    double y_centre = (this->points[0]._y + this->points[2]._y) / 2;

    return point{x_centre, y_centre};
}

square::operator double() const {
    //valid_square();
    double storona1 = sqrt(pow(this->points[0]._x - this->points[1]._x, 2) + pow(this->points[0]._y - this->points[1]._y, 2));
    return pow(storona1, 2);
}

std::istream& operator>>(std::istream& is, square& f) {
    point coordinats[4];
    is >> coordinats[0] >> coordinats[1] >> coordinats[2] >> coordinats[3];
    if(is.fail()) {
        throw std::invalid_argument("input fail");
    }
    for(int i = 0; i < 4; ++i) {
        f.points[i] = coordinats[i];
    }
    return is;

}

std::ostream& operator<<(std::ostream& os, const square& figure) {
    os << "coordinates of square\n";
    for(int i = 0; i < 4; ++i) {
        os << figure.points[i];
    }
    return os;
}