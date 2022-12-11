#ifndef NOTE_HPP
#define NOTE_HPP

#include "CorrectInput.hpp"

class Note {
private:
	std::string last_name;
	std::string first_name;
	std::string phone_number;
	int birthday[3] = {0, 0, 0};

public:
	Note() {
		std::cout << "The constructor without parameters of the class Note is called" << std::endl;
	};
	Note(const std::string& last_name_, const std::string& first_name_,
		const std::string& phone_number_, int birthday_[3])
	{
		std::cout << "The constructor with the parameters of the class Note is called" << std::endl;
		last_name = last_name_;
		first_name = first_name_;
		phone_number = phone_number_;
		memcpy(birthday, birthday_, sizeof birthday_);
	}
	Note(const Note& that) {
		std::cout << "The copy constructor of the class Note is called" << std::endl;
		last_name = that.last_name;
		first_name = that.first_name;
		phone_number = that.phone_number;
		memcpy(birthday, that.birthday, sizeof that.birthday);
	}
	~Note() {
		std::cout << "The deconstructor of the class Note is called" << std::endl;
	};

	void set_last_name(const std::string& last_name_) { last_name = last_name_; }
	void set_first_name(const std::string& first_name_) { first_name = first_name_; }
	void set_phone_number(const std::string& phone_number_) { phone_number = phone_number_; }
	void set_birthday(int birthday_[3]) { memcpy(birthday, birthday_, 3*sizeof(int)); }
	
	std::string get_last_name() const { return last_name; }
	std::string get_first_name() const { return first_name; }
	std::string get_phone_number() const { return phone_number; }
	int* get_birthday() { return birthday; }

	void print() {
		std::cout << (last_name + " " + first_name) << "\t"	<<
			(birthday[0] < 10 ? "0" : "") << birthday[0] << "." <<
			(birthday[1] < 10 ? "0" : "") << birthday[1] << "." <<
			birthday[2] << "\t" << phone_number << std::endl;
	}
	void edit() {
		std::string items[] = {
			"Select the option to change",
			"Last name",
			"First name",
			"Phone number",
			"Birthday",
			"Back" };
		std::string choice;
		int position = 1;
		unsigned char key = 0;
		while (true) {
			system("cls");
			print();
			std::cout << std::endl << items[0] << std::endl;
			for (auto i = 1; i < 6; i++)
				std::cout << (i == position ? " > " : "   ") << items[i] << std::endl;
			key = _getch();
			if (key == 87 || key == 119 || key == 150 || key == 230) position--;
			else if (key == 83 || key == 115 || key == 155 || key == 235) position++;
			else if (key == 13) {
				choice = items[position];
				break;
			}
			if (position < 1) position = 1;
			if (position >= 6) position = 5;
		}
		system("cls");
		if (choice == items[5]) return;
		print();
		std::cout << "Enter new value\n";
		if (choice == items[1])
			std::cin >> last_name;
		else if (choice == items[2])
			std::cin >> first_name;
		else if (choice == items[3]) {
			std::string field; std::cin >> field;
			while (true) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (std::all_of(field.begin(), field.end(), ::isdigit))
					phone_number = field;
				std::cout << "Incorrect input! Enter the correct value" << std::endl;
				std::cin >> field;
			}
		}
		else if (choice == items[4]) {
			int birthday[3];
			birthday[0] = correct_input<int>(1, 31);
			birthday[1] = correct_input<int>(1, 12);
			birthday[2] = correct_input<int>(1900, 3000);
			set_birthday(birthday);
		}
		print();
		system("pause");
	}
};

#endif //NOTE_HPP