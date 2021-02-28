#include <iostream>
#include <cassert>
#include <algorithm>
#define ll long long
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
using namespace std;
const int max_v = 8e5 +10; 
//i swear segtrees always need more memory than i am willing to give them
ll sum[max_v], pre[max_v], arr[max_v];
int n, q, s = 1, vals[30], sz;;
void U(int p, ll val, int k, int L, int R){
    if(p < L || R <= p || R <= L) return ;
    if(L + 1 == R){
        assert(L == p);
        pre[k] = max(val, 0ll);
        sum[k] = val;
        return ;
    }
    int mid = (L + R)/2;
    U(p, val, LC(k), L, mid);
    U(p, val, RC(k), mid, R);
    sum[k] = sum[LC(k)] + sum[RC(k)];
    pre[k] = max({pre[LC(k)], sum[LC(k)] + pre[RC(k)], 0ll});
}

void S(int qL, int qR, int k, int L, int R){
    if(qR <= L || R <= qL || R <= L) return;
    if(qL <= L && R <= qR){
        vals[sz++] = k;
        return ;
    }
    int mid = (L + R)/2;
    S(qL, qR, LC(k), L, mid); 
    S(qL, qR, RC(k), mid, R);
}

void print(){
    for(int i = 0; i<s*2; i++){
        cout << i << " " << pre[i] << " " << sum[i] << endl;
    }
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    while(s <= n) s <<= 1;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    for(int i = 0; i<n; i++)
        U(i, arr[i], 0, 0, s);
    //precomp();
    //print();
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int k; ll val;
            cin >> k >> val;
            U(k - 1, val, 0, 0, s);
        }else{
            int l, r;
            cin >> l >> r;
            sz = 0; S(l - 1, r, 0, 0, s);
            ll ans = 0ll, s = 0ll;
            for(int i = 0; i<sz; i++){
                ans = max({ans, s + pre[vals[i]]});
                s += sum[vals[i]];
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}