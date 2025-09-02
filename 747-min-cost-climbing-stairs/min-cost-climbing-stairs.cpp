class Solution {
public:
    int func(vector<int>&nums, int index){
        int n = nums.size();
        vector<int>dp(n+1,0);
        dp[index] = 0;

        for(int i=index+1;i<=n;i++){
            dp[i] = nums[i-1] + dp[i-1];

            if(i>=2)    
                dp[i] = min(dp[i], nums[i-2]+dp[i-2]);
        }

        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(func(cost, 0), func(cost,1));
    }
};