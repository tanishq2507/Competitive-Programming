#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#include <iostream>

void find_range(pair<pair<int,int>,double>&treex,int &dx,int &dy,vector<pair<int,int>>&ranges,int &rmax){
    int xi = treex.first.first;
    int yi = treex.first.second;
    double r = treex.second;
    double d1 = sqrt((dx-xi)*(dx-xi)+(dy-yi)*(dy-yi));
    double d2 = d1+r;
    double d3 = d1-r;

    int low,high;
    if(int(d3)!=d3)
        low = ceil(d3);
    else
        low = d3+1;
        
    if(int(d2)!=d2)
        high = floor(d2);
    else
        high = d2-1;
 
    
    if(high>=low){
        ranges.push_back({low,high});
    }
    return;
}
int findFreeinterval(vector<pair<int,int>>&ranges,int &rmax)
{

    sort(ranges.begin(),ranges.end());
    
    int ans=0;
    int i,j=0;
    int mx=0;
    for(i=1;i<=rmax;i++){
    	while(j<ranges.size() && ranges[j].first<=i){
    		mx=max(mx,ranges[j].second);
    		j++;
    	}
	    if(mx<i)
	        ans++;
    }
    return(ans);
}
int main() {
    ios_base::sync_with_stdio(false);
     cin.tie(0);
    
    int t=1;
    cin>>t;
    int xxx=1;
    while(t--){
        int ulx,uly,lrx,lry,i;
        cin>>ulx>>uly>>lrx>>lry;
        int dx,dy,n;
        cin>>dx>>dy>>n;
        vector<pair<pair<int,int>,double>>trees;
        for(i=0;i<n;i++){
            int xi,yi;
            double ri;
            cin>>xi>>yi>>ri;
            trees.push_back({{xi,yi},ri});
        }
        int maxR = min(min(dy-lry,uly-dy),min(lrx-dx,dx-ulx));
      
        vector<pair<int,int>>ranges;
        for(i=0;i<n;i++){
            find_range(trees[i],dx,dy,ranges,maxR);
        }
        int ans = findFreeinterval(ranges,maxR);
        cout<<"Case "<<xxx++<<": "<<ans<<endl;
        
}
   return 0;
}







