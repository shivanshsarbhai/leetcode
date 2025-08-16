class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double powerOfTwo = log2(n);
        // cout<<"power of two : "<<powerOfTwo;
        if(powerOfTwo == (int) powerOfTwo){
            if((int)powerOfTwo%2==0)
                return true;
        }

        return false;
    }
};

/*
power of 4 = even power of 2
power of 2 


*/