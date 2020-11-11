#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#define max_v 210000
#define cont continue
using namespace std;
 
vector<int> adj[max_v];
long long ans[max_v];
int sub[max_v], par[max_v];
 
long long dist = 0ll, n;
 
int dfs(int u, int d, int p){
    par[u] = p;
    dist += (long long)d;
    for(int v : adj[u]){
        if(v == p) cont;
        sub[u] += dfs(v, d + 1, u);
    }
    sub[u]++;
    return  sub[u] ;
}
 
void bfs(){
    queue<int> q;
    q.push(1);
    ans[1] = dist;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(v == par[u]) cont;
            ans[v] = ans[u] + (long long)((n - sub[v]) - sub[v]);
            q.push(v);
        }
    }
}
 
 
int main(){
    scanf("%d", &n);
    for(int i = 0; i<n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    bfs();
    for(int i = 1; i<=n; i++){
        printf("%lld ", ans[i]);
    }
    return 0;
}
