class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>lastPos(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                lastPos[i] = mp[nums[i]];
                mp[nums[i]] = i;
            }else {
                mp[nums[i]] = i;
            }
        }

        cout<<"Last Pos is : ";
        for(int num : lastPos)
            cout<<num<<" ";
        int maxToBeRemoved = -1;
        for(int i=nums.size()-1;i>=0;i--){
            maxToBeRemoved = max(maxToBeRemoved, lastPos[i]);
        }

        if(maxToBeRemoved == -1)
            return 0;
            
        return 1+maxToBeRemoved/3;
    }
};