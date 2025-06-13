class Solution {
public:
    void transpose(vector<vector<int>>&nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++)
                swap(nums[i][j], nums[j][i]);
        }
    }

    void reverseLineByLine(vector<vector<int>>&nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++)
                swap(nums[i][j], nums[i][n-j-1]);
        }
    }

    void rotate(vector<vector<int>>& nums) {
        transpose(nums);
        reverseLineByLine(nums);
    }
};



/*
       transpose          reverse
123                 147             741
456      =>         258     =>      852
789                 369             963

*/