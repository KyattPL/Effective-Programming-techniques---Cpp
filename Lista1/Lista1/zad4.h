#ifndef ZAD4_H
#define ZAD4_H

#include <string>
#include <iostream>

const std::string DEFAULT_NAME = "Joe";
const int DEFAULT_SIZE = 5;

class CTable {
private:
	std::string name;
	int* table;
	int size;

public:
	CTable();
	CTable(const std::string& name, int tableLength);
	CTable(const CTable& otherTable);
#ifndef DESTRUCTOR_OFF 

	~CTable();

#endif

	const std::string& get_name();
	int* get_table();
	int get_size();
	void set_name(const std::string& name);
	bool set_new_size(int newLength);
	void set_value_at(int offset, int newVal);
	CTable* clone();
	
	void print_table();
	CTable operator+(int element) const;
	CTable& operator+(CTable& tableToAdd);
	friend std::ostream& operator<<(std::ostream& os, CTable& tableToPrint);
#ifdef EQUAL_COPY
	CTable& operator=(CTable& refToTable);
#endif
};

std::ostream& operator<<(std::ostream& os, CTable& tabletoPrint);
CTable operator+(int element, const CTable& tableToExpand);

void mod_tab(CTable* cTab, int newSize);
void mod_tab(CTable cTab, int newSize);

#endif