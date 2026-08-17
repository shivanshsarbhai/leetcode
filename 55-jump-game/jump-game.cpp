class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxCanReach = nums[0];
        for(int i=1;i<n;i++){
            if(maxCanReach >= i)
                maxCanReach = max(maxCanReach, i+nums[i]);
        }

        return maxCanReach >= n-1;
    }
};