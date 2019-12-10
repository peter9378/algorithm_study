/**
*	BOJ
*	No.2864	5와 6의 차이
*	@author	peter9378
*	@date		2019.12.10
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B;
	cin >> A >> B;

	string bigA = "", bigB = "";

	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == '5')
			bigA += '6';
		else
			bigA += A[i];
	}
	for (int i = 0; i < B.length(); i++)
	{
		if (B[i] == '5')
			bigB += '6';
		else
			bigB += B[i];
	}

	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == '6')
			A[i] = '5';
	}
	for (int i = 0; i < B.length(); i++)
	{
		if (B[i] == '6')
			B[i] = '5';
	}

	cout << stoi(A) + stoi(B) << " " << stoi(bigA) + stoi(bigB);

	return 0;
}
