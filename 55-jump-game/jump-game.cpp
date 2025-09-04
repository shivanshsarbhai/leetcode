class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;

        int i=0;
        int maxReach = nums[0];

        for(;i<=maxReach;i++){

            maxReach = max(maxReach, i+nums[i]);
            // cout<<"i="<<i<<" "<<"MaxReach is : "<<maxReach<<endl;
            if(maxReach >= nums.size()-1)
                return true;
        }

        return false;
    }
};

/*

2 3 1 1 4

2 3 
*/