#include "../include/rectangle.h"
#include "../include/point.h"
#include <cmath>

const double eps = 1e-6;

static double distance(const point& p1, const point& p2) {
    return std::sqrt((p1._x - p2._x) * (p1._x - p2._x) + (p1._y - p2._y) * (p1._y - p2._y));
}

bool rectangle::valid_rectangle() const { 
    double storona1 = distance(this->points[0], this->points[1]);
    double storona2 = distance(this->points[1], this->points[2]);
    double storona3 = distance(this->points[2], this->points[3]);
    double storona4 = distance(this->points[3], this->points[0]);
    double diagonal1 = distance(this->points[0], this->points[2]);
    double diagonal2 = distance(this->points[1], this->points[3]);

    if(storona1 == storona3 && storona2 == storona4 && diagonal1 == diagonal2) {
        return true;
    }
    else {
        throw std::invalid_argument("not rectangle");
    }

    return true;
}

rectangle::rectangle(const point& x, const point& y, const point& z, const point& h) {
    this->points[0] = x;
    this->points[1] = y;
    this->points[2] = z;
    this->points[3] = h;
    valid_rectangle();
}

rectangle::rectangle(const point tochki[4]) {
    for(int i = 0; i < 3; ++i) {
        this->points[i] = tochki[i];
    }
    valid_rectangle();
}

rectangle &rectangle::operator=(const rectangle &kvadrat) {
    //kvadrat.valid_rectangle();
    //if(this != kvadrat) {
        for(int i = 0; i < 4; ++i) {
            this->points[i] = kvadrat.points[i];
        }
    //}
    return *this;
}

rectangle &rectangle::operator=(const rectangle &&kvadrat) noexcept {
    for(int i = 0; i < 4; ++i) {
        this->points[i] = std::move(kvadrat.points[i]);
    }
    //this->points = kvadrat.points; whyyy
    return *this;
}

bool rectangle::operator==(const figure &kvadrat) const {
    const rectangle* trey = dynamic_cast<const rectangle*>(&kvadrat);
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

void rectangle::get_points_of_figure() const {
    std::cout << *this << std::endl;
}

point rectangle::get_center() const{
    double x_centre = (this->points[0]._x + this->points[2]._x) / 2;
    double y_centre = (this->points[0]._y + this->points[2]._y) / 2;

    return point{x_centre, y_centre};
}

rectangle::operator double() const {
    //valid_rectangle();
    double storona1 = distance(this->points[0], this->points[1]);
    double storona2 = distance(this->points[1], this->points[2]);
    return storona1 * storona2;
}

std::istream& operator>>(std::istream& is, rectangle& f) {
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

std::ostream& operator<<(std::ostream& os, const rectangle& figure) {
    os << "coordinates of rectangle\n";
    for(int i = 0; i < 4; ++i) {
        os << figure.points[i];
    }
    return os;
}