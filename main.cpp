#include <iostream>
#include "../include/point.h"
#include "../include/triangle.h"
#include "./include/square.h"
#include "./include/rectangle.h"
#include <string>

int main()
{
    int capacity = 2;
    int n = 0;
    figure **figures = new figure*[capacity];

    bool run = true;
    int choice;

    // std::cout << "1 - add figure" << std::endl;
    // std::cout << "2 - remove figure" << std::endl;
    // std::cout << "3 - get_total_area" << std::endl;
    // std::cout << "4 - exit" << std::endl;

    while(run) {
        std::cout << "---------\n";
        std::cout << "1 - add figure" << std::endl;
        std::cout << "2 - remove figure" << std::endl;
        std::cout << "3 - get_total_area" << std::endl;
        std::cout << "4 - exit" << std::endl;
        std::cout << "---------\n";

        std::cout << "choose comand\n";
        std::cin >> choice;
        switch (choice)
        {
            case 1: 
            {
                std::cout << "---------\n";
                std::cout << "1 - triangle" << std::endl;
                std::cout << "2 - square" << std::endl;
                std::cout << "3 - rectangle" << std::endl;
                std::cout << "---------\n";
                int number_of_figure;
                std::cin >> number_of_figure;
                switch(number_of_figure) 
                {
                    case 1:
                    {
                        point points[3];
                        for(int i = 0; i < 3; ++i) {
                            point tmp_point;
                            std::cin >> tmp_point;
                            points[i] = tmp_point;
                        }
                        triangle* triangle_from_user = new triangle(points[0], points[1], points[2]);
                        figures[n] = triangle_from_user;
                        n++;
                        break;
                    }
                    case 2:
                    {
                        point points[4];
                        for(int i = 0; i < 4; ++i) {
                            point tmp_point;
                            std::cin >> tmp_point;
                            points[i] = tmp_point;
                        }
                        square* square_from_user = new square(points[0], points[1], points[2], points[3]);
                        figures[n] = square_from_user;
                        n++;
                        break;
                    }
                    case 3:
                    {
                        point points[4];
                        for(int i = 0; i < 4; ++i) {
                            point tmp_point;
                            std::cin >> tmp_point;
                            points[i] = tmp_point;
                        }
                        rectangle* rectangle_from_user = new rectangle(points[0], points[1], points[2], points[3]);
                        figures[n] = rectangle_from_user;
                        n++;
                        break;
                    }
                    default:
                    {
                        std::cout << "invalide figure" <<std::endl;
                    }
                    if(n * 10 >= capacity * 8) 
                    {
                        //std::cout << capacity << std::endl;
                        figure **new_figures = new figure*[capacity * 2];
                        for(int i = 0; i < n; ++i) {
                            new_figures[i] = (figures)[i];
                        }
                        delete[] figures;
                        figures = new_figures;
                        capacity *= 2;
                        //std::cout << "resize was called\n";
                    }
                }
                break;
            }
            case 2:
            {
                int index_of_figure_to_delete;
                std::cin >> index_of_figure_to_delete;
                if(index_of_figure_to_delete < 0 || index_of_figure_to_delete >= capacity) {
                    std::cout << "invalid index to delete" << std::endl;
                }
                else {
                    if(index_of_figure_to_delete >= n) {
                        std::cout << "this item is already empty" << std::endl;
                    }
                    else {
                        delete figures[index_of_figure_to_delete];
                        for(int i = index_of_figure_to_delete + 1; i < capacity; ++i) {
                            figures[i - 1] = figures[i];
                        }
                        n--;
                    }
                }
                break;
            }
            case 3:
            {
                double area = 0;
                for(int i = 0; i < n; ++i) {
                    area += static_cast<double>(*figures[i]);
                }
                std:: cout << "total area " << area << std::endl;
                break;
            }
            case 4:
            {
                delete[] figures;
                std::cout << "end of program" << std::endl;
                return 0;
            }
            default:
            {
                std::cout << "invalid choice";
                break;
            }
        }
    }
    return 0;
}