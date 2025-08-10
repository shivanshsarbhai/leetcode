class Solution {
public:
    int getMax(vector<int>&nums){
        int ans = INT_MIN;
        for(int num : nums)
            ans = max(ans, num);
        return ans;
    }

    long getHours(vector<int>&nums, int speed){
        long hours = 0;
        for(int num: nums){
            hours+=(num+speed-1)/speed;
        }

        return hours;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int beg = 1;
        int end = getMax(nums);
        int ans = INT_MAX;
        while(beg<=end){
            int cand = (beg)+(end-beg)/2;
            long hours = getHours(nums, cand);
            if(hours > h){
                beg = cand+1;
            } else {
                ans = cand;
                end = cand-1;
            }
        }

        return ans;
    }
};