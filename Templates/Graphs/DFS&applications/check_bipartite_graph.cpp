bool check_bipartite_dfs_helper(vector<vector<int>>&graph,int curr,vector<int>&color){
        bool result = true;
        for(int i=0;i<graph[curr].size();i++){
            int x = graph[curr][i];
            if(color[x]==-1){
                color[x] = 1-color[curr];
                result = check_bipartite_dfs_helper(graph,x,color);
                if(result==false)
                    return(false);
            }
            else{
                if(color[x]==color[curr])
                    return(false);
            }
        }
        return(true);
}
    bool check_bipartite(vector<vector<int>>&graph,int n){
        vector<int>color(n,-1);
        int flag=0;
        for(int i=0;i<n;i++){
            bool temp;
            if(color[i]==-1){
                color[i] =1;
                temp = check_bipartite_dfs_helper(graph,i,color);
                if(temp==false){
                    return(false);
                }
            }
        }
        return(true);
    }