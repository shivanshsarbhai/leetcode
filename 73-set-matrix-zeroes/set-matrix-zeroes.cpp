class Solution {
public:
    void makeAllZeros(vector<vector<int>>&nums, int row, int col){
        int n = nums.size();
        int m = nums[0].size();

        for(int i=0;i<n;i++)
            nums[i][col] = 0;
        
        for(int j=0;j<m;j++)
            nums[row][j] = 0;
    }
    void setZeroes(vector<vector<int>>& nums) {
        set<pair<int,int>>s;
        int n = nums.size();
        int m = nums[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==0){
                    s.insert({i,j});
                }
            }
        }

        for(auto entry : s){
            int row = entry.first;
            int col = entry.second;
            makeAllZeros(nums, row, col);
        }
    }
};