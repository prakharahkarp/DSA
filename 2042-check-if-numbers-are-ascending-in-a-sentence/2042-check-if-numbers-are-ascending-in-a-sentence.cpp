class Solution {
public:
    bool isDigit(char ch){
        return ch >= '0' &&ch <= '9';
    }
    
    bool areNumbersAscending(string s) {
        int currNum = 0, prevNum = -1, i;
        for(i = 0; i < s.length() - 1; i++){
            if(isDigit(s[i]) && isDigit(s[i + 1])){
                currNum = currNum * 10 + s[i]-'0';
                currNum = currNum * 10 + s[i + 1] - '0';
                if(prevNum >= currNum) return false;
                prevNum = currNum;
                currNum = 0;
                i++;
            }
            else if(isDigit(s[i])){
                currNum = currNum * 10 + s[i]-'0';
                if(prevNum >= currNum) return false;
                prevNum = currNum;
                currNum = 0;
            }
        }
        cout<<prevNum<<"\n";
        if(i != s.length()){
            if(isDigit(s[s.length() - 1])) return (s[s.length() - 1] - '0') > prevNum;
        }
        return true;
    }
};