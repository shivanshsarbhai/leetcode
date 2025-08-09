class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n, 0);
        dp[0] = s[0]-'0' > 0 ? 1 : 0;
        for(int i=1;i<n;i++){
            int lessThan10 = s[i]-'0';
            if(lessThan10 > 0)
                dp[i] += dp[i-1];
            int moreThan10ButLessThan26 = 10*(s[i-1]-'0')+lessThan10;

            if(moreThan10ButLessThan26>=10 && moreThan10ButLessThan26<27)
                dp[i] += i>=2 ? dp[i-2] : 1;
        }

        return dp[n-1];
    }
};