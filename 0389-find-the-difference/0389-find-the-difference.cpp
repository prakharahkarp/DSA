class Solution {
public:
    char findTheDifference(string s, string t) {
        int totalXOR = 0;
        for(int i = 0; i < s.size(); i++){
            totalXOR = (s[i]-'a')^totalXOR;
            totalXOR = (t[i]-'a')^totalXOR;
        }
        totalXOR = (t[t.size()-1]-'a')^totalXOR;
        return char(97+totalXOR);
    }
};