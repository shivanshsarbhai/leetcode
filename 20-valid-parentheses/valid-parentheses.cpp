class Solution {
public:
    bool isValid(string str) {
        map<char, char>mp;
        mp.insert({')', '('});
        mp.insert({']', '['});
        mp.insert({'}', '{'});

        stack<char>s;
        for(int i=0;i<str.length();i++){
            char ele = str[i];
            if(!s.empty() && mp.find(ele) != mp.end() && s.top() == mp[ele])
                s.pop();
            else
                s.push(ele);
        }

        return s.empty();
    }
};