class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        
        vector<int>nge(2*n-1, -1);
        stack<int>s;
        for(int i=2*n-1;i>=0;i--){

            while(!s.empty() && nums[i] >= s.top())
                s.pop();
            
            if(!s.empty())
                nge[i] = s.top();
            
            s.push(nums[i]);
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
            ans.push_back(nge[i]);

        return ans; 
    }
};

/*
 
1 2 1 1 2 1
2 -1 2 2 -1 -1

1 2 3 4 3 1 2 3 4 3
2 3 4 -1 4 

*/