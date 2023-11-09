class Solution {
public:
    #define MOD 1000000007
    int countHomogenous(string s) {
        int homogenousSubstringsCount = 0, count = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i - 1]) count++;
            else{
                homogenousSubstringsCount += (((long long)count%MOD) * ((count + 1)%MOD) / 2)%MOD;
                count = 1;
            }
        }
        homogenousSubstringsCount += (((long long)count%MOD) * ((count + 1)%MOD) / 2)%MOD;
        return homogenousSubstringsCount;
    }
};