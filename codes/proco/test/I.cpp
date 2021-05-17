//code by bckt
#include <iostream>
#include <map>
#include <set>
#include <utility>
 
using namespace std;
 
#define ll long long
#define MAXN 500500
 
ll n, arr[MAXN], avg = 0;
ll old[MAXN];
map<ll,ll> cnt;
ll offset = 0; // to be added to keys before checking
 
int main() {
 
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        old[i] = arr[i];
        avg += arr[i];
    }
    avg /= n;
 
    for (int i = 1; i < n; i++)
        arr[i] += arr[i-1];
    for (ll i = 0; i < n; i++)
        arr[i] -= (i + 1) * avg;
 
    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;
 
    ll ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, n - cnt[-offset]);
 
        ll cval = old[i] - avg;
        cnt[cval - offset]--;
 
        offset -= old[i];
        offset += avg;
 
        cnt[-offset]++;
 
    }
 
    printf("%lld\n", ans);
 
 
}
 
