//i deleted some functions and whatnot on this code
//refer to https://cses.fi/paste/1274e6e269ddec07170192/ 
//for more modularized and more scuffed code (actually dont)
//i made it my goal to make this code as short and unreadable as possible hahahahah
//jokes on you and me in future when i face this problem again.

#include <cstdio>
 
#define max_v 110000
#define cont continue
#define pow_2(n) (1 << (n))

const long long mod = (long long)(1e9 + 7);
 
long long fac[max_v], cnt[max_v], occ[max_v], term[max_v], pre[max_v], suf[max_v];
int n;
  
long long mul(long long a, long long b, long long mod = 1e9 + 7){
  return ((a % mod) * (b % mod)) % mod;
}

long long bin_pow(long long a, long long b){
  long long ans = 1ll;
  for(long long i = 1ll; i<=b; i <<= 1ll){
    if(i&b) ans = mul(a, ans);
    a = mul(a, a);
  }
  return ans;
}
  
int main(){
	scanf("%d", &n);
  
  long long factors = 1ll, product = 1ll, sum = 1ll;
  pre[0] = suf[n + 1] = 1ll;
  
  for(int i = 1; i<=n; i++){
    scanf("%lld%lld", &fac[i], &cnt[i]);
    factors = mul(factors, cnt[i] + 1ll);
    pre[i] = mul(pre[i - 1], cnt[i] + 1ll, mod - 1ll);
  }
  
  for(int i = n; i; i--){ 
    suf[i] = mul(suf[i + 1], cnt[i] + 1ll, mod - 1ll);
    occ[i] = mul(mul(pre[i - 1], suf[i + 1], mod - 1ll), ((cnt[i] * (cnt[i] + 1ll)) / 2), mod - 1ll);
    sum = mul(sum, mul(bin_pow(fac[i], cnt[i] + 1ll) - 1ll, bin_pow(fac[i] - 1ll, mod - 2ll)));
    product = mul(product, bin_pow(fac[i], occ[i] % (mod - 1ll)));
  }
 
  printf("%lld %lld %lld\n", factors, sum, product);
  
  return 0;
}
