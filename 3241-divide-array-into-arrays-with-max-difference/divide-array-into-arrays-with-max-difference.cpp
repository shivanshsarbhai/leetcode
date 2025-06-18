class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0;i<n;i+=3){
            int num1 = nums[i];
            int num2 = nums[i+1];
            int num3 = nums[i+2];

            if(num3-num1>k)    
                return {};
            
            ans.push_back({num1,num2,num3});
        }

        return ans;
    }
};

/*

1 1 3 3 4 5 7 8 9 

*/