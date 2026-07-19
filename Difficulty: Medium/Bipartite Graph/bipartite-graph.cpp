class Solution {
  public:
    bool BFS(vector<vector<int>>&adj,int curr,vector<int>&color,int currColor){
        queue<int>q;
        q.push(curr);
        color[curr]=currColor;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                if(color[v]==color[u])return false;
                else if(color[v]==-1){
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!BFS(adj,i,color,1)) return false;
            }
        }
        return true;
    }
};