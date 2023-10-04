vector<int> topo_sort(int v,map<int,vector<int>>&graph){
        vector<int>indeg(v,0);
        for (auto &i : graph){
            for(auto &j: i.second){
                indeg[j]+=1;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int j=0;j<v;j++){
            if(indeg[j]==0)
                q.push(j);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            if(graph.count(node)==1){
                for(auto &j : graph[node]){
                    indeg[j]-=1;
                    if(indeg[j]==0)
                        q.push(j);
                }
            }
        }
        return(ans);
    }