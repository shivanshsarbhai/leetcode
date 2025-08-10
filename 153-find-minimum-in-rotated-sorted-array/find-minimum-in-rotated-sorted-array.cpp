class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<=nums[n-1])
            return nums[0];
        
        int beg = 0;
        int end = n-1;
        while(beg<=end){
            int mid = (beg)+(end-beg)/2;
            if(nums[beg]<=nums[mid] && nums[mid]<=nums[end])
                return nums[beg];
           
           if(nums[mid]>=nums[beg])
                beg = mid+1;
            else
                end = mid;
        }

        return nums[beg];
    }
};