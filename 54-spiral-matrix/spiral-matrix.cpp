class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        int n = nums.size();
        int m = nums[0].size();
        int left = 0;
        int right = m-1;
        int top = 0;
        int bottom = n-1;

        while(top<=bottom && left<=right){
            int index = left;
            while(index<=right){
                ans.push_back(nums[top][index]);
                index++;
            }

            top++;
            index = top;
            while(index<=bottom){
                ans.push_back(nums[index][right]);
                index++;
            }

            right--;
            index = right;
            while(top<=bottom && left<=right && index>=left){
                ans.push_back(nums[bottom][index]);
                index--;
            }

            bottom--;
            index = bottom;
            while(top<=bottom && left<=right && index>=top){
                ans.push_back(nums[index][left]);
                index--;
            }

            left++;
        }
        return ans;
    }
};