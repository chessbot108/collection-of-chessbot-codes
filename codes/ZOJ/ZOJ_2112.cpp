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

#define max_v 51000
#define M 11000
#define LOGN 130
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
#define init(arr) memset(arr, 0, sizeof(arr))
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

struct query{
  int l, r, k, op, val; //op 0 -> query, 1 -> modify
  query(){}
  query(int a, int b, int c, int op){
    l = a, r = b, k = c, this->op = op;
  }
  query(int k, int val, int op){
    this->k = k, this->val = val, this->op = op;
  }
} queries[M];

int sum[max_v * LOGN], lc[max_v * LOGN], rc[max_v * LOGN];
int arr[max_v], srt[max_v + M], root[max_v], BIT[M], t1[max_v], t2[max_v];
int n, s, q, srt_ind, ind, tnum1, tnum2;
char str[100];

inline int get_ind(int key){
  return lower_bound(srt, srt + srt_ind, key) - &srt[0];
}

void dup(int& k){
  ind++;
  sum[ind] = sum[k];
  lc[ind] = lc[k];
  rc[ind] = rc[k];
  k = ind;
}

void U(int p, int& k, int L, int R){//val assumed to be 1
  if(R <= L || p < L || R <= p) return ;
  dup(k);
  if(L + 1 == R){
    assert(L == p);
    sum[k]++;
    return ;
  }
  
  int mid = (L + R) / 2;
  U(p, lc[k], L, mid);
  U(p, rc[k], mid, R);
}

void make_tree(){
  s = pow_2(LOG2(n));

  for(int i = 1; i<=n; i++){
    int t = arr[i];
    root[i] = root[i - 1];
    U(get_ind(t), root[i], 0, s);
  }

}

void get_BIT(int * t, int& tnum, int k){
  if(k > q) return ;
  t[tnum++] = BIT[k];
  get_BIT(t, tnum, k + lsb(k));
}





int main(){
  int T;
  scanf("%d", &T);

  while(T--){
    //init(sum);
    //init(lc);
    //init(rc); these 3 memset might make TLE
    sum[0] = lc[0] = rc[0] = srt_ind = ind = 0;
    init(arr);
    init(srt);
    init(root);
    init(BIT);
    
    scanf("%d%d", &n, &q);

    for(int i = 0; i<n; i++){
      scanf("%d", &arr[i]);
      srt[srt_ind] = arr[i];
    }

    for(int i = 0; i<q; i++){
      static char str[10];
      scanf("%s", str);
      if(str[0] == 'Q'){
        static int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l--;
        queries[i] = query(l, r, k, 0);
      }else{
        static int k, v;
        scanf("%d%d", &k, &v);
        queries[i] = query(k - 1, val, 1);
        srt[srt_ind++] = val;
      }
    }
    
    sort(srt, srt + srt_ind);
    
    make_tree();
    
    for(int i = 0; i<q; i++){
      query Q = queries[i];
      if(Q.op){
                
      }else{
        tnum1 = tnum2 = 0;
        get_BIT(t1, tnum1, Q.l + 1);
        get_BIT(t2, tnum2, Q.R + 1);

      }
    }

  }

	return 0;
}

