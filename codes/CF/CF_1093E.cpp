#include <iostream>
#include <queue>
#include <cassert>
#include <algorithm>
#include <cmath>
#define max_v 500000

#define cont continue
#define lsb(a) ((a) & -(a))
using namespace std;
const int SQRT = 450;
int BIT[SQRT][max_v];
int A[max_v], B[max_v], C[max_v], D[max_v];
int n, m;
int S(int k, int rt){
    int ans = 0;
    for(k++; k; k -= k&-k) ans += BIT[rt][k];
    return ans;
}

void U(int rt, int k, int val){
    for(k++; k <= n; k += k&-k) BIT[rt][k] += val;
}

int S(int l, int r, int h){
    int rt_l = l/SQRT +1, rt_r = r/SQRT, ans = 0;
    printf("%d %d %d %d %d", l, r, rt_l, rt_r, h); cout << endl;
    if(rt_l >= rt_r){
        while(l != r){ 
            cout << l << " " << r << " " << C[B[l]] << " " << (C[B[l]] <= h) << endl;
            ans += (C[B[l++]] <= h);
        }
        return ans;
    }

    while(l != rt_l * SQRT){
        ans += (C[B[l++]] <= h);
    }
    while(r != rt_r * SQRT){
        ans += (C[B[--r]] <= h);
    }
    while(rt_l != rt_r){
        ans += S(h, rt_l);
        rt_l += SQRT;
    }
    return ans;
}

void U(int x, int y){
    int a = C[B[x]], b = C[B[y]];
    U(x/SQRT, a, -1);
    U(y/SQRT, b, -1);
    U(x/SQRT, b, 1);
    U(y/SQRT, a, 1);
    swap(B[x], B[y]);
    D[B[x]] = x;
    D[B[y]] = y;
}

void print(){
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=n; j++){
            cout << S(i, i + 1, j) << " ";
        }
        cout << endl;
    }
    for(int i = 0; i<n; i++){
        cout << C[B[i]] << endl;
    }
}

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> A[i];
        C[A[i]] = i;
    }
    for(int i = 0; i<n; i++){
        cin >> B[i];
        D[B[i]] = i;
    }

    for(int i = 0; i<n; i++){
        U(i/SQRT, C[B[i]]);
    }
    int op, a, b, c, d;
    //print();
    for(int i = 0; i<n; i++){
        printf("%d %d %d %d %d", i, A[i], B[i], C[B[i]], D[A[i]]); cout << endl;
    }
    while(m--){
        cin >> op;
        if(op - 1){
            cin >> a >> b; a--, b--;
            U(a, b);
        }else{
            cin >> a >> b >> c >> d; a--, c--, d--;
            cout << S(a, b, d) << " " << S(a, b, c - 1) << endl;
            cout << S(a, b, d) - S(a, b, c - 1) << endl;
        }
        //print();
    }

    return 0;
}
