#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define cont continue
#define pii pair<int, int>
#define mp make_pair
#define pb push_back

#define moo printf
#define oom scanf
#define mool puts("");
using namespace std;

const int MX = 4e5 +100, int_max = 0x3f3f3f3f;

int par[MX], sz[MX], occ[MX], n;
vector<pii> cost;

void mkdsu(){ for(int i = 0; i<=(n+10)*4; i++) par[i] = i, sz[i] = 1;}
int find(int x){ if(x != par[x]) par[x] = find(par[x]); return par[x]; }
void Union(int a, int b){
  a = find(a), b = find(b);
  if(a == b) return ;
  if(sz[a] > sz[b]) swap(a, b);
  sz[b] += sz[a];
  par[a] = b;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  mkdsu();
  for(int i = 1; i<=n; i++){
    int v; cin >> v;
    cost.pb(mp(v, i));
    for(int j = 0; j<4; j++){
      int a, u = i*4 +j; cin >> a;
      if(occ[a]){//portal end known
        Union(occ[a], u);
      }
      occ[a] = u;
      if(j%2 == 1) Union(u, u - 1); //does it work?
    }
  }
  
  sort(cost.begin(), cost.end());
  int tot = 0;
  for(int i = 0; i<cost.size(); i++){
    int U = cost[i].second, w = cost[i].first;
    int u = U*4, v = U*4 +2;
    //moo("%d, %d -> [%d %d] -> [%d, %d]\n", U, w, u, v, find(u), find(v));
    if(find(u) == find(v)) cont; //alr merged
    Union(u, v);
    tot += w;
  }
  moo("%d\n", tot);
  return 0;
} 
