class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<pair<int, int>> occurrence(26, {-1, -1});
//         storing the first and last occurrence for each character
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
        
//         precomputing frequency of each english alphabet character present in the string uptil that index
        vector<vector<int>> frequencies;
        vector<int> temp(26, 0);
        for(int i = 0; i < s.length(); i++){
            temp[s[i] - 'a']++;
            frequencies.push_back(temp);
        }
        
//         traversing from a-z, finding the number of unique characters present between the first and last occurrence of that character in the string
//         i could have used a set so i dont have to precompute anything, i could have just traversed between the first and last occurrence of each character, storing every character in the set and at the end the size of the set would have been the number of unique characters in between
//         but i thought that this approach would be O(N^2) as i forgot that i would be traversing over the entire string in the outer loop also but in reality, the outer loop just runs from a-z, and hence the TC would have been O(26*N)
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
        } // TC of this loop O(26 * 26)
        
       return totalPallindromicSubsequences;     
    }
};

// SC -> O(26 * N)
// TC -> O(N)