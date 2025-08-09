class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        int n = s.length();
        int ansStart = 0;
        int ansEnd = 0;
        for(int i=0;i<n;i++){
            int left = i;
            int right = i;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1 > ans){
                    ans = right-left+1;
                    ansStart = left;
                    ansEnd = right;
                }
                left--;
                right++;
            }

            left = i;
            right = i+1;
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1 > ans){
                    ans = right-left+1;
                    ansStart = left;
                    ansEnd = right;
                }
                left--;
                right++;
            }         
        }

        string res = "";
        for(int i=ansStart;i<=ansEnd;i++)
            res+=s[i];

        return res;
    }
};