#ifndef MOD_H
#define MOD_H

int** allocateIrregularArray2D(int sizeX, int* sizesYY);
bool deallocateIrregularArray2D(int** array2D, int sizeX);
void fill_irreg_2_dim_with_zeros(int** piTable, int sizeX, int* sizesY);
void print_irreg_2_dim(int** piTable, int sizeX, int* sizesY);
void test_mod_1();

void test_mod_2();

#endif