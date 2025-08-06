class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0;
        int runningSmallest = nums[0];
        
        for(int i=1;i<nums.size();i++){
            ans = max(ans, nums[i]-runningSmallest);
            runningSmallest = min(runningSmallest, nums[i]);
        }

        return ans;
    }
};