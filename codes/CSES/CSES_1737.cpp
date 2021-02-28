#include <iostream>
#include <cassert>
#define ll long long
using namespace std;
const int LOGN = 30, max_v = 2e6;
ll sum[max_v * LOGN], arr[max_v];
int lc[max_v * LOGN], rc[max_v * LOGN], root[max_v]; 
int n, q, s = 1, ind = 1, len = 2;
void dup(int& k){
    ind++;
    lc[ind] = lc[k];
    rc[ind] = rc[k];
    sum[ind] = sum[k];
    k = ind;
}

void U(int p, ll val, int& k, int L, int R){
    if(p < L || R <= p || R <= L) return ;
    dup(k);
    if(L + 1 == R){
        assert(p == L);
        sum[k] = val;
        return ;
    }
    int mid = (L + R)/2;
    U(p, val, lc[k], L, mid);
    U(p, val, rc[k], mid, R);
    sum[k] = sum[lc[k]] + sum[rc[k]];
}

ll S(int qL, int qR, int k, int L, int R){
    if(qR <= L || R <= qL || R <= L || !k) return 0ll;
    if(qL <= L && R <= qR) return sum[k];
    int mid = (L + R)/2;
    return S(qL, qR, lc[k], L, mid) + S(qL, qR, rc[k], mid, R);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    while(s <= n) s *= 2; s *= 2;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i<n; i++){
        U(i, arr[i], root[1], 0, s);
    }
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int ver, k; ll val;
            cin >> ver >> k >> val;
            U(k - 1, val, root[ver], 0, s);
        }else if(op == 2){
            int k, a, b;
            cin >> k >> a >> b;
            cout << S(a - 1, b, root[k], 0, s) << '\n';
        }else{
            int k; cin >> k;
            root[len++] = root[k];
        }
    }

    return 0;
}