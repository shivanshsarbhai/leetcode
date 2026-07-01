class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums[0]);
        int index = 0;  //Number of elements in ans that are successsfully processed

        for(int i=1;i<nums.size();i++){
            int prevStart = ans[index][0];
            int prevEnd = ans[index][1];
            int currStart = nums[i][0];
            int currEnd = nums[i][1];

            if(currStart > prevEnd){
                ans.push_back(nums[i]);
                index++;
            }
            else {
                ans[index][1] = max(ans[index][1], currEnd);
            }
        } 
        return ans;
    }
};