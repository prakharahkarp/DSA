class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> vowFreq;
        string temp = "AEIOUaeiou";
        for(auto ch : s){
            if(temp.find(ch) != string::npos) vowFreq[ch]++;
        }
        int j;
        for(j = 0; j < temp.length(); j++){
            if(vowFreq.count(temp[j])) break;
        }
        for(int i = 0; i < s.length() && j < temp.length(); i++){
            if(temp.find(s[i]) != string::npos){
                s[i] = temp[j];
                vowFreq[temp[j]]--;
            }
            for(;j < temp.length(); j++){
            if(vowFreq.count(temp[j]) && vowFreq[temp[j]]) break;
            }
        }
        return s;
    }
};