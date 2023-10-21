class Solution {
public:
    void generateSubsetsWithSum(int ind, vector<int>& temp, vector<vector<int>> &uniqueSubsets, int size, int &target){
        if(target < 0) return ;
        if(ind > 9 ){
            if(target == 0 && temp.size() == size){
                uniqueSubsets.push_back(temp);
            }
            return ;
        }
        
//         pick
        temp.push_back(ind);
        target -= ind;
        generateSubsetsWithSum(ind + 1, temp, uniqueSubsets, size, target);
        
//         restore state
        temp.pop_back();
        target += ind;
        
//         not pick
        generateSubsetsWithSum(ind + 1, temp, uniqueSubsets, size, target);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> uniqueSubsets;
        
        generateSubsetsWithSum(1, temp, uniqueSubsets, k, n);
        
        return uniqueSubsets;
    }
};