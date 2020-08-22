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

using namespace std;
#define MAXN 100

int n;

int ar[MAXN]['Z' + 5];

int travel['Z' + 5] = {0};

int test(int s, int shift, int z, int k)
{
  int counter = -1;
  int t = 0;
  for(int i = shift; i < min(z + shift, k); i++)
  {
    counter++;
    if(i >= 0)
    {
      if(travel[counter] > 0 && travel[counter] == ar[s][i])
        t++;
    }
  }
  return t;
}

int main() {
  cin >> n;

  int k;
  int total = 0;
  cin >> k;

  for(int i = 0; i < n; i++)
    cin >> ar[i][0];

  char a;
  for(int i = 0; i < k; i++)
  {
    cin >> a;
    travel[i] = a;
  }


  for(int i = 0; i < n; i++)
  {
    int index = ar[i][0];
    for(int j = 0; j < index;j ++)
    {
      cin >> a;
      ar[i][j] = a;
    }

    int g = 0;
    for(int j = -index + 1; j < index; j++)
    {
      g = max(g, test(i, j, index, k));
    } 

    total += g;
    cout << i << " " << g << endl;
  }

  cout << total << endl;

  return 0;
}
