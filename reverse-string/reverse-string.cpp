class Solution {
public:
    void reverseStr(int ind, vector<char>& s){
        if(ind >= s.size()/2) return ;
        int temp = s[s.size() - ind - 1];
        s[s.size() - ind - 1] = s[ind];
        s[ind] = temp;
        reverseStr(ind + 1, s);
    }
    
    void reverseString(vector<char>& s) {
        reverseStr(0, s);
    }
};