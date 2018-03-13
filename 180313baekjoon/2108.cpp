/**
*	baekjoon_stepbystep
*	No. 2108 통계학
*	@author	peter9378
*	@date		2018.03.14
*/
#include <iostream>
#include <iomanip>
using namespace std;

int arr[8001];

// main
int main()
{
	ios::sync_with_stdio(false);
	// 입력받을 숫자 개수
	int N, input, sum=0;
	cin >> N;

	// 정렬할 숫자들 입력(counting sort를 위해 해당 인덱스의 배열을 1씩 증가)
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		// 속도 향상을 위해 입력과 동시에 counting, 음수를 고려하기 위해 4000을 더함
		arr[input+4000]++;
		// 속도 향상을 위해 입력과 동시에 총합을 계산
		sum += input;
	}

	// 최빈값 구하기
	int max_count=0, max_number;
	bool same_flag = false;
	for (int i = 0; i < 8001; i++)
	{
		// 최빈값이 여러 개일 경우 추가로 체크하기 위해
		if (max_count == arr[i])
			same_flag = true;

		// 최빈값 갱신
		if (max_count < arr[i])
		{
			max_count = arr[i];
			max_number = i - 4000;
			same_flag = false;
		}
	}

	// 최빈값이 여러 개 있을 경우
	bool second_flag = false;
	if (same_flag)
	{
		for (int i = 0; i < 8001; i++)
		{
			// 한 번 최빈값을 만나면 다음에 만날 때(두 번째로 작은 값을 만날 때) 최빈값 결정
			if (max_count == arr[i])
			{
				if (second_flag)
				{
					max_number = i - 4000;
					break;
				}
				else
					second_flag = true;
			}
		}
	}


	// 최대/최소 구하기
	int min, max, index=0;

	// 최소값 구하기, 처음에 더해준 4000을 빼줌
	while (!arr[index])
		index++;
	min = index - 4000;

	// 최대값 구하기, 처음에 더해준 4000을 빼줌
	index = 8000;
	while (!arr[index])
		index--;
	max = index - 4000;
	
	// 중간값 구하기(counting array에 직접적으로 영향을 주므로 마지막에 계산)
	int count = 0, median = -1;
	// 주어진 N개의 수의 반만큼 counting array를 차례대로 소거해가며 중간값 계산
	for (int i = 0; i < 8001; i++)
	{
		while (arr[i])
		{
			arr[i]--;
			count++;
			if (count == (N / 2)+1)
			{
				median = i - 4000;
				i = N;
				break;
			}
		}
	}


	// 출력
	cout << fixed << setprecision(0) << ((double)sum / (double) N) << "\n";
	cout << median << "\n";
	cout << max_number<< "\n";
	cout << max-min;
	return 0;
}