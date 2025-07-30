class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            
            if(mp.find(temp) != mp.end()){
                mp[temp].push_back(s);
            } else {
                mp[temp] = {s};
            }
        }

        vector<vector<string>>ans;
        for(auto ele : mp){
            ans.push_back(ele.second);
        }

        return ans;
    }
};