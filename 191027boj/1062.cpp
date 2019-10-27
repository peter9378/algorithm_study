/**
*	BOJ
*	No.1062	°¡¸£Ä§
*	@author	peter9378
*	@date		2019.10.27
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int N, K, answer;
string arr[51];
bool visit[26];

void dfs(int index, int count)
{
	if (count == K)
	{
		int result = 0;
		for (int i = 0; i < N; i++)
		{
			bool flag = true;
			for (int j = 0; j < arr[i].length(); j++)
			{
				if (!visit[arr[i][j] - 97])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				result++;
		}
		answer = max(answer, result);
		return;
	}

	for (int i = index; i < 26; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			dfs(i, count + 1);
			visit[i] = false;
		}
	}
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	if (K < 5)
	{
		cout << "0";
		return 0;
	}
	else if (K == 26)
	{
		cout << N;
		return 0;
	}

	K -= 5;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		arr[i] = s.substr(4, s.length() - 4);
	}

	visit[0] = true;
	visit[2] = true;
	visit[8] = true;
	visit[13] = true;
	visit[19] = true;

	dfs(0, 0);
	cout << answer;

	return 0;
}