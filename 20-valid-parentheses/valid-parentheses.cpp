class Solution {
public:
    unordered_map<char, char> mp = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    bool isValid(string str) {
        int n = str.length();
        stack<char>s;
        for(int i=0;i<n;i++){
            if(mp.find(str[i]) == mp.end())
                s.push(str[i]);
            
            else{
                if(s.empty() || mp[str[i]]!=s.top())
                    return false;
                
                s.pop();
            }
        }

        return s.empty();
    }
};