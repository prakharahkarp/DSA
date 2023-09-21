class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(nums[0] > x && nums[nums.size()-1] > x) return -1;
        
        long long prefix = 0, suffix = 0;
        int leftLimit = -1, rightLimit = -1, ans = nums.size(); 
        
        for(int i = 0; i < nums.size(); i++){
            if(prefix + nums[i] <= x){
                prefix += nums[i];
                leftLimit = i;
            }
            else break;
        }
        if(leftLimit == nums.size() - 1){
            if(prefix == x) return nums.size();
            return -1;
        }
        
        for(int i = nums.size()-1; i >= 0; i--){
            if(suffix + nums[i] <= x){
                suffix += nums[i];
                rightLimit = i;
            }
            else break;
        }
        
        if(prefix == x) ans = min(ans, leftLimit + 1);
        if(suffix == x) ans = min(ans, (int)nums.size() - rightLimit);
        if(rightLimit == -1){
            if(prefix == x) return ans;
            return -1;
        }
        if(leftLimit == -1){
            if(suffix == x) return ans;
            return -1;
        }
        int windowStart = rightLimit, windowEnd = 0, currWindowLen = nums.size() - rightLimit;
        long long windowSum = suffix + nums[windowEnd++];
        currWindowLen++;
        while(true){
            if(windowStart == nums.size() && windowSum == x){
                ans = min(currWindowLen, ans);
                break;
            }
            if(windowSum == x){
                ans = min(currWindowLen, ans);
                windowSum -= nums[windowStart++];
                currWindowLen--;  
            }
            else if(windowSum > x){
                windowSum -= nums[windowStart++];
                currWindowLen--;
            }
            else{
                if(windowEnd <= leftLimit){
                    windowSum += nums[windowEnd++];
                    currWindowLen++;
                }
                else break;
            }
        }
        if(ans > -1) return ans;
        return -1;
    }
};

// My first intuition was to use binary search to find window size and for every mid, find the prefix sum, suffix sum and the circular sum using sliding window technique and if any of these equal to x such that the number of elements included are equal to the window size, I return true otherwise I return false. But this approach is wrong as it does not give the optimal answers. Although I know, that this solution can be solved using Binary Search but I could not solve it.
