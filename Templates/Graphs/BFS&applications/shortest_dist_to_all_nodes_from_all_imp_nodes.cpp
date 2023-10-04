vector<int> shortest_dist_bfs(vector<vector<int>>&graph,vector<int>&imp_nodes){
    // shortest distance to all nodes from imp/starting nodes
    queue<int>que;
    int n = graph.size();
    vector<int>dist_list(n,1e9);
    vector<bool>visited(n,false);
    for(int i=0;i<imp_nodes.size();i++){
        que.push(imp_nodes[i]);
        visited[imp_nodes[i]]=true;
        dist_list[imp_nodes[i]]=0;
    }
    
    int dist=0;
    while(que.empty()==0){
        int sze = que.size();
        dist++;
        for(int i=0;i<sze;i++){
            int curr = que.front();
            que.pop();
            
            for(auto &friend1:graph[curr]){
                if(visited[friend1]==true)
                    continue;
                else{
                    dist_list[friend1]=dist;
                    que.push(friend1);
                    visited[friend1]=true;
                }
            }
        }
    }
    return(dist_list);
}