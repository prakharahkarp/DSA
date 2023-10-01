class Solution {
public:
    double findVal(double x, int n){
        if(n == 0) return 1;
        if(n % 2) return x * findVal(x * x, n / 2);
        return findVal(x * x, n / 2);
    }
    
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        double tempRes;
        if(n == INT_MIN){
            tempRes = findVal(x, INT_MAX) * x;
            tempRes = 1.0 / tempRes;
        }
        else if(n < 0){
            tempRes = findVal(x, abs(n));
            tempRes = 1/ tempRes;
        }
        else tempRes = findVal(x, n);
        
        return tempRes;
    }
};

// 2 4 16 256 
// 1 2 4   8