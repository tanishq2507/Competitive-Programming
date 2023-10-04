vector<vector<int>>up;
    getKthAncestor_pre_processing(int n, vector<int>& parent) {
        
        int i,j,v;
        up = vector<vector<int>>(n,vector<int>(20,-1));
        
        for(v=0;v<n;v++){
            up[v][0]=parent[v];
        }
        for(j=1;j<20;j++){
            for(v=0;v<n;v++){
                if(up[v][j-1]!=-1)
                    up[v][j] = up[up[v][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int j=0;
        int v = node;
        for(j=0;j<20;j++){
            if(k & (1<<j)){
                v = up[v][j];
                if(v==-1)
                    return(-1);
            }
        }
        return(v);
    }