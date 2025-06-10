class Solution {
public:
    int maxDifference(string s) {
        //need to calculate diff of highestOddFreq and lowestEvenFreq
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++)
            freq[s[i]-'a']++;

        int highestOdd = INT_MIN;
        int lowestEven = INT_MAX;        
        for(int count : freq){
            if(count%2==0 && count!=0){
                lowestEven = min(lowestEven, count);
            } else {
                highestOdd = max(highestOdd, count);
            }
        }

        return highestOdd - lowestEven;
    }
};