class Solution {
public:
    void generateSubsets(int ind, vector<int> temp, set<vector<int>> &uniqueSubsets, vector<int> &nums){
        if(ind == nums.size()){
            sort(temp.begin(), temp.end());
            uniqueSubsets.insert(temp);
            return ;
        }

        // pick
        temp.push_back(nums[ind]);
        generateSubsets(ind + 1, temp, uniqueSubsets, nums);

        // not pick
        temp.pop_back();
        generateSubsets(ind + 1, temp, uniqueSubsets, nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> uniqueSubsets;
        vector<int> temp;

        generateSubsets(0, temp, uniqueSubsets, nums);

        vector<vector<int>> subsets;
    
        for(auto it : uniqueSubsets){
            subsets.push_back(it);
        }
        
        return subsets;
    }
};