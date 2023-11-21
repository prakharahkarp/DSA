class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while(num){
            rev = rev * 10 + num%10;
            num /= 10;
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {

        int mod = 1e9;
        mod += 7;
        unordered_map<int, int> sameDiffFreq;
        for(auto num : nums){
            int rev = reverse(num);
            sameDiffFreq[num - rev]++;
        }

        int nicePairsCount = 0;

        for(auto it : sameDiffFreq){
            int temp = it.second;
            int temp2 = (((long long)temp%mod) * ((temp - 1)%mod) /2)%mod;
            nicePairsCount = (nicePairsCount + temp2)%mod;
        }

        return nicePairsCount;
    }
};