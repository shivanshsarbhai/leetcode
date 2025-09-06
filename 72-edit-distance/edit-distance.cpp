class Solution {
public:
    int func(string word1, string word2, int i, int j, vector<vector<int>>&dp){
        if(i<0)
            return j+1; // insert all characters of targetString
        if(j<0)
            return i+1; // delete all characters of sourceString
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i]==word2[j])
            return dp[i][j] = func(word1, word2, i-1,j-1,dp);

        int insertOp = func(word1, word2, i, j-1, dp);
        int deleteOp = func(word1, word2, i-1, j, dp);
        int replaceOp = func(word1, word2, i-1, j-1, dp);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if(n==0 || m==0)
            return n+m;
            
        vector<vector<int>>dp(n, vector<int>(m, -1));
        func(word1, word2, n-1, m-1, dp);
        return dp[n-1][m-1];
    }
};