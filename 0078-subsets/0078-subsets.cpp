class Solution {
public:
    void generateSubsets(int ind, vector<int>& nums, vector<vector<int>>& res, vector<int>& temp){
        if(ind >= nums.size()){
            res.push_back(temp);
            return ;
        }
        
        temp.push_back(nums[ind]);
        generateSubsets(ind + 1, nums, res, temp);
        temp.pop_back();
        
        generateSubsets(ind + 1, nums, res, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        
        generateSubsets(0, nums, res, temp);
        
        return res;
    }
};