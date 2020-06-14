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

#define max_v 1100000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
#define init0(foo) memset(foo, 0, sizeof(foo));
#define left first
#define right second
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

long long prefix[max_v], arr[max_v];
int t[max_v], p[max_v]; 
//t is the left index of the max interval when the right is the R
//p is the right index of the max interval when the left is the L
pair<int, int> d[max_v];

int sum(int l, int r){ return prefix[r] - prefix[l]; }
int sum(pair<int, int>& a){ return prefix[a.right] - prefix[a.left]; }
bool better(pair<int, int>& a, pair<int, int>& b){
  if(sum(a) == sum(b))
    return (a.left < b.left) || (a.left == b.left && a.right < b.right);
  return sum(a) < sum(b);
}

bool better(int a, int b, int c, int d){
  if(sum(a, b) == sum(c, d))
    return (a < c) || (a == c && b < d);
  return sum(a, b) < sum(c, d);
}

class seg_tree{
  int s, n;
  
  void construct(int k, int L, int R){
    if(L == R){
      d[k] = make_pair(L, R);
      t[k] = L; p[k] = L;
      return ;
    }

    int mid = (L + R) / 2;
    int lc = k*2 + 1, rc = k*2 + 2;
    construct(lc, L, mid);
    construct(rc, mid, R);

    long long v1 = sum(L, p[lc]);
    long long v2 = sum(L, p[rc]);

    if(v1 == v2) p[k] = min(p[lc], p[rc]);
    else p[k] = (v1 > v2) ? p[lc] : p[rc];

    v1 = sum(t[lc], R);
    v2 = sum(t[rc], R);

    if(v1 == v2) t[k] = min(t[lc], t[rc]);
    else t[k] = (v1 > v2) ? t[lc] : t[rc];

    d[k] = (better(d[lc], d[rc])) ? d[lc] : d[rc];
    d[k] = (better(d[k], make_pair(t[lc], p[rc]))) ? d[k] : make_pair(t[lc], r[rc]);

  }

  public:
    seg_tree(int s){
      this->s = s;
      this->n = pow_2((int)ceil(log2(s)));
      init0(t);
      init0(d);
      
      for(int i = 0; i<=n; i++)
        d[i] = make_pair(0, 0);
      
      construct(0, 0, n);
    }
    
    pair<int, int> Q_p(int l, int r, int k, int L, int R){
      if(p[k] <= r) return make_pair(L, p[k]);
      int mid = (L + R) / 2, lc = k*2 + 1, rc = k*2 + 2;
    }

};

int main(){
	
	return 0;
}

