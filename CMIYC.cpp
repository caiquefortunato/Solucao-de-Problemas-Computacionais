#include <iostream>

using namespace std;

int main()
{
	int entrada, rest;
	long long div, size;
	//long long div;

	cin >> entrada;

	for(int i = 0; i < entrada; i++)
	{
		cin >> size;

		rest = size % 3;
		div = size / 3;

		if(rest != 0) cout << "0" << endl;
		else cout << div  << endl;
	}

	return 0;
}
