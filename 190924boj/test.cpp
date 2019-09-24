#include <iostream>
#include <string>
using namespace std;

string arr[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, loop;
	cin >> n >> loop;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	for (int index = 0; index < n / 2; index++)
	{
		int go = loop;
		if (index % 2)
			go = -go;
		go %= (4 * (n - 2 * index - 1));
		if (go < 0) {
			go += (4 * (n - 2 * index - 1));
		}

		for (int i = 0; i < go; i++)
		{
			string temp = arr[index][index];

			for (int j = index + 1; j < n - index; j++)
				arr[j - 1][index] = arr[j][index];

			for (int j = index + 1; j < n - index; j++)
				arr[n - index - 1][j - 1] = arr[n - index - 1][j];

			for (int j = n - index - 1; j > index; j--)
				arr[j][n - index - 1] = arr[j - 1][n - index - 1];

			for (int j = n - index - 1; j > index; j--)
				arr[index][j] = arr[index][j - 1];

			arr[index][index + 1] = temp;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}


	return 0;
}