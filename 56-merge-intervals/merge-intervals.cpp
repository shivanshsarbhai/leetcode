class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n-1;i++){
            int firstEnd = nums[i][1];
            int secondStart = nums[i+1][0];
            int firstStart = nums[i][0];
            int secondEnd = nums[i+1][1];
            if(firstEnd < secondStart)
                ans.push_back(nums[i]);
            else
                nums[i+1] = {firstStart, max(firstEnd, secondEnd)}; 
        }

        ans.push_back(nums[n-1]);
        return ans; 
    }
};