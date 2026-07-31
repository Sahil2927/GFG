class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Code here
         // Step 1: Build the adjacency list
        // Vertices can be 0-indexed or 1-indexed; using V + 1 covers both safely
        vector<vector<pair<int, int>>> adj(V + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Step 2: Run Dijkstra backwards starting from 'dest'
        // This calculates the absolute shortest distance from any node to 'dest'
        vector<long long> dist(V + 1, 1e18); // Use 1e18 to prevent any integer overflow
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[dest] = 0;
        pq.push({0, dest});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // Step 3: Check if a valid path exists
        if (dist[src] == 1e18) {
            return {-1};
        }

        // Step 4: Reconstruct the path forward from 'src' to 'dest'
        // Greedily pick the smallest neighbor index that sits on a shortest path
        vector<int> path;
        int current = src;
        path.push_back(current);

        while (current != dest) {
            int next_node = -1;

            for (const auto& neighbor : adj[current]) {
                int v = neighbor.first;
                int w = neighbor.second;

                // Condition: Is this neighbor part of an optimal path to dest?
                if (dist[current] == dist[v] + w) {
                    // Always prefer the smaller vertex number for lexicographical order
                    if (next_node == -1 || v < next_node) {
                        next_node = v;
                    }
                }
            }
            
            current = next_node;
            path.push_back(current);
        }

        return path;
        
    }
};