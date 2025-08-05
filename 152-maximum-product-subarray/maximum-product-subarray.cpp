class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int localMax = nums[0];
        int localMin = nums[0];
        int globalMax = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0)
                swap(localMax, localMin);
                
            localMax = max(nums[i], localMax*nums[i]);
            localMin = min(nums[i], localMin*nums[i]);

            globalMax = max(max(localMin,localMax), globalMax);
        }

        return globalMax;
    }
};