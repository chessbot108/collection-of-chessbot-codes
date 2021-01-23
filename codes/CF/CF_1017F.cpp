#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define ll long long
#define cont continue
#define mul(x, y) (((x&mod) * (y&mod))&mod)
#define add(x, y) (((x&mod) + (y&mod))&mod)
using namespace std;

const ll mod = (1ll << 32ll) -1ll;
ll n, a, b, c, d, sz = 0;

ll eval(ll x){
    return add(add(mul(mul(a, x), mul(x, x)), mul(b, mul(x, x))), add(mul(c, x), d));
}

ll primes[(int)1e6];

int main(){


    cin >> n >> a >> b >> c >> d;

    for(int i = 2; i<=n; i++){
        primes[sz++] = (ll)i;
        for(int j = 0; j<sz - 1 && primes[j]*primes[j]<=i; j++){
            if(!(i%primes[j])){
                sz--;
                break;
            }
        }      
    }
    ll ans = 0ll;
    for(int i = 0; i<sz; i++){
        for(ll j = primes[i]; j <= n; j *= primes[i]){
            ans += eval(primes[i]) * (n/j);
        }
    }
    cout << ans << endl;


    return 0;
}

