class Solution {
public:
    int getBouquets(vector<int>&nums, int days, int adj){
        int ans = 0;
        int flowers = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=days){
                flowers++;
                if(flowers == adj){
                    ans++;
                    flowers = 0;
                } 
            } else {
                flowers = 0;
            }
        }

        return ans;
    }
    int minDays(vector<int>& nums, int m, int k) {
        if((long long)m*k>nums.size())
            return -1;

        int beg = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(beg<=end){
            int mid = (beg)+(end-beg)/2;
            int bouquets = getBouquets(nums, mid, k);

            if(bouquets < m)
                beg = mid+1;
            else{
                ans = mid;
                end = mid-1;
            }
        }

        return ans;
    }
};