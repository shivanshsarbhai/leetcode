class Solution {
public:
    bool brute(string s, string t){
        //TC : O(NlogN + MlogM)
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    bool better(string s, string t){
        if(s.length() != t.length())
            return false;

        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                return false;
        }

        return true;
    }

    bool isAnagram(string s, string t) {
        // return brute(s, t);
        return better(s,t);
    }
};