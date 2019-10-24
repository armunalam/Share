#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int);

int goldbach(int num)
{
	if (num % 2 != 0) return -1;
	else
	{
		int counter = 0;
		for (int i = 2; i < num; i++)
		{
			for (int j = 2; j < num; j++)
			{
				if (i + j == num && isPrime(i) && isPrime(j))
				{
					counter++;
				}
			}
		}
		return ceil(counter / 2.0);
	}
}

int main()
{
	int T, n;
	cin >> T;

	int *arr = new int [T];

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		arr[i] = goldbach(n);
	}

	for (int i = 0; i < T; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}

bool isPrime(int num)
{
	bool prime = false;
	if (num == 2) return true;
	else
	{
		for (int i = 2; i < sqrt(num) + 1; i++)
		{
			if (num % i == 0)
			{
				prime = false;
				break;
			}
			else
			{
				prime = true;
			}
		}
	}

	return prime;
}
