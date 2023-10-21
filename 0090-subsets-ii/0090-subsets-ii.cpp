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
        temp.pop_back();

        // not pick
        // when not picking a ind, we ignore all indices with (value == nums[ind]). This helps in ensuring that we do not generate            a duplicate subset
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