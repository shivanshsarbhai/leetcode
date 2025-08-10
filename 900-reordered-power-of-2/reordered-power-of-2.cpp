class Solution {
public:
    vector<int> getFreq(int num){
        vector<int>ans;
        while(num>0){
            ans.push_back(num%10);
            num = num/10;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        set<vector<int>>s;

        for(int i=0;i<32;i++){
            long powerOfTwo = pow(2, i);
            s.insert(getFreq(powerOfTwo));
        }

        vector<int>freq = getFreq(n);
        return s.find(freq)!=s.end();
    }
};