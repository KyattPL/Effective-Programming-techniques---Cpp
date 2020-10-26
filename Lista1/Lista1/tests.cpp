#include <iostream>
#include "tests.h"
#include "zad1.h"
#include "zad2.h"
#include "zad3.h"
#include "zad4.h"

void test_exercise_1() {
	alloc_table_add_5(5);
}

void test_exercise_2_and_3() {
	int** piTable = NULL;
	alloc_table_2_dim(&piTable, 5, 3);
	fill_table_2_dim_with_zeros(piTable, 5, 3);
	print_table_2_dim(piTable, 5, 3);
	dealloc_table_2_dim(piTable, 5);
}

void test_exercise_4() {
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