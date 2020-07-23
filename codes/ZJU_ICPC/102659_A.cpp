#include <iostream>
#include <queue>
#define MAXN 2025
using namespace std;
int n, m;
int row[MAXN];
int col[MAXN];
bool vis[MAXN][MAXN];
int track[MAXN][MAXN];
int count = 0;
int total = 0;
int main() {
  cin >> n >> m;
  total = n * n;
  queue<pair<int , int>> pq;
  pq.push(make_pair(n, n));

  while(!pq.empty())
  {
    pair<int, int> p = pq.front();
    pq.pop();
    int a = p.first;
    int b = p.second;
    //cout << a << " " << b << endl;
    vis[a][b] = true;
    int counter = 0;
    bool flag = true;
    if(a -1 >= 0 && !vis[a - 1][b])
      pq.push(make_pair(a - 1, b));
    if(b - 1 >= 0 && !vis[a][b - 1])
      pq.push(make_pair(a, b - 1));
    while(flag)
    {
      if(a - counter <= 0 || b - counter <= 0) 
      {
        flag = false;
      }
      else
      {
      if(n - col[a - counter] > m && n - row[b - counter] > m)
        count++;

      //cout << a - counter << " " << b - counter << " " << flag << endl;
      col[a - counter] ++;
      row[b - counter]++;
      vis[a - counter][b-counter] = true;
      track[a - counter][b-counter] = total;
      counter++;
      

      total--;
      }
    }
  }

  cout << count << endl;

  for(int i = 1; i <= n; i++)
  {
    for(int j = 1; j <= n;j ++)
    {
      cout << track[i][j] << " ";
    }
    cout << endl;
  }
  
}
