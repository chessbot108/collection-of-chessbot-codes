#include <bits/stdc++.h>
using namespace std;

int n, t;
char arr[100][100];
int num[100][100];

int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(){
  cin >> n >> t;
  int x = 0, y = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
      num[i][j] = -1;
      if(arr[i][j] == 'Z'){
        x = i;
        y = j;
      }
    }
  }
  queue<pair<int, int>> q;
  num[x][y] = 0;
  q.push(make_pair(x, y));
  while(!q.empty()){
    pair<int, int> st = q.front();
    for(int i = 0; i < 4; i++){
      pair<int, int> st2 = st;
      st2.first += moves[i][0];
      st2.second += moves[i][1];
      if(st2.first >= n || st2.second >= n || st2.first < 0 || st2.second < 0 || arr[st2.first][st2.second] == '#' || num[st2.first][st2.second] != -1){
        continue;
      }
      num[st2.first][st2.second] = num[st.first][st.second] + 1;
      q.push(st2);
    }
    q.pop();
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(num[i][j] == t + 1) ans++;
    }    
  }
  cout << ans << endl;
}
