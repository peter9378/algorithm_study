/**
*	baekjoon_stepbystep
*	No. 10989 수 정렬하기 3
*	@author	peter9378
*	@date		2018.03.14
*/
#include <iostream>
using namespace std;

int arr[10001];

// main
int main()
{
	ios::sync_with_stdio(false);
	// 입력받을 숫자 개수
	int T, input;
	cin >> T;

	// 정렬할 숫자들 입력(counting sort를 위해 해당 인덱스의 배열을 1씩 증가)
	for (int i = 0; i < T; i++)
	{
		cin >> input;
		// 속도 향상을 위해 입력과 동시에 counting
		arr[input]++;
	}

	// 출력(자연수이므로 1-base array)
	for (int i = 1; i <= 10000; i++)
	{
		while (arr[i])
		{
			cout << i << "\n";
			arr[i]--;
		}
	}
	return 0;
}