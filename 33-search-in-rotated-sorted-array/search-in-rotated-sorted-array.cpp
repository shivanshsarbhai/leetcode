class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0] == target)
            return 0;
        
        if(nums[n-1] == target)
            return n-1;
        
        int beg = 1;
        int end = n-1;

        while(beg<=end){
            int mid = (beg) + (end-beg)/2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] >= nums[beg]){
                //left half is sorted
                if(target >= nums[beg] && target < nums[mid])
                    end = mid - 1;
                else
                    beg = mid + 1;
            } else {
                //right half is sorted
                if(target > nums[mid] && target <= nums[end])
                    beg = mid + 1;
                else
                    end = mid-1;
            }
        }

        return -1;
    }
};