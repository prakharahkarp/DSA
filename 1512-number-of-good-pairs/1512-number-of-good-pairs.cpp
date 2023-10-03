class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }
        int countPairs = 0;
        for(auto it : freq){
            countPairs += (it.second) * (it.second - 1)/2;
        }
        return countPairs;
    }
};