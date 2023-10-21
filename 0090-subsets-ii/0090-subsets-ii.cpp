class Solution {
public:
    void generateSubsets(int ind, vector<int> &temp, vector<vector<int>> &uniqueSubsets, vector<int> &nums){
        if(ind == nums.size()){
            uniqueSubsets.push_back(temp);
            return ;
        }

        // pick
        temp.push_back(nums[ind]);
        generateSubsets(ind + 1, temp, uniqueSubsets, nums);

        // not pick
        temp.pop_back();
        ind = upper_bound(nums.begin(), nums.end(), nums[ind]) - nums.begin();
        generateSubsets(ind, temp, uniqueSubsets, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> uniqueSubsets;
        vector<int> temp;
        
        sort(nums.begin(), nums.end());

        generateSubsets(0, temp, uniqueSubsets, nums);
        
        return uniqueSubsets;
    }
};