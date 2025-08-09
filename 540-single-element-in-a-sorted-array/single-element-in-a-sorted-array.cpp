class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
            
        if(nums[0]!=nums[1])
            return nums[0];
        
        else if(nums[n-1]!=nums[n-2])
            return nums[n-1];
        
        int beg = 2;
        int end = n-3;
        while(beg<=end){
            int mid = (beg)+(end-beg)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];

            if(mid%2==0){
                if(nums[mid]==nums[mid+1])
                    beg = mid+1;
                else
                    end = mid-1;
            } else {
                if(nums[mid]==nums[mid-1])
                    beg = mid+1;
                else
                    end = mid-1;
            }
        }

        return -1;
    }
};