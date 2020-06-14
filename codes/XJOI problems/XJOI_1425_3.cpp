#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <functional>

#define max_v 110
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define lsb(n) ((n) & (-(n)))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<int> arr[max_v];
bool vis[max_v];
int par[max_v];

int F(int cur){
  vis[cur] = true;
  if(par[cur] && (!arr[cur].size())) return 0;
  if(par[cur] && (arr[cur].size() != 2)) return -1 * max_v;

  int L = F(arr[cur][0]);
  int R = F(arr[cur][1]);

  if(L != R) return -1 * max_v;
  else return L + 1;
}

int main(){
  int n, root;
  scanf("%d%d", &n, &root);

  for(int i = 1; i<=n; i++){
    scanf("%d", &par[i]);
    if(par[i] < 0) root = i;
    else arr[par[i]].push_back(i);
  }

  int ans = F(root);

  for(int i = 1; i<=n; i++){
    if(!vis[i] && arr[i].size() > 0) ans = -1;
  }

  if(ans < 0) printf("no");
  else printf("yes");


  return 0;
}

