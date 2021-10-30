#include <iostream>
#include <stdio.h>
using namespace std;
void InputArray(int* n, int** a) {
	FILE* f1;
	fopen_s(&f1, "E:\\lab8.txt", "rt");
	fscanf_s(f1, "%d", n);
	*a = (int*)malloc(sizeof(int) * *n);
	for (int i = 0; i < *n; i++) {
		fscanf_s(f1, "%d ", &((*a)[i]));
	}
	fclose(f1);
}
int Find_imax(int n, int* a) {
	int max = a[0];
	int index_max = 0;
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
			index_max = i;
		}
	}
	return index_max;
}
int Find_imin(int n, int* a) {
	int min = a[0];
	int index_min = 0;
	for (int i = 0; i < n; i++) {
		if (min > a[i]) {
			min = a[i];
			index_min = i;
		}
	}
	return index_min;
}
void UpdateArray(int n, int* a) {
	FILE* f2;
	fopen_s(&f2, "E:\\lab9.txt", "wt");
	int index_max1 = Find_imax(n, a);
	int index_min1 = Find_imin(n, a);
	for (int i = 0; i < n; i++) {
		if ((a[i] % 2 == 0) && (i < index_max1) && (i > index_min1)) {
			fprintf(f2, "%d ", a[i]);
		}
		if ((a[i] % 2 == 0) && (i > index_max1) && (i < index_min1)) {
			fprintf(f2, "%d ", a[i]);
		}
	}
	fclose(f2);
}
int main() {
	int size;
	int* arr;
	InputArray(&size, &arr);
	UpdateArray(size, arr);
	free(arr);
	return 0;
}