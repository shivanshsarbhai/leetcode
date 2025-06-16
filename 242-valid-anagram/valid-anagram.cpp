class Solution {
public:
    bool brute(string s, string t){
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    bool isAnagram(string s, string t) {
        return brute(s, t);
    }
};