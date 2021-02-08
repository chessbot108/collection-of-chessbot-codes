#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

ll tri(ll l, ll w, ll h){
    return (l * w * h)/20ll;
}

ll rect(ll l, ll w, ll h){
    return (l * w * h)/30ll;
}

ll pris(ll l, ll w, ll h){
    return (l * w * h)/10ll;
}


int main(){
    freopen("presents.in", "r", stdin);
    freopen("presents.out", "w+", stdout);
    int n; cin >> n;
    ll ans = 0ll;
    while(n--){
        ll a, b, c, d; char op;
        cin >> a >> op >> b >> c >> d;
        ans += ((op != 'r') ? ((op != 't') ? rect(b, c, d) : tri(b, c, d)) : pris(b, c, d)) + (a/10ll) * 5ll;
    }
    cout << ans << '\n';
    return 0;
}