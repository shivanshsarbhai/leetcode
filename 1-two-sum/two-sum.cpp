class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++)
            nums.push_back({arr[i], i});

        
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = n-1;

        while(i<j){
            pair<int,int>p1 = nums[i];
            pair<int,int>p2 = nums[j];

            if(p1.first + p2.first < target)
                i++;
            
            else if(p1.first + p2.first > target)
                j--;
            
            else
                break;
        }

        return {nums[i].second,nums[j].second};
    }
};