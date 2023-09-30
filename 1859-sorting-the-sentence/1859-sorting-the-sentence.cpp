class Solution {
public:
    bool isDigit(char ch){
        return (ch >= '0' && ch <= '9');
    }
    
    bool isChar(char ch){
        return (ch != ' ' && !isDigit(ch));
    }
    
    string sortSentence(string s) {
        vector<string> temp(9, "");
        int totalWords = 0;
        string word = "", ans = "";
        for(int i = 0; i < s.length(); i++){
            if(isDigit(s[i])){
                temp[s[i] - '0' - 1] = word;
                totalWords = max(totalWords, s[i] - '0');
                word = "";
            }
            if(isChar(s[i])) word += s[i];
        }
        for(int i = 0; i < totalWords - 1; i++){
            ans += temp[i];
            ans += " ";
        }
        return ans + temp[totalWords - 1];
    }
};