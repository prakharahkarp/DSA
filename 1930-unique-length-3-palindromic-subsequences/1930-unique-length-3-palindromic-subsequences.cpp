class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> occurrence(26, {-1, -1});
        
        for(char ch = 'a'; ch <= 'z'; ch++){
            for(int i = 0; i < s.length(); i++){
                if(s[i] == ch){
                    occurrence[ch - 'a'].first = i;
                    break;
                }
            }
            for(int i = s.length() - 1; i >= 0; i--){
                if(s[i] == ch){
                    occurrence[ch - 'a'].second = i;
                    break;
                }
            }
        }
        
        vector<vector<int>> frequencies;
        vector<int> temp(26, 0);
        for(int i = 0; i < s.length(); i++){
            temp[s[i] - 'a']++;
            frequencies.push_back(temp);
        }

        int totalPallindromicSubsequences = 0;
        for(char ch = 'a'; ch <= 'z'; ch++){
            int firstOccurrence = occurrence[ch - 'a'].first;
            int lastOccurrence = occurrence[ch - 'a'].second;
            if(firstOccurrence == -1 || lastOccurrence - firstOccurrence < 2) continue;
            int uniqueCharactersBetween = 0;
            for(int i = 0; i < 26; i++){
                int diff_freq = frequencies[lastOccurrence][i] - frequencies[firstOccurrence][i];
                if(i == ch - 'a') diff_freq--;
                if(diff_freq > 0) uniqueCharactersBetween++;
            }
            totalPallindromicSubsequences += uniqueCharactersBetween;
        }
       return totalPallindromicSubsequences;     
    }
};