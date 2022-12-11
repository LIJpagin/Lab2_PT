#ifndef LIST_HPP
#define LIST_HPP

#include "Note.hpp"

struct Item {
	Note* data;
	Item* next{ nullptr }, * prev{ nullptr };
};

class List {
protected:
	Item* m_beg{ nullptr }, * m_end{ nullptr };
	int m_size{ 0 };
	bool correct_index(int index);
	Item* move(int index);

public:
	List() {};
	~List() { clear(); };

	int size() const;
	bool is_empty() const;

	void add_end(Note* data);
	void add_begin(Note* data);
	void insert(int index, Note* data);

	Note* get(int index);
	void set(Note* data, int index);
	void print();

	void find_person(std::string last_name);
	void sort_phone_numbers();

	void erase(int index);
	void clear();
};

#endif //LIST_HPP