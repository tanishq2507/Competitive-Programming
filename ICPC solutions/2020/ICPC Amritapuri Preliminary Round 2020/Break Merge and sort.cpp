
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

void divide_list(vector<int>&list1,int &cost,priority_queue<int, vector<int>, greater<int>>&pq){
    list1.push_back(-1);
    int n = list1.size();
    if(n==1)
            pq.push(1);
    else{
        int max1 = 0;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(list1[i]>list1[i+1]){
                cost += cnt;
                pq.push(cnt);
                if(cnt>max1)
                    max1 = cnt;
                cnt=1;
            }
            else{
                cnt+=1;
            }
        }
        cost-=max1;
        
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    int t=1;
    cin>>t;
    int xxx=1;
    
    while(t--){
        int N,i,j,k;
        cin>>N;
        int total_len=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        int cost=0;
        for(i=0;i<N;i++){
            cin>>k;
            total_len += k;
            vector<int>list1(k);
            for(j=0;j<k;j++)
                cin>>list1[j];
            divide_list(list1,cost,pq);
        }
        
        while(pq.size()!=1){
            int l1 = pq.top();
            pq.pop();
            int l2 = pq.top();
            pq.pop();
            cost+=l1+l2;
            pq.push(l1+l2);
        }
        cout<<cost<<endl;
        
    }

   return 0;
}

