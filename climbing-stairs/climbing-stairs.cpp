class Solution {
public:
    int findWays(int n, vector<int>& cache){
        if(cache[n] != -1) return cache[n];
        int val = findWays(n - 2, cache) + findWays(n - 1, cache);
        cache[n] = val;
        return cache[n];
    }
    
    int climbStairs(int n) {
//         this is just a variation of fibonacci number
//         since there are only two possible steps, we can either reach (n - 1)th ladder and then take 1 more steps or we can reach (n-2)th ladder and take 2 steps at once. So if we know, that in how many ways can we reach (n-1)th and (n-2)th ladder, then the number of ways to reach nth ladder is just the sum of these two values
        if(n == 1) return 1;
        vector<int> cache(46, -1);
        cache[0] = 1;
        cache[1] = 1;
        return findWays(n, cache);
    }
};