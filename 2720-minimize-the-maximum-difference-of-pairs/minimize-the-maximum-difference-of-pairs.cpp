class Solution {
public:
    int getCount(vector<int>&nums, int k){
        //returns the count of pairs int nums, whose abs difference is <=k . Only unique elements to be selected
        int count = 0;
        for(int i=0;i<nums.size()-1;){
            int num1 = nums[i];
            int num2 = nums[i+1];

            if(num2-num1 <=k ){
                i+=2;
                count++;
            } else {
                i++;
            }
        }
        return count;
    }
   
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        //binary search on the minimum maximum difference
        int beg = 0;
        int end = 1e9+1;
        int ans = 0;
        while(beg<=end){
            //assuming mid is the maximum difference among p pairs
            int mid = beg + (end-beg)/2;        
            int countPairsWithDiffLessThanMid = getCount(nums, mid);

            if(countPairsWithDiffLessThanMid<p)
                beg = mid+1;
            else
            {
                ans = mid;
                end = mid-1;
            }
        }      

        return ans;
    }
};