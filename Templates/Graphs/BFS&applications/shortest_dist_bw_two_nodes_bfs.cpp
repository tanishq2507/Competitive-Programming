int shortest_path_bfs(vector<vector<int>>&graph,int s,int f,vector<int>&parent){
	//shortest distance from source node s to destination node f
	//parent is used for mapping the path
    if(s==f)
        return(0);
    queue<int>que;
    que.push(s);
    int n = graph.size();
    vector<bool>visited(n,false);
    visited[s]=true;
    int ans=0;
    while(que.empty()==0){
        int sze = que.size();
        ans++;
        for(int i=0;i<sze;i++){
            int curr = que.front();
            que.pop();
            
            for(auto &friend1:graph[curr]){
                if(visited[friend1]==true)
                    continue;
                else{
                    parent[friend1] = curr;
                    if(friend1==f)
                        return(ans);
                    que.push(friend1);
                    visited[friend1] = true;
                }
            }
        }
    }
    return(-1);
}
