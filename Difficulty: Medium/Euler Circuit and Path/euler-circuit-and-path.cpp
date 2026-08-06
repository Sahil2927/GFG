class Solution {
  public:
    void DFS(vector<vector<int>>& adj, vector<bool>&visited, int u){
        visited[u]=true;
        for(auto &v:adj[u]){
            int nbr=v;
            if(visited[nbr]==false){
                DFS(adj,visited,nbr);
            }
        }
    }
    bool isConnected(int V,vector<vector<int>>&adj){
        int nonZeroDegreeVertex=-1;
        for(int i=0;i<V;i++){
            if(adj[i].size()!=0){
                nonZeroDegreeVertex=i;
                break;
            }
        }
        // Edge case: If the graph has no edges at all, it is considered Eulerian
        if (nonZeroDegreeVertex == -1) {
            return true; 
        }
        vector<bool>visited(V,false);
        
        //start DFS from nonZeroDegreeVertex
        DFS(adj,visited,nonZeroDegreeVertex);
        
        for(int i=0;i<V;i++){
            if(visited[i]==false && adj[i].size()>0){
                return false;
            }
        }
    }
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        
        if(isConnected(V,adj)==false) return 0;
        int oddDegree=0;
        for(int i=0;i<V;i++){
            if(adj[i].size()%2!=0){
                oddDegree++;
            }
        }
        if(oddDegree>2){
            return 0;
        }
        if(oddDegree==2){
            return 1; //EP
        }
        return 2; //EC
        
    }
};