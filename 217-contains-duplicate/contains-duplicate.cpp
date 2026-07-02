class Solution {
public:
    bool better(vector<int>& nums) {
        //TC : O(N) , SC: O(N)
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
        }

        return false;
    }

    bool containsDuplicate(vector<int>& nums) {
        //brute force would be O(n2)
        return better(nums);
    }
};