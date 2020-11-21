#include "zad4.h"
#include <iostream>
#include <string>

CTable::CTable() 
	: name(DEFAULT_NAME), size(DEFAULT_SIZE), table(new int[DEFAULT_SIZE])
{
	std::cout << "bezp: '" <<  name << "'" << std::endl;
}

CTable::CTable(const std::string& name, int tableLength) 
	: name(name), size(tableLength), table(NULL)
{
	this->name = name;
	if (tableLength > 0) {
		table = new int[tableLength];
		size = tableLength;
	}
	else {
		table = new int[DEFAULT_SIZE];
		size = DEFAULT_SIZE;
	}

	std::cout << "parametr: '" << name << "'" << std::endl;
}

CTable::CTable(const CTable& otherTable) {
	name = otherTable.name + "_copy";
	size = otherTable.size;
	table = new int[size];
	for (int i = 0; i < size; i++) {
		table[i] = otherTable.table[i];
	}

	std::cout << "kopiuj: '" << name << "'" << std::endl;
}

#ifndef DESTRUCTOR_OFF
CTable::~CTable() {
	std::cout << "usuwam: '" << name << "'" << std::endl;
	delete[] table;
}
#endif

const std::string& CTable::get_name() {
	return name;
}

int* CTable::get_table() {
	return table;
}

int CTable::get_size() {
	return size;
}

void CTable::set_name(const std::string& name) {
	this->name = name;
}

bool CTable::set_new_size(int newLength) {
	if (newLength <= 0) {
		return false;
	}
	int* newTab = new int[newLength];
	
	if (newLength <= size) {
		for (int i = 0; i < newLength; i++) {
			newTab[i] = table[i];
		}
	} else {
		for (int i = 0; i < size; i++) {
			newTab[i] = table[i];
		}
	}

	delete[] table;
	table = newTab;
	size = newLength;

	return true;
}

void CTable::set_value_at(int offset, int newVal) {
	if (offset < 0 || offset >= size) {
		return;
	}
	else {
		table[offset] = newVal;
	}
}

CTable* CTable::clone() {
	CTable* clone = new CTable(name, size);
	for (int i = 0; i < size; i++) {
		clone->get_table()[i] = this->get_table()[i];
	}
	return clone;
}

void CTable::print_table() {
	std::cout << *this;
}

CTable& CTable::operator+(CTable& tableToAdd) {
	int newSize = size + tableToAdd.size;
	CTable* outcome = new CTable(name + tableToAdd.name, newSize);
	for (int i = 0; i < size; i++) {
		outcome->get_table()[i] = table[i];
	}
	for (int i = 0; i < tableToAdd.size; i++) {
		outcome->get_table()[size + i] = tableToAdd.table[i];
	}
	return *outcome;
}

#ifdef EQUAL_COPY
CTable& CTable::operator=(CTable& refToTable) {
	name = refToTable.name;
	size = refToTable.size;
	table = new int[size];
	for (int i = 0; i < size; i++) {
		table[i] = refToTable.table[i];
	}
	return *this;
}
#endif

std::ostream& operator<<(std::ostream& os, CTable& tableToPrint) {
	std::cout << "[";
	for (int i = 0; i < tableToPrint.size; i++) {
		std::cout << tableToPrint.table[i];
		if (i != tableToPrint.size - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]\n";
	return os;
}

CTable CTable::operator+(int element) const {
	int newSize = size + 1;
	CTable newTab(name, newSize);
	newTab.table[0] = element;	
	for (int i = 1; i < newSize; i++) {
		newTab.table[i] = table[i - 1];
	}
	return newTab;
}

CTable operator+(int element, const CTable& tableToExpand) {
	return tableToExpand + element;
}

void mod_tab(CTable* cTab, int newSize) {
	cTab->set_new_size(newSize);
}

void mod_tab(CTable cTab, int newSize) {
	cTab.set_new_size(newSize);
}