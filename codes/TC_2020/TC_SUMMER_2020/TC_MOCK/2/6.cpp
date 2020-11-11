//code by daniel

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool check(string s){
  for(int i = 0; i < s.length(); i++){
    if(s[i] != s[s.length()-i-1]){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    if(check(to_string(i))){
      printf("%d\n", i);
    }
  }
}
