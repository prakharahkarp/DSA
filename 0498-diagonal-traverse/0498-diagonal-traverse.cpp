class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        vector<int> ans;
        int limitingVal = nums.size() - 1 + nums[0].size() - 1;
        
        for(int sum = 0; sum <= 2 * limitingVal; sum++){
            for(int i = sum, j = 0; i >= 0 && j <= sum; i--, j++){
                if(sum%2){
                    if(j < nums.size() && i < nums[j].size()){
                        // cout << nums[j][i] << " ";
                        ans.push_back(nums[j][i]);
                    }
                } else {
                    if(i < nums.size() && j < nums[i].size()){
                        // cout << nums[i][j] << " ";
                        ans.push_back(nums[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};