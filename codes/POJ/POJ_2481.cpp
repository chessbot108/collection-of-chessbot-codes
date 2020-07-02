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

#define max_v 210000
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

vector<pair<int, int> > cows, srt;
int BIT[max_v], ans[max_v], same[max_v], n;

int S(int k){
  if(!k) return 0;
  return BIT[k] + S(k - lsb(k));
}

void U(int k){
  if(k >= max_v) return ;
  BIT[k]++;
  U(k + lsb(k));
}

int get_ind(const pair<int, int>& key) { return lower_bound(srt.begin(), srt.end(), key) - srt.begin();}

int main(){
	while(scanf("%d", &n)){
    if(!n) break;
    memset(same, 0, sizeof(same));
    memset(BIT, 0, sizeof(BIT));
    memset(ans, 0, sizeof(ans));
    cows.clear(); srt.clear();

    for(int i = 0; i<n; i++){
      int x, y;
      scanf("%d%d", &x, &y);
      cows.push_back(make_pair(x, 100001 - y));
      srt.push_back(make_pair(x, 100001 - y));
    }

    sort(srt.begin(), srt.end());

    for(int i = 0; i<n; i++){
      ans[i] = S(srt[i].second + 1) - same[get_ind(srt[i])];
      U(srt[i].second + 1);
      same[get_ind(srt[i])]++;
    }
    
    for(int i = 0; i<n; i++){
      printf("%d ", ans[get_ind(cows[i])]);
    }
    puts("");


  }
  

	return 0;
}

