//code by aaron


#include <iostream>
#include <queue>
#define MAXN 2000
using namespace std;
int n;
int ar[MAXN][MAXN] = {0};
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
 
void setup(int i, int j, int index, int count)
{
  if(ar[i][j] != 0)
    return;
  int a, b;
  a = i + y[index];
  b = j + x[index];
  //cout << "A " << a << " " << "B " << b << endl;
  if(a > n || a < 1 || b > n || b < 1 || ar[a][b] != 0)
  {
    int prev = index;
    index++;
    if(index == 4)
      index = 0;
  }
 
  ar[i][j] = count;
   
   
  setup(i + y[index], j + x[index], index, count+1);
}
 
 
int main() {
  cin >> n;
  setup(1 , 1, 0, 1);
  int i, j;
  cin >> i >> j;
  cout << ar[i][j] << endl;
   return 0;
}
