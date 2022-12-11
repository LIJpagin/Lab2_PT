#include "List.hpp"
#include "Menu.hpp"

void menu_create(List& list) {
	Note* note = new Note;
	std::cout << "Enter the following fields\n";
	std::string field;

	std::cout << "Last name: ";
	std::cin >> field; note->set_last_name(field);
	std::cout << "First name: ";
	std::cin >> field; note->set_first_name(field);
	std::cout << "Phone number: ";
	std::cin >> field;
	while (true) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (field.length() == 11 && std::all_of(field.begin(), field.end(), ::isdigit)) {
			note->set_phone_number(field);
			break;
		}
		std::cout << "Incorrect input! Enter the correct value" << std::endl;
		std::cin >> field;
	}
	std::cout << "Birthday: ";
	int birthday[3];
	birthday[0] = correct_input<int>(1, 31);
	birthday[1] = correct_input<int>(1, 12);
	birthday[2] = correct_input<int>(1900, 3000);
	note->set_birthday(birthday);

	std::string items[] = {
		"Choose where to add a note",
		"To the beginning",
		"By index",
		"To the end",
		"Back" };
	std::string choice = menu(items, 5);

	if (choice == items[1])
		list.add_begin(note);
	else if (choice == items[2]) {
		std::cout << "Enter the note index\n";
		int index = correct_input<int>(1, list.size() - 1);
		list.insert(index, note);
	}
	else if (choice == items[3])
		list.add_end(note);
}
void menu_show(List& list) {
	if (list.is_empty()) {
		std::cout << "The list is empty, first create a note\n";
		system("pause");
		return;
	}
	std::string items[] = {
		"Select an action",
		"Show note by index",
		"Show all notes",
		"Back" };
	std::string choice = menu(items, 4);
	system("cls");

	if (choice == items[1]) {
		std::cout << "Enter the note index" << std::endl;
		int index = correct_input<int>(0, list.size() - 1);
		list.get(index)->print();
	}
	else if (choice == items[2])
		list.print();
	else if (choice == items[3])
		return;
	system("pause");
}
void menu_del(List& list) {
	if (list.is_empty()) {
		std::cout << "The list is empty, no deletion required\n";
		system("pause");
		return;
	}
	std::string items[] = {
		"Select an action",
		"Delete a note by index",
		"Delete all notes",
		"Back" };
	std::string choice = menu(items, 4);
	system("cls");

	if (choice == items[1]) {
		std::cout << "Enter the note index\n";
		int index = correct_input<int>(1, list.size() - 1);
		list.erase(index);
	}
	else if (choice == items[2])
		list.clear();
	else if (choice == items[3])
		return;
	system("pause");
}

#if 1

int main() {
	List list;
	while (true) {
		std::string items[] = {
			"Select an action",
			"Create",
			"Edit",
			"Show",
			"Sort",
			"Find",
			"Delete",
			"Quit" };
		std::string choice = menu(items, 8);
		system("cls");

		if (choice == items[1])
			menu_create(list);
		else if (choice == items[2]) {
			if (list.is_empty()) {
				std::cout << "The list is empty, first edit a note\n";
				system("pause");
			}
			else {
				std::cout << "Enter the note index\n";
				int index = correct_input<int>(0, list.size() - 1);
				list.get(index)->edit();
			}
		}
		else if (choice == items[3])
			menu_show(list);
		else if (choice == items[4]) {
			if (list.is_empty()) {
				std::cout << "The list is empty, first edit a note\n";
				system("pause");
			}
			else {
				list.sort_phone_numbers();
				list.print();
				system("pause");
			}
		}
		else if (choice == items[5]) {
			if (list.is_empty()) {
				std::cout << "The list is empty, first edit a note\n";
				system("pause");
			}
			else {
				std::cout << "Enter the last name person\n";
				std::string field; std::cin >> field;
				list.find_person(field);
				system("pause");
			}
		}
		else if (choice == items[6])
			menu_del(list);
		else if (choice == items[7])
			exit(0);

		system("cls");
	}
	return 0;
}

#else

#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

ifstream file;	//ËÒıÓ‰Ì˚È Ù‡ÈÎ

int main() {
	setlocale(LC_ALL, "Rus");
	std::cout << "¬‚Â‰ËÚÂ ËÏˇ Ù‡ÈÎ‡: ";
	std::string name, line;
	char c;
	bool f = true;

	try {
		std::cin >> name;
		file.open(name);
		if (!file) throw 1;
		if (file.peek() == ifstream::traits_type::eof()) throw 2;
	}
	catch (int i) {
		f = false;
		std::cout << "Œ¯Ë·Í‡ π" << i << ": ";
		switch (i) {
		case 1:
			std::cout << "ÕÂ‚ÂÌÓÂ ËÏˇ Ù‡ÈÎ‡" << std::endl;
			break;
		case 2:
			std::cout << "‘‡ÈÎ ÔÛÒÚÓÈ" << std::endl;
			file.close();
			break;
		}
	}

	std::string number[] = { " ÕŒÀ‹ ", " Œƒ»Õ ", " ƒ¬¿ ", " “–» ", " ◊≈“€–≈ ",
		" œﬂ“‹ ", " ÿ≈—“‹ ", " —≈Ã‹ ", " ¬Œ—≈Ã‹ ", " ƒ≈¬ﬂ“‹ " };

	if (f) {
		while (!file.eof()) {
			while (getline(file, line, '\n')) {
				for (int i = 0; i < line.size(); i++) {
					c = line[i];
					if (isdigit(c)) std::cout << number[atoi(&c)];
					else if (c == '.' || c == '!' || c == '?')
						std::cout << c << std::endl;
					else std::cout << c;
				}
			}
		}
		file.close();
	}
	std::cout << std::endl;
	return 0;
}
#endif