/**
*	SW Expert Academy
*	No. 1244 최대 상금
*	@author	peter9378
*	@date		2018.03.28
*/
#include <iostream>
#include <string>
using namespace std;


// swap함수 구현, 포인터 사용으로 배열에 바로 적용 가능
void swap(int* a, int* b)
{
	int* temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

// selection sort 구현
int sort(int arr[], int size, int count)
{
	int max, now_count = 0;
	int temp[6];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];

	for (int i = 0; i < size; i++)
	{
		max = i;
		bool flag = false;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[max] <= arr[j])
			{
				max = j;
				flag = true;
			}
		}
		if (flag)
		{
			swap(arr[max], arr[i]);
			now_count++;
			if (now_count == count)
				return 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != temp[i])
			return count - now_count;
	}
	return count;
}

// ctoi 함수 구현
int ctoi(char target)
{
	if (target == '0')
		return 0;
	else if (target == '1')
		return 1;
	else if (target == '2')
		return 2;
	else if (target == '3')
		return 3;
	else if (target == '4')
		return 4;
	else if (target == '5')
		return 5;
	else if (target == '6')
		return 6;
	else if (target == '7')
		return 7;
	else if (target == '8')
		return 8;
	else if (target == '9')
		return 9;
	return -1;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 테스트 케이스 개수 입력
	int T;
	cin >> T;

	// 테스트 케이스 루프
	for (int test_case = 1; test_case <= T; test_case++)
	{
		// 필요한 데이터 입력
		string str;
		int swap_count;
		int arr[6];
		cin >> str >> swap_count;

		// string을 int배열로 변환
		for (int i = 0; i < str.length(); i++)
			arr[i] = ctoi(str.at(i));

		// 소트
		int remain_count = sort(arr, str.length(), swap_count);

		// 소트했는데 카운트가 남아있으면
		if (remain_count>0)
		{
			// 홀수일 경우에만 맨 끝 두자리를 바꿈
			if (remain_count % 2)
			{
				swap(arr[str.length() - 1], arr[str.length() - 2]);
				// 근데 사실 아무것도 바뀐게 없는거면 다시 바꿈
				if(remain_count == swap_count)
					swap(arr[str.length() - 1], arr[str.length() - 2]);
			}
		}
		else
		{
			// 카운트가 없는데 순서가 괜히 바뀐 경우
			if (arr[str.length() - 2] < arr[str.length() - 1])
				swap(arr[str.length() - 1], arr[str.length() - 2]);
		}

		// 출력
		cout << "#" << test_case << " ";
		for (int i = 0; i < str.length(); i++)
			cout << arr[i];
		cout << "\n";
	}
	return 0;
}