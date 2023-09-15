class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> temp;
        for(int i = 0; i < groupSizes.size(); i++){
            temp[groupSizes[i]].push_back(i);
            if(temp[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back(temp[groupSizes[i]]);
                temp[groupSizes[i]] = {};
            }
        }
        return ans;
    }
};