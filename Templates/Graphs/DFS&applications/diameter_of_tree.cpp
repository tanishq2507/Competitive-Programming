void dfs_distance_tree(int curr,vector<vector<int>>&gmat,vector<int>&dist,int caller){
        for(int i =0;i<gmat[curr].size();i++){
            int x = gmat[curr][i];
            if(x!=caller){
            dist[x]=dist[curr]+1;
            dfs_distance_tree(x,gmat,dist,curr);
            }
        }
    }
    vector<int>calculate_distance_tree(int node,vector<vector<int>>&gmat,int n){
        vector<int>dist(n,0);
        dfs_distance_tree(node,gmat,dist,-1);
        return(dist);
    }
int diameter_of_tree(vector<vector<int>>&graph,int root){
        vector<int>dist1 = move(calculate_distance_tree(root,graph,graph.size()));
        int p1 = root;
        int max1 = 0,i;
        for(i=0;i<graph.size();i++)
            if(dist1[i]>dist1[p1])
                p1 = i;
        vector<int>dist2 = move(calculate_distance_tree(p1,graph,graph.size()));
        int ans=0;
        for(i=0;i<graph.size();i++)
            if(dist2[i]>ans)
                ans = dist2[i];
        return(ans);
                
    }