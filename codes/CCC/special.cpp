#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("special.in", "r", stdin);
    freopen("special.out", "w+", stdout);
    long long n; cin >> n;
    int a = 0, b = 0, c = 0;
    while(n%2ll == 0ll){
        n /= 2ll;
        a++;
    }
    while(n%3ll == 0ll){
        n /= 3ll;
        b++;
    }
    while(n%11ll == 0ll){
        n /= 11ll;
        c++;
    }
    cout << a << " " << b << " " << c << '\n';
    return 0;
}