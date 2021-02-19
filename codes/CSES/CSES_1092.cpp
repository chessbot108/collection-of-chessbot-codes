#include <iostream>
using namespace std;
long long vis[1100000], n, x, tot, cnt;
int main(){
  cin >> n;
  x = ((n)*(n+1ll))/4;
  if(n*(n+1ll) != x*4ll){
    cout << "NO\n";
  }else{
    cout << "YES\n";
    for(int i = n; i>=1; i--){
      if(tot + i <= x){
        tot += i;
        vis[i] = true;
        cnt++;
      }
    }
    cout << cnt << "\n";
    for(int i = 1; i<=n; i++){
      if(vis[i]) cout << i << " ";
    }
    cout << "\n" << n - cnt << "\n";
    for(int i = 1; i<=n; i++){
      if(!vis[i]) cout << i << " ";
    }
    cout << "\n";
  }
  
  return 0;
}
