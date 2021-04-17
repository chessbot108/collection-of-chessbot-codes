#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <set>

#define cont continue
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert

#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))

#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline
#define orz assert

const ll mod = 1e9 + 7;
const int MX = 3e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
  freopen((file_name+".in").c_str(), "r", stdin);
  freopen((file_name+".out").c_str(), "w+", stdout);
}

char str[10][MX];
char ans[MX * 2], temp[MX * 2];
int n;
bool splice(int a, int b){
  //moo("%d %d\n", a, b);
  for(int i = 0; i<n*3+5; i++) temp[i] = 0;
  int j = 0, i, k = 0;
  for(i = 0; i < n * 2; i++){
    while(j < n * 2 && str[a][i] != str[b][j]){
      //moo("%d %d, %c %c %d, %s\n", i, j, str[a][i], str[b][j], k, temp);
      temp[k++] = str[b][j];
      j++;
    }
    temp[k++] = str[a][i];
    j++;
    //moo("temp: %s\n", temp);
  }
  if(k <= n * 3){
    for(; k < 3 * n; k++){
      temp[k] = '0'; //padding
    }
    return 1;
  }
  else return 0;
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--){
    scanf("%d", &n);
    for(int i= 0; i<3; i++){
      for(int j = 0; j<n*2 +5; j++) str[i][j] = 0;
      scanf("%s", str[i]);
      //for(int j =0; j<n*2; j++) str[i][j] = (rng()%2) + '0';
      //moo("%s\n", str[i]);
      assert(strlen(str[i]) == n * 2);
    }
    //if(!(strcmp(str[0], str[1]) && strcmp(str[1], str[2]) && strcmp(str[0], str[2]))) cont;

    for(int i = 0; i<3; i++){
      for(int j = 0; j<3; j++){
        if(i == j) cont;
        if(splice(i, j)){
          for(int k = 0; k<n*3; k++) ans[k] = temp[k];
          i = j = 4;
        }
      }
    }
    ans[n*3] = 0;
    //moo("%d\n", strlen(ans));
    moo("%s\n", ans);
  }

  return 0;
}


