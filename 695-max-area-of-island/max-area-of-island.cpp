class Solution {
public:
    void bfs(vector<vector<int>>& nums, int x, int y, vector<vector<bool>>& visited, int &area){
        visited[x][y] = true;
        queue<pair<int,int>>q;
        q.push({x,y});
        vector<int>dx = {0,1,0,-1};
        vector<int>dy = {1,0,-1,0};

        while(!q.empty()){
            pair<int,int>currCell = q.front();
            q.pop();
            area++;

            for(int i=0;i<4;i++){
                int newX = currCell.first + dx[i];
                int newY = currCell.second + dy[i];

                if(newX>=0 && newX<nums.size() 
                && newY>=0 && newY<nums[0].size() 
                && nums[newX][newY]==1 
                && !visited[newX][newY]){
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==1 && !visited[i][j]){
                    int area = 0;
                    bfs(nums, i, j, visited, area);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};