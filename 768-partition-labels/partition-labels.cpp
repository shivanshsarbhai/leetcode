class Solution {
public:
    vector<pair<int,int>> mergeIntervals(vector<pair<int,int>>intervals){
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>>ans;
        ans.push_back(intervals[0]);
        int index = 0;
        pair<int,int>emptyPair = {-1,-1};
        for(int i=1;i<intervals.size();i++){
            pair<int,int>interval = intervals[i];
            if(interval != emptyPair){
                int currStart = interval.first;
                int currEnd = interval.second;
                int prevStart = ans[index].first;
                int prevEnd = ans[index].second;

                if(prevEnd > currStart){
                    ans[index].first = prevStart;
                    ans[index].second = max(prevEnd, currEnd);
                }

                else{
                    ans.push_back(interval);
                    index++;
                }
            }
        }

        return ans;
    }

    void print(vector<pair<int,int>>intervals){
        cout<<"Printing intervals : ";
        for(pair<int,int> interval : intervals){
            cout<<"("<<interval.first<<","<<interval.second<<") ";
        }

        cout<<endl;
    }
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>>intervals(26, {-1,-1});
        pair<int,int>emptyPair = {-1,-1};
        for(int i=0;i<s.length();i++){
            if(intervals[s[i]-'a'] == emptyPair){
                intervals[s[i]-'a'].first = i;
                intervals[s[i]-'a'].second = i;
            }
            
            else
                intervals[s[i]-'a'].second = i;
        }

        // print(intervals);
        vector<pair<int,int>>mergedIntervals = mergeIntervals(intervals);
        // print(mergedIntervals);
        vector<int>ans;
        for(pair<int,int> interval : mergedIntervals){
            if(interval != emptyPair)
                ans.push_back(interval.second - interval.first + 1);
        }

        return ans;
    }
};