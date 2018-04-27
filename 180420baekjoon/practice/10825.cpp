/**
*	baekjoon online judge
*	No. 10825 국영수
*	@date		2018.04.27
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 학생 구조체
struct member {
	string name;
	int korean, english, math;
};

// 배열
member arr[100001];

// 비교 함수
bool compare(member a, member b)
{
	if (a.korean == b.korean && a.english == b.english && a.math == b.math)
		return a.name < b.name;
	if (a.korean == b.korean && a.english == b.english)
		return a.math > b.math;
	if (a.korean == b.korean)
		return a.english < b.english;
	return a.korean > b.korean;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 학생 명수 입력
	int N;
	cin >> N;

	// 학생 점수 입력
	for (int i = 0; i < N; i++)
		cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;

	// 정렬
	sort(arr, arr + N, compare);

	// 출력
	for (int i = 0; i < N; i++)
		cout << arr[i].name << "\n";

	return 0;
}