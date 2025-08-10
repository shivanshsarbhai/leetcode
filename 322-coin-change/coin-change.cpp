class Solution {
public:
    int coinChange(vector<int>& nums, int amount) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, INT_MAX));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0 && j==0)
                    dp[i][j] = 0;
                else if(i==0)
                    dp[i][j] = INT_MAX;
                else if(j==0)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i-1][j];
                    if (nums[i-1] <= j && dp[i][j - nums[i-1]] != INT_MAX)
                        dp[i][j] = min(dp[i-1][j], 1+dp[i][j-nums[i-1]]);
                }
            }
        }

        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};