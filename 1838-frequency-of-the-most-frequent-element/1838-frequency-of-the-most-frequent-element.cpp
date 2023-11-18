class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long windowStart = 0, freq = 0, maxFreq = 0, curr = 0, cost = 0;

        while(curr < nums.size()){
            if(cost + freq * (nums[curr] - nums[max(curr - 1, (long long)0)]) <= k){
                cost += freq * (nums[curr] - nums[max(curr - 1, (long long)0)]);
                freq++;
                curr++;
                maxFreq = max(maxFreq, freq);
            } else if(windowStart < curr){
                cost -= (nums[curr - 1] - nums[windowStart]);
                windowStart++;
                freq--;
            } else {
                curr++;
                windowStart++;
            }
        }
        return maxFreq;
    }
};
