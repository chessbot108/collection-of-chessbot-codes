#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <set>

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
#define init(arr, val) memset(arr, val, sizeof(arr))
//geniousity limit exceeded
#define moo printf
#define oom scanf
const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

vector<int> primes, adj[MX*10], adj2[MX];
int vis[MX], arr[MX], n;
set<int> st;

void seive(){
  for(int i = 2; i<=1e6; i++){
    if(!vis[i]) primes.pb(i);
    else cont;
    for(int j = i; j <= 1e6; j += i){ vis[j] = 1; adj2[j]pb(i); }
  }
}

int norm(int a){
  for(int i = 0; i < primes.size(); i++){
    if(primes[i]*primes[i] > a) cont;
    if(a%(primes[i]*primes[i] == 0)) return a/(primes[i]*primes[i]);
  }
  return a;
}

int solve(){
  cin >> n;
  seive();
  for(int i = 0; i<n; i++){
    cin >> arr[i]; arr[i] = norm(arr[i]);
    if(arr[i] == 1) return 1;
    if(st.count(arr[i])) return 2;
    st.insert(arr[i]);
  }
  sort(arr, arr + n);
  for(int i = 0; i<n; i++){
    if(adj2[arr[i]].size() == 1){
      adj[1].pb(adj2[arr[i]][0]);
      adj[adj2[arr[i]][0]].pb(1);
    }else{
      assert(adj2[arr[i]].size() == 2);
      adj[adj2[arr[i]][0]].pb(adj2[arr[i]][1]);
      adj[adj2[arr[i]][1]].pb(adj2[arr[i]][0]);
    }
  }

}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	return 0;
}


