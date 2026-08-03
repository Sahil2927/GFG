class Solution {
  public:
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        vector<vector<P>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({wt, v});
            adj[v].push_back({wt, u}); // Because the graph is undirected
        }
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int node=p.second;
            
            if(inMST[node]==true) continue;
            
            inMST[node]=true;
            sum+=wt;
             // Traverse all adjacent neighbors of the current node
            for (auto& nbr_pair : adj[node]) {
                int nbr_wt = nbr_pair.first;
                int nbr = nbr_pair.second;

                if (!inMST[nbr]) {
                    pq.push({nbr_wt, nbr});
                }
            }
        }
        return sum;
    }
};