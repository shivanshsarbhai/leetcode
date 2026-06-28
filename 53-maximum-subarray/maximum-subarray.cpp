class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int globalMax = nums[0];

        for(int i=1;i<nums.size();i++){
            maxSoFar = max(nums[i], maxSoFar + nums[i]);
            globalMax = max(globalMax, maxSoFar);
        }

        return globalMax;
    }
};