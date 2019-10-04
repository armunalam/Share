#include <iostream>

using namespace std;

int acase(int a)
{
	if (a >= 'A' && a <= 'Z')
		return a + 'a' - 'A';
	else return a;
}

void bubbleSort(string &str)
{
	char temp;
	for (unsigned int i = 0; i < str.length() - 1; i++)
	{
		for (unsigned int j = 0; j < str.length() - 1; j++)
		{
			if (acase(str[j]) > acase(str[j + 1]))
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}

int main()
{
	string str = "uxBcbaA";

	bubbleSort(str);

	cout << str;
}
