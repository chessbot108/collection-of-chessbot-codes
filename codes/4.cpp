//code by thomas
#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  int size = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n - i - 1; j++){
      cout << " ";
    }
    for(int j = 0; j < size; j++){
      cout << "*";
    }
    cout << endl;
    size += 2;
  }
   return 0;
}
