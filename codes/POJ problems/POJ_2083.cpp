#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool p[2600][2600];
int pow_3[10];
void set(int x, int y, bool reg, int size){
  if(size == 0){
    p[x][y] = reg;
    return ;
  }
  else if(!reg){
    return;
  }

  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      set(i*pow_3[size - 1] + x, j*pow_3[size - 1] + y, !((i + j)&1), size - 1);
    }
  }
  


}
int main(){
  
  int tot = 1, n;
  for(int i = 0; i<10; i++){
    pow_3[i] = tot; tot *= 3;
  }
  
  set(0, 0, 1, 7);

  while(scanf("%d", &n)){
    if(n == -1) break;
    
    for(int i = 0; i<pow_3[n-1]; i++){
      for(int j = 0; j<pow_3[n-1]; j++){
        putchar((p[i][j]) ? 'X':' ');
      }
      puts("");
    }
    puts("-");
  }
  
  
  

  return 0;
} 

