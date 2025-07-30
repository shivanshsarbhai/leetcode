class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_set<char>s;

        while(right < str.length()){
            if(s.find(str[right]) != s.end()){
                ans = max(ans, right-left);
                while(left <= right && s.find(str[right]) != s.end()){
                    s.erase(str[left]);
                    left++;
                }
            } else {
                s.insert(str[right]);
                right++;
            }
        }

        return max(ans, right-left);
    }
};