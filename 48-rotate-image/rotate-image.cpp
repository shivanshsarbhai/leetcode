class Solution {
public:
    void transpose(vector<vector<int>>&nums){
        int n = nums.size();
        int m = nums[0].size();

        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(nums[i][j], nums[j][i]);
            }
        }
    }

    void mirrorImage(vector<vector<int>>&nums){
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                swap(nums[i][j], nums[i][m-j-1]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        mirrorImage(matrix);
    }
};