class Solution {
public:
    string reverseWords(string s) {
        string ans = "", word = "";
        
        for(int start = 0; start < s.length(); start++){
            if(s[start] != ' '){
                word += s[start];
            } else{
                if(ans.length() > 0 && word.length() > 0) ans = word + " " + ans;
                else ans = word + ans;
                word = "";
            }
        }
        if(ans.length() > 0 && word.length() > 0) ans = word + " " + ans;
        else ans = word + ans;

        return ans;
    }
};