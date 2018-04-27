/**
*	baekjoon online judge
*	No. 10814 나이순 정렬
*	@date		2018.04.27
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 회원 구조체
struct member {
	int age;
	string name;
};

// 배열
member arr[100001];

// 비교 함수
bool compare(member a, member b)
{
	return a.age < b.age;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 회원 명수 입력
	int N;
	cin >> N;

	// 회원 정보 입력
	for (int i = 0; i < N; i++)
		cin >> arr[i].age >> arr[i].name;

	// 정렬 - 순서를 보장하기 위해 stable_sort 사용
	stable_sort(arr, arr + N, compare);

	// 출력
	for (int i = 0; i < N; i++)
		cout << arr[i].age << " " << arr[i].name << "\n";

	return 0;
}