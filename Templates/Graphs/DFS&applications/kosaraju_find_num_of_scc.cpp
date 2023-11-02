void sort_by_finish_times(vector<vector<int>>&graph,int node,vector<bool> &visited,stack<int>&stack1){

	    visited[node]=true;
	    for(auto v:graph[node]){
	        if(visited[v]==false){
	            sort_by_finish_times(graph,v,visited,stack1);
	        }
	    }
	    stack1.push(node);
	}
	vector<vector<int>> reverse_graph(vector<vector<int>>& orig_graph,int V){
	    vector<vector<int>>new_graph(V);
	    for(int i=0;i<V;i++){
	        for(auto &vv:orig_graph[i]){
	            new_graph[vv].push_back(i);
	        }
	    }
	    return(new_graph);
	}
	void DFS(int u,vector<bool>&visited,vector<vector<int>>& adj){
        
        visited[u]=true;
        
        for(int v: adj[u]){
        
            if(visited[v]==false)
            {
                DFS(v,visited,adj);
            }
        }
       
    }
    int kosaraju(int V, vector<vector<int>>& graph)
    {
        //Function to find number of strongly connected components in the graph.
        vector<bool>visited1(V,false);
        stack<int>stack1;
        for(int i=0;i<V;i++){
            if(visited1[i]==false){

                sort_by_finish_times(graph,i,visited1,stack1);
            }
        }

        vector<vector<int>> new_g = reverse_graph(graph,V);
        vector<bool>visited2(V,false);
        int c=0;
        while(stack1.empty()==0){
            int node = stack1.top();
            stack1.pop();
            if(visited2[node]==false){
                c+=1;
                DFS(node,visited2,new_g);
            }
        }
        return(c);
        
        
    }