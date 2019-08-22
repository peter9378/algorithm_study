/**
*	Programmers
*	2017 KAKAO BLIND RECRUIMTMENT#1	프렌즈4블록
*	@author	peter9378
*	@date		2019.08.22
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	while (true)
	{
		vector<pair<int, int>> v;
		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				char target = board[i][j];
				if (target == '0')
					continue;
				if (board[i + 1][j + 1] == target && board[i + 1][j] == target && board[i][j + 1] == target)
				{
					v.push_back(make_pair(i, j));
					v.push_back(make_pair(i, j + 1));
					v.push_back(make_pair(i + 1, j));
					v.push_back(make_pair(i + 1, j + 1));
				}
			}
		}
		if (v.empty())
			break;
		for (int i = 0; i < v.size(); i++)
		{
			if (board[v[i].first][v[i].second] != '0')
				answer++;
			board[v[i].first][v[i].second] = '0';
		}

		for (int i = 0; i < n; i++)
		{
			queue<char> temp;
			for (int j = m - 1; j > -1; j--)
			{
				if (board[j][i] != '0')
					temp.push(board[j][i]);
			}
			for (int j = m - 1; j > -1; j--)
			{
				if (temp.empty())
					board[j][i] = '0';
				else
				{
					board[j][i] = temp.front();
					temp.pop();
				}
			}
		}
	}
	return answer;
}