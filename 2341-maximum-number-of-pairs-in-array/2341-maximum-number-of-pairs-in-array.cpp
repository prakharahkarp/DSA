class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int> ans(2,0);
        for(auto it:freq){
            ans[0]+=it.second/2;
            ans[1]+=it.second%2;
        }
        return ans;
    }
};