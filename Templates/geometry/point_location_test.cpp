
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    while(t--){
        
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        
        double a = (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
        
        if(a>0)
            cout<<"LEFT"<<endl;
        else if(a==0)
            cout<<"TOUCH"<<endl;
        else
            cout<<"RIGHT"<<endl;
    
    }

   return 0;
}

