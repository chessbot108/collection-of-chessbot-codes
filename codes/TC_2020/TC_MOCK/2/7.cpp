//code by aaron
#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
  string n;
  cin >> n;
   
 
  int total = 0;
  for(int i = 0; i < n.length(); i++)
    total += n.at(i) - 48;
 
  cout << total << endl;
 
}
