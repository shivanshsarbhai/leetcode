class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0;
        int end = n-1;
        vector<int>ans = {-1,-1};
        while(beg<=end){
            int mid = (beg)+(end-beg)/2;

            if(nums[mid]==target){
                int left = mid;
                int right = mid;
                while(left>=0 && nums[left]==target)
                    left--;
                while(right<n && nums[right]==target)
                    right++;
                
                ans = {left+1, right-1};
                break;
            } else if(nums[mid]<target)
                beg = mid+1;
            else
                end = mid-1;
        }

        return ans;
    }
};