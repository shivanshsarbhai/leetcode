class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int firstEle = nums[i];
            int secondEle = target - firstEle;

            if(mp.find(secondEle) != mp.end())
                return {mp[secondEle], i};
            
            mp[firstEle] = i;
        }

        return {-1,-1};
    }
};