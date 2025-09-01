class Solution {
public:
    int brute(vector<int>& nums, int k){
        int n = nums.size();
        priority_queue<int>pq;

        for(int num : nums)
            pq.push(num);
        
        for(int i=0;i<k-1;i++)
            pq.pop();
        
        return pq.top();
    }

    int optimal(vector<int>& nums, int k){
        //maintain minheap of size k
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int num : nums){
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }

    int findKthLargest(vector<int>& nums, int k) {
        return optimal(nums, k);
    }
};