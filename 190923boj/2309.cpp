/**
*	BOJ
*	No.2309	일곱 난쟁이
*	@author	peter9378
*	@date		2019.09.23
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int temp;
	for (int i = 0; i < 9; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> per;
	for (int i = 0; i < 7; i++)
		per.push_back(1);
	for (int i = 0; i < 2; i++)
		per.push_back(0);

	sort(per.begin(), per.end());
	sort(v.begin(), v.end());

	do
	{
		int sum = 0;
		for (int i = 0; i < 9; i++)
		{
			if (per[i])
				sum += v[i];
		}
		if (sum == 100)
			break;
	} while (next_permutation(per.begin(), per.end()));

	for (int i = 0; i < 9; i++)
	{
		if (per[i])
			cout << v[i] << "\n";
	}

	return 0;
}