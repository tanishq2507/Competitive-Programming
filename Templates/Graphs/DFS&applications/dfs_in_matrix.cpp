void dfs_matrix(int i,int j,vector<vector<int>>&matrix,vector<pair<int,int>>&island,vector<vector<bool>>&visited){
    int n = matrix.size();
    int m = matrix[0].size();
    if(i<0 || j<0 || i>=n||j>=m){
        return;
    }
    
    if(matrix[i][j]==1)
        return;
    
    if(visited[i][j]==true)
        return;
    island.push_back({i,j});
    
    visited[i][j] = true;
    dfs_matrix(i+1,j,matrix,island,visited);
    dfs_matrix(i-1,j,matrix,island,visited);
    dfs_matrix(i,j+1,matrix,island,visited);
    dfs_matrix(i,j-1,matrix,island,visited);
    
}