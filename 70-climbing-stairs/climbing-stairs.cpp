class Solution {
public:
    int recursive(int n){
        if(n==1)
            return 1;
        
        if(n==2)
            return 2;

        return recursive(n-1) + recursive(n-2);
    }

    int bottomUp(int n){
        vector<int>dp(46,0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
            dp[i] = dp[i-1]+dp[i-2];

        return dp[n];
    }
    int climbStairs(int n) {
        // return recursive(n);
        return bottomUp(n);
    }
};