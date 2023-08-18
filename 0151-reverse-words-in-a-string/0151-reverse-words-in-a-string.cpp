class Solution {
public:
    string reverseWords(string s) {
        string tmp="",ans="",dup=" "+s;
        int count=0,i;
        for(i=0;i<dup.size()-1;i++){
            if(dup[i]!=' ') tmp+=dup[i];
            else if(dup[i]==' '&&dup[i+1]!=' '){
                if(count<=1) ans=tmp;
                else ans=tmp+" "+ans;
                tmp="";
                count++;
            }
        }
        if(dup[i]!=' ') tmp+=dup[i];
        if(count<=1) ans=tmp;
        else ans=tmp+" "+ans;
        return ans;
    }
};