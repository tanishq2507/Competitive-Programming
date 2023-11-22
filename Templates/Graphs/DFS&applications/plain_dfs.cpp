void DFS(int u,vector<bool>&visited,vector<vector<int>>& adj){
        
        visited[u]=true;
        
        for(int v: adj[u]){
        
            if(visited[v]==false)
            {
                DFS(v,visited,adj);
            }
        }
       
    }