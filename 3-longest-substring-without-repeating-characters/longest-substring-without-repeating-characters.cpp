class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        unordered_set<char>s;
        int ans = 0;
        int left = 0;
        int right = 0;

        while(right < n){
            if(s.find(str[right]) == s.end()){
                s.insert(str[right]);
                right++;
                ans = max(ans, right-left);
            } else {
                ans = max(ans, right-left);
                s.erase(str[left]);
                left++;
            }
        }
        return ans;
    }
};


/*
{}
abcabcbb
L
R

*/