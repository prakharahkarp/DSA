class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_ind = 0;
        for(int i = 0; i < t.length(); i++){
            if(s[s_ind] == t[i]) s_ind++; 
            if(s_ind == s.length()) break;
        }
        return s_ind >= s.length();
    }
};