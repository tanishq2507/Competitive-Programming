#include <bits/stdc++.h>
using namespace std;
using ll=  long long;
#define MOD 1000000007
#define endl "\n"

struct segtree {
    
    int size;
    vector<pair<int,int>> values ;
    
    void init(int n){
        size = 1;
        while(size < n )
            size = size*2;
        values.assign(2*size, {0,1});
    }
    
    void build(vector<int> &list1, int node_ind , int lx, int rx){
        if(rx - lx == 1){
            if(lx < list1.size()){
                values[node_ind] = {list1[lx],1};
            }
            return;
        }
        int m = (lx + rx)/2;
        build(list1,2*node_ind +1,lx,m);
        build(list1,2*node_ind +2,m,rx);
        int val1 = values[2*node_ind+1].first;
        int c1 = values[2*node_ind+1].second;
        int val2 = values[2*node_ind+2].first;
        int c2 = values[2*node_ind+2].second;
        
        if(val1<val2)
            values[node_ind] = {val1,c1};
        else if(val2<val1)
            values[node_ind] = {val2,c2};
        else
            values[node_ind] = {val1,c1+c2};
        
    }
    void build(vector<int>&list1){
        build(list1,0,0,size);
    }
    
    void set(int i, int val, int node_ind, int lx, int rx){
        
        //lx and rx are borders of current segment/node
        // i is index of element in input array
        
        if(rx - lx == 1){
            values[node_ind] = {val,1};
            return;
        }
        
        int m  = (lx + rx)/2;
        
        if(i<m){
            set(i, val, 2*node_ind +1, lx, m);
        }
        else{
            set(i, val, 2*node_ind +2, m,rx);
        }
        int val1 = values[2*node_ind+1].first;
        int c1 = values[2*node_ind+1].second;
        int val2 = values[2*node_ind+2].first;
        int c2 = values[2*node_ind+2].second;
        
        if(val1<val2)
            values[node_ind] = {val1,c1};
        else if(val2<val1)
            values[node_ind] = {val2,c2};
        else
            values[node_ind] = {val1,c1+c2};
    }
    
    void set(int i , int val){
        set(i,val,0,0,size);
    }
    
    pair<int,int> calc(int l,int r,int node_ind,int lx,int rx){
        if(lx>=r || l>=rx)
            return(make_pair(INT_MAX,1));
        if(lx>=l && rx<=r)
            return(values[node_ind]);
        int m = (lx + rx)/2 ; 
        pair<int,int> p1 = calc(l,r,2*node_ind +1,lx,m);
        pair<int,int> p2 = calc(l,r,2*node_ind +2,m,rx);
        
        int val1 = p1.first;
        int c1 = p1.second;
        int val2 = p2.first;
        int c2 = p2.second;
        
        if(val1<val2)
            return(make_pair(val1,c1));
        else if(val2<val1)
             return(make_pair(val2,c2));
        else
             return(make_pair(val1,c1+c2));
            
    }
    
    pair<int,int> calc(int l,int r){
        // finds min element in index l to r-1
        return calc(l,r,0,0,size);
    }
    
};
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    int t=1;
    //cin>>t;
    
    
    while(t--){
        
        int n,m;
        cin>>n>>m;
        
        segtree st;
        st.init(n);
        
        vector<int>list1(n);
        for(int i = 0; i<n; i++){
            cin>>list1[i];
        }
        st.build(list1);
        while(m--){
            int op;
            cin>>op;
            
            if(op == 1){
                int i,v;
                cin>>i>>v;
                st.set(i,v);
            }
            else{
                int l,r;
                cin>>l>>r;
                pair<int,int>p1 =  st.calc(l,r) ;
                cout<<p1.first<<" "<<p1.second<<endl;
                
            }
        }
        
    }

   return 0;
}