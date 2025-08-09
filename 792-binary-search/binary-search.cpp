class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0;
        int end = n-1;
        int ans = -1;

        while(beg<=end){
            int mid = (beg)+(end-beg)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            } else if(nums[mid]<target)
                beg = mid+1;
            else
                end = mid-1;
        }

        return ans;
    }
};