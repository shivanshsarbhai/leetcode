class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = nums.size();
        int i = 0;
        while(i<n && nums[i][1] < newInterval[0]){
            ans.push_back(nums[i]);
            i++;
        }

        while(i<n && nums[i][0]<=newInterval[1]){
            newInterval[0] = min(newInterval[0], nums[i][0]);
            newInterval[1] = max(newInterval[1], nums[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        while(i<n){
            ans.push_back(nums[i]);
            i++;
        }

        return ans;
    }
};