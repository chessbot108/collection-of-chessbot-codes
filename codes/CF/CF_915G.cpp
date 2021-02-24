#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define max_v 2100000
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
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

const ll mod = 1e9 + 7;

using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
ll m[max_v], low[max_v], vis[max_v], BIT[max_v], fac[max_v];
ll freq[max_v], p[max_v], n, k, ans[max_v], contr[max_v];
//this'll hurt my brain for sure
//mew(1) is 1
//mew(2) is -1
//mew(3) is -1
//mew(6) is 1
//hopefully this'll work for my brick of a brain

ll bin_pow(ll a, ll b){
  ll ans = 1ll;
  for(ll i = 0; pow_2(i) <= b; i++){
    if(b&pow_2(i)){
      ans = mul(ans, a);
    }
    a = mul(a, a);
  }
  return ans;
} 

ll S(int k, ll A){ return (!k) ? A%mod : S(k - lsb(k), A + BIT[k]);}
void U(int k, ll val){ for(; k <=n; k += lsb(k)) BIT[k] += val;}


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  low[1] = mod; //1 -> 0 for a better progression
  m[1] = 1;
  //seive for primes, low[i] is the smallest prime that divides i
  for(int i = 2; i<=2e6; i++){
    if(vis[i]) cont;
    for(int j = i; j<=2e6; j += i){
      if(!vis[j]) low[j] = i;
      vis[j] = 1;
    }
  }
  //compute m, or mobius's function
  for(int i = 2; i <=2e6; i++){
    if(low[i] == i) m[i] = -1;
    else if((i/low[i])%low[i] == 0) m[i] = 0;
    else m[i] = m[i/low[i]] * -1;
    //if(i <= 100) cout << i << ' ' << m[i] << '\n';
  }

  cin >> n >> k;
  //compute each i^n
  for(int i = 1; i<=k; i++){
    p[i] = bin_pow((ll)i, n); 
  }
  ll tot = 0ll;
  
  for(int i = 1; i<=k; i++){
    //ans[i] = ans[i - 1]; //the current answer is similar to the prior one
    /**for(int j = i; j; j /= low[j]){
      ans[i] -= contr[j];  //the only differences are the numbers 
      contr[j] = mul(mod + m[j], p[i/j]);   //that evenly divide i
      ans[i] += contr[j];       //thats what this is for
      (ans[i] += mod*2) %= mod;
      assert(i%j == 0);
    **/
    //ans[i] = ans[i - 1]; //the current answer is similar to the prior one
    //cout << "factors of " << i << " :";
    ans[i] = ans[i - 1];
    int ind = 0;
    for(int j = i; j; j/=low[j]){
      if((j/low[j])%low[j] != 0 && j != 1){
        fac[ind++] = low[j];
      } 
    }
    for(int b = 0; b < pow_2(ind); b++){
      int x = 1;
      for(int j = 0; j<ind; j++) if(b&pow_2(j)) x *= fac[j];
      //cout << " " << x;
      ans[i] += mod - contr[x];
      //U(x, mod -contr[x]);
      contr[x] = ((m[x] * p[i/x])+mod)%mod;
      //U(x, mod + contr[x]);
      ans[i] += mod + contr[x];
    }
    //cout << endl;
    //for(int j = 1; j<=n; j++) ans[i] += contr[j];
    //ans[i] += S(n, 0ll);
    
    ans[i] %= mod; 
    //cout << i << ' ' <<  ans[i] << ' ' << (int)(ans[i]^(ll)i)%mod << endl;
    tot += ans[i] ^ (ll)i;
  }
  
  cout << tot%mod << '\n'; //WHY IS IT WA. WHY WHY WHY
  return 0;
}
