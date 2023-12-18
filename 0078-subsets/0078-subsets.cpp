class Solution {
public:
    void findAllUniqueSubsets(vector<int>& nums, int currInd, vector<int>& temp, vector<vector<int>>& ans){
        
        if(currInd == nums.size()){
            ans.push_back(temp);
            return ;
        }
        
//         icnlude curr Index value
        temp.push_back(nums[currInd]);
        findAllUniqueSubsets(nums, currInd + 1, temp, ans);
//         restore original state
        temp.pop_back();
        
//         do not include curr Index value
        findAllUniqueSubsets(nums, currInd + 1, temp, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        findAllUniqueSubsets(nums, 0, temp, ans);
        return ans;
    }
};