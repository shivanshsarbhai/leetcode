class Solution {
public:
    pair<vector<vector<int>>, vector<int>>fetchPreComputations(int numCourses,  vector<vector<int>>& prerequisites){
        vector<vector<int>>adjList(numCourses);
        vector<int>inorder(numCourses, 0);

        for(vector<int>preReq : prerequisites){
            int course = preReq[0];
            int pre = preReq[1];
            adjList[pre].push_back(course);
            inorder[course]++;
        }

        return {adjList, inorder};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        pair<vector<vector<int>>, vector<int>>preCompute = fetchPreComputations(numCourses, prerequisites);
        vector<vector<int>>adjList = preCompute.first;
        vector<int>inorder = preCompute.second;
        queue<int>q;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(int child : adjList[course]){
                inorder[child]--;
                if(inorder[child]==0)
                    q.push(child);
            }
        }

        if(ans.size() != numCourses)
            return {};

        return ans;
    }
};


/*
[[1,0],[2,0],[3,1],[3,2]]

3 <---
^.   |
|.   |
1->0->2

0 = {2}
1 = {0,3}
2 = {3}

inorder
0. 1
1. 0
2. 1
3. 2


*/