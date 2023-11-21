bool dfs(int n,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>& on_stack,vector<int>& cycle) {
	visited[n] = on_stack[n] = true;
	for (int u : adj[n]) {
		if (on_stack[u]) {
			cycle.push_back(n);  // start cycle
			on_stack[n] = on_stack[u] = false;
			return true;
		} else if (!visited[u]) {
			if (dfs(u,adj,visited,on_stack,cycle)) {  // continue cycle
				if (on_stack[n]) {
					cycle.push_back(n);
					on_stack[n] = false;
					return true;
				} else {  // found u again
					cycle.push_back(n);
					return false;
				}
			}
			if (!cycle.empty())  // finished with cycle
				return false;
		}
	}
	on_stack[n] = false;
	return false;
}

vector<int>find_nodes_in_cycle(vector<vector<int>>& graph,int N){
    vector<int>cycle;
    vector<bool>visited(N+1,false);
    vector<bool>on_stack(N+1,false);
    for (int i = 1; cycle.empty() && i <= N; i++) 
        dfs(i,graph,visited,on_stack,cycle);
	
	reverse(cycle.begin(), cycle.end());
	return(cycle);
}