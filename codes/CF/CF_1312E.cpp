#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>

#define cont continue
#define pow_2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))

const ll mod = 1e9 + 7;
const int MX = 550, int_max = 0x3f3f3f3f;
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int dp[MX][MX], val[MX][MX];
int arr[MX*2], n;

/**
dp[i][j] is min elements formed by merging [i...j)
if dp[i][j] == 1, val[i][j] is the value if the merge
**/


int main(){
	cin.tie(0) -> sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i<=n; i++){
    cin >> arr[i];
  }
  memset(dp, 0x3f, sizeof(dp));
  for(int i = 1; i<=n; i++){
    dp[i][i + 1] = 1;
    val[i][i + 1] = arr[i];
  }

  for(int len = 1; len <= n; len++){
    for(int i = 1; i + len + 1 <=n + 1; i++){
      int j = i + len + 1;
      for(int k = i + 1; k<j; k++){
        //cout << "\t" << i << " " << k << " " << j << " " << dp[i][k] << " " <<  dp[k][j] << endl;
        if((dp[i][k] == 1 && dp[k][j] == 1) && (val[i][k] == val[k][j])){
          dp[i][j] = 1, val[i][j] = val[i][k] + 1; 
        }else{
          //cout << "the else case " << endl;
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
      //cout << "all contrib to" << endl;
      //cout << i << " " << j << " " << dp[i][j] << endl;
    }
  }
  cout << dp[1][n + 1] << '\n';
	return 0;
}


