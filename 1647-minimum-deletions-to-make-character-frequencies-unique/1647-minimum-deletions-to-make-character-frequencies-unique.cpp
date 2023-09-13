class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        sort(freq.begin(),freq.end());
        
        int deletions = 0, currHigh  = freq[25], i;
        for(i = 25; i >= 0; i--){
            if(currHigh == 0 || freq[i]==0) break;
            if(freq[i] >= currHigh) {
                deletions += freq[i]-currHigh;
                currHigh--;
            }
            else currHigh = freq[i]-1;
        }
        while(i >= 0 && freq[i]){
            deletions += freq[i] - currHigh;
            i--;
        }
        return deletions;
    }
};