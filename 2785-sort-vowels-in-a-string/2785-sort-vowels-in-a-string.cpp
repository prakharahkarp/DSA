class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;

        for(auto ch : s){
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' ||ch == 'e' ||ch == 'i' || ch == 'o' || ch == 'u') vowels.push_back(ch);
        }

        sort(vowels.begin(), vowels.end());

        int ind = 0;

        for(auto& ch : s){
            if(ind == vowels.size()) break;
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' ||ch == 'e' ||ch == 'i' || ch == 'o' || ch == 'u') ch = vowels[ind++];
        }

        return s;
    }
};