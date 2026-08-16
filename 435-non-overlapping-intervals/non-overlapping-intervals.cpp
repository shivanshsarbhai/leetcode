class Solution {
public:
    static bool sortByEndTime(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), sortByEndTime);

        int ans = 0;
        int prevEnd = nums[0][1];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i][0] < prevEnd) {
                // Overlap → remove current
                ans++;
            } else {
                // No overlap → keep current
                prevEnd = nums[i][1];
            }
        }

        return ans;
    }
};