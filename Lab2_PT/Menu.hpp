#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <conio.h>
#include <iostream>

std::string menu(std::string items[], int numbers) {
	int position = 1;
	unsigned char key = 0;
	while (true) {
		system("cls");
		std::cout << items[0] << std::endl;
		for (auto i = 1; i < numbers; i++)
			std::cout << (i == position ? " > " : "   ") << items[i] << std::endl;
		key = _getch();
		if (key == 87 || key == 119 || key == 150 || key == 230) position--;
		else if (key == 83 || key == 115 || key == 155 || key == 235) position++;
		else if (key == 13) return items[position];
		if (position < 1) position = 1;
		if (position >= numbers) position = numbers - 1;
	}
}

#endif //MENU_HPP