#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

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
const int max_v = 4e5 +10, int_max = 0x3f3f3f3f, LOGN = 40;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}
//min pst, let's do this

int root[max_v], low[max_v], arr[max_v], fac[LOGN], primes[max_v], cnt[LOGN], vis[max_v];
int mn[max_v * LOGN], rc[max_v * LOGN], lc[max_v * LOGN];
ll contr[max_v], ans = 1ll;
//root[i] is the pst of i
int n, q, sz= 0, s = 1, ind = 0;
void precomp(){
  for(int i = 2; i<=2e5; i++){
    if(vis[i]) cont;
    primes[sz++] = low[i]= i;
    for(int j = i * 2; j<=2e5; j += i){
      if(!vis[j]){
        vis[j] = 1;
        low[j] = i;
      }
    }
  }
}

void U(int p, int val, int& k, int L, int R){
  //cout << k << " " << L << " " << R << endl;
  if(k == 0) k = ++ind; 
  if(L + 1 == R){
    assert(L == p);
    mn[k] += val;
    return ;
  }
  int mid = (L + R)/2;
  if(p < mid) U(p, val, lc[k], L, mid);
  else U(p, val, rc[k], mid, R);
  mn[k] = min(mn[lc[k]], mn[rc[k]]);
  //cout << k << " " << L << " " << R << " " << mn[lc[k]] << " " << mn[rc[k]] << " " << lc[k] << " " << rc[k] << endl;
}

int Q(int qL, int qR, int k, int L, int R){
  if(qR <= L || R <= qL || R <= L) return (R <= n) ? 0 : int_max;
  if(qL <= L && R <= qR){
    //cout << "for queries " <<  qL << " " << qR << " " << k << " " << L << " " << R <<  " " << mn[k] << endl;
    return mn[k]; 
  }
  int mid = (L + R)/2;
  return min(Q(qL, qR, lc[k], L, mid), Q(qL, qR, rc[k], mid, R));
}


int gcd(int a, int b){
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

void update(int k, int val, int op){
  int tot = 0;
  //fac[0] = low[val];
  //cout << k << " " << val << endl;
  init(cnt, 0);
  init(fac, 0);
  for(int i = val; i != 1; i /= low[i]){
    
    //cout << "\t" << low[i] << " " << tot << " " << cnt[tot] << " " << fac[tot] << endl;
    if(low[i] != fac[tot]) tot++;

    fac[tot] = low[i];
    cnt[tot]++;
  }
  //cout << "fac gen done" << endl;
  for(int i = 1; i<=tot; i++){
    
    int old = Q(0, n, root[fac[i]], 0, s);
    U(k, cnt[i], root[fac[i]], 0, s);
    int nuw = Q(0, n, root[fac[i]], 0, s);
    //cout << i << " " << fac[i] << " " << cnt[i] << " " << old << " " << nuw << endl;
    while(nuw-- > old){
      ans = mul(ans, fac[i]);
    }
    //cnt[i] = fac[i] = 0;
  }
  if(op) cout << ans << '\n';
}



int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> q;
  while(s <= n) s *= 2;
  
  precomp();
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    update(i, arr[i], 0);
  }
  /**
  ans = (ll)arr[0];
  
  for(int i = 1; i<n; i++){
    ans = (ll)gcd(ans, arr[i]);
  }
  **/
  while(q--){
    int k, val;
    cin >> k >> val;
    update(k - 1, val, 1);
  }
	return 0;
}


