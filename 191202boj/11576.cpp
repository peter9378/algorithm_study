/**
*	BOJ
*	No.11576	Base Conversion
*	@author	peter9378
*	@date		2019.12.02
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	cin >> A >> B;

	int m;
	cin >> m;

	long long sum = 0;
	for (int i = 0; i < m; i++)
	{
		long long temp;
		cin >> temp;
		sum += (pow(A, m - i - 1)*temp);
	}

	vector<int> v;
	while (sum)
	{
		v.push_back(sum%B);
		sum /= B;
	}

	for (int i = v.size() - 1; i > -1; i--)
		cout << v[i] << " ";

	return 0;
}
