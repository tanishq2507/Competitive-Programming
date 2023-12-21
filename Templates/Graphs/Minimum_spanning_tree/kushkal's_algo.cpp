int find_parent(int node,vector<int>& parent){
    if(parent[node]==node)
        return(node);
    return(parent[node]=find_parent(parent[node],parent));
}

int make_union(vector<int>edgex,vector<int>& sze,vector<int>&parent){
    int up1,up2;
    int w = edgex[0];
    int u = edgex[1];
    int v = edgex[2];
    up1 = find_parent(u,parent);
    up2 = find_parent(v,parent);
    if(up1!=up2){
        if(sze[up1]>=sze[up2]){
            parent[up2]=up1;
            sze[up1]+=sze[up2];
        }
        else{
            parent[up1]=up2;
            sze[up2]+=sze[up1];
        }
        
        return(w);
    }
    else
        return(0);
    
}

ll mst_weight(vector<vector<int>>&edges2,vector<int>& parent,vector<int>& sze){
//Krushkal's algo
        int i;
        ll c=0;
        for(i=0;i<edges2.size();i++){
            c+=(ll)make_union(edges2[i],sze,parent);
        }
        return(c);
    }

bool is_mst(int n,vector<int>& parent){
        int i ;
        int par = find_parent(0,parent);
        for(i=1;i<n;i++){
            if(find_parent(i,parent)!=par)
                return(false);
        }
        return(true);
    }
