class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;

        for(int i=0;i<n;i++){
            int asteroid = abs(nums[i]);
            int dir = nums[i] > 0 ? 1 : -1;
            bool destroyed = false;
            while(!destroyed && !s.empty() && s.top() > 0 && dir < 0){
                if(abs(s.top()) < asteroid)
                    s.pop();
                else if (abs(s.top()) == asteroid){
                    s.pop();
                    destroyed = true;
                } else
                    destroyed = true;
            }

            if(!destroyed)
                s.push(nums[i]);

        }

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};