class Solution {
public:
    string reverseWords(string s) {
        string ans = "", word = "";
        for(char ch : s){
            if(ch == ' '){
                word += ch;
                ans += word;
                word = "";
            } else{
                word = ch + word;
            }
        }
        ans += word;
        return ans;
    }
};