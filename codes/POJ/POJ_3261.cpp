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
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 110000
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


int sa[max_v], rk[max_v], lcp[max_v], tmp[max_v], disc[max_v], srt[max_v], pos[max_v]; //disc needed :/
int str[max_v], n, m, K;

void comp_SA(){
  int mx = m + 1;
  for(int i = 1; i<=n; i++){
    rk[i] = str[i];
    sa[i] = i;
  }
  for(int i = 1; i / 2 < n; i *= 2){
    int k = i/2, p = k;
    for(int j = 1; j<=k; j++) tmp[j] = (n + 1) - j;
    for(int j = 1; j<=n; j++) if(sa[j] > k) tmp[++p] = sa[j] - k;
    memset(pos, 0, sizeof(pos));
    for(int j = 1; j<=n; j++) pos[rk[j]]++;
    for(int j = 1; j<=mx; j++) pos[j] += pos[j - 1];
    for(int j = n; j; j--) sa[pos[rk[tmp[j]]]--] = tmp[j];
    for(int j = 1; j<=n; j++) tmp[sa[j]] = tmp[sa[j - 1]] + (rk[sa[j]] != rk[sa[j - 1]] || rk[sa[j] + k] != rk[sa[j - 1] + k]);
    for(int j = 1; j<=n; j++) rk[j] = tmp[j];
    mx = rk[sa[n]];
    if(mx == n) break;
  }

}


void comp_LCP(){
  for(int i = 1; i<=n; i++){
    lcp[rk[i]] = max(0, lcp[rk[i - 1]] - 1);
    for(; str[sa[rk[i]] + lcp[rk[i]]] == str[sa[rk[i] - 1] + lcp[rk[i]]]; lcp[rk[i]]++);
  }
}

bool check(int x){
  //printf("%d\n", x);
  assert(x && x != n + 1);
  int ans = 0, cnt = 1;
  for(int i = 1; i<=n; i++){
    cnt = (lcp[i] >= x) ? cnt + 1 : 1;
    //printf("%d ", cnt);
    ans = max(ans, cnt);
  }
  //puts("");
  return ans >= K;
}

int bin_search(int l, int r){ //[a, b)
  if(l > r) return l - 1;
  int mid = (l + r + 1) / 2;
  //printf("%d %d %d\n", l, r, mid);
  if(!check(mid)){
    return bin_search(l, mid - 1);
  }else{
    return bin_search(mid + 1, r);
  }
}


int main(){
	scanf("%d%d", &n, &K);
  for(int i = 1; i<=n; i++){
    scanf("%d", &str[i]);
    str[i]++; //avoiding 0 for fenceposts and other things
    srt[i] = str[i];
  }
  sort(srt + 1, srt + n + 1);
  m = std::unique(srt + 1, srt + n + 1) - &srt[1];
  for(int i = 1; i<=n; i++) str[i] = (lower_bound(srt + 1, srt + m + 1, str[i]) - &srt[0]);
  //reassign each value to be the disc key. relative ordering will stay the same
  //for(int i = 1; i<=n; i++) printf("%d ", str[i]); puts("");
	comp_SA();
  //for(int i = 1; i<=n; i++){
    //printf("%d, %d: ", i, sa[i]);
    //for(int j = sa[i]; j <=n; j++){
      //printf("%d ", srt[str[j]] - 1);
    //}
    //puts("");
  //}
  comp_LCP(); //luckily no rmq needed
  //for(int i = 1; i<=n; i++) printf("%d %d %d %d\n", i, rk[i], sa[i], lcp[i]); puts("");

  printf("%d\n", bin_search(1, n));
  
  

  return 0;
}

