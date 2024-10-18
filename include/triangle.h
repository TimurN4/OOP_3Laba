#pragma once
#include "../include/point.h"
#include "../include/figure.h"

class triangle : public figure{
    public :
        triangle();
        triangle(const point& x, const point& y, const point& z);
        triangle(const point points[3]);

        triangle &operator=(const triangle &treygolnik);
        triangle &operator=(const triangle &&treygolnik) noexcept;
        bool operator==(const figure &treygolnik) const;

        void get_points_of_figure() const;
        point get_center() const;
        operator double() const;

        friend std::istream& operator>>(std::istream& is, triangle& f);
        friend std::ostream& operator<<(std::ostream& os, triangle& figure);

        bool valid_triangle() const;
    private : 
        point points[3];
};