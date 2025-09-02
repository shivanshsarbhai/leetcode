class Solution {
public:
    int dpApproach(vector<int>&nums, int index){
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

    int optimal(vector<int>& nums){
        int n = nums.size();
        int prev1 = 0;
        int prev2 = 0;
        int cost = 0;

        for(int i=2;i<=n;i++){
            cost = min(nums[i-1]+prev1, nums[i-2]+prev2);
            prev2 = prev1;
            prev1 = cost;
        }

        return cost;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // return min(dpApproach(cost, 0), dpApproach(cost,1));
        return optimal(cost);
    }
};