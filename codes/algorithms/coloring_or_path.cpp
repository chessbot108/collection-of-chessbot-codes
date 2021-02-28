//it appears that i cannot submit this problem
//i have the right idea and the intuition
//but it passes very basic samples
//i'll just assume it works
//https://tinyurl.com/tgq8sigl
//its a problem of either give a k-coloring of a graph
//or output a simple path of length k
//due to magic one of the two is always possible


#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
using namespace std;
const int max_v = 1e3 + 10;
int col[max_v], stack[max_v], freq[max_v];
vector<int> adj[max_v];
int sz = 0, n, m, k;
bool color(int u, int p){
    stack[sz++] = u;
    for(int v : adj[u]){
        if(~col[v]) freq[col[v]]++; 
    }
    int mex = 1; 
    while(freq[mex]){ mex++;}
    if(mex > k) return false;    
    col[u] = mex;

    for(int v : adj[u]){
        if(col[v] == -1){
            assert(v != p);
            if(!color(v, u)) return false;
        }else{
            freq[col[v]]--;
        }
    }    

    sz--;
    return true;
}

int main(){
    freopen("pathorcoloring.in", "r", stdin);
    freopen("pathorcoloring.out", "w+", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> k;
        for(int i = 0; i<=n; i++){
            adj[i].clear();
            stack[i] = freq[i] = 0;
            col[i] = -1;
        }
        for(int i = 0; i<m; i++){
            int a, b; cin >> a >> b;
            if(a == b) continue;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        sz = 0;
        if(color(1, 0)){
            cout << "coloring ";
            for(int i = 1; i<=n; i++){
                cout << col[i] << " ";
            }
        }else{
            cout << "path ";
            assert(sz >= k + 1);
            for(int i = 0; i<=k; i++){
                cout << stack[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}