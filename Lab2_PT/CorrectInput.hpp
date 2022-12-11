#ifndef CORRECTINPUT_HPP
#define CORRECTINPUT_HPP

#include <iostream>
#include <numeric>
#include <algorithm>
#include <conio.h>

template <typename Type>
Type correct_input() {
    Type temp; std::cin >> temp;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect input! Enter the correct value" << std::endl;
        std::cin >> temp;
    }
    return temp;
}

template <typename Type>
Type correct_input(Type left, Type right) {
    Type temp; std::cin >> temp;
    while (std::cin.fail() || temp < left || temp > right) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect input! Enter the correct value" << std::endl;
        std::cin >> temp;
    }
    return temp;
}

#endif CORRECTINPUT_HPP