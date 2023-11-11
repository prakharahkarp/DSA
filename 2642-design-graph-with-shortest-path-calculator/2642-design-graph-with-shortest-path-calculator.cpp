class Graph {
private:
    int V;
    vector<pair<int, int>> G[100];
public:
    Graph(int n, vector<vector<int>>& edges) {
        V = n;
        for(auto edge : edges){
            G[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        G[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int dijkstra(int V, vector<pair<int, int>> adj[], int S, int D)
    {
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        set<pair<int, int>> st;
        st.insert({0, S});
        while(!st.empty()){
            int curr_node = (*(st.begin())).second;
            int curr_dist = (*(st.begin())).first;

            st.erase({curr_dist, curr_node});

            for(auto it : adj[curr_node]){
                int new_dist = it.second + curr_dist;
                if(new_dist < dist[it.first]){
                    dist[it.first] = new_dist;
                    st.insert({new_dist, it.first});
                }
            }
        }
        return dist[D];
    }

    int shortestPath(int node1, int node2) {
        if(dijkstra(V, G, node1, node2) == (int)1e9) return -1;
        else return dijkstra(V, G, node1, node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */