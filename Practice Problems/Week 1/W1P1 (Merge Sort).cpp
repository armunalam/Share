#include <iostream>

using namespace std;

int acase(int);
void merge(string &, int, int, int);
void mergeSort(string &, int, int);

int main()
{
	string str = "uxBcbaA";
	int len = str.length() - 1;

	mergeSort(str, 0, len);

	cout << str;
}

void mergeSort(string &A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r)/2;
		mergeSort(A, p , q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

void merge(string &A, int p, int q, int r)
{
	int n1 = q - p + 1, n2 = r - q;
	int *L = new int [n1], *R = new int [n2];

	for (int i = 0; i < n1; i++)
		L[i] = A[p + i];

	for (int j = 0; j < n2; j++)
		R[j] = A[q + j + 1];

	int i = 0, j = 0;

	for (int k = p; k <= r; k++)
	{
		if (acase(L[i]) <= acase(R[j]))
		{
			if (i >= n1)
			{
				A[k] = R[j];
				j++;
			}
			else
			{
				A[k] = L[i];
				i++;
			}
		}
		else
		{
			if (j >= n2)
			{
				A[k] = L[i];
				i++;
			}
			else
			{
				A[k] = R[j];
				j++;
			}
		}
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
