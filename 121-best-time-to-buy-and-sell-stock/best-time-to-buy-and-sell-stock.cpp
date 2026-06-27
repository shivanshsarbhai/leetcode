class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int ans = 0;
        for(int i=0;i<prices.size();i++){
            ans = max(ans, prices[i] - minSoFar);
            minSoFar = min(minSoFar, prices[i]);
        }

        return ans;
    }
};