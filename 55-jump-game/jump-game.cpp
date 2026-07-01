class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return true;

        int maxFromHere = nums[0];
        int maxFromBefore = nums[0];
        for(int i=0;i<n;i++){
            if(i<=maxFromBefore){
                maxFromHere = i+nums[i];
                maxFromBefore = max(maxFromBefore , maxFromHere);
            }
        }

        return maxFromBefore >= n-1;
    }
};

/*
maxFromBefore = 2
maxFromHere   = 2

i=1
maxFromHere = 3
maxFromBefore = 3

i=2
maxFromHere = 3
maxFromBefore = 3

i=3
maxFromHere = 3
maxFromBefore = 3
*/