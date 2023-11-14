int count_nodes_in_st(int curr,vector<vector<int>>&graph,vector<int>&nodes_in_st,int caller){
    nodes_in_st[curr]=1;
    for(auto &node:graph[curr]){
        if(node != caller){
            nodes_in_st[curr] += count_nodes_in_st(node,graph,nodes_in_st,curr);
        }
    }
    return(nodes_in_st[curr]);
}