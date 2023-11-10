class Solution {
public:
    void BFS(int src, map<int, vector<int>>& mp, int n, unordered_map<int, int>& visited, vector<int>& ans){
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it : mp[curr]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        map<int, vector<int>> mp;
        unordered_map<int, int> visited;
        int src;
//         creating an adjacency matrix for our pairs
        for(int i = 0; i < adjacentPairs.size(); i++){
            mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
            mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            visited[adjacentPairs[i][1]] = 0;
            visited[adjacentPairs[i][0]] = 0;
        }
//         finding the source vertex i.e. the first element of the array
        for(auto it : mp){
            if(it.second.size() == 1){
                src = it.first;
                break;
            }
        }
        vector<int> ans;
        BFS(src, mp, n + 2, visited, ans);
        return ans;
    }
};