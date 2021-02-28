#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const long long int_max = 0x3f3f3f3f3f3f3f3f;
long long dist[600][600], n, m, q;
int main(){
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> m >> q;
  memset(dist, 0x3f, sizeof(dist));
  while(m--){
    long long a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    dist[b][a] = min(dist[b][a], c);
  }
  for(int i = 0; i<=n; i++) dist[i][i] = 0;
  for(int k = 1; k<=n; k++){
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=n; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  while(q--){
    int a, b; cin >> a >> b;
    cout << ((dist[a][b] != int_max) ? dist[a][b] : -1) << '\n';
  }
  return 0;
}
