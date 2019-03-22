#include <iostream>
#include <time.h>

using namespace std;

// прототипы функций
void merge(int*, int, int);
void mergeRec(int*, int, int);
int N;

int main() {
	cin >> N; // количество входных элементов
	// если пригодится для отладки, генератор случайных чисел
	// srand(time(NULL)); // инициализатор генератора
	// rand()%99 + 1: сгенерирует случайное число от 1 до 99.

	int* A = new int[N];
	/*for (int i = 0; i < N; i++) {
		cin >> A[i]; // заполнение массива
	}        
	mergeRec(A, 0, N-1); // вызов сортировки
        
        for (int i = 0; i < N; i++) {
		cout << A[i] << " "; // печать
	}*/
	A[1] = 2;
	A[2] = 4;
	swap(A[1],A[2]);
	cout << A[1] << ' ' << A[2];
	delete[] A; // освободили память
	return 0;
}

void swap(int *

void mergeRec(int* A, int left, int right) {
	if (left < right){
		if (left +1 = right) {
			if (A[left] > A[right])  return;
		}
	}
	
	// рекурсивный вызов разделения, затем вызов слияния
	// необходимо реализовать

}

void merge(int *A, int left, int right){
	// процедура для слияния A[left .. mid] и A[mid+1 .. right];
	// необходимо реализовать

}; 