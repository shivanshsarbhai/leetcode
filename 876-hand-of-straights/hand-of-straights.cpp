class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0)
            return false;

        //initialize a map;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;

        //initialize the minHeap;
        priority_queue<int,vector<int>, greater<int>>pq;
        for(const auto&pair : mp){
            pq.push(pair.first);
        }
        
        while(!pq.empty()){
            int smallest = pq.top();

            //getting the start of next group
            while(!pq.empty() && mp[smallest]==0){
                pq.pop();

                if(pq.empty())
                    return true;
                else
                    smallest = pq.top();
            }

            for(int i=0;i<k;i++){
                int ele = smallest + i;
                if(mp[ele] <= 0)
                    return false;
                else {
                    mp[ele]--;
                }
            }

        }

        return true;
    }
};