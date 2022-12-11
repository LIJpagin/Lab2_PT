#include "List.hpp"

bool List::correct_index(int index) {
	return 0 <= index && index < m_size;
}
Item* List::move(int index) {
	bool is_begin = index <= m_size / 2;
	Item* ptr = is_begin ? m_beg : m_end;
	for (size_t i = 0; i < (is_begin ? index : m_size - index - 1); i++)
		ptr = is_begin ? ptr->next : ptr->prev;
	return ptr;
}

bool List::is_empty() const {
	return !m_size;
}
int List::size() const {
	return m_size;
}

void List::add_end(Note* data) {
	try {
		Item* temp = new Item;
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
void List::add_begin(Note* data) {
	try {
		Item* temp = new Item;
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
void List::insert(int index, Note* data) {
	if (is_empty() || !correct_index(index))
		throw new std::exception("");
	try {
		Item* where = move(index);
		Item* temp = new Item;
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

Note* List::get(int index) {
	if (!correct_index(index))
		throw new std::exception("");
	return move(index)->data;
}
void List::set(Note* data, int index) {
	if (!correct_index(index))
		throw new std::exception("");
	move(index)->data = data;
}

void List::print() {
	Item* temp = m_beg;
	while (temp)
		temp->data->print(), temp = temp->next;
}

void List::find_person(std::string last_name) {
	std::transform(last_name.begin(), last_name.end(),
		last_name.begin(), tolower);
	Item* ptr = m_beg;
	while (ptr) {
		std::string temp = ptr->data->get_last_name();
		std::transform(temp.begin(), temp.end(), temp.begin(), tolower);
		if (temp == last_name) {
			ptr->data->print();
			return;
		}
		ptr = ptr->next;
	}
	std::cout << "Note not found" << std::endl;
}
void List::sort_phone_numbers() {
	for (auto i = m_beg; i != nullptr; i = i->next)
		for (auto j = i; j != m_beg && j->prev->data->get_phone_number()
				> j->data->get_phone_number(); j = j->prev)
			std::swap(j->prev->data, j->data);
}

void List::erase(int index) {
	if (!correct_index(index))
		throw new std::exception("");
	Item* temp = move(index);
	(temp->next)->prev = temp->prev;
	(temp->prev)->next = temp->next;
	m_size--;
	delete temp;
}
void List::clear() {
	Item* temp;
	while (m_beg != nullptr) {
		temp = m_beg;
		m_beg->data->~Note();
		m_beg = m_beg->next;
		delete temp;
	}
	m_end = nullptr;
	m_size = 0;
}