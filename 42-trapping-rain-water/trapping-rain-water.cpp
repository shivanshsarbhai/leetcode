class Solution {
public:
    vector<int> findGreatestElement(vector<int>&nums, int start, int end){
        int op = start < end ? 1 : -1;
        int n = nums.size();
        vector<int>ans(n, -1);
        int maxSoFar = -1;
        for(int i=start;;i+=op*1){
            if(op==-1){
                if(i<end)
                    break;
            } else {
                if(i>end)
                    break;
            }

            ans[i] = maxSoFar;
            maxSoFar = max(maxSoFar, nums[i]);
        }

        return ans;
    }

    void print(vector<int>&nums){
        cout<<"Priniting Array : ";
        for(int num : nums)
            cout<<num<<" ";
        cout<<endl;
    }

    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngeOnLeft = findGreatestElement(nums, 0, n-1);
        print(ngeOnLeft);
        vector<int> ngeOnRight = findGreatestElement(nums, n-1, 0);
        print(ngeOnRight);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(0, min(ngeOnLeft[i], ngeOnRight[i]) - nums[i]);
        }

        return ans;

    }
};