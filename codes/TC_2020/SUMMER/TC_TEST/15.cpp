#include <bits/stdc++.h>
using namespace std;

//code by thomas;

struct juice{
  int v, q;
};

juice arr[30];
int dp[30][600];
int n;

int dfs(int cur, int s){
  if(cur == n){
    if(s == 0){
      return 1;
    } else {
      return -1000000;
    }
  }   
  if(dp[cur][s] != -1) return dp[cur][s];
  dp[cur][s] = 0;
  for(int i = 0; i <= arr[cur].q; i++){
    int tmp = dfs(cur + 1, s - (arr[cur].v * i));
    if(tmp > 0){
      dp[cur][s] += tmp;
    }
  }
  return dp[cur][s];
}

int main(){
  int s;
  cin >> n >> s;
  for(int i = 0; i < 30; i++){
    for(int j = 0; j < 600; j++){
      dp[i][j] = -1;
    }
  }
  for(int i = 0; i < n; i++){
    cin >> arr[i].q >> arr[i].v;
  }
  cout << dfs(0, s) << endl;
}
