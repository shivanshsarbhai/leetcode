class Solution {
public:
    void populateFurther(vector<int>&dp, int index, int end, int val){
        int size = dp.size();
        int endIndex = min(size-1, end);
        for(int i=index;i<=endIndex;i++){
            dp[i] = min(dp[i], val);
        }
    }
    int brute(vector<int>&nums){
       int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;

        for(int i=0;i<n;i++){
            if(dp[i] != INT_MAX)
                populateFurther(dp, i+1, i+nums[i], 1+dp[i]);
        }

        return dp[n-1];
    }
    int optimal(vector<int>&nums){
        int n = nums.size();
        int jumps = 0;
        int maxReach = 0;
        int endIndex = 0;

        for(int i=0;i<n-1;i++){
            maxReach = max(maxReach, i+nums[i]);
            if(i==endIndex){
                jumps++;
                endIndex = maxReach;
            }
        }

        return jumps;
    }

    int jump(vector<int>& nums) {
        return optimal(nums);
    }
};

/*
[2,3,1,1,4]
       ^

i=4
maxReach = 4;
jumps = 2;
endIndex = 4;

*/