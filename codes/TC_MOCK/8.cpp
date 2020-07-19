//code by thomas
#include <iostream>
#include <cstdio>
using namespace std;
 bool prime[1000010];
  int sum[1000010]; 
  
int main(){
  int t;
  scanf("%d", &t);
 for(int i = 0; i < 1000010; i++){
    prime[i] = true;
    sum[i] = 0;
  }
  prime[0] = false;
  prime[1] = false;
  for(int i = 2; i*i < 1000010; i++){
    if(prime[i]){
      for(int j = i*i; j <= 1000010; j+=i){
        prime[j] = false;
      }
    }
  }
  for(int i = 1; i < 1000010; i++){
    sum[i] = sum[i - 1];
    if(prime[i]) sum[i]++;
  }
  while(t--){
    int n;
    scanf("%d", &n);
    printf("%d\n", sum[n]);
  }
  return 0;
}
