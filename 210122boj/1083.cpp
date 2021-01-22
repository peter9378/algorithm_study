/**
*	BOJ
*	No.1083	¼ÒÆ®
*	@author	peter9378
*	@date		2021.01.22
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

double arr[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int S;
	cin >> S;

	int temp, index = 0;
	for (int i = 0; i < N && S; i++)
	{
		temp = index = -1;
		for (int j = i, k = 0; j < N && k <= S; j++, k++)
		{
			if (temp < v[j])
			{
				temp = v[j];
				index = j;
			}
		}

		for (int j = index; i < j && S; j--, S--)
			swap(v[j], v[j - 1]);
	}

	for (int i = 0; i < N; i++)
		cout << v[i] << " ";

	return 0;
}
