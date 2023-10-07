class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int countInc = 0, countDec = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]) countInc++;
            else if(nums[i] < nums[i - 1]) countDec++;
        }
        if(countInc == 0 || countDec == 0) return true;
        return false;
    }
};