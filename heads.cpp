#include <iostream>
#include <vector>

using namespace std;

typedef struct win {int v; int p;} win;

main()
{
	int max1, max2, min1, min2, count = 0;
	win winners;
	vector < win > finaly;

	cin >> max1 >> max2 >> min1 >> min2;

	for(int i = min1; i <= max1; i++)
	{
		for(int j = min2; j <= max2; j++)
		{
			if(i == j) break;
			if(j > i) break;
			count ++;
			winners.v = i;
			winners.p = j;
			finaly.push_back(winners);
		} // fim do for j
	} // fim do for i

	cout << count << endl;

	for(int i = 0; i < count; i++)
		cout << finaly[i].v << " " << finaly[i].p << endl;

	return 0;
}
