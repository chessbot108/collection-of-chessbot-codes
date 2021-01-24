#include <map>
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
#include <utility>
#define max_v 110000
#define int_max 0x3f3f3f3f
#define cont continue
using namespace std;

int vis[135], alph[max_v];
int l = 1, r = 1, j = 1, uni;

int adj[max_v][135];

string a, tmp;

int solve(){
  int ans = 0;
  for(int i = 0; i<a.size(); i++){
    //cout << i << " " << a[i] << " " << vis[a[i]] << " " << j << " " << ans << endl;
    if(vis[a[i]] <= j){
      ans++;
    }
    j = vis[a[i]];
  }
  
  return ans;
}


int main(){
	cin >> a;
  tmp = a;
  sort(tmp.begin(), tmp.end());
  uni = unique(tmp.begin(), tmp.end()) - tmp.begin();
  tmp.resize(uni);
  //cout << uni << endl;
  assert(uni <= 26);

  
  for(int j = 0; j<=a.size(); j++){
    if(j) for(int i = 0; i<uni; i++) adj[j][tmp[i]] = adj[j - 1][tmp[i]];
    adj[j][a[j]] = j + 1;

  }
  int ans = int_max;
  for(int i = 0; i<a.size(); i++){
    bool works = true;
    for(int j = 0; j<uni; j++){
      vis[tmp[j]] = adj[i][tmp[j]];
      if(vis[tmp[j]] == 0) works = false;
    }
    if(works)
      ans = min(ans, solve());
  }
  
  
  
  cout << ans << endl;
  
return 0;
}

