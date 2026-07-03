class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<int>row(n, 1);
        vector<int>col(m, 1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums[i][j]*=col[j]*row[i];
            }
        }
    }
};