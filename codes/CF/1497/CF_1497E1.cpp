#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val, sz) memset(arr, val, sizeof(arr[0]) * (sz))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 2e5 +10, MXAI = 1e7 + 100, int_max = 0x3f3f3f3f;
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//taking subtask 1 with a simple greedy sweep

int freq[MXAI], arr[MX], low[MXAI], n, k;
vector<int> primes;

void seive(){
  for(int i = 2; i<=1e7; i++){
    if(!low[i]){
      primes.pb(i);
      low[i] = i;
    }
    for(int j = 0; j < primes.size() && primes[j] <= low[i] && i*primes[j] <= 1e7; j++){
      low[i*primes[j]] = primes[j];
    }
  }
}

int norm(int a){
  //normalizing a, or ridding a of all perfect sqaures
  for(int i = a; i != 1; i/=low[i]){
    while(a%(low[i]*low[i]) == 0) a /= (low[i]*low[i]);
  }
  return a;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  seive();
  /**
  for(int i = 2; i<= 100; i++){
    moo("%d %d %d\n", i, low[i], norm(i));
  }
  **/
  int T; cin >> T;
  while(T--){
    cin >> n >> k;
    init(arr, 0, n + 5);
    int ans = 1, st = 0;
    for(int i = 0; i<n; i++){
      cin >> arr[i];
      arr[i] = norm(arr[i]);
      if(freq[arr[i]]){
        ans++;
        //moo("[%d ", st);
        for(int j = st; j<i; j++){
          freq[arr[j]] = 0;
        }
        st = i;
        //moo("%d]\n", st-1);
      
      }
     freq[arr[i]] = 1;
    }
    for(int i = 0; i<n; i++){
      freq[arr[i]] = 0;
    }
    moo("%d \n", ans);
  }
	return 0;
}


