class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long windowStart = 0, freq = 1, maxFreq = 1, curr = 1, cost = 0;

        while(curr < nums.size()){
            if(cost + freq * (nums[curr] - nums[curr - 1]) <= k){
                cost += freq * (nums[curr] - nums[curr - 1]);
                freq++;
                curr++;
                maxFreq = max(maxFreq, freq);
            } else if(cost > 0){
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
