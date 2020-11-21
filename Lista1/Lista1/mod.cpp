#include <iostream>
#include "mod.h"
#include "zad4.h"

int** allocateIrregularArray2D(int sizeX, int* sizesY) {
	
	if (sizeX <= 0 || sizesY == NULL) {
		return NULL;
	}

	for (int i = 0; i < sizeX; i++) {
		if (sizesY[i] <= 0) {
			return NULL;
		}
	}

	int** piTable = new int*[sizeX];

	for (int i = 0; i < sizeX; i++) {
		piTable[i] = new int[sizesY[i]];
	}

	return piTable;
}

bool deallocateIrregularArray2D(int** array2D, int sizeX) {
	if (sizeX <= 0) {
		return false;
	}

	for (int i = sizeX - 1; i >= 0; i--) {
		delete[] array2D[i];
	}

	delete[] array2D;
	return true;
}

void fill_irreg_2_dim_with_zeros(int** piTable, int sizeX, int* sizesY) {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizesY[i]; j++) {
			piTable[i][j] = 0;
		}
	}
}

void print_irreg_2_dim(int** piTable, int sizeX, int* sizesY) {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizesY[i]; j++) {
			std::cout << piTable[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void test_mod_1() {
	int* irregSizes = new int[5];

	irregSizes[0] = 3;
	irregSizes[1] = 2;
	irregSizes[2] = 4;
	irregSizes[3] = 5;
	irregSizes[4] = 1;

	int** irregArr = allocateIrregularArray2D(5, irregSizes);
	fill_irreg_2_dim_with_zeros(irregArr, 5, irregSizes);
	print_irreg_2_dim(irregArr, 5, irregSizes);
	deallocateIrregularArray2D(irregArr, 5);
}

void test_mod_2() {
	CTable tab("Mod2", 5);
	tab.set_value_at(0, 1);
	tab.set_value_at(1, 2);
	tab.set_value_at(2, 3);
	tab.set_value_at(3, 4);
	tab.set_value_at(4, 5);

	std::cout << tab << std::endl;
	CTable added = tab + 130;
	added.print_table();
	CTable added2 = 15 + tab;
	added2.print_table();
}