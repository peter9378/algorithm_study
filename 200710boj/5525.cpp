/**
*	BOJ
*	No.5525	IOIOI
*	@author	peter9378
*	@date		2020.07.10
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, length;
	string s;
	cin >> N >> length >> s;

	int answer = 0;
	for (int i = 0; i < length; i++)
	{
		if (s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			int numO = 0;
			while (s[i] == 'I' && s[i + 1] == 'O')
			{
				i += 2;
				numO++;
				if (s[i] == 'I' && numO == N)
				{
					numO--;
					answer++;
				}
			}
		}
	}

	cout << answer;

	return 0;
}