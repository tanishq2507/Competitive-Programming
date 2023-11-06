const int MAX_N = 100005;
const int LOG = 31;
int a[MAX_N];
int m[MAX_N][LOG]; // m[i][j] is minimum among a[i..i+2^j-1]
int ind_arr[MAX_N][LOG];//stores indices of corresponding elements
int bin_log[MAX_N];

pair<int,int> query_for_smallest(int L, int R) { // O(1)
    //L and R are zero based indices
    //return value and index of smallest element
	int length = R - L + 1;
	int k = bin_log[length];
	if(m[L][k]<=m[R-(1<<k)+1][k])
	    return(make_pair(m[L][k],ind_arr[L][k]));
	else
	    return( make_pair(m[R-(1<<k)+1][k],ind_arr[R-(1<<k)+1][k]));
}

int query_for_second_smallest(int L,int R){
    pair<int,int>p1 = query_for_smallest(L,R);
    int ind1 = p1.second;
    if(ind1!=L && ind1!=R){
        pair<int,int>p2 = query_for_smallest(L,ind1-1);
        pair<int,int>p3 = query_for_smallest(ind1+1,R);
        return(min(p2.first,p3.first));
    }
    else if(ind1==L){
        pair<int,int>p2 = query_for_smallest(L+1,R);
        return(p2.first);
    }
    else{
        pair<int,int>p2 = query_for_smallest(L,R-1);
        return(p2.first);
    }
}

void pre_process_sparse_table(int n,vector<int>&list1){
    bin_log[1] = 0;
	for(int i = 2; i <= n; i++) {
		bin_log[i] = bin_log[i/2]+1;
	}
	for(int i = 0; i < n; i++) {
		a[i] = list1[i];
		m[i][0] = a[i];
		ind_arr[i][0] = i;
	}

	//preprocessing, O(N*log(N))
	for(int k = 1; k < LOG; k++) {
		for(int i = 0; i + (1 << k) - 1 < n; i++) {
		    if(m[i][k-1]<=m[i+(1<<(k-1))][k-1]){
		        m[i][k] = m[i][k-1];
		        ind_arr[i][k] = ind_arr[i][k-1];
		    }
		    else{
		        m[i][k] =  m[i+(1<<(k-1))][k-1];
		        ind_arr[i][k] = ind_arr[i+(1<<(k-1))][k-1];
		    }
		}
	}
}
