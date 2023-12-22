vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist_list(V,1e8);
        dist_list[S]=0;
        for(int i =0;i<V-1;i++){
            for(int j = 0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist_list[u]!=1e8 && dist_list[u]+w<dist_list[v])
                    dist_list[v] = dist_list[u] + w;
            }
        }
        //checking for negative cycle
        for(int j = 0;j<edges.size();j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist_list[u]!=1e8 && dist_list[u]+w<dist_list[v]){
                    dist_list[v] = dist_list[u] + w;
                    vector<int>nah;
                    nah.push_back(-1);
                    return(nah);
                }
            }
            return(dist_list);
    }