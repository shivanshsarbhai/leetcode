class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int>pse(n, -1);
        vector<int>nse(n, n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]<=nums[s.top()])
                s.pop();
            
            if(s.empty())
                pse[i] = -1;
            else
                pse[i] = s.top();
            s.push(i);
        }

        while(!s.empty())
            s.pop();

        for(int i=n-1;i>=0;i--){
             while(!s.empty() && nums[i]<=nums[s.top()])
                s.pop();
            
            if(s.empty())
                nse[i] = n;
            else
                nse[i] = s.top();
            s.push(i);           
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int width = nse[i]-pse[i]-1;
            int height = nums[i];
            ans = max(ans, width * height);
        }

        return ans;
    }
};