#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cassert>
#define st(a, b) memset(a, 0, sizeof(int)* (b+10))
#define max_v (int)3e5 +100
using namespace std;
int ansL[max_v][3], ansR[max_v][3], L[max_v][3], R[max_v][3];
int n, t;
char str[max_v];
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%s", str);
        st(ansL, n); st(ansR, n); st(L, n); st(R, n);
        
        for(int i = 1; i<=n; i++){
            if(str[i - 1] == 'L'){
                L[i][0] = 1;
                R[i - 1][1] = 1;
            }else{
                L[i][1] = 1;
                R[i - 1][0] = 1;
            }
        }
        ansL[0][0] = ansL[0][1] = ansR[n][0] = ansR[n][1] = 0;
        for(int i = 1; i<=n; i++){
            ansL[i][0] = (L[i][0] > 0) ? ansL[i - 1][1] + 1 : 0;
            ansL[i][1] = (L[i][1] > 0) ? ansL[i - 1][0] + 1 : 0;
            //printf("%d -> %d %d; %d %d\n", i, L[i][0], L[i][1], ansL[i][0], ansL[i][1]);
        }
        
        for(int i = n - 1; i>=0; i--){
            ansR[i][0] = (R[i][0] > 0) ? ansR[i + 1][1] + 1 : 0;
            ansR[i][1] = (R[i][1] > 0) ? ansR[i + 1][0] + 1 : 0;
            //printf("%d -> %d %d; %d %d\n", i, R[i][0], R[i][1], ansR[i][0], ansR[i][1]);
        }

        for(int i = 0; i<=n; i++){
            printf("%d ", ansR[i][0] + ansL[i][0] + 1);
        }
        puts("");

    }



    return 0;
}