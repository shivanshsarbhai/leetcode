class Solution {
public:
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    bool isWithinBounds(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int freshCount = 0;

        // Step 1: Push all rotten oranges into queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    freshCount++;
            }
        }

        // Edge case: no fresh oranges
        if(freshCount == 0) return 0;

        int time = -1;
        // Step 2: BFS
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int k=0;k<size;k++){
                auto [x,y] = q.front(); q.pop();
                for(int d=0; d<4; d++){
                    int newX = x + dx[d];
                    int newY = y + dy[d];
                    if(isWithinBounds(newX, newY, n, m) && grid[newX][newY] == 1){
                        grid[newX][newY] = 2; // Rot it
                        freshCount--;
                        q.push({newX,newY});
                    }
                }
            }
        }

        // If fresh oranges remain → impossible
        return freshCount == 0 ? time : -1;
    }
};
