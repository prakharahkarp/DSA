class Solution {
public:
     int findNthTerm(int n, vector<int>& cache){
        if(cache[n] != -1) return cache[n];
        int val = findNthTerm(n - 2, cache) + findNthTerm(n - 1, cache);
        cache[n] = val;
        return cache[n];
    }
    
    int fib(int n) {
        if(n < 2) return n;
        vector<int> cache(31, -1);
        cache[0] = 0;
        cache[1] = 1;
        return findNthTerm(n, cache);
    }
};