bool dfs_cycle_detector(int node,int par,vector<int>&temp,vector<bool>&visited,vector<vector<int>>&graph){
    visited[node]=true;
    temp.push_back(node);
    
    for(int &v:graph[node]){
        
        if(visited[v]==false){
            if(dfs_cycle_detector(v,node,temp,visited,graph)==true)
                return(true);
            }
        else{
            if(par!=v){
                temp.push_back(v);
                return(true);
            }
        }
        
    }
    temp.pop_back();
    return(false);
}
vector<int>find_nodes_in_cycle(vector<vector<int>>&graph){
    int n = graph.size();
    vector<bool>visited(n,false);
    vector<int>temp;
    bool result = false;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            result = dfs_cycle_detector(i,-1,temp,visited,graph);
            if(result==true)
                break;
        }
    }
    if(result==false)
        return(temp);
    else{
        vector<int>ans;
        int sze = temp.size();
        int st = temp[sze-1];
        ans.push_back(st);
        for(int i=sze-2;i>=0;i--){
            if(temp[i]==st)
                break;
            ans.push_back(temp[i]);
        }
        return(ans);
    }
}