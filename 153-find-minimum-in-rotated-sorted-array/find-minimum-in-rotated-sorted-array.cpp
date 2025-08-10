class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();      
        int beg = 0;
        int end = n-1;
        int ans = INT_MAX;
        while(beg<=end){
            int mid = (beg)+(end-beg)/2;
            if(nums[end]>=nums[beg]){
                ans = min(ans, nums[beg]);
                break;
            }
               
            if(nums[mid]>=nums[beg])
                beg = mid+1;
            else{
                ans = min(ans, nums[mid]);           
                end = mid-1;
            }
        }

        return ans;
    }
};