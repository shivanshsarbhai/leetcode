class Solution {
    inline static vector<int>dx = {0,1,0,-1};
    inline static vector<int>dy = {1,0,-1,0};

public:
    void dfs(vector<vector<char>>& nums, vector<vector<bool>>& visited, int x, int y){
        visited[x][y] = true;
        for(int i=0;i<4;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(newX>=0 && newX<nums.size() && newY>=0 && newY<nums[0].size() && nums[newX][newY] =='1' && !visited[newX][newY])
                dfs(nums, visited, newX, newY);
        }
    }

    int dfs(vector<vector<char>>& nums){
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && nums[i][j] == '1'){
                    dfs(nums, visited, i, j);
                    count++;
                }   
            }
        }

        return count;
    }
    
    int numIslands(vector<vector<char>>& nums) {
        return dfs(nums);
    }
};