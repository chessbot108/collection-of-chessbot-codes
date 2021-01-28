#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <iterator>
#define max_v 220000
#define cont continue
#define lsb(k) ((k) & -(k))
#define pb push_back
using namespace std;

struct query{
    int l, r, l1, r1, x, y, op;
    query(){}
    query(int a, int b, int c){op = a, x = b, y = c;}
    query(int a, int b, int c, int d, int e){op = a, l = b, r = c, l1 = d, r1 = e;}
} q[max_v];

vector<int> adj[max_v];
vector<int> BIT[max_v];
int n, m;
int A[max_v], B[max_v], C[max_v], D[max_v], B2[max_v], D2[max_v];
//A and B are the input, C is the inverse of A
//so A[C[i]] == i and the same goes for D and B
//B2 and D2 a one i use for simulating
int get_ind(int a, int k){ 
    //cout << a << " " << k << endl;
    assert(*lower_bound(adj[a].begin(), adj[a].end(), k) == k);
    return lower_bound(adj[a].begin(), adj[a].end(), k) - adj[a].begin();
}

void U(int a, int b, int val, int op){
    //cout << "updating " << a << " " << b << " " << val << " " << op << endl; 
    for( ; a && a <= n; a += lsb(a)){
        for(int i = b ; i && i <= n; i += lsb(i)){
            //cout << a << "  " << i << endl;
            if(op) BIT[a][get_ind(a, i)] += val;
            else adj[a].pb(i);
        }
    }
}

int S(int a, int b, int op){
   int ans = 0;
   //if(op) cout << "sum of " << a << " " << b << endl;
   for( ; a; a -= lsb(a)){
       for(int i = b; i; i -= lsb(i)){
           //if(op) cout << a << " " << i << endl;
           if(op) ans += BIT[a][get_ind(a, i)];
           else adj[a].pb(i);
       }
   } 
   return ans;
}

int S(int a, int b, int c, int d, int op){
    //sum of rectangle :/
    //[a, c]; [b, d]
    //cout << a << " " << b << " " << c << " " << d << " " << op << endl;
    int sm = S(a, b, op), m1 = S(a, d, op), m2 = S(c, b, op), big = S(c, d, op);
    //cout << sm << " " << m1 << " " << m2 << " " << big << endl;
    return (sm + big) - (m1 + m2);
}

void U(int a, int b, int op){
    //swap positions a and b in permutation b
    int x = (op) ? C[B[a]] : C[B2[a]], y = (op) ? C[B[b]] : C[B2[b]];
    U(x, a, -1, op);
    U(y, b, -1, op);
    U(x, b, 1, op);
    U(y, a, 1, op);
    if(op){
        D[B[a]] = b;
        D[B[b]] = a;
        swap(B[a], B[b]);
    }else{
        swap(B2[a], B2[b]);
    }
}



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    //cout << "not being broken" << endl; 
    for(int i = 1; i<=n; i++){
        cin >> A[i];
        C[A[i]] = i;
    }

    for(int i = 1; i<=n; i++){
        cin >> B[i];
        D[B[i]] = i;
    }

    for(int i = 1; i<=n; i++){
        B2[i] = B[i];
        U(i, D[A[i]], 1, 0);
    }

    for(int i = 0; i<m; i++){
        int op;
        cin >> op;
        if(op == 1){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            swap(b, c); //magic
            a--, b--;
            q[i] = query(op, a, b, c, d);
            S(a, b, c, d, 0);
        }else{
            int a, b;
            cin >> a >> b;
            q[i] = query(op, a, b);
            U(a, b, 0);
        }
    }   
    
    for(int i = 0; i<=n; i++){
        
        adj[i].pb(0); //to make the BIT 1-based :/
        
        sort(adj[i].begin(), adj[i].end()); //coord compression
     
        auto it = unique(adj[i].begin(), adj[i].end());
        adj[i].resize(it - adj[i].begin());
        BIT[i] = vector<int>(adj[i].size(), 0); //main optimization for log^2 memory
    
    }

    /**
    for(int i = 0; i<=n; i++){
        cout << i << " " << adj[i].size() << endl;
        for(int j = 0; j <adj[i].size(); j++) cout << adj[i][j] << " ";
        cout << endl;
    }
    
    cout << endl << endl;
    **/
    for(int i = 1; i<=n; i++){     
        U(i, D[A[i]], 1, 1);
    }

    for(int i = 0; i<m; i++){
        if(q[i].op - 1){
            U(q[i].x, q[i].y, 1);
        }else{
            cout << S(q[i].l, q[i].r, q[i].l1, q[i].r1, 1) << endl;
        }

    }

    return 0;
}