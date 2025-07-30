class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_set<char>s;

        while(right < str.length()){
            if(s.find(str[right]) == s.end()){
                ans = max(ans, right-left+1);
                s.insert(str[right]);
                right++;
            } else {
                s.erase(str[left++]);
            }
        }

        return max(ans, right-left);
    }
};