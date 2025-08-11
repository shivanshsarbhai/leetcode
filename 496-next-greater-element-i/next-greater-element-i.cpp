class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        map<int,int>nge;
        stack<int>s;
        for(int i=n2-1;i>=0;i--){
            while(!s.empty() && nums2[i]>=s.top())
                s.pop();
            if(s.empty())
                nge[nums2[i]] = -1;
            else 
                nge[nums2[i]] = s.top();

            s.push(nums2[i]);
        }

        vector<int>ans(n1, -1);
        for(int i=0;i<n1;i++){
            if(nge.find(nums1[i])!=nge.end()) 
                ans[i] = nge[nums1[i]];
        }

        return ans;
    }
};