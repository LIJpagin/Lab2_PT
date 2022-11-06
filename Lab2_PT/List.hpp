#pragma once
#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

template <class Type>
struct Item {
	Type data;
	Item<Type>* next{ nullptr }, * prev{ nullptr };
};

template <class Type>
class List {
protected:
	Item<Type>* m_beg{ nullptr }, * m_end{ nullptr };
	int m_size{ 0 };
	bool correct_index(int index);
	Item<Type>* move(int index);

public:
	List() {};
	~List() { clear(); };

	int size() const;
	bool is_empty() const;

	void add_end(Type data);
	void add_begin(Type data);
	void insert(int index, Type data);

	Type get(int index);
	void set(Type data, int index);

	void erase(int index);
	void clear();
};

template <class Type>
bool List<Type>::correct_index(int index) {
	return 0 <= index && index < m_size;
}
template <class Type>
Item<Type>* List<Type>::move(int index) {
	bool is_begin = index <= m_size / 2;
	Item<Type>* ptr = is_begin ? m_beg : m_end;
	for (size_t i = 0; i < (is_begin ? index : m_size - index - 1); i++)
		ptr = is_begin ? ptr->next : ptr->prev;
	return ptr;
}

template <class Type>
bool List<Type>::is_empty() const {
	return !m_size;
}
template <class Type>
int List<Type>::size() const {
	return m_size;
}

template <class Type>
void List<Type>::add_end(Type data) {
	try {
		Item<Type>* temp = new Item<Type>;
		temp->data = data;
		if (!m_beg)
			m_beg = m_end = temp;
		else {
			m_end->next = temp;
			temp->prev = m_end;
			m_end = temp;
		}
		m_size++;
	}
	catch (const std::bad_alloc& error) {
		std::cout << "Error: " << error.what() << std::endl;
	}
}
template <class Type>
void List<Type>::add_begin(Type data) {
	try {
		Item<Type>* temp = new Item<Type>;
		temp->data = data;
		if (!m_beg)
			m_beg = m_end = temp;
		else {
			temp->next = m_beg;
			m_beg->prev = temp;
			m_beg = temp;
		}
		m_size++;
	}
	catch (const std::bad_alloc& error) {
		std::cout << "Error: " << error.what() << std::endl;
	}
}
template <class Type>
void List<Type>::insert(int index, Type data) {
	if (is_empty() || !correct_index(index))
		throw new std::exception("");
	try {
		Item<Type>* where = move(index);
		Item<Type>* temp = new Item<Type>;
		temp->data = data;
		temp->next = where;
		temp->prev = where->prev;
		(where->prev)->next = temp;
		where->prev = temp;
		m_size++;
	}
	catch (const std::bad_alloc& error) {
		std::cout << "Error: " << error.what() << std::endl;
	}
}

template <class Type>
Type List<Type>::get(int index) {
	if (!correct_index(index))
		throw new std::exception("");
	return move(index)->data;
}
template <class Type>
void List<Type>::set(Type data, int index) {
	if (!correct_index(index))
		throw new std::exception("");
	move(index)->data = data;
}

template <class Type>
void List<Type>::erase(int index) {
	if (!correct_index(index))
		throw new std::exception("");
	Item<Type>* temp = move(index);
	(temp->next)->prev = temp->prev;
	(temp->prev)->next = temp->next;
	m_size--;
	delete temp;
}
template <class Type>
void List<Type>::clear() {
	Item<Type>* temp;
	while (m_beg != nullptr) {
		temp = m_beg;
		m_beg = m_beg->next;
		delete temp;
	}
	m_end = nullptr;
	m_size = 0;
}

#endif //LIST_HPP