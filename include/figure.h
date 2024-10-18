#pragma once
#include "../include/point.h"
#include "iostream"
#include "cmath"

class figure {
    public :
        virtual void get_points_of_figure() const;
        virtual point get_center() const;
        virtual operator double() const;

        virtual bool operator==(const figure& f) const;
        friend std::istream& operator>>(std::istream& is, figure& f);
        friend std::ostream& operator<<(std::ostream& os, figure& figure);

        virtual ~figure() noexcept = default;
};