class Solution {
public:
    void findAllUniqueSubsets(vector<int>& nums, int currInd, vector<vector<int>>& ans, vector<int>& temp){
        
        if(currInd >= nums.size()){
            ans.push_back(temp);
            return ;
        }
        
//         include the current Index value 
        temp.push_back(nums[currInd]);
        findAllUniqueSubsets(nums, currInd + 1, ans, temp);
        
//         restore current state
        temp.pop_back();
        
//         don't include any occurrence of current Index value
        currInd = upper_bound(nums.begin(), nums.end(), nums[currInd]) - nums.begin();
        findAllUniqueSubsets(nums, currInd, ans, temp);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        findAllUniqueSubsets(nums, 0, ans, temp);
        
        return ans;
    }
};