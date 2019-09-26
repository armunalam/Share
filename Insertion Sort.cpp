#include <iostream>
#include <cstdlib>

using namespace std;

void insertionSort(int A[], int size)
{
	int key, i;
	for (int j = 2; j < size; j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int main()
{
	int size = 20;
	int A[size];
	for (int i = 0; i < size; i++)
		{
			A[i] = rand() % 100;
		}
	insertionSort(A, size);

	for (int i = 0; i < size - 1; i++)
	{
		cout << A[i] << ", ";
	}
	cout << A[size - 1];
}
