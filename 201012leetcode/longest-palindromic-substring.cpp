class Solution {
public:
	string longestPalindrome(string s) {
		bool dp[1001][1001];
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++)
				dp[i][j] = false;
		}

		string answer = "";
		int x, y, temp;
		x = y = temp = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			for (int j = i; j < s.length(); j++) {
				if (i == j)
					dp[i][j] = true;
				else if (s[i] == s[j]) {
					if (j - i == 1)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][j - 1];
				}
				if (dp[i][j] && j - i >= temp) {
					temp = j - i;
					x = i;
					y = j;
				}
			}
		}
		return s.substr(x, y - x + 1);
	}
};