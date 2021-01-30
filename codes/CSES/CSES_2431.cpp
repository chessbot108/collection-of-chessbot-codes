#include <cstdio>
#define ll long long
int main(){
    ll t, a; scanf("%lld", &t);
    while(t--){
        scanf("%lld", &a);
        ll k = a, b = 1, tot = 0ll;
        for(ll i = 1ll; k >= b*i; i++, b*= 10ll){
            k -= b*i;
            tot += 9ll*b;
        }
        tot++;
        printf("%lld %lld %lld\n", tot, k, b);
    }   

    return 0;
}