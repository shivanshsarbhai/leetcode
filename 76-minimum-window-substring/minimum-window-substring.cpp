class Solution {
public:
    bool isTContainedInS(unordered_map<char,int>&sMap, unordered_map<char,int>&tMap){
        for(auto ele : tMap){
            if(ele.second > sMap[ele.first])
                return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";
        
        unordered_map<char,int>tMap;
        for(int i=0;i<t.length();i++)
            tMap[t[i]]++;
        
        unordered_map<char,int>sMap;
        int left = 0;
        int right = 0;
        int minLength = INT_MAX;
        int leftStart = 0;
        int rightStart = 0;

        while(right < s.length()){
            sMap[s[right]]++;
            while(isTContainedInS(sMap,tMap)){
                if(right-left +1 < minLength){
                    leftStart = left;
                    rightStart = right;
                    minLength = right-left+1;
                }

                sMap[s[left]]--;
                left++;
            } 

            right++;
        }

        return (minLength == INT_MAX) ? "" : s.substr(leftStart, minLength);

    }
};