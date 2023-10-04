class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long windowStart = 0, windowSize = 1, maxWindowSize = 1, curr = 1, cost = 0;
        while(curr < nums.size()){
            if(cost + (nums[curr] - nums[curr - 1]) * (curr - windowStart) <= k){
                cost += (nums[curr] - nums[curr - 1]) * (curr - windowStart);
                windowSize++;
                maxWindowSize = max(windowSize, maxWindowSize);
                curr++;
            } else if(windowStart < curr){
                cost -= (nums[curr - 1] - nums[windowStart++]);
                windowSize--;
            } else{
                curr++;
                windowSize++;
            }
        }
        return maxWindowSize;
    }
};
