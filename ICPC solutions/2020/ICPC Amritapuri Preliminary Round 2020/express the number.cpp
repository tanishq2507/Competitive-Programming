
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define endl "\n"
void print_list(vector<int>&clist){
    for(int i=0;i<clist.size();i++)
        std::cout << clist[i] << " ";
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    
    while(t--){
        int n,x,i;
        cin>>n>>x;
        if(n%2==1 && x==0)
            cout<<-1<<endl;
        else{
            int rem = n;
            int ans=0;
            for(i=30;i>=0;i--){
                
                if(rem<= x && rem>0){
                    ans+=1;
                    break;
                }
                if(rem & (1<<i)){
                    if(i%2==1){
                        ans += 1;
                        rem = rem-(1<<i);
                    }
                    else{
                        rem = rem-(1<<(i-1));
                        ans += 1;
                        if(rem<= x && rem>0){
                            ans += 1;
                            break;
                            }
                        rem = rem-(1<<(i-1));
                        ans += 1;
                    }
                }
            }
            cout<<ans<<endl;
        }
            
    }

   return 0;
}

