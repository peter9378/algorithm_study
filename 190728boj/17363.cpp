/**
*	BOJ
*	No.17363	우유가 넘어지면?
*	@author	peter9378
*	@date		2019.07.28
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char arr[101][101];
char arrr[101][101];

char convert(char c)
{
	switch (c)
	{
	case '-':
		return '|';
	case '|':
		return '-';
	case '/':
		return '\\';
	case '\\':
		return '/';
	case '^':
		return '<';
	case '<':
		return 'v';
	case 'v':
		return '>';
	case '>':
		return '^';
	}
	return c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			arrr[M-j-1][i] = convert(arr[i][j]);
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arrr[i][j];
		cout << "\n";
	}

	return 0;
}