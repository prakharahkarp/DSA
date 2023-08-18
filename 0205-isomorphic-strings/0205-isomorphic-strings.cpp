class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1,m2;
        bool ans=true;
        for(int i=0;i<s.length();i++){
            if(m1.count(s[i])==0) m1[s[i]]=t[i];
            else if(m1[s[i]]!=t[i]) ans=false;
            if(m2.count(t[i])==0) m2[t[i]]=s[i];
            else if(m2[t[i]]!=s[i]) ans=false;
        }
        return ans;
    }
};