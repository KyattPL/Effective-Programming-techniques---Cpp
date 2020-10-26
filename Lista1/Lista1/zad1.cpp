#include "zad1.h"
#include <iostream>

void alloc_table_add_5(int size) {

	if (size <= 0) {
		return;
	}

	int* piTab = new int[size];

	for (int i = 0; i < size; i++) {
		piTab[i] = i + ADDEND;
	}

	print_table_1_dim(piTab, size);
	dealloc_table_1_dim(piTab);
}

void print_table_1_dim(int* piTable, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << piTable[i] << " ";
	}
	std::cout << std::endl;
}

void dealloc_table_1_dim(int* piTable) {
	delete[] piTable;
}