class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1])
                        j++;
                    
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                } else if(sum>0)
                    k--;
                else
                    j++;
            }
            
        }

        vector<vector<int>>ans;
        for(vector<int>triplet : s)
            ans.push_back(triplet);
        
        return ans;
    }
};


/*

-4 -1 -1 0 1 2


*/