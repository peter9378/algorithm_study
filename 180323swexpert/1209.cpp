/**
*	SW Expert Academy
*	No. 1209 Sum
*	@author	peter9378
*	@date		2018.03.27
*/
#include <iostream>
using namespace std;

// 한 변의 길이
#define MAX 100

// max 함수 구현
int max(int a, int b)
{
	return a > b ? a : b;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 루프
	for (int test_case = 1; test_case < 11; test_case++)
	{
		// 테스트 케이스 번호 입력
		int trash;
		cin >> trash;

		// 배열 선언
		int arr[MAX][MAX];
		int max_sum = 0;

		// 배열 입력
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
				cin >> arr[i][j];
		}

		// 가로 및 세로 합 계산, 최대값 추출
		for (int i = 0; i < MAX; i++)
		{
			int breadth_sum = 0;
			int height_sum = 0;
			for (int j = 0; j < MAX; j++)
			{
				breadth_sum += arr[i][j];
				height_sum += arr[j][i];
			}
			max_sum = max(max_sum,max(breadth_sum, height_sum));
		}

		// 대각선 최대값 계산
		int diagonal_sum = 0;
		for (int i = 0; i < MAX; i++)
			diagonal_sum += arr[i][i];
		max_sum = max(max_sum, diagonal_sum);

		// 반대 대각선 최대값 계산
		diagonal_sum = 0;
		for (int i = 0; i < MAX; i++)
			diagonal_sum += arr[MAX - 1 - i][i];
		max_sum = max(max_sum, diagonal_sum);

		// 출력
		cout << "#" << test_case << " " << max_sum << "\n";
	}
	return 0;
}