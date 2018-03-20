/**
*	SW Expert Academy
*	No. 1974 스도쿠 검증
*	@author	peter9378
*	@date		2018.03.20
*/
#include <iostream>
using namespace std;

#define MAX_RANGE 9
#define ONE_RANGE 3

int arr[MAX_RANGE][MAX_RANGE];
bool check[MAX_RANGE+1];

void initialize()
{
	for (int i = 1; i < 10; i++)
		check[i] = false;
	return;
}

bool checking()
{
	for (int i = 1; i < 10; i++)
	{
		if (!check[i])
			return false;
	}
	return true;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	
	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	bool process;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		process = true;
		// 스도쿠 입력
		for (int i = 0; i < MAX_RANGE; i++)
		{
			for (int j = 0; j < MAX_RANGE; j++)
				cin >> arr[i][j];
		}
		
		// 가로줄 검증
		for (int i = 0; i < MAX_RANGE; i++)
		{
			if (!process)
				break;
			initialize();
			for (int j = 0; j < MAX_RANGE; j++)
				check[arr[i][j]] = true;
			if (!checking())
				process = false;
		}

		// 세로줄 검증
		if (process)
		{
			for (int i = 0; i < MAX_RANGE; i++)
			{
				if (!process)
					break;
				initialize();
				for (int j = 0; j < MAX_RANGE; j++)
					check[arr[j][i]] = true;
				if (!checking())
					process = false;
			}
		}

		// 3x3 검증
		if (process)
		{
			for (int i = 0; i < ONE_RANGE; i++)
			{
				for (int j = 0; j < ONE_RANGE; j++)
				{
					if (!process)
					{
						i = ONE_RANGE;
						j = ONE_RANGE;
						continue;
					}
					initialize();
					for (int x = 0; x < ONE_RANGE; x++)
					{
						for (int y = 0; y < ONE_RANGE; y++)
							check[arr[i * 3 + x][j * 3 + y]] = true;
					}
					if (!checking())
						process = false;
				}
			}
		}

		// 출력
		cout << "#" << test_case << " ";
		cout << process ? 1 : 0;
		cout << "\n";
	}

	return 0;
}