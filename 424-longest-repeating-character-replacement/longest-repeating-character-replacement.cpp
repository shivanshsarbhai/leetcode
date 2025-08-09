class Solution {
public:
    int getMaxFreq(map<char,int>&mp){
        int ans = -1;
        for(auto entry : mp){
            ans = max(ans, entry.second);
        }

        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        map<char,int>mp;
        int left = 0;
        int right = 0;
        while(right<s.length()){
            mp[s[right]]++;
            int maxFreqInWindow = getMaxFreq(mp);
            int windowLength = right-left+1;

            while(left<s.length() && windowLength - maxFreqInWindow > k){
                mp[s[left]]--;
                left++;
                windowLength = right-left+1;
                maxFreqInWindow = getMaxFreq(mp);
            }

            ans = max(ans, right-left+1);
            right++;
        }


        return ans;
    }
};