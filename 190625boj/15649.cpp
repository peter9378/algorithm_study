/**
*	BOJ
*	No.15649	N과  M(1)
*	@author	peter9378
*	@date		2019.06.25	- Remember 6.25 -
*/
#include <iostream>
using namespace std;

int N, M;
int arr[11];
bool visit[11];

// dfs
void dfs(int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i];
			if (i != N - 1)
				cout << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				arr[count] = i + 1;
				dfs(count + 1);
				visit[i] = false;
			}
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> M;

	dfs(0);

	return 0;
}