
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    while(t--){
        	string s1,s2;
			cin>>s1>>s2;
			int i,c=0;
			for(i=0;i<s1.size();i++){
				if(s1[i]=='1')
					c+=1;
				else if(s1[i]=='3')
					c+=4;
				else if(s1[i]=='5')
					c+=6;
				else
					c+=9;
			}
           for(i=0;i<s2.size();i++){
				if(s2[i]=='1')
					c-=1;
				else if(s2[i]=='3')
					c-=4;
				else if(s2[i]=='5')
					c-=6;
				else
					c-=9;
			}
			cout<<c<<endl;
    }   

   return 0;
}

