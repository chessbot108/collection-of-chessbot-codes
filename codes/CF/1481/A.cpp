#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_v = 1e5 + 10;

//the general idea is that i only have to count the direct moves towards (px, py)
//if (px, py) is right and up from the origin, 
//i only need to count the right moves and the up moves
//i think this greedy works
char str[max_v];
int freq[130];

int main(){
    int t; scanf("%d", &t);
    while(t--){
        memset(freq, 0, sizeof(freq));
        int x, y, n;
        scanf("%d%d%s", &x, &y, str);
        n = strlen(str);
        
        for(int i = 0; i<n; i++){
            freq[str[i]]++;
        }

        int hor = (x < 0) ? freq['L'] : freq['R'];
        int ver = (y < 0) ? freq['D'] : freq['U'];
        printf("%s\n", (hor >= abs(x) && ver >= abs(y)) ? "YES" : "NO");
        
    }
    return 0;
}