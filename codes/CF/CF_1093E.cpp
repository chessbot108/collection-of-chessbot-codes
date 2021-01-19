#include <iostream>
#include <queue>
#include <cassert>
#include <algorithm>
#include <cmath>
#define max_v 500000

#define cont continue
#define lsb(a) ((a) & -(a))
using namespace std;
const int gave_up = 4e7;
int sum[gave_up], rc[gave_up], lc[gave_up], root[max_v], ind = 0, s;
int A[max_v], B[max_v], C[max_v], D[max_v], n, m;
//i have given up on a 2d BIT, time to pop in a PST

int mem[max_v], ms = 0, P;
/**
void U(int p, int val, int& k, int L, int R){
    if(!k){
        if(ms)k = mem[--ms];
        else k = ++ind;
    }
    if(L + 1 == R){
        assert(L == p);
        sum[k] += val;
        return ;
    }
    int mid = (L + R) / 2;
    if(p < mid) U(p, val, lc[k], L, mid);
    else U(p, val, rc[k], mid, R);
    sum[k] = sum[lc[k]] + sum[rc[k]];
    if(!sum[k] && k){
        mem[ms++] = k, k = 0;
    }
}
**/
void U(int val, int& k){
    int L = 0, R = s, mid;
    while(L + 1 != R){
        if(!k) if(ms){ k = mem[--ms];} else{ k = ++ind;}
        sum[k] += val, mid = L + R >> 1;
        if(!sum[k]) mem[ms++] = k;
        if(P < mid) k = lc[k], R = mid;
        else k = rc[k], L = mid;
    }
    sum[k] += val;
}


int S(int p, int k, int L, int R){
    if(!k || R <= L) return 0;
    //cout << L << " " << R << " " << qL << " " << qR << " " << k << endl;
    //[0....p)
    int mid = (L + R) / 2;
    if(p < mid){
        return S(p, lc[k], L, mid);
    }else{
        return sum[lc[k]] + S(p, rc[k], mid, R);
    }
    assert(false);
}

int S(int a, int b){
    //a++, b++;
    b++;
    //cout << "\nquery sum of " << a << " " << b << endl;
    int ans = 0;
    for(; a; a -= lsb(a)){
        //cout << a << " " << b << " " << S(0, b + 1, root[a], 0, s) << endl;
        ans += S(b, root[a], 0, s);
    }
    //cout << ans << endl;
    return ans;
}

void U(int a, int b, int val){
    //a++, b++;
    //cout << "\nudpating " << a << " " << b << " by " << val << endl;
    P = b;
    for(; a <= s; a += lsb(a)){
        //cout << a << " " << b << endl;
        U(val, root[a]);
    }
}


int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    s = (1 << 18); //heh 
    for(int i = 1; i<=n; i++){
        cin >> A[i];
        C[A[i]] = i;
    }
    for(int i = 1; i<=n; i++){
        cin >> B[i];
        D[B[i]] = i;
    }

    for(int i = 1; i<=n; i++){
        U(C[i], D[i], 1);
        //cout << S(C[i], D[i]) << endl;
    }
    //print();
    int a, b, c, d;
    for(; m--; ){
        int op; cin >> op;
        if(op - 1){
            cin >> a >> b; //a--, b--;
            U(C[B[a]], a, -1);
            U(C[B[b]], b, -1);
            U(C[B[a]], b, 1);
            U(C[B[b]], a, 1);
            swap(B[a], B[b]);
            D[B[a]] = a;
            D[B[b]] = b; //idk if this is needed.
        }else{
            
            cin >> a >> c >> b >> d;
            a--, b--;
            //a--, b--, c--, d--;
            //cout << a << " " << b << " " << c << " " << d << endl;
            //cout << S(a - 1, b - 1) << " " << S(c, d) << " " << S(a - 1, d) << " " << S(c, b - 1) << endl;
            cout << (S(a, b) + S(c, d)) - (S(a, d) + S(c, b)) << '\n';
        }
        //cout << "after " << i + 1 << "th query: " << endl;
        //print();
    }
    

    return 0;
}
