//code by daniel

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  int n; scanf("%d", &n);
  int arr[n][n];

  bool dir = true; // true = up, false = down
  arr[0][0] = 1;
  int i = 0, j = 0, k = 1;
  while(true){
    if(dir == true){
      if(i == 0 || j == n-1){
        if(j == n-1){
          arr[++i][j] = ++k;
        }
        else{
          arr[i][++j] = ++k;
        }
        dir = false;
      }
      else{
        arr[--i][++j] = ++k;
      }
    }
    else{
      if(i == n-1 || j == 0){
        if(i == n-1){
          arr[i][++j] = ++k;
        }
        else{
          arr[++i][j] = ++k;
        }
        dir = true;
      }
      else{
        arr[++i][--j] = ++k;
      }
    }

    if(i == n-1 && j == n-1){
      break;
    }
  }

  for(int a = 0; a < n; a++){
    for(int b = 0; b < n; b++){
      printf("%d ", arr[a][b]);
    }
    printf("\n");
  }
}
