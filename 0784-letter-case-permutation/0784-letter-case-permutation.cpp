class Solution {
public:
    void generatePermutations(int ind, string& s, vector<string>& res){
        if(ind >=  s.length()){
            res.push_back(s);
            return ;
        }
        char prevChar = s[ind];
        if(!isdigit(prevChar)){
            if(isupper(prevChar)){
                s[ind] = tolower(s[ind]); 
                generatePermutations(ind + 1, s, res);
                s[ind] = prevChar;
                generatePermutations(ind + 1, s, res);
            } else {
                s[ind] = toupper(s[ind]);
                generatePermutations(ind + 1, s, res);
                s[ind] = prevChar;
                generatePermutations(ind + 1, s, res);
            }
        }
        else generatePermutations(ind + 1, s, res);
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        generatePermutations(0, s, res);
        return res;
    }
};