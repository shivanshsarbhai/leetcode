class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m-1;

        vector<int>ans;
        while(top<=bottom && left<=right){
            
            for(int j=left;j<=right;j++)
                ans.push_back(nums[top][j]);
            top++;

            for(int i=top;i<=bottom;i++)
                ans.push_back(nums[i][right]);
            right--;

            if(top<=bottom){
                for(int j=right;j>=left;j--)
                    ans.push_back(nums[bottom][j]);
                bottom--;
            }

            
            if(right>=left){
                for(int i=bottom;i>=top;i--)
                    ans.push_back(nums[i][left]);
                left++;
            }
        }

        return ans;
    }
};