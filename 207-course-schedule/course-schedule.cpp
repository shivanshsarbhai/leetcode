class Solution {
public:
    vector<vector<int>> getAdjList(int n, vector<vector<int>>&nums){
        vector<vector<int>>ans(n);
        for(vector<int>num : nums){
            int course = num[0];
            int coursePreReq = num[1];
            ans[coursePreReq].push_back(course);
        }
        return ans;
    }

    bool hasCycle(vector<vector<int>>&adj, int node, vector<bool>&visited, vector<bool>&dfsVisited){
        visited[node] = true;
        dfsVisited[node]=true;

        for(int child : adj[node]){
            if(dfsVisited[child])
                return true;
            
            if(!visited[child] && hasCycle(adj, child, visited, dfsVisited))
                return true;
        }

        dfsVisited[node] = false;
        return false;
    }
    bool hasCycle(int n, vector<vector<int>>&adj){
        vector<bool>visited(n, false);
        vector<bool>dfsVisited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i])
                if(hasCycle(adj, i, visited, dfsVisited))
                    return true;
        }

        return false;
    }


    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList = getAdjList(n, prerequisites);
        return !hasCycle(n, adjList);
    }
};


/*
[0,1]
1->0

*/