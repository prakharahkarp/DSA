class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> findDup;
        int i = 0;
        for(; i <= min(k, (int)nums.size() - 1); i++){
            findDup.insert(nums[i]);
        }
        if(findDup.size() < i) return true;
        int windowStart = 0;
        for( ; i < nums.size(); i++){
            findDup.erase(nums[windowStart]);
            findDup.insert(nums[i]);
            if(findDup.size() < i - windowStart) return true;
            windowStart++;
        }
        return false;
    }
};