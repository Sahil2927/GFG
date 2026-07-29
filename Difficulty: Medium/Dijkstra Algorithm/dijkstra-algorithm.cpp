class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Undirected graph
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(V,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d>result[node]) continue;
            for(const auto &nbr:adj[node]){
                int v=nbr.first;
                int weight=nbr.second;
                
                if(result[node]+weight<result[v]){
                    result[v]=result[node]+weight;
                    pq.push({result[v],v});
                }
            }
        }
        return result;
    }
};