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

#define max_v 110000
#define int_max 0x3f3f3f3f
#define cont continue
using namespace std;

int vis[130], alph[max_v];
int l = 1, r = 1, j = 1, uni;

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
  //cout << uni << endl;
  int ans = int_max;
  assert(uni <= 26);
  for(int i = 0; i < a.size(); i++){
    if(vis[a[i]]) cont;
    //alph[r] = a[i];
    vis[a[i]] = r++;
    //cout << l << " " << r << endl;
    if(r - l == uni){
      ans = min(ans, solve());
      vis[a[l++]] = 0;
    }

  }
  
  cout << ans << endl;
  
return 0;
}
