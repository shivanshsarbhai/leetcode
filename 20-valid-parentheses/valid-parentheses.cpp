class Solution {
public:
    bool isValid(string str) {
        stack<char>s;
        map<char,char>mp;
        mp[']'] = '[';
        mp['}'] = '{';
        mp[')'] = '(';

        for(int i=0;i<str.length();i++){
            if(s.empty()){
                s.push(str[i]);
                continue;
            } 

            if(str[i] == ')' || str[i]=='}' || str[i]==']')
            {
                if(s.top()==mp[str[i]]){
                    s.pop();    
                    continue;
                }
            }

            s.push(str[i]);
        }

        return s.empty();
    }
};