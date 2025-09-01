class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();

        //binSearch on row
        int beg = 0;
        int end = n-1;
        int row = 0;
        while(beg<=end){
            int mid = (beg)+(end-beg)/2;

            if(nums[mid][0] > target)
                end = mid-1;
            
            else{
                row = mid;
                beg = mid+1;
            }
        }

        //binSearch on column
        beg = 0;
        end = m-1;
        while(beg<=end){
            int mid = (beg)+(end-beg)/2;

            if(nums[row][mid] == target)
                return true;

            if(nums[row][mid] < target)
                beg = mid+1;
            
            else
                end = mid-1;
        }

        return false;
    }
};