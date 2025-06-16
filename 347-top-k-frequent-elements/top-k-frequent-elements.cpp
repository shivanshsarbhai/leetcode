class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>>pq;
        
        for(auto &entry: mp)
            pq.push({entry.second, entry.first});
        
        vector<int>ans;
        while(k>0){
            pair<int,int>top = pq.top();
            pq.pop();
            ans.push_back(top.second);
            k--;
        }

        return ans;
    }
};