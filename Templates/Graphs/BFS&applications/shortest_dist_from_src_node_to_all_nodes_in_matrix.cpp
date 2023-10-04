vector<vector<int>> shortest_dist_from_src_bfs_matrix(vector<vector<char>>&graph,int si,int sj){
    //returns shortest distance from source node to all nodes in graph
    int dist = 0;
    queue<pair<int,int>>que;
    int r,c;
    
    r = graph.size();
    c = graph[0].size();
    
    que.push(make_pair(si,sj));
    vector<vector<bool>>visited(r,vector<bool>(c,false));
    visited[si][sj]=true;
    vector<vector<int>>dist_mat(r,vector<int>(c,1e9));
    while(que.empty()==0){
        dist++;
        int sze=que.size();
        for(int i=0;i<sze;i++){
            pair<int,int>p1 = que.front();
            que.pop();
            int x = p1.first;
            int y = p1.second;
            if(x+1<r && graph[x+1][y]!='T' && visited[x+1][y]==false){
                visited[x+1][y]=true;
                dist_mat[x+1][y]=dist;
                que.push(make_pair(x+1,y));
            }
            if(x-1>=0 && graph[x-1][y]!='T' && visited[x-1][y]==false){
                visited[x-1][y]=true;
                dist_mat[x-1][y]=dist;
                que.push(make_pair(x-1,y));
            }
            if(y+1<c && graph[x][y+1]!='T' && visited[x][y+1]==false){
                visited[x][y+1]=true;
                dist_mat[x][y+1]=dist;
                que.push(make_pair(x,y+1));
            }
            if(y-1>=0 && graph[x][y-1]!='T' && visited[x][y-1]==false){
                visited[x][y-1]=true;
                dist_mat[x][y-1]=dist;
                que.push(make_pair(x,y-1));
            }
        }
    }
    return(dist_mat);
}