//SCAMMMMMMMMMMMMMMMMMMMMM. I HAVE CODES FOR XOR NOT OR. 2 HOURS GONE
//AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
//AND THE DIFFERENCE ISN'T A CHANGE OF OPERATORS
//THE PROBLEM ITSELF IS MUCH HARDER
//I MAD
//>:(
//XJOI 1644 1
//11/24 test 1
//choose numbers


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
#define int_max 0x3f3f3f3f
#define cont continue
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

const int sigma = 260;

int arr[max_v], pre[max_v], back[max_v], freq[sigma], ans[max_v], d[max_v], cnt[sigma];
vector<pair<int, int>> query[sigma][max_v]; //right end, query ID
int n, q;

void find_a(int * a, int s, int e, int inc, int x){
  memset(a, 0, sizeof(int) * max_v);
  memset(freq, 0, sizeof(freq));
  memset(cnt, 0, sizeof(cnt));
  printf("x == %d\n", x);
  for(int i = s; i != e; i += inc){
    a[i] = freq[x ^ arr[i]];
    printf("\t%d round; \n\t\tarr[i] == %d and freq[x^arr[i]] == %d\n", i, arr[i], freq[x^arr[i]]);
    for(int j = 0; j<sigma; j++){
      freq[arr[i]^j] += cnt[j];
    }
    cnt[arr[i]]++;
  }
  puts("\n\n\n");
}

void solve(int x){
  memset(pre, 0, sizeof(pre));
  find_a(d, 0, n, 1, x);
  find_a(back, n - 1, -1, -1, x);
  for(int i = 1; i<=n; i++){
    pre[i] = pre[i - 1] + d[i];
  }
  printf("for x == %d:\n\t", x);
  for(int i = 0; i<n; i++) printf("%d ", pre[i]); puts("");
  printf("table for x == %d\n", x);
  for(int i = -1; i<n; i++) printf("%3d", i); puts("");

  int sub = 0;
  for(int i = 0; i<n; i++){
    for(auto p : query[x][i]){
      ans[p.second] = max(pre[p.first] - sub, 0);
    }
       
    printf("%2d|", i);
    for(int j = 0; j<n; j++) printf("%3d", max(pre[j] - sub, 0)); puts("");
    sub += back[i];

  }
  puts("\n\n");
}



int main(){
	scanf("%d%d", &n, &q);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  for(int i = 0; i<q; i++){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    query[c][a - 1].push_back(make_pair(b - 1, i));
  }
  for(int i = 0; i<sigma; i++){
    solve(i);
  }
  for(int i = 0; i<q; i++){
    printf("%d\n", ans[i]);
  }
	return 0;
}

