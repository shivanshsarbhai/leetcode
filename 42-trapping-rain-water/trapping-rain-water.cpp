class Solution {
public:
    vector<int> findGreatestElement(vector<int>&nums, int start, int end){
        int op = start < end ? 1 : -1;
        int n = nums.size();
        vector<int>ans(n, -1);
        int maxSoFar = -1;
        for(int i=start;;i+=op*1){
            if(op==-1){
                if(i<end)
                    break;
            } else {
                if(i>end)
                    break;
            }

            ans[i] = maxSoFar;
            maxSoFar = max(maxSoFar, nums[i]);
        }

        return ans;
    }

    int better(vector<int>&nums){
        int n = nums.size();
        vector<int> ngeOnLeft = findGreatestElement(nums, 0, n-1);
        vector<int> ngeOnRight = findGreatestElement(nums, n-1, 0);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(0, min(ngeOnLeft[i], ngeOnRight[i]) - nums[i]);
        }

        return ans;
    }

    int optimal(vector<int>&nums){
        int ans = 0;
        int n = nums.size();
        int left = 0;
        int maxLeft = nums[0];
        int right = n-1;
        int maxRight = nums[n-1];

        while(left<=right){
            if(nums[left]<=nums[right]){
                ans+= max(0,maxLeft - nums[left]);
                maxLeft = max(maxLeft, nums[left++]);
            } else{
                ans+= max(0,maxRight - nums[right]);
                maxRight = max(maxRight, nums[right--]);
            }
        }

        return ans;
    }

    int trap(vector<int>& nums) {
        // return better(nums);
        return optimal(nums);
    }
};