#include <cstdio> //casually deletes all STL lib since i can't use "head" if i include them
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#define max_v 5010
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

const long long mod = 1e9 + 7;
int  dp[max_v][max_v];
int c[max_v], s[max_v], groups[120];
int n, m, k;

int bin_pow(int a, int b){
  //a^b % c;
  long long ans = 1ll;
  long long ind = (long long)a;
  for(int i = 0; pow_2(i) <= b; i++){
    if(b & pow_2(i)){
      ans *= ind;
      ans %= mod;
    }
    ind = (ind * ind) % mod;

  }
  return ans;
}


int main(){
  //freopen("poetry.in", "r", stdin);
  //freopen("poetry.out", "w+", stdout);
	scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i<n; i++){
    scanf("%d%d", &s[i], &c[i]);
  }
  for(int i = 0; i<m; i++){
    static char str[10];
    scanf("%s", str);
    groups[str[0]]++;
  }
  
  dp[0][0] = 1;
  for(int i = 0; i<=k; i++){
    int t = 0;
    for(int j = 0; j<=n; j++) t = (t + dp[i][j]) % mod;
    
    for(int j = 0; j<n; j++){
      
      if(i + s[j] < max_v) (dp[i + s[j]][c[j]] += t) %= mod;

      //printf("%3d", dp[i][j]);
    }
    //puts("");
  }
  
  long long ans = 1ll;
  
  for(int i = 'A'; i<='Z'; i++){
    long long temp = 0ll;
    if(groups[i] == 0) cont;
    for(int j = 1; j<=n; j++){ //over every group, if none in group, dp would be 0 so no effect
      (temp += (long long)bin_pow(dp[k][j], groups[i])) %= (long long)mod;
    }
    //printf("for %d there are %lld ways\n", i, temp);
    ans *= temp;
    ans %= (long long)mod;
  }

  printf("%lld\n", ans);


	return 0;
}

