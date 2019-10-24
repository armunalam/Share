#include <iostream>

using namespace std;

int repeatChar(string);
int palindrome(string);

int main()
{
	string str;
	cin >> str;

	cout << palindrome(str);

	return 0;
}

int palindrome(string str)
{
	int size = str.length();
	int dup = repeatChar(str);

	return size - dup - 1;
}

int repeatChar(string str)
{
	int size = str.length(), c = 0;
	int *recur = new int [size], sum = 0;

	for (int i = 0; i < size; i++)
		recur[i] = 1;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (str[i] == str[j] && str[j] != '`')
			{
				recur[c]++;
				str[j] = '`';
			}
		}
		c++;
	}

	for (int i = 0; i < size; i++)
	{
		if (recur[i] > 1)
		{
			recur[i] = recur[i] / 2 * 2;
			sum += recur[i];
		}
	}

	delete [] recur;
	return sum;
}
