/**
*	BOJ
*	No.14427	¼ö¿­°ú Äõ¸® 15
*	@author	peter9378
*	@date		2020.06.21
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
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

int arr[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	set<pair<int, int>> s;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		s.insert({ arr[i], i });
	}

	int M;
	cin >> M;

	while (M--)
	{
		int a;
		cin >> a;

		if (a == 1)
		{
			int b;
			cin >> a >> b;

			s.erase({ arr[a], a });
			arr[a] = b;
			s.insert({ arr[a], a });
		}
		else
			cout << (*s.begin()).second << "\n";
	}

	return 0;
}
