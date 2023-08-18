class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') {
                st.push(s[i]);
                if(st.size()>1){
                    ans=ans+s[i];
                }
            }
            else {
                if(st.size()>1){
                    ans=ans+s[i];
                }
                st.pop();
            }
        }
        return ans;
    }
};