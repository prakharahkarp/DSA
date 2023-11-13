class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;

        string temp = "AEIOUaeiou";
        for(auto ch : s){
            if(temp.find(ch) != string::npos) vowels.push_back(ch);
        }

        sort(vowels.begin(), vowels.end());

        int ind = 0;

        for(auto& ch : s){
            if(ind == vowels.size()) break;
            if(temp.find(ch) != string::npos) ch = vowels[ind++];
        }

        return s;
    }
};