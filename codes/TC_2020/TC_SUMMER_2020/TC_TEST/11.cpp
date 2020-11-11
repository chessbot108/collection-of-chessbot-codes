#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>
#define MAXN 25
using namespace std;

bool vis[MAXN] = {0};
double ar[MAXN];
int n;
double p;

int dfs(int i,  double amount, int step)
{
  vis[i] = true;
  int mini = 30;
  for(int j = i + 1; j < n; j++)
  {
    //cout << "VIS " << j << " AMOUNT " << ar[j] - ar[i] << endl;
    if(!vis[j] && ar[j] - ar[i] > 0)
    {
      //cout << "IN" << endl;
      if(amount + ar[j] - ar[i] >= p)
        mini = min(mini, step);
      //cout << "MIN1 " << mini << endl;
      vis[j] = true;
      for(int k = i + 1; k < n; k++)
      {
        if(!vis[k])
        {
          mini = min(mini, dfs(k, amount + ar[j] - ar[i], step+1));
        }
      }
      //cout << "MIN " << mini << endl;
      vis[j] = false;
    }
  }
  vis[i] = false;
  return mini;
}

int main() {
  cin >> n >> p;
  for(int i = 0; i < n ;i++)
  {
    cin >> ar[i];
  }

  int mini = dfs(0, 0, 1) * 2;
  for(int i = 1; i < n; i++)
  {
    mini = min(mini, dfs(i, 0, 1) * 2);
  } 
  cout << mini << endl;
}
