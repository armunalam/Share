#include <iostream>

using namespace std;

int acase(int);
void insertionSort(string &);

int main()
{
	string str = "uxBcbaA";

	insertionSort(str);

	cout << str;
}

void insertionSort(string &A)
{
	int key, i;
	for (unsigned int j = 1; j < A.length(); j++)
	{
		key = A[j];
		i = j - 1;
		while (i >= 0 && acase(A[i]) > acase(key))
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int acase(int a)
{
	if (a >= 'A' && a <= 'Z')
	{
		return a + 'a' - 'A';
	}
	else
	{
		return a;
	}
}
