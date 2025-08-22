class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)
            return 1;
        
        if(n==0)
            return 1;
        int sign = n>0 ? 1: -1;
        double X = x;
        long N = n;
        N = abs(N);


        double ans = 1;
        if(n%2==0)
            ans = myPow(X*X, N/2);
        else
            ans = x*myPow(X*X, N/2);
        
        return sign==1 ? ans : (double)1/ans;
    }
};