class Solution {
public:
    int solve(vector<int>& nums, int left, int right) {
        int prev2 = 0;  // dp[i-2]
        int prev1 = 0;  // dp[i-1]
        for(int i = left; i <= right; i++) {
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};
