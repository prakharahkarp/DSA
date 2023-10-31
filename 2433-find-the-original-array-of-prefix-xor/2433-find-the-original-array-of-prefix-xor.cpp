class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        vector<int> originalArr = pref;
        
        for(int i = 1; i < originalArr.size(); i++){
            originalArr[i] = (pref[i]^pref[i - 1]); 
        }
        
        return originalArr;
    }
};