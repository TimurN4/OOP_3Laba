#pragma once
#include "../include/point.h"
#include "../include/figure.h"

class square : public figure{
    public :
        square();
        square(const point& x, const point& y, const point& z, const point& h);
        square(const point points[4]);

        square &operator=(const square &kvadrat);
        square &operator=(const square &&kvadrat) noexcept;
        bool operator==(const figure &kvadrat) const;

        void get_points_of_figure() const;
        point get_center() const;
        operator double() const;

        friend std::istream& operator>>(std::istream& is, square& f);
        friend std::ostream& operator<<(std::ostream& os, const square& figure);
    private : 
        point points[4];
        bool valid_square() const;
};