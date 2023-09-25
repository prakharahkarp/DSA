class Solution {
public:
    char findTheDifference(string s, string t) {
        int totalXOR = 0;
        for(int i = 0; i < s.size(); i++){
            totalXOR = (s[i]-'a')^totalXOR;
        }
        for(int i = 0; i < t.size(); i++){
            totalXOR = (t[i]-'a')^totalXOR;
        }
        return char(97+totalXOR);
    }
};