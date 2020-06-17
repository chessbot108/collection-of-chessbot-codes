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
#include <deque>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 410000
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << n)
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)ceil(log2((n))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int set_tag[max_v], add[max_v];
long long sum[max_v];
bool marked[max_v];
pair<int, int> arr[220000];  
int siz[max_v];
class seg_tree{
  int s, n;
  //d is min, t is max
  
  void push_down(int k, int L, int R){
    if(L + 1 == R) return; //nothing to push down
    if(marked[k]){
      set_tag[LC(k)] = set_tag[RC(k)] = set_tag[k]; //merge tag
      int mid = (L + R) / 2; 
      sum[LC(k)] = (long long)(mid - L) * (long long)set_tag[k]; //merge sums
      sum[RC(k)] = (long long)(R - mid) * (long long)set_tag[k]; 
      set_tag[k] = 0; //reset tag
      marked[k] = false; //reset mark
      marked[LC(k)] = marked[RC(k)] = true; //mark
    }
  }
  
  void update(int k){
    sum[k] = sum[LC(k)] + sum[RC(k)];
  }

  void S(int qL, int qR, int k, int val, int L, int R){
    //printf("%d %d %d %d %d %d\n", qL, qR, k, val, L, R);
    if(R <= L || R <= qL || qR <= L) return; 
    if(qL <= L && R <= qR){
      set_tag[k] = val;
      sum[k] = (long long)val * (long long)(R - L);
      marked[k] = true;
      return ;
    }

    push_down(k, L, R);
    int mid = (L + R) / 2;
    S(qL, qR, LC(k), val, L, mid);
    S(qL, qR, RC(k), val, mid, R);
    update(k);
  }
  
  long long Q_sum(int qL, int qR, int k, int L, int R){ 
    //printf("%d %d %d %d %d\n", qL, qR, k, L, R);
    if(R <= L || R <= qL || qR <= L) return 0LL;
    if(qL <= L && R <= qR) return sum[k];
    push_down(k, L, R);
    int mid = (L + R) / 2;
    return Q_sum(qL, qR, LC(k), L, mid) + Q_sum(qL, qR, RC(k), mid, R);
  }
  
  void G(int qL, int qR, int k, int L, int R, deque<int>& dq){
    if(R <= L || R <= qL || qR <= L) return;
    if(qL <= L && R <= qR){
      dq.push_back(k);
      return ;
    }
    //push_down(k, L, R);
    int mid = (L + R) / 2;
    G(qL, qR, LC(k), L, mid, dq);
    G(qL, qR, RC(k), mid, R, dq);
  }

  public:

    seg_tree(int s){
      this->s = s;
      this->n = pow_2(LOG2(s));
      memset(sum, 0, sizeof(sum));
      memset(set_tag, 0, sizeof(set_tag));
      memset(marked, false, sizeof(marked));
      for(int i = n - 1; i < n*2; i++){
        arr[i] = make_pair(i - (n - 1), i - (n - 2));
        siz[i] = 1;
      }
      for(int i = n - 2; i >= 0; i--){
        arr[i] = make_pair(arr[LC(i)].first, arr[RC(i)].second);
        siz[i] = siz[LC(i)] * 2;
      }
    }


    void set_val(int l, int r, int val){
      S(l, r, 0, val, 0, this->n);
    }

    long long query_sum(int l, int r){
      return Q_sum(l, r, 0, 0, this->n);
    }
    
    int query_sum(int k){
      return Q_sum(arr[k].first, arr[k].second, 0, 0, this->n);
    }

    deque<int> get_intervals(int l, int r){
      deque<int> dq;
      G(l, r, 0, 0, this->n, dq);
      return dq;
    }

    void print(){
      for(int i = 0; i<(this->n - 1) + this->s; i++){
        printf("%d:\n\tlc->%d, rc->%d\n\tleft_bound->%d, right_bound->%d\n\tsum->%lld\n\tmarked->%d, set_tag->%d\n", i, LC(i), RC(i), arr[i].first, arr[i].second, sum[i],(int) marked[i], set_tag[i]);
      }
      puts("");
    }
    
    void P(){
      for(int i = 0; i<n - 1; i++){
       // printf("arr[%d] == %lld\n",i, query_sum(i, i + 1));
      }
      puts("");
    }
};

seg_tree S(4);

int left_0(const deque<int>& DQ){
  deque<int> dq = DQ;
  while(!dq.empty()){
    int cur = dq.front(); dq.pop_front();
//    printf("%d, %d %d\n", cur, arr[cur].first, arr[cur].second);
    if(S.query_sum(cur) == siz[cur]) cont;
    else if(siz[cur] == 1 && S.query_sum(cur) == 0) return arr[cur].first;
    else dq.push_front(RC(cur)), dq.push_front(LC(cur));
  }
  return -1;
}

int DIE(const deque<int>& DQ){
  deque<int> dq = DQ;
  while(!dq.empty()){
    int cur = dq.back(); dq.pop_back();
    if(S.query_sum(cur) == siz[cur]) cont;
    else if(siz[cur] == 1 && S.query_sum(cur) == 0) return arr[cur].first;
    else dq.push_back(LC(cur)), dq.push_back(RC(cur));
  }
  return -1;
}

int right_0(const deque<int>& DQ, int b){
  int tot = 0;
  deque<int> dq = DQ;
  while(!dq.empty()){
    int cur = dq.front(); dq.pop_front();
 //   printf("%d, %d %d %d %lld\n", cur, arr[cur].first, arr[cur].second, siz[cur], sum[cur]);
    if(tot + siz[cur] - (int)S.query_sum(cur) < b) tot += siz[cur] -(int)S.query_sum(cur);
    else if(tot + 1 == b && S.query_sum(cur) == 0LL && siz[cur] == 1) return arr[cur].first;
    else dq.push_front(RC(cur)), dq.push_front(LC(cur));
  }
  return DIE(DQ);
}


int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int n, q;
    scanf("%d%d", &n, &q);
    S = seg_tree(n);
    S.set_val(0, n, 0);
   // S.print();
    while(q--){
      int t, a, b;
      scanf("%d%d%d", &t, &a, &b);
      //S.print();
      if(t == 1){
        deque<int> temp = S.get_intervals(a, n);
       // for(int X : temp)
       //   printf("%d, %d %d\n", X, arr[X].first, arr[X].second);
       // puts("");
        int L = left_0(temp);// puts("");
        int R = right_0(temp, b);// puts("");
       // assert((L != -1) ^ (R != -1));
        if(L == -1) printf("Can not take any one.\n");
        else{
          //if(R < 0) R = right_0(temp, R * -1);
          assert(R >= 0);
          printf("%d %d\n", L, R);
         // S.P();
          S.set_val(L, R + 1, 1);
         // S.P();
        }

      }else{
        b++;
        printf("%lld\n", S.query_sum(a, b));
       // S.P();
        S.set_val(a, b, 0);
        //S.P();
      }
    }
    
    puts("");
  }

	return 0;
}

