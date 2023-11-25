
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
        int n,i,num;
        cin>>n;
        vector<int>list1(n);
        vector<int>req(n);
        map<int,priority_queue<int>>mp;
        for(i=0;i<n;i++){
            cin>>num;
            list1[i] = num;
            req[i] = num;
            mp[num].push(i);
        }
        sort(req.begin(),req.end());
        vector<pair<int,int>>anslist;
        for(i=0;i<n;i++){
            if(req[i]!=list1[i]){
                int ind1 = mp[req[i]].top();
                anslist.push_back({i,ind1});
                anslist.push_back({ind1,i});
                anslist.push_back({i,ind1});
                mp[req[i]].pop();
                mp[list1[i]].pop();
                mp[list1[i]].push(ind1);
                swap(list1[i],list1[ind1]);
                
            }
            else{
                mp[list1[i]].pop();
            }
        }
        cout<<anslist.size()<<endl;
        for(i=0;i<anslist.size();i++){
            cout<<anslist[i].first+1<<" "<<anslist[i].second+1<<endl;
        }
        
    }

   return 0;
}

