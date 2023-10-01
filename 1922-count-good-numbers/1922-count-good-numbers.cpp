class Solution {
public:
    const int MOD = 1000000007;

long long countGoodStrings(long long x, long long n){
    if(n == 0){
        return 1;
    }
    if(n % 2){
        return (x % MOD * countGoodStrings(x, n-1) % MOD) % MOD;
    }
    return (countGoodStrings(((x%MOD) * (x%MOD))%MOD, n / 2))%MOD;
}

int countGoodNumbers(long long n) {
    if (n == 0) {
        return 0;
    }
    long long ans = 1;
    if(n % 2){
        ans = 5;
        n--;
    }
    ans = (ans % MOD * countGoodStrings(20, n/2) % MOD) % MOD;
    return ans;
}


};

// 520 20 
//     6