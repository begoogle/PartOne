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

void DeleteDynArray(int*& ptr) {
	delete[]ptr;
}

void DeleteLastElement(int* &ptr, int &size) {
	size--;
	int* newarr = new int[size];

	for (int i = 0; i < size; i++) {
		newarr[i] = ptr[i];
	}

	std::swap(newarr, ptr);

	DeleteDynArray(newarr);
}

void EnterIndex(int& index) {
	std::cout << "Enter index -> ";
	std::cin >> index;
}

void EnterNumbers( int& number) {
	std::cout << "Enter number -> ";
	std::cin >> number;
}

void CreateInputNewNumbers(int*& ptr, int& size) {
	int index;
	int number;

	EnterIndex(index);
	EnterNumbers(number);
	
	size++;

	int* newarr = new int[size];

	for (int i = 0, j = 0; i < size; i++) {
		newarr[i] = ptr[j];

		j++;

		if (newarr[i] == newarr[index - 1]) {
			newarr[index - 1] = number;
			j--;
		}
	}

	std::swap(newarr, ptr);

	DeleteDynArray(newarr);
}

void DeleteNumIndex(int* &ptr, int &size) {
	int index;

	EnterIndex(index);

	size--;

	int* newarr = new int[size];

	for (int i = 0, j = 0; i < size; i++) {
		newarr[i] = ptr[j];

		j++;

		if (newarr[i] == newarr[index - 1]) {
			newarr[i] = ptr[j];
		}
	}

	std::swap(newarr, ptr);

	DeleteDynArray(newarr);
}

int main() {
	srand(time(NULL));

	int size;

	DynMemory(size);

	int* arr = new int[size];

	InizDinMemory(arr, size);
	
	Print(arr, size);

	CreateInputNewNumbers(arr, size);

	Print(arr, size);

	DeleteNumIndex(arr, size);

	Print(arr, size);

	DeleteLastElement(arr, size);

	Print(arr, size);

	DeleteDynArray(arr);

	return 0;
}

