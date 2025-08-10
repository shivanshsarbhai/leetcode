class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;

        long N = (long)n;

        return (N & (N-1)) == 0L;
    }
};