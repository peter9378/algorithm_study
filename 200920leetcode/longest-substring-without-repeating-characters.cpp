class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        for(int i=0;i<s.length();i++) {
            unordered_map<char, int> um;
            for(int j=0;i+j<s.length();j++) {
                if(um.find(s[i+j]) != um.end()) {
                    i = um[s[i+j]];
                    break;
                }
                um[s[i+j]] = i+j;
                answer = max(answer, j + 1);
            }
        }
        return answer;
    }
};
