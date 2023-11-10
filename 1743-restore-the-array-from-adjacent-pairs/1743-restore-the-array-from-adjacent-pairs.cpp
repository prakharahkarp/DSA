class Solution {
public:
    void BFS(int src, unordered_map<int, vector<int>>& mp, int n, unordered_map<int, int>& visited, vector<int>& ans){
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
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> visited;
        int src;
        
//         creating an adjacency matrix for our pairs
//         since our vertices can be negative, therefore we use a map
        for(int i = 0; i < adjacentPairs.size(); i++){
            mp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
            mp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
//             making sure that initially all of our vertices are unvisited
            visited[adjacentPairs[i][1]] = 0;
            visited[adjacentPairs[i][0]] = 0;
        }
//         finding the source vertex i.e. the first element of the array
//         only the end elements will be linked to only one element, all other elements will be linked to multiple elements
//         so we find one of the two ending elements and begin our traversal from there
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