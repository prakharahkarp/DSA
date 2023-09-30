class Solution {
public:
    int flag = 0;
    int skipWhiteSpaces(int ind, string& s){
//         this recursive function helps us in skipping white spaces
        if(ind == s.size()) return ind;
        if(s[ind] == ' ')  return skipWhiteSpaces(ind + 1, s);
        return ind;
    }
    
    int convertToNum(int ind, string& s,int ans, unordered_set<char>& digits){
//         helps us in converting digit string to a signed number
        if((ind == s.size())||(digits.find(s[ind]) == digits.end())) return ans;
        if((flag == 1) && (((-1 * ans == INT_MIN/10) && ((s[ind] - '0') >= 8)) || (-1 * ans < INT_MIN/10))) return INT_MIN;
        if((flag == 0) && (((ans == INT_MAX/10) && ((s[ind] - '0') >= 7)) || (ans > INT_MAX/10))) return INT_MAX;
        ans = ans * 10 + (s[ind] - '0');
        return convertToNum(ind + 1, s, ans, digits);
    }
    
    int myAtoi(string s) {
//         the set here helps us in checking if the current character is a digit or not
        unordered_set<char> digits({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
        int ind = skipWhiteSpaces(0, s);
//         checking for the sign of the number, if present
        if(s[ind] == '-'){
            flag = 1;
            ind++;
        }
        else if(s[ind] == '+') ind++;
//         checking if the character following the sign is a digit or not. If not, we return 0
        if(digits.find(s[ind]) == digits.end()) return 0;
        long long temp = convertToNum(ind, s, 0, digits);
        if(flag == 1 && temp > 0) temp = temp * -1;
        return temp;
    }
};