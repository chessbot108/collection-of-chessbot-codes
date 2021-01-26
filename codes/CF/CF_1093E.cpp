//that took way too long. ac with dnq. woot woot
//this problem can be seen as the 3d partial order problem
//as you have to count the updates with time, x, and y
//before the current query. this is solvable with cdq dnq
//big thanks to this blog
//https://robert1003.github.io/2020/01/31/cdq-divide-and-conquer.html

#include <iostream>
#include <queue>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <vector>

#define max_v 510000
#define cont continue
#define lsb(a) ((a) & -(a))
using namespace std;

struct query{
    int op, x, y, ind, amt, val;
    query(){}
    query(int a, int b, int c, int d, int e, int f){ op=a,x=b,y=c,ind=d,amt=e,val=f;}
} arr[max_v * 8], tmp[max_v * 8];

int A[max_v], B[max_v], C[max_v], D[max_v];
int ans[max_v], rec[max_v], BIT[max_v], vec[max_v], sz = 0, h = 0, n, m;

int S(int k){ return (!k) ? 0 : BIT[k] + S(k - lsb(k));}
void U(int k, int val){ for(; k<=n && k; k += lsb(k)) BIT[k] += val;}

void solve(int l, int r){
    if(l + 1 == r) return ;
    int mid = (l + r)/2;
    solve(l, mid); solve(mid, r);
    int j = l, k = mid, sum = 0, cnt = 0;
    while(j < mid || k < r){
        if(k == r || (j < mid && arr[j].x <= arr[k].x)){
            U(arr[j].y, arr[j].val);
            rec[sum++] = arr[j].y * arr[j].val;
            tmp[cnt++] = arr[j++];
        }else{      
            ans[arr[k].ind] += arr[k].amt * S(arr[k].y);
            tmp[cnt++] = arr[k++];
        }
    }
    
    assert(cnt == r - l);
    for(int i = 0; i<sum; i++){
        if(rec[i] < 0) U(-rec[i], 1); else U(rec[i], -1);
        rec[i] = 0;
    }
    assert(!S(n + 1)); //make sure the BIT is 0
    for(int i = l; i<r; i++){
        arr[i] = tmp[i - l];
    }
}

void mk(int a, int b, int c, int d, int e, int f){ arr[sz++] = query(a, b, c, d, e, f); }

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> A[i];
        C[A[i]] = i;
    }
    for(int i = 1; i<=n; i++){
        cin >> B[i];
    }

    for(int i = 1; i<=n; i++){
        mk(2, C[B[i]], i, 0, 0, 1);
    }
    for(int i = 1; i<=m; i++){
        int op, a, b, c, d; cin >> op;
        if(op - 1){
            cin >> a >> b;
            mk(op, C[B[a]], a, 0, 0, -1);
            mk(op, C[B[b]], b, 0, 0, -1);
            swap(B[a], B[b]);
            mk(op, C[B[a]], a, 0, 0, 1);
            mk(op, C[B[b]], b, 0, 0, 1);
        }else{
            cin >> a >> c >> b >> d;
            a--, b--;
            mk(op, a, b, h, 1, 0);
            mk(op, c, d, h, 1, 0);
            mk(op, a, d, h, -1, 0);
            mk(op, c, b, h, -1, 0);
            h++;
        }
    }

    solve(0, sz);
    for(int i = 0; i<h; i++){
        cout << ans[i] << endl;
    }
    return 0;
}