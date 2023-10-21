class Solution {
public:
    void generateSubsetsWithSum(int ind, vector<int>& temp, vector<vector<int>> &uniqueSubsets, vector<int> &candidates,int &target){
        if(target < 0) return ;
        if(ind == candidates.size()){
            if(target == 0){
                uniqueSubsets.push_back(temp);
            }
            return ;
        }
        
//         pick
        temp.push_back(candidates[ind]);
        target -= candidates[ind];
        generateSubsetsWithSum(ind + 1, temp, uniqueSubsets, candidates, target);
        
//         restore state
        temp.pop_back();
        target += candidates[ind];
        
//         not pick
        ind = upper_bound(candidates.begin(), candidates.end(), candidates[ind]) - candidates.begin();
        generateSubsetsWithSum(ind, temp, uniqueSubsets, candidates, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        vector<vector<int>> uniqueSubsets;
        
        generateSubsetsWithSum(0, temp, uniqueSubsets, candidates, target);
        
        return uniqueSubsets;
    }
};