#ifndef ZAD4_H
#define ZAD4_H

#include <string>

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
	CTable(CTable& otherTable);
	~CTable();

	const std::string& get_name();
	int* get_table();
	int get_size();
	void set_name(const std::string& name);
	bool set_new_size(int newLength);
	CTable* clone();
};

void mod_tab(CTable* cTab, int newSize);
void mod_tab(CTable cTab, int newSize);

#endif