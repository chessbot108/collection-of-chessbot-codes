//code by aaron
#include <iostream>
#include <queue>
using namespace std;
int n;
int main() {
  cin >> n;
  priority_queue<pair<int, int>> q;
  int a, b;
  for(int i = 0; i < n; i++)
  {
    cin >> a >> b;
    q.push(make_pair(a + b, a));
  }

  for(int i = 0; i < n; i++)
  {
    pair<int, int> top = q.top();
    q.pop();
    cout << top.second << " " << top.first - top.second << endl;
  }
  return 0;
}
