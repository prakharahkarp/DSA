class Solution {
public:
    void printPermutations(std::vector<int>& permutation, std::vector<std::vector<int>>& allPermutations, int swapPosFirst){
    if(swapPosFirst == permutation.size()){
        allPermutations.push_back(permutation);
        return ;
    }
    for(int i = swapPosFirst; i < permutation.size(); i++){
        std::swap(permutation[swapPosFirst], permutation[i]);
        printPermutations(permutation, allPermutations, swapPosFirst + 1);
        std::swap(permutation[swapPosFirst], permutation[i]);
    }
}
    
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<int> permutation = nums;
        std::vector<std::vector<int>> allPermutations;
        printPermutations(permutation, allPermutations, 0);
        return allPermutations;
    }
};