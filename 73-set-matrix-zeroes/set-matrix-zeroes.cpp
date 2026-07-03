class Solution {
public:
    void better(vector<vector<int>>& nums){
        // TC : O(n*m) ; SC : O(n) + O(m);
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

    void optimal(vector<vector<int>>&nums){
        // TC : O(n*m) ; SC : O(1);
        bool setFirstRowZero = false;
        bool setFirstColZero = false;
        int n = nums.size();
        int m = nums[0].size();

        for(int i=0;i<n;i++){
            if(nums[i][0]==0){
                setFirstColZero = true;
                break;
            }
        }

        for(int j=0;j<m;j++){
            if(nums[0][j]==0){
                setFirstRowZero=true;
                break;
            }
        }



        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums[i][j]==0){
                    nums[i][0] = 0;
                    nums[0][j] = 0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums[i][0]==0 || nums[0][j]==0)
                    nums[i][j]=0;
            }
        }

        for(int i=0;i<n;i++){
            if(setFirstColZero){
                nums[i][0]=0;
            }
        }

        for(int j=0;j<m;j++){
            if(setFirstRowZero){
                nums[0][j]=0;
            }
        }

    }

    void setZeroes(vector<vector<int>>& nums) {
        // better(nums);
        optimal(nums);
    }
};