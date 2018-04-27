/**
*	baekjoon online judge
*	No. 11650 좌표 정렬하기
*	@date		2018.04.27
*/
#include <iostream>
#include <algorithm>
using namespace std;

// 좌표 구조체
struct xy {
	int x, y;
};

// 배열
xy arr[100001];

// 비교 함수
bool compare(xy a, xy b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 점의 개수 입력
	int N;
	cin >> N;

	// 좌표 입력
	for (int i = 0; i < N; i++)
		cin >> arr[i].x >> arr[i].y;

	// 정렬
	sort(arr, arr + N, compare);

	// 출력
	for (int i = 0; i < N; i++)
		cout << arr[i].x << " " << arr[i].y << "\n";

	return 0;
}