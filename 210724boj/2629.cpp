/**
*	BOJ
*	No.2629	¾çÆÈÀú¿ï
*	@author	peter9378
*	@date		2021.07.24
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

int N, arr[31];
bool check[15001];
bool possible[31][15001];

void measure(int target, int weight)
{
	if (target > N)
		return;
	if (possible[target][weight])
		return;

	possible[target][weight] = true;
	check[weight] = true;

	measure(target + 1, weight);
	measure(target + 1, weight + arr[target]);
	measure(target + 1, abs(weight - arr[target]));
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	measure(0, 0);

	int t;
	cin >> t;
	while (t--)
	{
		int ball;
		cin >> ball;

		if (ball <= 15000 && check[ball])
			cout << "Y";
		else
			cout << "N";
		cout << " ";
	}

	return 0;
}
