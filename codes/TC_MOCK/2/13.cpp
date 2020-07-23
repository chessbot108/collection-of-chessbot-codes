//code by aaron. we never submitted it
#include <bits/stdc++.h>
#define MAXN 110000
using namespace std;
int n, m;
vector<int> ar[MAXN];

bool visited[MAXN];


int dfs(int a, int depth)
{
  int g = 0;
  visited[a] = true;
  for(int x : ar[a])
  {
    if(!visited[x])
      g = max(g, dfs(x, depth + 1));
  }
  return g;
}

int main() {

  cin >> n >> m;
  int a, b;
  for(int i = 0; i < m; i++)
  {
    scanf("%d%d", &a, &b);
    ar[a].push_back(b);
    ar[b].push_back(a);
  }

  int cur = 0x3f3f3f3f;
  vector<int> v;
  for(int i = 1; i <= n; i++)
  {
    memset(visited, 0, sizeof(visited));
    int g = dfs(i, 0);
    if(g < cur)
    {
      v.clear();
      cur = g;
      v.push_back(i);
    }
    else if(g == cur)
    {
      v.push_back(i);
    }
  }


  for(int x : v)
  {
    printf("%d ", x);
  }
  cout << endl;
}
