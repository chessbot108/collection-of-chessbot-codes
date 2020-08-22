//code by aaron
#include <iostream>
#include <string>
using namespace std;
string a, b;
int main() {
  cin >> a >> b;
  string cur;
  if(b.length() > a.length())
  {
    string temp = a;
    a = b;
    b = temp;
  }
  int l = b.length();
  int q = a.length();
  int remainder = 0;
  for(int i = 1; i <= l; i++)
  {
    int k = b.at(l - i) - 48;
    int p = a.at(q - i) - 48;
    int c = k + p + remainder;
    cur = to_string(c % 10) + cur;
    remainder = c / 10;
  }

  for(int i = q - l - 1; i >= 0; i--)
  {
    int k = a.at(i) - 48;
    int c = k + remainder;
    cur = to_string(c % 10) + cur;
    remainder = c / 10;
  }
  if(remainder > 0)
    cur = to_string(remainder) + cur;
  cout << cur << endl;
  return 0;
}
