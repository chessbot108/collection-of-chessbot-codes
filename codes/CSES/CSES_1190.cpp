#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <vector>
#define ll long long
#define LC(n) ((n << 1) + 1)
#define RC(n) ((n + 1) << 1)
using namespace std;
const int max_v = 2e5 *4;
ll sum[max_v], pre[max_v], suf[max_v], arr[max_v], ans[max_v];
int n, q, s = 1;
void U(int p, ll val, int k, int L, int R){
    if(p < L || R <= p || R <= L) return ;
    if(L + 1 == R){
        assert(L == p);
        sum[k] = pre[k] = suf[k] = ans[k] = val;
        return ;
    } 
    int mid = (L + R)/2;
    U(p, val, LC(k), L, mid);
    U(p, val, RC(k), mid, R);
    sum[k] = sum[LC(k)] + sum[RC(k)];
    pre[k] = max({pre[LC(k)], sum[LC(k)] + pre[RC(k)], 0ll});
    suf[k] = max({suf[RC(k)], sum[RC(k)] + suf[LC(k)], 0ll});
    ans[k] = max({ans[LC(k)], ans[RC(k)], suf[LC(k)] + pre[RC(k)], 0ll});
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    while(s <= n) s *= 2; s *= 2;
    for(int i = 0; i<n; i++)
        cin >> arr[i];

    for(int i = 0; i<n; i++){
        U(i, arr[i], 0, 0, s);
    }
    while(q--){
        int k; ll val;
        cin >> k >> val;
        U(k - 1, val, 0, 0, s);
        cout << max(0ll, ans[0]) << '\n';
    }

    return 0;
}