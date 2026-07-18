// class Solution {
//   public:
//     bool cycleDetection(vector<vector<int>>& adj,int u, vector<bool>&visited, vector<bool>&inRecursion){
//         visited[u]=true;
//         inRecursion[u]=true;
        
//         for(int v:adj[u]){
//             if(visited[v]==false && cycleDetection(adj,v,visited,inRecursion)){
//                 return true;
//             }
//             else if(inRecursion[v]==true){
//                 return true;
//             }
//         }
//         inRecursion[u]=false;
//         return false;
//     }
//     bool isCyclic(int V, vector<vector<int>> &edges) {
//         // code here
//         vector<vector<int>>adj(V);
        
//         for(auto& edge:edges){
//             int u=edge[0];
//             int v=edge[1];
            
//             adj[u].push_back(v);
//         }
        
//         vector<bool>visited(V,false);
//         vector<bool>inRecursion(V,false);
        
//         for(int i=0;i<V;i++){
//             if(!visited[i] && cycleDetection(adj,i,visited,inRecursion)){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            
            adj[u].push_back(v);
        }
        int count=0;
        queue<int>q;
        vector<int>indegree(V,0);
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                indegree[v]++;
            }
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                indegree[v]--;
                
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count==V) return false;
        return true;
    }
};