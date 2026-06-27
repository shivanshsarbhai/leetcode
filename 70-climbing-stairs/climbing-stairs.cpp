class Solution {
public:
    int dpMethod(int n){

        if(n<=2)
            return n;
            
        vector<int>dp(n+1, 0);
        dp[1]=1;
        dp[2]=2;

        for(int i=3;i<=n;i++)
            dp[i] = dp[i-1]+dp[i-2];
        
        return dp[n];
    }

    int optimal(int n){
        if(n<=2)
            return n;
        
        int first = 1;
        int second = 2;
        int ans = -1;

        for(int i=3;i<=n;i++){
            ans = first + second;
            first = second;
            second = ans;
        }

        return ans;
    }

    int climbStairs(int n) {
        return dpMethod(n);    
    }
};