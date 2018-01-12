#include <iostream>
#include <string>


using namespace std;

int main()
{
	int n = 6;

	for (int i = 1; i <= n; i++)
	{
		string character(n - i, ' ');
		string space(i, '#');
		cout << character << space << endl;
	}




	cout << endl;

	system("pause");
	return 0;
}