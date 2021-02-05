#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <cstring>
#define ll long long
using namespace std;
const int max_v = 1e5 + 100;
ll A[max_v], B[max_v];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    for(int tc = 1; tc<=t; tc++){
        int n, m; cin >> n >> m;
        for(int i = 0; i<n; i++) cin >> A[i];
        for(int j = 0; j<m; j++) cin >> B[j];
        int j = 0, k = 0, sz = 1; ll ans = 0;
        while(j < n || k < m){
            if(k == m || (j < n && A[j] > B[k])){
                ans += (ll)sz++ * A[j++];
            }else{
                ans += (ll)sz++ * B[k++];
            }
        }
        assert(n + m + 1 == sz);
        printf("Case %d: %lld\n", tc, ans);
    }
    return 0;
}