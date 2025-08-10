class Solution {
public:
    void backtrack(vector<int>&nums, int target, vector<vector<int>>&ans, vector<int>&curr, int start){
        if(target==0){
            ans.push_back(curr);
            return;
        }

        for(int i=start;i<nums.size();i++){
            if(nums[i] > target)
                break;

            curr.push_back(nums[i]);
            backtrack(nums, target-nums[i], ans, curr, i);
            curr.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr = {};
        backtrack(nums, target, ans, curr, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};