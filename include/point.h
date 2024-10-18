#pragma once
#include <iostream>

class point {
    public :
        double _x, _y;
        point();
        point(double x, double y);
        //virtual ~point() noexcept;

        // bool operator==(const point& p);
        // bool operator!=(const point& p);
        friend std::istream& operator>>(std::istream& is, point& point);
        friend std::ostream& operator<<(std::ostream& os, const point& point);
};