class Solution {
public:
    bool dfs(vector<vector<char>>&board, string &word, 
    vector<vector<bool>>&visited, int i, int j, int index){
        if (board[i][j] != word[index]) 
            return false;
        
        if (index == word.size() - 1) 
            return true;

        visited[i][j] = true;

        vector<int>dx = {0,1,0,-1};
        vector<int>dy={1,0,-1,0};
        for(int dir=0;dir<4;dir++){
            int newX = i+dx[dir];
            int newY = j+dy[dir];

            if(newX>=0 && newX<board.size() && newY>=0 && newY<board[0].size() && !visited[newX][newY])
                if(dfs(board, word, visited, newX, newY, index+1))
                    return true;
        }

        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(board[i][j]==word[0]){
                    if(dfs(board, word, visited, i,j,0))
                        return true;
                }
        }
        
        return false;
    }
};