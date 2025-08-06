class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        int index = 0;
        for(int i=1;i<n;i++){
            int prevStart = ans[index][0];
            int prevEnd = ans[index][1];
            int start = nums[i][0];
            int end = nums[i][1];

            if(start > prevEnd){
                ans.push_back(nums[i]);
                index++;
            }
            else{
                ans[index][0] = min(ans[index][0], start);
                ans[index][1] = max(ans[index][1], end);
            }
        }

        return ans;
    }
};