class Solution {
public:
    int getMinNumber(string s){
        char mappedChar = 'a';
        bool isFirstChar1 = s[0] == '1' ? true : false;
        char newChar = 'a';
        if(!isFirstChar1){
            mappedChar = s[0];
            newChar = '1';
        } else {
            newChar = '0';
            int i=0;
            while(i<s.length() && (s[i]=='0' || s[i]=='1')){
                i++;
            }

            if(i<s.length())
                mappedChar = s[i];
        }

        for(int i=0;i<s.length();i++){
            if(s[i]==mappedChar)
                s[i] = newChar;
        }

        return stoi(s);
    }

    int getMaxNumber(string s){
        char mappedChar = 'a';
        for(int i=0;i<s.length();i++){
            if(mappedChar == 'a' && s[i]!='9')
                mappedChar = s[i];
            
            if(mappedChar == s[i])
                s[i] = '9';
        }

        return stoi(s);
    }

    int maxDiff(int num) {
       string s = to_string(num);
       int a = getMaxNumber(s);
       int b = getMinNumber(s);
        return a-b; 
    }
};