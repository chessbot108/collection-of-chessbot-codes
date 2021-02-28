#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#define max_v 220000
#define int_max 0x3f3f3f3f
#define ll long long
#define cont continue

using namespace std;
int a[max_v], b[max_v], arr[max_v], par[max_v], sz[max_v], cyc[max_v];
bool vis[110][110];
int n, k;
ll m;
int find(int x){
  if(par[x] != x) par[x] = find(par[x]);
  return par[x];
}

void Union(int u, int v){
  u = find(u), v = find(v);
  if(u == v) return ;
  if(sz[u] > sz[v]) swap(u, v);
  par[u] = v;
  sz[v] += sz[u];
}



int main(){
  cin >> n >> k >> m;
  for(int i = 0; i<k; i++){
    cin >> a[i] >> b[i];
  }
  for(int i = 1; i<=n; i++) arr[i] = i;
  if(n <=100 && k <= 200){
    int cnt = 0;
    for(ll j = 0; j<m && cnt <n; j+=1ll){
      int i = j%k;
      swap(arr[a[i]], arr[b[i]]);
      vis[arr[a[i]]][b[i]] = true;
      vis[arr[b[i]]][a[i]] = true;
      if(arr[a[i]] == a[i]){
        if(!cyc[a[i]]) cyc[a[i]] = 1, cnt++;
      }
      if(arr[b[i]] == b[i]){
        if(!cyc[b[i]]) cyc[b[i]] = 1, cnt++;
      }
    }
    for(int i = 1; i<=n; i++){
      int cnt = 1;
      
      //cout << i << ": ";
      for(int j = 1; j<=n; j++){
        if(vis[i][j]){ 
          cnt++; 
          //cout << j << " "; 
        }
      }
      //cout << " ans is:";
      
      cout << cnt << endl;
    }
  }else{
    for(int i = 0; i<=n; i++) par[i] = i, sz[i] = 1;
    for(int i = 0; i<k; i++){
      Union(a[i], b[i]);
    }
    for(int i = 1; i<=n; i++){
      cout << sz[find(i)] << endl;
    }
  }

	return 0;
}

