#include <iostream>
using namespace std;
const int max_v = 2e5 +10, LOGN = 30;
int super[max_v][LOGN+10], n, q;

void precomp(){
    for(int j = 1; j<LOGN; j++){
        for(int i = 1; i<=n; i++){
            super[i][j] = super[super[i][j - 1]][j - 1];
            //cout << "super of " << i <<  " " << j << " " << super[i][j] << '\n';
        }
    }
}

int k_up(int u, int k){
    for(int i = LOGN -1; i >= 0; i--){
        //cout << u << " " << i << " " << super[u][i] << '\n';
        if(k >= (1 << i)) k = k - (1 << i), u = super[u][i];
        
    }
    return u;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1; i<=n; i++){
        cin >> super[i][0];
    }
    precomp();
    while(q--){
        int u, k; cin >> u >> k;
        cout << k_up(u, k) << '\n';
    }
    return 0;
}