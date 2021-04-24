//code by daniel. aaron worked on this, but daniel's code was much cleaner
#include <iostream>
#include <vector>

using namespace std;

string s1, s2;

string multiply(){
  int len1 = s1.length();
  int len2 = s2.length();
  if (len1 == 0 || len2 == 0){
    return "0";
  }

  vector<int> v(len1 + len2, 0);

  int i1 = 0;
  int i2 = 0;

  for (int i = len1 - 1; i >= 0; i--){
    int carry = 0;
    int n1 = s1[i] - '0';

    i2 = 0;
    for (int j = len2 - 1; j >= 0; j--){
      int n2 = s2[j] - '0';
      int sum = n1*n2 + v[i1 + i2] + carry;
      carry = sum/10;
      v[i1 + i2] = sum % 10;

      i2++;
    }

    v[i1 + i2] += carry;

    i1++;
  }

  int i = v.size() - 1;
  while (i >= 0 && v[i] == 0){
    i--;
  }

  if (i == -1){
    return "0";
  }

  string ret = "";

  while (i >= 0){
    ret += to_string(v[i--]);
  }

  return ret;
}

int main(){
  cin >> s1 >> s2;
  cout << multiply() << endl;
  return 0;
}
