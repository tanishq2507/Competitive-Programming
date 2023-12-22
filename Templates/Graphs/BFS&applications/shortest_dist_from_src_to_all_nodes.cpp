vector<ll> shortest_dist_bfs(vector<vector<int>>&graph,int src){
    // shortest distance to all nodes from src node
    queue<int>que;
    int n = graph.size();
    vector<ll>dist_list(n,1e9);
    vector<bool>visited(n,false);
    dist_list[0] = 0;
    ll dist=0;
    que.push(src);
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
