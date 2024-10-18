#include <iostream>
#include "src/triangle.cpp"

int main()
{
    try
    {
        triangle t1(point(0, 0), point(1, 0), point(0, 1));
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}