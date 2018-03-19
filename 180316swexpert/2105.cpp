/**
*	sw Expert Academy
*	No. 2105 디저트 카페
*	@author	peter9378
*	@date		2018.03.20
*/

#include <iostream>
using namespace std;

int arr[22][22];
int visit[21][21];
int desert[101];
int cnt, result, tempx, tempy;

// 하나씩 다 돌아보며 check
// state 0:우하 1:우하, 좌하 2:좌하, 좌상 3:좌상, 우상 4:우상
void check(int x, int y, int state)
{
	cnt++;
	desert[arr[x][y]]++;
	visit[x][y]++;

	if (state == 4 && visit[x][y] == 2) {
		if (result < cnt - 1) {
			result = cnt - 1;
		}
	}
	else {
		if (state == 0) {
			if (!desert[arr[x + 1][y + 1]] && arr[x][y] != 0) {
				check(x + 1, y + 1, 1);
			}
		}
		else if (state == 1) {
			if (!desert[arr[x + 1][y + 1]] && arr[x + 1][y + 1] != 0) {
				check(x + 1, y + 1, 1);
			}
			if (!desert[arr[x + 1][y - 1]] && arr[x + 1][y - 1] != 0) {
				check(x + 1, y - 1, 2);
			}
		}
		else if (state == 2) {
			if (!desert[arr[x + 1][y - 1]] && arr[x + 1][y - 1] != 0) {
				check(x + 1, y - 1, 2);
			}
			if (!desert[arr[x - 1][y - 1]] && arr[x - 1][y - 1] != 0) {
				check(x - 1, y - 1, 3);
			}
		}
		else if (state == 3) {
			if (!desert[arr[x - 1][y - 1]] && arr[x - 1][y - 1] != 0) {
				check(x - 1, y - 1, 3);
			}
			if (tempx == x - 1 && tempy == y + 1) {
				check(x - 1, y + 1, 4);
			}
			else {
				if (!desert[arr[x - 1][y + 1]] && arr[x - 1][y + 1] != 0) {
					check(x - 1, y + 1, 4);
				}
			}
		}
		else {
			if (tempx == x - 1 && tempy == y + 1) {
				check(x - 1, y + 1, 4);
			}
			else {
				if (!desert[arr[x - 1][y + 1]] && arr[x - 1][y + 1] != 0) {
					check(x - 1, y + 1, 4);
				}
			}
		}
	}
	cnt--;
	desert[arr[x][y]]--;
	visit[x][y]--;
	return;
}

void initialize()
{
	// arr배열을 모두 0으로 초기화
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
			arr[i][j] = 0;
	}
	// 기준을 -1로 초기화
	result = -1;

	return;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++)
	{
		// 한 변의 길이 입력
		int N;
		cin >> N;

		// 값 초기화
		initialize();

		// 디저트 카페 종류 입력
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
				cin >> arr[i][j];
		}

		for (int i = 1; i < N; i++)
		{
			for (int j = 2; j < N; j++)
			{
				tempx = i;
				tempy = j;
				check(i, j, 0);
			}
		}

		cout << "#" << test_case << " " << result << "\n";
	}





	return 0;
}