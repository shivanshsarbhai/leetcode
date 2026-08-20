class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLeft = 0;
        int maxRight = 0;

        int ans = 0;
        for(int i=0;i<n;i++){
            //Assuming that ith element is the middle most element with odd length
            int left = i-1;
            int right = i+1;
            while(left>=0 && right < n && s[left]==s[right]){
                left--;
                right++;
            }

            if(ans < right-left-1){
                maxLeft = left+1;
                maxRight = right-1;
                ans = max(ans, right-left-1);
            }

            left = i;
            right = i+1;
            while(left>=0 && right < n && s[left]==s[right]){
                left--;
                right++;
            }

            if(ans < right-left-1){
                maxLeft = left+1;
                maxRight = right-1;
                ans = max(ans, right-left-1);
            }
        }


        return s.substr(maxLeft, ans);
    }
};