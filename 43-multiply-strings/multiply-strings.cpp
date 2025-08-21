class Solution {
public:
    string multiply(string nums1, string nums2) {
        int n = nums1.length();
        reverse(nums1.begin(), nums1.end());
        reverse(nums2.begin(), nums2.end());
        vector<int>ans(400,0);
        for(int i=0;i<nums1.length();i++){
            int carry = 0;
            for(int j=0;j<nums2.length();j++){
                int index = i+j; //important
                int d1 = nums1[i]-'0';
                int d2 = nums2[j]-'0';
                int mulp = (ans[index] + d1*d2 + carry);
                ans[index] = mulp%10;
                carry = mulp/10;        
            }

            if(carry > 0)
                ans[i+nums2.length()] += carry; 
        }

        int i = ans.size() - 1;
        while (i > 0 && ans[i] == 0) 
            i--;

        string finalAns = "";
        while (i >= 0)
            finalAns+= (ans[i--] + '0');

        return finalAns;
    }
};