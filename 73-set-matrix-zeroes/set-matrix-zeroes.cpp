class Solution {
public:
    void suboptimal(vector<vector<int>>&nums) {
        //TC : O(nm)
        //SC : O(n + m)
        int n = nums.size();
        int m = nums[0].size();
        vector<int>rows(n, 1);
        vector<int>cols(m, 1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j] == 0){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rows[i]==0 || cols[j]==0)
                    nums[i][j] = 0;
            }
        }
    }

void optimal(vector<vector<int>>& nums) {
    int n = nums.size();
    int m = nums[0].size();

    bool firstRow = false;
    bool firstCol = false;

    // Check first row
    for (int j = 0; j < m; j++) {
        if (nums[0][j] == 0)
            firstRow = true;
    }

    // Check first column
    for (int i = 0; i < n; i++) {
        if (nums[i][0] == 0)
            firstCol = true;
    }

    // Use first row/column as markers
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (nums[i][j] == 0) {
                nums[i][0] = 0;
                nums[0][j] = 0;
            }
        }
    }

    // Zero marked rows/columns
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (nums[i][0] == 0 || nums[0][j] == 0)
                nums[i][j] = 0;
        }
    }

    // Zero first row
    if (firstRow) {
        for (int j = 0; j < m; j++)
            nums[0][j] = 0;
    }

    // Zero first column
    if (firstCol) {
        for (int i = 0; i < n; i++)
            nums[i][0] = 0;
    }
}

    void setZeroes(vector<vector<int>>& nums) {
        // suboptimal(nums);
        optimal(nums);
    }
};