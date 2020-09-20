class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        for(int i=0;i<s.length();i++) {
            unordered_set<char> us;
            for(int j=0;i+j<s.length();j++) {
                if(us.find(s[i+j]) != us.end()) {
                    break;
                }
                us.insert(s[i+j]);
                answer = max(answer, j + 1);
            }
        }
        return answer;
    }
};
