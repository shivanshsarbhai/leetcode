class Solution {
public:
    unordered_map<int, vector<char>> mp{
        {2, {'a','b','c'}},
        {3, {'d','e','f'}},
        {4, {'g','h','i'}},
        {5, {'j','k','l'}},
        {6, {'m','n','o'}},
        {7, {'p','q','r','s'}},
        {8, {'t','u','v'}},
        {9, {'w','x','y','z'}}
    };


    void backtrack(string digits, int index, string &s, vector<string>&ans){
        if(s.length() == digits.length()){
            ans.push_back(s);
            return;
        }

        for(char ch : mp[digits[index]-'0']){
            string temp = s+ch;
            backtrack(digits, index+1, temp, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string currString = "";
        if(digits.length() > 0)
            backtrack(digits, 0, currString, ans);
        return ans;
    }
};