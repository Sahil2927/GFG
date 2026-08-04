class Solution {
  public:
    // Step-1: Fill stack with DFS completion order
    void dfsFill(int u, const vector<vector<int>>& adj, vector<bool> &visited, stack<int>& st) {
        visited[u] = true;
        for(const int &v : adj[u]) {
            if(!visited[v]) {
                dfsFill(v, adj, visited, st);
            }
        }
        st.push(u);
    }
	
    // Step-3: Traverse the reversed graph
    void dfsTraverse(int u, const vector<vector<int>>& adjReversed, vector<bool> &visited) {
        visited[u] = true;
        for(const int &v : adjReversed[u]) {
            if(!visited[v]) {
                dfsTraverse(v, adjReversed, visited);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges) {
        // FIX: Build an actual Adjacency List from the given list of edges
        vector<vector<int>> adj(V);
        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        // Step-1: Store order of DFS in stack
        stack<int> st;
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfsFill(i, adj, visited, st);
            }
        }
        
        // Step-2: Make a reversed graph using our correct adjacency list
        vector<vector<int>> adjReversed(V);
        for(int u = 0; u < V; u++){
            for(const int &v : adj[u]){
                adjReversed[v].push_back(u);
            }
        }
        
        // Step-3: Call DFS based on stack order
        int count = 0;
        visited = vector<bool>(V, false);
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                dfsTraverse(node, adjReversed, visited);
                count++;
            }
        }
        
        return count;
    }
};
