class Solution {
public:
    void reverse(vector<int>& temp){
        int i = 0, j = temp.size()-1;
        while(j > i){
            swap(temp[i], temp[j]);
            i++;
            j--;
        }
    }
    
    int minOperations(vector<int>& nums, int x) {
        if(nums[0] > x && nums[nums.size()-1] > x) return -1;
        
        vector<int> temp;
        long long prefix = 0, suffix = 0;
        int leftLimit = -1, rightLimit = -1, ans = nums.size(); 
        for(int i = nums.size()-1; i >= 0; i--){
            if(suffix + nums[i] <= x){
                suffix += nums[i];
                rightLimit = i;
                temp.push_back(nums[i]);
            }
            else break;
        }
        if(rightLimit == 0 && suffix == x) return ans;
        else if(rightLimit == 0) return -1;
        reverse(temp);
        for(int i = 0; i < nums.size(); i++){
            if(prefix + nums[i] <= x){
                prefix += nums[i];
                leftLimit = i;
                temp.push_back(nums[i]);
            }
            else break;
        }

        int windowStart = 0, windowEnd = 1;
        long long windowSum = temp[0];
        while(windowStart < temp.size()){
            if(windowSum == x){
                ans = min(windowEnd - windowStart, ans);
                windowSum -= temp[windowStart++];
            }
            else if(windowSum > x){
                windowSum -= temp[windowStart++];
            }
            else{
                if(windowEnd < temp.size()) windowSum += temp[windowEnd++];
                else break;
            }
        }
        if(ans > -1) return ans;
        return -1;
    }
};