#include <iostream>

void DynMemory(int &size) {
	std::cin >> size;
}

void InizDinMemory(int* &ptr, int &size) {
	for (int i = 0; i < size; i++) {
		ptr[i] = rand() % 10 + 1;
	}
}

void Print(int* &ptr, int &size) {
	for (int i = 0; i < size; i++) {
		std::cout << ptr[i] << " ";
	}
	std::cout << "\n";
}

void DeleteLastElement(int* &ptr, int &size) {
	size--;
	int* newarr = new int[size];

	for (int i = 0; i < size; i++) {
		newarr[i] = ptr[i];
	}

	std::swap(newarr, ptr);

	delete[]newarr;
}

void DeleteDynArray(int* &ptr) {
	delete[]ptr;
}

int main() {
	srand(time(NULL));

	int size;

	DynMemory(size);

	int* arr = new int[size];

	InizDinMemory(arr, size);
	
	Print(arr, size);

	DeleteLastElement(arr, size);

	Print(arr, size);

	DeleteDynArray(arr);

	return 0;
}

