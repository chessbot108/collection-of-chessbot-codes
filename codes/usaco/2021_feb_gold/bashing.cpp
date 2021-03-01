#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>

#define cont continue
#define pow_2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) ((a%mod + b%mod)%mod)
#define mul(a, b) ((a%mod * b%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;
const int int_max = 0x3f3f3f3f, max_v = 1e3;
using namespace std;
int cow[max_v][max_v], group[max_v][max_v];

int Q(int d, int x, int y){
  
  int tot = 0;
  for(int i = 0; i<=d; i++){
    if(d >= max_v || x >= max_v || y >= max_v) break;
    tot += cow[x][y];
    x++, y++;
  }
  return tot;
} 






int main(){
	cin.tie(0) -> sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i<max_v; i++){
    for(int j = 0; j<max_v; j++){
      //if(i + 10 == j + 40){ cout << "X"; cont; }
      bool works = true;
      for(int k = 1; k<=max_v; k *= 3){
        if(((i/k)%3) %2 != ((j/k)%3)%2) works = false;
      }
      if(works) cow[i][j]++;
      if(i < 100 && j < 100) cout << ((works) ? "1" : "0");
    }
    if(i < 100) cout << endl;
  }
  for(int i = 0; i<max_v; i++){
    for(int j = 0; j<max_v; j++){
      int k = 1;
      while(k <= max_v){
        if(Q(k, i + 1, j + 1)) break;
        k *= 3;
      }
      if(Q(k, i + 1, j + 1) == 0) group[i][j] = 0;
      else group[i][j] = (log((double)k)/log(3.0)) +1;
      if(i < 100 && j < 100) cout << group[i][j];
    }
    if(i < 100) cout << endl;
  }
  while(n--){
    int a, b, c;
    cin >> a >> b >> c;
    cout << Q(a, b, c) << endl;
  }
	return 0;
}
/**
 * try bashing
 * ll overflow
 * mod negatives
 * debug!!! assert!!!
 * dont forget to take all input
 * time matters!!!
 * dont start coding until you know how to solve it
 * have fun kek
**/

