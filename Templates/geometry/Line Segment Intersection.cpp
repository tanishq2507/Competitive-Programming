
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int orient(int x1,int y1,int x2, int y2, int x3, int y3){
    
    ll a = ((ll)(y3-y2))*(x2-x1) - ((ll)(y2-y1))*(x3-x2);
        
    if(a>0)//anti_clockwise or left
        return(1);
    else if(a==0)//collinear
        return(0);
    else
        return(2);
            
}

bool onseg(int x1,int y1,int x2,int y2,int x3,int y3){
    if(orient(x1,y1,x2,y2,x3,y3)==0 && x3>=min(x1,x2) && x3<=max(x1,x2) && y3>=min(y1,y2) && y3<=max(y1,y2))
        return(true);
    else
        return(false);
}

bool intersect(int x1,int y1,int x2,int y2,int x3, int y3, int x4 ,int y4){
    
    if(orient(x1,y1,x2,y2,x3,y3)+orient(x1,y1,x2,y2,x4,y4)==3 && orient(x3,y3,x4,y4,x1,y1)+orient(x3,y3,x4,y4,x2,y2)==3)
        return(true);
    else{
        if(onseg(x1,y1,x2,y2,x3,y3)|| onseg(x1,y1,x2,y2,x4,y4) || onseg(x3,y3,x4,y4,x1,y1) || onseg(x3,y3,x4,y4,x2,y2))
            return(true);
        else
            return(false);
    }
    
            
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    while(t--){
        
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        
        bool ans = intersect(x1,y1,x2,y2,x3,y3,x4,y4);
        
        if(ans==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    
    }

   return 0;
}

