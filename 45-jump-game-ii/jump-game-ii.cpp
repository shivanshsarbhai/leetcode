class Solution {
public:
    void populateFurther(vector<int>&dp, int index, int end, int val){
        int size = dp.size();
        int endIndex = min(size-1, end);
        for(int i=index;i<=endIndex;i++){
            dp[i] = min(dp[i], val);
        }
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0;

        for(int i=0;i<n;i++){
            if(dp[i] != INT_MAX)
                populateFurther(dp, i+1, i+nums[i], 1+dp[i]);
        }

        return dp[n-1];
    }
};

/*
[1,2,3]
[0,X,X]
[0,1,X]



*/