#include "zad2.h"
#include <iostream>

bool alloc_table_2_dim(int*** piTable, int sizeX, int sizeY) {

	if (sizeX <= 0 || sizeY <= 0) {
		return false;
	}

	*piTable = new int*[sizeX];

	for (int i = 0; i < sizeX; i++) {
		(*piTable)[i] = new int[sizeY];
	}

	return true;
}

void fill_table_2_dim_with_zeros(int** piTable, int sizeX, int sizeY) {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			piTable[i][j] = 0;
		}
	}
}

void print_table_2_dim(int** piTable, int sizeX, int sizeY) {
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			std::cout << piTable[i][j] << " ";
		}
		std::cout << std::endl;
	}
}