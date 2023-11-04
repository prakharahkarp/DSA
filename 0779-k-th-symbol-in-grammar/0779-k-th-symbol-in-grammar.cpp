class Solution {
public:
    int findVal(int n, int k){
        if(n == 1 && k == 1) {
            return 0;
        }
        int prevVal = findVal(n - 1, ceil(k/2.0));
        if(prevVal == 0){
            if(k%2) return 0;
            else return 1;
        } else {
            if(k%2) return 1;
            return 0;
        }
    }
    
    int kthGrammar(int n, int k) {
        return findVal(n, k);
    }
};