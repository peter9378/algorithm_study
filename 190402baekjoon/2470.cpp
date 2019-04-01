/**
*	baekjoon online judge
*	No. 2470	두 용액
*	@author	peter9378
*	@date		2019.04.02
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int temp[100001];

bool compare(int a, int b)
{
	return abs(a) < abs(b);
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];


	sort(arr, arr+N, compare);

	int temp = 2000000000, minA = 1000000001, minB = 1000000001;
	for(int i=0;i<N-1;i++)
	{
		if (abs(arr[i] + arr[i + 1])<temp)
		{
			minA = arr[i];
			minB = arr[i + 1];
			temp = abs(arr[i] + arr[i + 1]);
		}
	}
	
	if(minA<minB)
		cout << minA << " " << minB;
	else
		cout << minB << " " << minA;


	return 0;
}