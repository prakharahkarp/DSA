class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        double res = 1;
        if(n == INT_MIN){
            res = x;
            n++;
        }
        int flag = 0;
        if(n < 0){
            flag = 1;
            n = 0 - n;
        }
        
        while(n > 0){
            if(n % 2){
                res *= x;
                n--;
            }
            x *= x;
            n /= 2;
        }
        if(flag) return 1/res;
        return res;
    }
};

