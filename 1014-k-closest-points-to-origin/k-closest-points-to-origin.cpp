class Solution {
public:

    double getDist(vector<int>&p){
        int x = p[0];
        int y = p[1];

        long x2 = x*x;
        long y2 = y*y;
        double ans = pow(x2+y2, 0.5);
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>>pq;

        for(int i=0;i<points.size();i++){
            double dist = getDist(points[i]);
            pq.push({dist, i});
        }

        vector<vector<int>>ans;
        while(!pq.empty() && k>0){
            pair<double,int>topEle = pq.top();
            pq.pop();
            int index = topEle.second;
            ans.push_back(points[index]);
            k--;
        }

        return ans;
    }
};