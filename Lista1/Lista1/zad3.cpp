#include "zad3.h"
#include <iostream>

bool dealloc_table_2_dim(int** piTable, int sizeX) {
	// Argument sizeY jest absolutnie zb�dny:

	if (sizeX <= 0) {
		return false;
	}

	for (int i = sizeX - 1; i >= 0; i--) {
		delete[] piTable[i];
	}

	delete[] piTable;
	return true;
}