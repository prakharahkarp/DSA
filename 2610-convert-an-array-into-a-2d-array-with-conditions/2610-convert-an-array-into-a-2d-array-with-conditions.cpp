class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
//         fiding the max frequency element to determine the number of rows
        unordered_map<int, int> mp;
        
        for(auto it : nums){
            mp[it]++;
        }
        
        int rows = 0;
        for(auto it : mp){
            rows = max(rows, it.second);
        }
        
//         creating array
        vector<vector<int>> arr;
        while(rows--){
            vector<int> row;
            for(auto &it : mp){
                if(it.second > 0){
                    row.push_back(it.first);
                    it.second--;
                }
            }
            arr.push_back(row);
        }
        
        
        return arr;
    }
};