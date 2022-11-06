#pragma once
#ifndef NOTE_HPP
#define NOTE_HPP

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Note {
public:
	string last_name;
	string first_name;
	string phone_number;
	int birthday[3] = {0, 0, 0};

	Note() {
		cout << "The constructor without parameters of the class Note is called" << endl;
	};
	Note(const string& last_name_, const string& first_name_,
		const string& phone_number_, int birthday_[3])
	{
		cout << "The constructor with the parameters of the class Note is called" << endl;
		last_name = last_name_;
		first_name = first_name_;
		phone_number = phone_number_;
		memcpy(birthday, birthday_, sizeof birthday_);
	}
	Note(const Note& that) {
		cout << "The copy constructor of the class Note is called" << endl;
		last_name = that.last_name;
		first_name = that.first_name;
		phone_number = that.phone_number;
		memcpy(birthday, that.birthday, sizeof that.birthday);
	}
	~Note() {
		cout << "The deconstructor of the class Note is called" << endl;
	};

	void set_last_name(const string& last_name_) { last_name = last_name_; }
	void set_first_name(const string& first_name_) { first_name = first_name_; }
	void set_phone_number(const string& phone_number_) { phone_number = phone_number_; }
	void set_birthday(int birthday_[3]) { memcpy(birthday, birthday_, sizeof birthday_); }
	
	string get_last_name() const { return last_name; }
	string get_first_name() const { return first_name; }
	string get_phone_number() const { return phone_number; }
	//int* get_birthday() const { return birthday; }
};

#endif //NOTE_HPP