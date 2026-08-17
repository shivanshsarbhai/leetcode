class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int localMax = nums[0];
        for(int i=0;i<nums.size();i++){
            int localMax = max(localMax+nums[i],nums[i]);
            ans = max(ans, localMax);
        }
        return ans;

    }
};