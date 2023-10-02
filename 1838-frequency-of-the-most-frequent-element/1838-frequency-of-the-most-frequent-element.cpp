class Solution {
public:
    bool isGood(int x, vector<int>& nums, int k){
        long long windowStart = 0, windowEnd = x, windowSum = 0, minWindowSum = 0, maxEle = nums[windowEnd - 1];
        for(int i = 0; i < windowEnd; i++){
            windowSum += maxEle - nums[i];
        }
        minWindowSum = windowSum;
        for(int i = windowEnd; i < nums.size(); i++){
            windowSum += (nums[i] - maxEle) * (x - 1) - (maxEle - nums[windowStart++]);
            maxEle = nums[i];
            minWindowSum = min(windowSum, minWindowSum);
        }
        return minWindowSum <= k;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() + 1;
        while(r > l + 1){
            int mid = l + (r - l)/2;
            if(isGood(mid, nums, k)) l = mid;
            else r = mid;
        }
        return l;
    }
};