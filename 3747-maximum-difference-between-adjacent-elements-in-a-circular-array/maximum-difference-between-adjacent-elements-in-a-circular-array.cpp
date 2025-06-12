class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(nums[0]);
        n++;

        int ans = INT_MIN;
        for(int i=1;i<n;i++)
            ans = max(ans, abs(nums[i]-nums[i-1]));
        
        return ans;
    }
};