#pragma once
#include "../include/point.h"
#include "../include/figure.h"

class rectangle : public figure{
    public :
        rectangle();
        rectangle(const point& x, const point& y, const point& z, const point& h);
        rectangle(const point points[4]);

        rectangle &operator=(const rectangle &pramoygolnik);
        rectangle &operator=(const rectangle &&pramoygolnik) noexcept;
        bool operator==(const figure &pramoygolnik) const;

        void get_points_of_figure() const;
        point get_center() const;
        operator double() const;

        friend std::istream& operator>>(std::istream& is, rectangle& f);
        friend std::ostream& operator<<(std::ostream& os, const rectangle& figure);
    private : 
        point points[4];
        bool valid_rectangle() const;
};