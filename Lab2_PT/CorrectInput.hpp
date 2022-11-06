#pragma once
#ifndef CORRECTINPUT_HPP
#define CORRECTINPUT_HPP

#include <iostream>
#include <numeric>
#include <algorithm>

template <typename Type>
Type correct_input() {
    Type temp;
    std::cin >> temp;
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
    Type temp;
    std::cin >> temp;
    while (std::cin.fail() || temp < left || temp > right) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect input! Enter the correct value" << std::endl;
        std::cin >> temp;
    }
    return temp;
}

std::string trim(std::string str) {
	size_t begin = str.find_first_not_of(" \t");
	if (begin == std::string::npos) return "";
	size_t end = str.find_last_not_of(" \t");
	size_t range = end - begin + 1;
	return str.substr(begin, range);
}

std::string split(std::string& str, char ch) {
	size_t sep = str.find(ch);
	if (sep == std::string::npos) return "";
    std::string sub = str.substr(0, sep);
	str.erase(0, sep + 1);
	sub = trim(sub);
	str = trim(str);
	return sub;
}

#endif CORRECTINPUT_HPP