/**
*	goorm
*	No.15551	신에게는 아직 12척의 배가 있사옵니다
*	@author	peter9378
*	@date		2019.09.28
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[11][11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> per;
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			cin >> arr[i][j];
		per.push_back(i);
	}

	int answer = -1;
	vector<int> temp;
	do
	{
		int sum = 0;
		for (int i = 0; i < 11; i++)
			sum += arr[i][per[i]];
		if (sum > answer)
		{
			answer = sum;
			temp.clear();
			for (int i = 0; i < 11; i++)
				temp.push_back(per[i]);
		}

	} while (next_permutation(per.begin(), per.end()));

	cout << answer << endl;
	for (int i = 0; i < 11; i++)
		cout << temp[i] + 1 << " ";


	return 0;
}