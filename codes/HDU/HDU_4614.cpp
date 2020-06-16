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

  public:

    seg_tree(int s){
      this->s = s;
      this->n = pow_2(LOG2(s));
      memset(sum, 0, sizeof(sum));
      memset(set_tag, 0, sizeof(set_tag));
      memset(marked, false, sizeof(marked));
    }


    void set_val(int l, int r, int val){
      S(l, r, 0, val, 0, this->n);
    }

    long long query_sum(int l, int r){
      return Q_sum(l, r, 0, 0, this->n);
    }
    
    void print(){
      for(int i = 0; i<(this->n - 1) + this->s; i++){
        printf("%d:\n\tlc->%d, rc->%d\n\tsum->%lld\n\tset_tag->%d\n", i, LC(i), RC(i), sum[i], set_tag[i]);
      }
      puts("");
    }

};


int main(){
  
  

	return 0;
}

