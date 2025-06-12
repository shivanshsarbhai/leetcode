class Solution {
public:
    int getNoOfSetBits(int n){
        int count = 0;
        while(n!=0){
            count += n%2;
            n = n>>1;
        }

        return count;
    }

    vector<int> brute(int n){
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int noOfSetBits = getNoOfSetBits(i);
            ans.push_back(noOfSetBits);
        }

        return ans;
    }

    vector<int> countBits(int n) {
        return brute(n);
    }
};