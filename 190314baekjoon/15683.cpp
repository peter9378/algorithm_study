/**
*	baekjoon online judge
*	No. 15683	감시
*	@author	peter9378
*	@date		2019.03.14
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// cctv struct
struct cctv {
	int x, y, num;
	cctv(int x, int y, int n) :x(x), y(y), num(n) {}
};

int N, M, answer;
int arr[8][8];
int visit[8][8];
vector<cctv> v;

// checking function
void check(int x, int y, int direction, int flag) 
{
	if (direction == 0) 
	{
		x--;
		while (x >= 0) 
		{
			if (arr[x][y] == 6)
				return;
			if (flag == 0) 
				visit[x][y]++;
			else 
				visit[x][y]--;
			x--;
		}
	}
	else if (direction == 1) 
	{
		y++;
		while (y < M) 
		{
			if (arr[x][y] == 6)
				return;
			if (flag == 0) 
				visit[x][y]++;
			else 
				visit[x][y]--;
			y++;
		}
	}
	else if (direction == 2) 
	{
		x++;
		while (x < N)
		{
			if (arr[x][y] == 6)
				return;
			if (flag == 0) 
				visit[x][y]++;
			else 
				visit[x][y]--;
			x++;
		}
	}
	else 
	{
		y--;
		while (y >= 0) 
		{
			if (arr[x][y] == 6)
				return;
			if (flag == 0) 
				visit[x][y]++;
			else 
				visit[x][y]--;
			y--;
		}
	}
}

int calculate()
{
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0 && visit[i][j] == 0)
				temp++;
		}
	}
	return temp;
}

// dfs
void dfs(int index) 
{
	if (index == v.size()) 
	{
		answer = min(answer, calculate());
		return;
	}

	int x = v[index].x;
	int y = v[index].y;
	int num = v[index].num;

	if (num == 1) 
	{
		// check 4 directions
		for (int i = 0; i < 4; i++) 
		{
			check(x, y, i, 0);
			dfs(index + 1);
			check(x, y, i, 1);
		}
	}
	else if (num == 2) 
	{
		for (int i = 0; i < 2; i++) 
		{
			check(x, y, i, 0);
			check(x, y, i + 2, 0);
			dfs(index + 1);
			check(x, y, i, 1);
			check(x, y, i + 2, 1);
		}
	}
	else if (num == 3) 
	{
		for (int i = 0; i < 4; i++) 
		{
			check(x, y, i, 0);
			check(x, y, (i + 1 == 4) ? 0 : i + 1, 0);
			dfs(index + 1);
			check(x, y, i, 1);
			check(x, y, (i + 1 == 4) ? 0 : i + 1, 1);
		}
	}
	else if (num == 4) 
	{
		for (int i = 0; i < 4; i++) 
		{
			check(x, y, i, 0);
			check(x, y, (i + 1 >= 4) ? i + 1 - 4 : i + 1, 0);
			check(x, y, (i + 2 >= 4) ? i + 2 - 4 : i + 2, 0);
			dfs(index + 1);
			check(x, y, i, 1);
			check(x, y, (i + 1 >= 4) ? i + 1 - 4 : i + 1, 1);
			check(x, y, (i + 2 >= 4) ? i + 2 - 4 : i + 2, 1);
		}
	}
	else if (num == 5) 
	{
		for (int i = 0; i < 4; i++)
			check(x, y, i, 0);
		dfs(index + 1);
		for (int i = 0; i < 4; i++)
			check(x, y, i, 1);
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0 || arr[i][j] == 6)
				continue;
			v.push_back(cctv(i, j, arr[i][j]));
		}
	}
	
	// dfs
	answer = 1000000000;
	dfs(0);

	// print answer
	cout << answer;
	return 0;
}
