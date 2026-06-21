class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                if(isalpha(s[i]))
                    str+=tolower(s[i]);
                else
                    str+=s[i];
            }
        }

        for(int i=0;i<str.length()/2;i++){
            if(str[i] != str[str.length()-1-i])
                return false;
        }

        return true;


    }
};