#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int max_v = 5500;
ll dist[max_v], w[max_v];
int u[max_v], v[max_v], n, m;

ll bellman(int a, int b){
    memset(dist, 0xbf, sizeof(dist));
    dist[a] = 0ll;
    for(int i = 0; i<n - 1; i++){
        for(int j = 0; j<m; j++){
            dist[v[j]] = max(dist[v[j]], dist[u[j]] + w[j]);
        }
    }
    for(int i = 0; i<m; i++){
        if(dist[v[i]] < dist[u[i]] + w[i]) return -1ll;
    }
    return dist[b];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    cout << bellman(1, n) << '\n';

    return 0;
}