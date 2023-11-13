class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target) return 0;
        
        unordered_map<int, vector<int>> adj;
        unordered_set<int> visitedStops, visitedRoutes;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                adj[routes[i][j]].push_back(i);
                if(routes[i][j] == source){
                    q.push({1,i});
                    visitedRoutes.insert(i);
                    visitedStops.insert(routes[i][j]);
                }
            }
        }
        
        while(!q.empty()){
            int curr_route = q.front().second;
            int busChanges = q.front().first;
            q.pop();
            for(auto stop : routes[curr_route]){
                if(stop == target) return busChanges;
                if(visitedStops.find(stop) == visitedStops.end()){
                    visitedStops.insert(stop);
                    for(auto otherRoutes : adj[stop]){
                        if(visitedRoutes.find(otherRoutes) == visitedRoutes.end()){
                            visitedRoutes.insert(otherRoutes);
                            q.push({busChanges + 1, otherRoutes});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};