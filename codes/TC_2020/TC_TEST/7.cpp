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
#define MAXN 1005

using namespace std;

int ar[MAXN];
int change[MAXN];
int n;

void calculate()
{
  for(int i = 1; i < 6; i++)
  {
    if(ar[i] > ar[i + 1])
    {
      change[i + 1] += ar[i] / 2;
      change[i] -= ar[i] / 2;
    }
  }
  if(ar[6] > ar[1])
  {
    change[1] += ar[6] / 2;
    change[6] -= ar[6]/2;
  }
}

void update()
{
  for(int i = 1; i <= 6; i++)
  {
    ar[i] += change[i];
    change[i] = 0;
  }
}

int main() {
  cin >> n;
  for(int i = 1; i <= 6; i++)
  {
    cin >> ar[i];
  }

  for(int i = 0; i < n; i++)
  {
    calculate();
    update();
  }

  for(int i = 1; i <= 6; i++)
  {
    cout << ar[i] << endl;
  }

}

/**
input:
2
1 2 3 4 5 6
output:
2
4
3
4
3
5

input: 
2
5 7 8 10 12
output:
12 
6
12
8
10
6
12
 **/
