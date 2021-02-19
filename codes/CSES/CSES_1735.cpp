#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define ll long long
using namespace std;
const int LOGN = 18, max_v = (1 << LOGN)*4;
 
ll sum[max_v], set[max_v], arr[max_v], add[max_v], lz[max_v];
int n, q, s = 1;
ll Q(int k, int L, int R){
    return (ll)(R - L)*add[k] + ((lz[k]) ? set[k] * (ll)(R - L) : sum[k]);
}
 
void push_down(int k, int L, int R){
    if(L + 1 == R) return ;
    if(lz[k]){
        add[LC(k)] = add[RC(k)] = 0ll;
        set[LC(k)] = set[RC(k)] = set[k];
        set[k] = lz[k] = 0ll;
        lz[LC(k)] = lz[RC(k)] = 1ll;
    }
    int mid = (L + R)/2;
    add[LC(k)] += add[k];
    add[RC(k)] += add[k];
    add[k] = 0ll;
    sum[k] = Q(LC(k), L, mid) + Q(RC(k), mid, R); 
}
 
void U(int qL, int qR, int op, ll val, int k, int L, int R){
    if(qR <= L || R <= qL || R <= L) return ;
    if(qL <= L && R <= qR){
        if(op == 2){
            set[k] = val;
            add[k] = 0ll;
            lz[k] = 1ll;
        }else{
            add[k] += val;
        }
        return ;
    } 
    push_down(k, L, R);
    int mid = (L + R)/2;
    U(qL, qR, op, val, LC(k), L, mid);
    U(qL, qR, op, val, RC(k), mid, R);
    sum[k] = Q(LC(k), L, mid) + Q(RC(k), mid, R);
}
 
ll S(int qL, int qR, int k, int L, int R){
    if(qR <= L || R <= qL || R <= L) return 0ll;
    if(qL <= L && R <= qR) return Q(k, L, R);
    push_down(k, L, R);
    int mid = (L + R)/2;
    return S(qL, qR, LC(k), L, mid) + S(qL, qR, RC(k), mid, R);
}
 
void make_tree(){
    for(int i = s - 1; i<s + n - 1; i++){
        sum[i] = arr[i - (s - 1)];
    }
    for(int i = s - 2; i >= 0; i--){
        sum[i] = sum[LC(i)] + sum[RC(i)];
    }
}
 
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    while(s <= n) s *= 2;
    assert(s <= (1 << LOGN));
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    make_tree();
    while(q--){
        int op; cin >> op;
        if(op == 3){
            int a, b; cin >> a >> b;
            cout << S(a - 1, b, 0, 0, s) << endl;
        }else{
            int a, b; ll c;
            cin >> a >> b >> c;
            U(a - 1, b, op, c, 0, 0, s);
        }
    }
    return 0;
}
