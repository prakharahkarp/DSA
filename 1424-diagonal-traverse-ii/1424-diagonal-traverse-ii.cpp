class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<vector<int>> temp;
        
        for(int row = 0; row < nums.size(); row++){
            for(int col = 0; col < nums[row].size(); col++){
                temp.push_back({row + col, col, row});
            }
        }
        
        sort(temp.begin(), temp.end());
        
        for(auto it : temp){
            // cout << it[0] << " " << it[1] << " " << it[2] << "\n";
            ans.push_back(nums[it[2]][it[1]]);
        }
        
        return ans;
    }
};