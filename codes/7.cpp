//code by daniel
#include <iostream>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    
    double ans = 0;
    if(n <= 30){
        ans = n*0.2;
        printf("%.2lf\n", ans);
    }
    else if(n > 60){
        printf("NO\n");
    }
    else{
        ans = 6;
        ans += (n-30)*0.6;
        printf("%.2lf\n", ans);
    }
    return 0;
}
