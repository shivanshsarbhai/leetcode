class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>lowestOnLeft(n);
        int ans = -1;
        int runningMin = INT_MAX;
        for(int i=0;i<n;i++){
            lowestOnLeft[i] = runningMin;
            runningMin = min(runningMin, nums[i]);
        }

        for(int i=0;i<n;i++)
            if(nums[i] != lowestOnLeft[i])
                ans = max(ans, nums[i]-lowestOnLeft[i]);
        
        return ans;
    }
};