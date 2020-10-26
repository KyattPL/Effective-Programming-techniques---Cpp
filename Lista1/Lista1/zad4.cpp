#include "zad4.h"
#include <iostream>
#include <string>

CTable::CTable() {
	name = DEFAULT_NAME;
	table = new int[DEFAULT_SIZE];
	size = DEFAULT_SIZE;

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

CTable::CTable(CTable& otherTable) {
	name = otherTable.name + "_copy";
	size = otherTable.size;
	table = new int[size];
	for (int i = 0; i < size; i++) {
		table[i] = otherTable.table[i];
	}

	std::cout << "kopiuj: '" << name << "'" << std::endl;
}

CTable::~CTable() {
	std::cout << "usuwam: '" << name << "'" << std::endl;
	delete[] table;
}

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

CTable* CTable::clone() {
	CTable* clone = new CTable(this->get_name(), this->get_size());
	for (int i = 0; i < this->get_size(); i++) {
		clone->get_table()[i] = this->get_table()[i];
	}
	return clone;
}

void mod_tab(CTable* cTab, int newSize) {
	cTab->set_new_size(newSize);
}

void mod_tab(CTable cTab, int newSize) {
	cTab.set_new_size(newSize);
}