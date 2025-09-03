class Solution {
public:
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};

    bool isWithinBounds(vector<vector<char>>&nums, int i, int j){
        return 
        i>=0 
        && i<nums.size()
        && j>-0
        && j<nums[0].size();
    }

    void print(vector<vector<char>>&nums){
        cout<<"Board is : ";
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[0].size();j++)
                cout<<nums[i][j]<<" ";
            cout<<endl;
        }
    }
    
    void bfs(vector<vector<char>>&nums, vector<vector<bool>>&visited, int x, int y){
        queue<pair<int,int>>q;
        q.push({x,y});

        while(!q.empty()){
            pair<int,int>cell = q.front();
            q.pop();
            int cellX = cell.first;
            int cellY = cell.second;
            for(int i=0;i<4;i++){
                int newX = cellX+dx[i];
                int newY = cellY+dy[i];
                if(isWithinBounds(nums, newX, newY) && nums[newX][newY]=='O' && !visited[newX][newY]){
                    q.push({newX, newY});
                    nums[newX][newY] = 'N';
                    visited[newX][newY]=true;
                }
            }
        }

    }

    bool isOnBorder(int i, int j, int n , int m){
        if(i==0 || j==0 || i==n-1 || j==m-1)
            return true;
        
        return false;
    }

    void solve(vector<vector<char>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!isOnBorder(i,j,n,m))
                    continue;

                if(nums[i][j]=='O' && !visited[i][j]){
                    nums[i][j] = 'N';
                    visited[i][j] = true;
                    bfs(nums, visited, i, j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]=='N')
                    nums[i][j] = 'O';
                else
                    nums[i][j] = 'X';
            }
        }
    }
};