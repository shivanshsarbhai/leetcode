class Solution {
public:
    vector<int> getFreqArray(string s){
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++)
            freq[s[i]-'a']++;

        return freq;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<vector<int>, vector<string>>mp;

        for(string s : strs){
            vector<int>freqArray = getFreqArray(s);
            mp[freqArray].push_back(s);
        }

        for(const auto&[key, value]: mp)
            ans.push_back(value);

        return ans;
    }
};