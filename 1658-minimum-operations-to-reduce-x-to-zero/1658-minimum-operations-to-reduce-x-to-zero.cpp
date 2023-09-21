class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long totalSum = 0;
        for(auto it : nums){
            totalSum += it;
        }
        if(totalSum == x) return nums.size();
        long long requiredSum = totalSum - x;
        int remMaxLen = 0;
        int windowStart = 0, windowEnd = 0, windowSum = 0;
        while(windowStart < nums.size()){
            if( windowSum == requiredSum){
                remMaxLen = max(remMaxLen, windowEnd - windowStart);
                windowSum -= nums[windowStart++];
            }
            else if(windowSum > requiredSum){
                windowSum -= nums[windowStart++];
            }
            else if(windowEnd < nums.size()){
                windowSum += nums[windowEnd++];
            }
            else break;
        }
        if(remMaxLen == 0) return -1;
        return nums.size() - remMaxLen;
    } 
};