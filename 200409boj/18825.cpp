/**
*	BOJ
*	No.18825	눈치게임 A+B! A-B! A+B! 터렛! A+B! 피보나치 함수! A+B! A-B! A+B! 어린 왕자! A+B! ACM Craft! A+B! A-B! A+B! 습격자 초라기! A+B! 벡터 매칭! A+B! A-B! A+B! A/B! A+B! 터렛! A+B! A-B! A+B! 분산처리! A+B! A+B! 마셔라! 마셔라 마셔라! 마셔라 틀이 들어간다! 
*	@author	peter9378
*	@date		2020.04.09
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDistance(int x1, int y1, int x2, int y2)
{
	return pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int distance = getDistance(x1, y1, x2, y2);
		if (x1 == x2 && y1 == y2 && r1 == r2)
			cout << "-1\n";
		else if (distance == pow((r1 + r2), 2))
			cout << "1\n";
		else if (distance == pow(abs(r1 - r2), 2) && distance)
			cout << "1\n";
		else if (distance > pow((r1 + r2), 2))
			cout << "0\n";
		else if (distance < pow(abs(r1 - r2), 2))
			cout << "0\n";
		else
			cout << "2\n";
	}


	return 0;
}