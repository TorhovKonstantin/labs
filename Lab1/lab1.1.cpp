#include <iostream>
using namespace std;

void exponention()
{
	int i, k, num;
	cout << "Vvesti osnovania: ";
	cin >> num;
	int power(int, int);
	for (i = 0; i < 10; i++)
	{
		k=power(num, i);
		cout<< "Chislo: "<< num << "\tstepen': " << i << "\titog: " << k << endl;
	}
}

int power(int x, int n)
{
	int i, p = 1;
	for (i = 1; i < n; i++) p *= x;
	return p;
}

int main(){
	exponention();
}