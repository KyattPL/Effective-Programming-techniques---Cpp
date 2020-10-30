#include <iostream>
#include "tests.h"
#include "zad1.h"
#include "zad2.h"
#include "zad3.h"
#include "zad4.h"

void test_exercise_1_1() {
	alloc_table_add_5(5);
}

void test_exercise_1_2_and_1_3() {
	int** piTable = NULL;
	alloc_table_2_dim(&piTable, 5, 3);
	fill_table_2_dim_with_zeros(piTable, 5, 3);
	print_table_2_dim(piTable, 5, 3);
	dealloc_table_2_dim(piTable, 5);
}

void test_exercise_1_4() {
	CTable c_tab;
	CTable* c_new_tab;
	c_new_tab = c_tab.clone();

	mod_tab(c_tab, 10);
	std::cout << c_tab.get_size() << std::endl;

	mod_tab(&c_tab, 10);
	std::cout << c_tab.get_size() << std::endl;

	CTable* dynamic = new CTable("Jack", 3);
	// Celowy memory leak, nie bêdzie komunikatu
	// destruktora w konsoli.
	CTable static_tab[2];
	CTable* dynamic_tab = new CTable[4];
	// Celowy memory leak, nie bêdzie komunikatu
	// destruktora w konsoli dla ¿adnego obiektu z tablicy.
}

void test_exercise_2_1() {
	CTable tab0, tab1;
	tab0.set_new_size(6);
	tab1.set_new_size(4);
	tab0 = tab1;
}

void test_exercise_2_3() {
	CTable tab0, tab1;
	tab0.set_new_size(6);
	tab1.set_new_size(4);
	for (int i = 0; i < 6; i++) {
		tab0.set_value_at(i, i + 1);
	}
	for (int i = 0; i < 4; i++) {
		tab1.set_value_at(i, i + 51);
	}
	tab0 = tab1;
	tab1.set_value_at(2, 123);
	tab0.print_table();
	tab1.print_table();
}

void test_exercise_2_4() {
	CTable tab0, tab1;
	tab0.set_new_size(1);
	tab1.set_new_size(1);
	tab0.set_value_at(0, 2);
	tab1.set_value_at(0, 34);
	
	CTable concatenated = tab0 + tab1;
	tab0.print_table();
	tab1.print_table();
	tab0.set_value_at(0, 123);
	concatenated.print_table();
}