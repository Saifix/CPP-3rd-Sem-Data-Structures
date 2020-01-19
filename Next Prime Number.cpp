#include<iostream>
#include <ctime>
using namespace std;
bool prime(int n)
{
	for (int z = 2; z <= sqrt(double(n)); z++)
		if (n % z == 0)
			return false;
	return true;
}
int main()
{
	int num, stop;
	clock_t time_req;
	do
	{
		cout << "Please enter a number : ";
		cin >> num;
		time_req = clock();
		for (int x = num; x > 1; ++x)
		{
			if (prime(x))
			{
				cout << "Smallest Prime number after " << num << " : " << x << endl;
				time_req = clock() - time_req;
				cout << "It took " << (float)time_req / CLOCKS_PER_SEC << " seconds to search next prime number." << endl;
				break;
			}
		}
		cout << endl << "Do you want to check another number(0=NO or 1=Yes?)";
		cin >> stop;
		cout << endl;
		while (stop < 0 || stop>1)
		{
			cout << "Please select given number commands : ";
			cin >> stop;
		}
	} while (stop == 1);
	system("pause");
}
