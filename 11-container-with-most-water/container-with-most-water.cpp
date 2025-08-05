class Solution {
public:
    int maxArea(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int ans = 0;
        while(left<right){
            int width = right-left;
            int height = min(nums[left], nums[right]);
            ans = max(ans, width*height);

            if(nums[left]<nums[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};