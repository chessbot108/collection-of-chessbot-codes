//miles

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int psum[n];
    cin >> psum[0];
    for(int i = 1; i < n; i++){
        int a;
        scanf("%d", &a);
        psum[i] = psum[i-1]+a;
    }
    for(int i =0; i < m; i++){
        int a;
        scanf("%d", &a);
        printf("%d\n",psum[a-1]);
    }
}
