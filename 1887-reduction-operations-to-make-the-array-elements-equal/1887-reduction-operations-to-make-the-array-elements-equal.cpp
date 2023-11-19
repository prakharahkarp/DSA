class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int operationCnt = 0, count = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(nums[i] == nums[i + 1]) count++;
            else{
                operationCnt += count;
                count++;
            }
        }
        
        return operationCnt;
    }
};