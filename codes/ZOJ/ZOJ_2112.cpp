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
int arr[max_v], srt[max_v + M], root[max_v], BIT[max_v], t1[LOGN], t2[LOGN];
int n, s, q, srt_ind, ind, tnum1, tnum2;

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

void U_seg(int p, int&k, int L, int R){
  if(R <= L || p < L || R <= p) return ;
  dup(k);
  if(L + 1 == R){
    assert(L == p);
    sum[k]++;
    return ;
  }

  int mid = (L + R) / 2;
  U_seg(p, lc[k], L, mid);
  U_seg(p, rc[k], mid, R);
  sum[k] = sum[lc[k]] + sum[rc[k]];
}

void U_BIT(int p, int&k, int L, int R, int val){
  if(R <= L || p < L || R <= p) return ;
  if(!k) dup(k);
  
  if(L + 1 == R){
    assert(L == p);
    sum[k]+= val;
    return ;
  }
  
  int mid = (L + R) / 2;

  U_BIT(p, lc[k], L, mid, val);
  U_BIT(p, rc[k], mid, R, val);
  sum[k] = sum[lc[k]] + sum[rc[k]];
} 

int Q(int kth, int L, int R){
  if(L + 1 == R) return L;
  int s = 0;
  for(int i = 0; i < tnum1; i++)
    s -= sum[lc[t1[i]]];
  
  for(int i = 0; i < tnum2; i++)
    s += sum[lc[t2[i]]];
  
  int mid = (L + R) / 2;
  if(kth <= s){
    for(int i = 0; i<tnum1; i++)
      t1[i] = lc[t1[i]];
    for(int i = 0; i<tnum2; i++)
      t2[i] = lc[t2[i]];

    return Q(kth, L, mid);
  }else{
    for(int i = 0; i<tnum1; i++)
      t1[i] = rc[t1[i]];
    for(int i = 0; i<tnum2; i++)
      t2[i] = rc[t2[i]];

    return Q(kth - s, mid, R); 
  }
  assert(false);
}

int S(int p, int k, int L, int R){
  if(R <= L || p < L || R <= p) return 0;
  if(L + 1 == R) return sum[k];
  int mid = (L + R) / 2;
  return S(p, lc[k], L, mid) + S(p, rc[k], mid, R);
}

int main(){
  //setIO("a");
  int T;
  scanf("%d", &T);
  while(T--){
    init(arr);
    init(srt);
    init(root);
    init(BIT);
    
    scanf("%d%d", &n, &q);
    
    s = pow_2(LOG2(n + q)), ind = 0, srt_ind = 0;
    
    for(int i = 1; i<=n; i++){
      scanf("%d", &arr[i]);
      srt[srt_ind++] = arr[i];
    }

    for(int i = 0; i<q; i++){
      queries[i] = query();
      char c;
      scanf(" %c", &c);
      
      if(c == 'Q'){
        scanf("%d%d%d", &queries[i].l, &queries[i].r, &queries[i].k);
        queries[i].op = 0;
      }else{
        scanf("%d%d", &queries[i].k, &queries[i].val);
        queries[i].op = 1;
        srt[srt_ind++] = queries[i].val;
      }
      //printf("%d %d %d %d %d\n", queries[i].op, queries[i].l, queries[i].r, queries[i].k, queries[i].val);
    }

    sort(srt, srt + srt_ind);

    for(int i = 1; i<=n; i++){
      root[i] = root[i - 1];
      int t = arr[i];
      U_seg(get_ind(t), root[i], 0, s);
      //printf("%d\n", root[i]);
    }
    /** 
    for(int i = 0; i<srt_ind; i++){
      printf("%d -> %d\n", i + 1, srt[i]);
    }
    puts("");

    for(int i = 0; i<=n; i++){
      printf("root %d:\n", i);
      for(int j = 0; j < n + q; j++){
        printf("%d ", S(j, root[i], 0, s));
      }
      puts("");
    }
    **/
    for(int i = 0; i<q; i++){
      query qu = queries[i];

      if(qu.op){
        for(int x = qu.k; x <= n; x += lsb(x)){
          U_BIT(get_ind(arr[qu.k]), BIT[x], 0, s, -1);
          U_BIT(get_ind(qu.val), BIT[x], 0, s, 1);
        }
        arr[qu.k] = qu.val;
      }else{
        tnum1 = tnum2 = 0;
        t1[tnum1++] = root[qu.l - 1];
        for(int p = qu.l - 1; p; p -= lsb(p)){
          t1[tnum1++] = BIT[p];
        }
        t2[tnum2++] = root[qu.r];
        for(int p = qu.r; p; p -= lsb(p)){
          t2[tnum2++] = BIT[p];
        }
        /**
        printf("qu.l %d\n", qu.l);
        for(int i = 0; i<tnum1; i++) printf("%d ", t1[i]);
        printf("\nqu.r %d\n", qu.r);
        for(int i = 0; i<tnum2; i++) printf("%d ", t2[i]);
        puts("");
        **/
        printf("%d\n", srt[Q(qu.k, 0, s)]);
      }
  

    }   


  }
  return 0;
}


