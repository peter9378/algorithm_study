/**
*	Code Forces
*	#578 A.	Hotelier
*	@author	peter9378
*	@date		2019.08.12
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[11];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 60)
			arr[s[i] - 48] = 0;
		else
		{
			if (s[i] == 'L')
			{
				int index = 0;
				while (arr[index])
					index++;
				arr[index] = 1;
			}
			else
			{
				int index = 9;
				while (arr[index])
					index--;
				arr[index] = 1;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		cout << arr[i];

	return 0;
}