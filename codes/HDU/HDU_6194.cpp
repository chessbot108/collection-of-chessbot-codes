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

char str[max_v];
int rk[max_v], sa[max_v], tmp[max_v], pos[max_v], lcp[max_v], rmq[max_v];
int n, k;
list<pair<int, int> > dq; //.first is value and .second is index
void precomp(){
  int mx = 255;
  //init
  for(int i = 1; i<=n; i++){
    rk[i] = str[i];
    sa[i] = i;
  }
  //sorting suffixes with radix sort
  for(int i = 1; i/2 < n; i *= 2){
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
  //lcp array comp
  for(int i = 1; i<=n; i++){
    lcp[rk[i]] = max(lcp[rk[i - 1]] - 1, 0);
    if(rk[i] > 1)
      for(; str[sa[rk[i]] + lcp[rk[i]]] == str[sa[rk[i] - 1] + lcp[rk[i]]]; lcp[rk[i]]++);
  }
}


int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d%s", &k, str + 1);
    n = strlen(str + 1);
    //assert(false);
    precomp();
    for(int i = 1; i<=n; i++){
      printf("%d %d %d %d\n", i, sa[i], rk[i], lcp[i]);
      for(int j = sa[i]; j<=n; j++){
        printf("%c", str[j]);
      }
      puts("");
    }
    long long total = 0;
    if(k == 1){  
      for(int i = 1; i<=n; i++){
        int k = max(lcp[rk[i]], lcp[rk[i + 1]]);
        total += (long long) ((n + 1 - i) - k);
      }
    }else{
      for(int i = 1; i<=n; i++){
        assert(i == 1 || (dq.size()));
        if(i - k >= dq.front().second) dq.pop_front();
        while(!dq.empty() && dq.back().first > lcp[i]){
          dq.pop_back();
        }
        dq.push_back(make_pair(lcp[i], i));
        rmq[i] = dq.front().first; //amount for (lcp[rk[i - k]], lcp[rk[i]]] which is waht we want
      }
      for(int i = 1; i<=n; i++){
        printf("%d\n", rmq[rk[i]]);
        if(i - k >= 1 && i + k <= n && lcp[i - k] < rmq[i] && lcp[i + 1] < rmq[i]) total += (long long)rmq[i];
      }
    }
    printf("%lld\n", total);
  }
	return 0;
}

