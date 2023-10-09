class Solution {
public:
    int maxOR;
    
    void countSubsetsWithGivenOr(int ind, vector<int>& nums, int& count, int& subsetOR){
        if(ind == nums.size()) return ;
        int prevOR = subsetOR;
        subsetOR = subsetOR | nums[ind];
        if(subsetOR == maxOR) count++;
        countSubsetsWithGivenOr(ind + 1, nums, count, subsetOR);
        subsetOR = prevOR;
        countSubsetsWithGivenOr(ind + 1, nums, count, subsetOR);
        subsetOR = prevOR;
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        int subsetOR = 0, count = 0;
        for(int i = 0; i < nums.size(); i++) maxOR = maxOR | nums[i];
        countSubsetsWithGivenOr(0, nums, count, subsetOR);
        return count;
    }
};