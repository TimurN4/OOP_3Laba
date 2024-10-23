#pragma once
#include "../include/point.h"
#include "iostream"
#include "cmath"

class figure {
    public :
        virtual void get_points_of_figure() const = 0;
        virtual point get_center() const = 0;
        virtual operator double() const = 0;

        virtual bool operator==(const figure& f) const = 0;
        friend std::istream& operator>>(std::istream& is, figure& f);
        friend std::ostream& operator<<(std::ostream& os, const figure& figure);

        virtual ~figure() noexcept = default;
};