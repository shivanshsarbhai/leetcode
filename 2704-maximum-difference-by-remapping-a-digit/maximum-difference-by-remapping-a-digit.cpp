class Solution {
public:
    int mapFirstNonXDigitToX(string s, char x){
        char mappedNumber = 'a';
        for(int i=0;i<s.length();i++){
            if(mappedNumber == 'a' && s[i]!=x)
                mappedNumber = s[i];
            
            if(s[i]==mappedNumber)
                s[i]=x;
        }
        return stoi(s);
    }

    int minMaxDifference(int num) {
        string s = to_string(num);
        long maximum = mapFirstNonXDigitToX(s, '9');
        long minimum = mapFirstNonXDigitToX(s, '0');
        return maximum - minimum; 
    }
};


/*

ans = maximum - minimum 
maximum = map first non 9 digit to 9
minimum = map first non 0 digit to 0

*/