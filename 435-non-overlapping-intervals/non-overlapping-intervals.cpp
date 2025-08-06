class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), comp);
        int ans = 0;
        int lastNonOverLapping = 0;

        for(int i=1;i<nums.size();i++){
            int prevStart = nums[lastNonOverLapping][0];
            int prevEnd = nums[lastNonOverLapping][1];
            int start = nums[i][0];
            int end = nums[i][1];

            if(start>=prevEnd)
            {
                lastNonOverLapping = i;
                continue;
            }
            
            else
                ans++;
        }

        return ans;
    }
};

/*

(1,11) (2, 12) (11,22) (1 100)

*/