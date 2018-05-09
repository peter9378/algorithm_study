/**
*	baekjoon_stepbystep
*	No. 6588	골드바흐의 추측
*	@author	peter9378
*	@date		2018.05.09
*/
#include <iostream>
using namespace std;

// 소수 배열
int arr[1000001] = { 0, 1 };

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	

	arr[0] = arr[1] = 1;

	for (int i = 2; i*i <= 1000000; i++) 
	{
		for (int j = 0; (i*(i + j)) <= 1000000; j++) 
			arr[(i*i) + (i*j)] = 1;
	}

	int input, check;
	while (true) 
	{
		cin >> input;

		if (!input) 
			break;
		else 
		{
			check = 0;
			for (int i = 3; i <= (input / 2); i++) 
			{
				if ((!arr[i]) && (!arr[input - i])) 
				{
					cout << input << " = " << i << " + " << input - i << "\n";
					check = 1;
					break;
				}
			}
			if (!check)
				cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}