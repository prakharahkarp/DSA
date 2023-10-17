class Solution {
public:
    void getAllCombinations(int ind, vector<int>& candidates, int target, int &sum, vector<int>& temp, vector<vector<int>>& res){
        if(sum > target) return ;
        if(ind == candidates.size()){
            if(sum == target){
                res.push_back(temp);
            }
            return ;
        }
        
        temp.push_back(candidates[ind]);
        sum += candidates[ind];
        getAllCombinations(ind, candidates, target, sum, temp, res);
        
        temp.pop_back();
        sum -= candidates[ind];
        getAllCombinations(ind + 1, candidates, target, sum, temp, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        getAllCombinations(0, candidates, target, sum, temp, res);
        
        return res;
    }
};